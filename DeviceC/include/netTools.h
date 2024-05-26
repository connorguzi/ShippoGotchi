#include "secrets.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include "utils.h"

#ifndef NETTOOLS_H
#define NETTOOLS_H

#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"


class netTools{

private:

    MQTTClient client = MQTTClient(256);
    WiFiClientSecure net = WiFiClientSecure();
    String publisher;
    String subscriber;
    String thing_name;
    const char* ntpServer = "pool.ntp.org";
    const long  gmtOffset_sec = 0;
    const int   daylightOffset_sec = 3600;
    int cur_time;
    int cur_temp;
    int cur_icon;

    void messageHandler(String &topic, String &payload);

public:
    netTools(int pub); // 0 for J 1 for C
    void init();
    void cloop();
    // void CpublishMessage(String str);
    void publishMessage(int str);
    bool fixConnection();
    int updateWeather();
    int updateTime();
    int getTime();
    int getTemp();
    int getIcon();
};


#endif