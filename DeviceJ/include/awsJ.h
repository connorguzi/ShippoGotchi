#include "julianna_secrets.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include "utils.h"

#ifndef AWS_H
#define AWS_H

// aws.h
extern MQTTClient Jclient;
extern WiFiClientSecure net;


void JconnectAWS();
void Jloop();
void JpublishMessage(int str);
// void JpublishMessage(String str);



#endif