#include "awsC.h"
#include "display.h"
#include "time.h"

MQTTClient Cclient = MQTTClient(256);
WiFiClientSecure net = WiFiClientSecure();

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;

// WiFiClientSecure net = WiFiClientSecure();
// MQTTClient client = MQTTClient(256);
void messageHandler(String &topic, String &payload);

void Cloop(){
    Cclient.loop();
}

void CconnectAWS()
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
    Cclient.begin(AWS_IOT_ENDPOINT, 8883, net);

    // Create a message handler
    Cclient.onMessage(messageHandler);

    Serial.print("Connecting to AWS IOT");

    while (!Cclient.connect(CTHINGNAME)) {
        Serial.print(".");
        delay(100);
    }

    if(!Cclient.connected()){
        Serial.println("AWS IoT Timeout!");
        return;
    }

    // Subscribe to a topic
    Cclient.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

    Serial.println("AWS IoT Connected!");

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

}

void CpublishMessage(int str)
{
    JsonDocument doc;
    doc["time"] = millis();
    doc["publisher"] = "C";
    doc["subscriber"] = "J";
    doc["msg"] = str;
    char jsonBuffer[512];
    serializeJson(doc, jsonBuffer); // print to client
    Serial.println("Message Sent");
    Cclient.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void messageHandler(String &topic, String &payload) {
    JsonDocument recdoc;
    // Serial.println("incoming: " + topic + " - " + payload);
    deserializeJson(recdoc, payload);
    // Serial.print(strcmp(recdoc["subscriber"], "C"));
    if(strcmp(recdoc["subscriber"], "C") == 0 ){
        Serial.println("message recieved");
        displayMsg(recdoc["msg"]);
    }
  
}
