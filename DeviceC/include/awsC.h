#include "secrets.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include "utils.h"

#ifndef AWSC_H
#define AWSC_H

// aws.h
// extern MQTTClient Jclient;
extern MQTTClient Cclient;
extern WiFiClientSecure net;

class netTools{

private:

    int date2int(const char* st);

public:
    float cur_temp;
    float for_temp[4];
    int for_times[4];
    int cur_time;
    int code;
    int for_codes[4];

    // Creates weather instance
    netTools();
    
    void init();

    void update_current();

    void update_time();

    void update_forecast();

    int get_icon();
};

void CconnectAWS();
void Cloop();
// void CpublishMessage(String str);
void CpublishMessage(int str);


#endif