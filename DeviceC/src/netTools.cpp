#include "netTools.h"
#include "display.h"
#include "time.h"

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

// const char* ntpServer = "pool.ntp.org";
// const long  gmtOffset_sec = 0;
// const int   daylightOffset_sec = 3600;

// WiFiClientSecure net = WiFiClientSecure();
// MQTTClient client = MQTTClient(256);
// void messageHandler(String &topic, String &payload);

netTools::netTools(int pub){
    if (pub){
        publisher = "C";
        subscriber = "J";
        thing_name = "Connor_ESP32";
    }
    else{
        publisher = "J";
        subscriber = "C";
        thing_name = "Julianna_ESP32"
    }
}

void netTools::cloop(){
    client.loop();
}

void netTools::init()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.println("Connecting to Wi-Fi");

    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    // Configure WiFiClientSecure to use the AWS IoT device credentials
    net.setCACert(AWS_CERT_CA);
    net.setCertificate(AWS_CERT_CRT);
    net.setPrivateKey(AWS_CERT_PRIVATE);

    // Connect to the MQTT broker on the AWS endpoint we defined earlier
    client.begin(AWS_IOT_ENDPOINT, 8883, net);

    // Create a message handler
    // client.onMessage(messageHandler);
    client.onMessage([this](String &topic, String &payload) {
        this->messageHandler(topic, payload);
    });

    Serial.print("Connecting to AWS IOT");

    while (!client.connect(thing_name)) {
        Serial.print(".");
        delay(100);
    }

    if(!client.connected()){
        Serial.println("AWS IoT Timeout!");
        return;
    }

    // Subscribe to a topic
    client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

    Serial.println("AWS IoT Connected!");

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    
}

void netTools::publishMessage(int str)
{
    JsonDocument doc;
    doc["time"] = millis();
    doc["publisher"] = publisher;
    doc["subscriber"] = subscriber;
    doc["msg"] = str;
    char jsonBuffer[512];
    serializeJson(doc, jsonBuffer); // print to client
    Serial.println("Message Sent");
    client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void netTools::messageHandler(String &topic, String &payload) {
    JsonDocument recdoc;
    deserializeJson(recdoc, payload);
    if(strcmp(recdoc["subscriber"], subscriber.c_str()) == 0 ){
        Serial.println("message recieved");
        displayMsg(recdoc["msg"]);
    }
  
}

bool netTools::fixConnection(){
    if(WiFi.status() != WL_CONNECTED){
        WiFi.reconnect();
    }
    if (!client.connected()){
        client.connect(thing_name);
    }
}