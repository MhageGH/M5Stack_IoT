#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <M5Stack.h>
#include "network_param.h"
WiFiClientSecure httpsClient;
PubSubClient mqttClient(httpsClient);

void setup() {
  M5.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  httpsClient.setCACert(rootCA);
  httpsClient.setCertificate(certificate);
  httpsClient.setPrivateKey(privateKey);
  mqttClient.setServer(endpoint, port);
  mqttClient.setCallback(mqttCallback);
}

void mqttCallback (char* topic, byte* payload, unsigned int length) {
  for (int i = 0; i < length; i++) M5.Lcd.print((char)payload[i]);
}

void loop() {
  while (!mqttClient.connected()) {
    if (mqttClient.connect(device)) mqttClient.subscribe(subTopic, 0);
    else delay(5000);
  }
  if(M5.BtnA.wasPressed()) mqttClient.publish(pubTopic, "Hello. This is M5Stack.");
  M5.update();
  mqttClient.loop();
}
