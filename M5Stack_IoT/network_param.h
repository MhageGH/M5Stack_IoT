#ifndef _NETWORK_H
#define _NETWORK_H

// for WiFi
char *ssid = "xxxx";
char *password = "xxxx";

// for AWS IoT
const char *endpoint = "xxxx";
const int port = 8883;
const char *subTopic = "xxxx";
const char *pubTopic = "xxxx";
const char *device = "xxxx";

const char* rootCA = 
"-----BEGIN CERTIFICATE-----\n" \
"xxxx"
"-----END CERTIFICATE-----\n";

const char* certificate = 
"-----BEGIN CERTIFICATE-----\n" \
"xxxx"
"-----END CERTIFICATE-----\n";

const char* privateKey = 
"-----BEGIN RSA PRIVATE KEY-----\n" \
"xxxx"
"-----END RSA PRIVATE KEY-----\n";


#endif // _NETWORK_H
