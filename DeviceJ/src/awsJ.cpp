#include "awsJ.h"
#include "display.h"
MQTTClient Jclient = MQTTClient(256);
WiFiClientSecure net = WiFiClientSecure();



// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

// WiFiClientSecure net = WiFiClientSecure();
// MQTTClient client = MQTTClient(256);
void messageHandler(String &topic, String &payload);

void succ();
void fail();

void Jloop(){
    Jclient.loop();
}

void JconnectAWS()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.println("Connecting to Wi-Fi");

    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    // Configure WiFiClientSecure to use the AWS IoT device credentials
    net.setCACert(J_AWS_CERT_CA);
    net.setCertificate(J_AWS_CERT_CRT);
    net.setPrivateKey(J_AWS_CERT_PRIVATE);

    // Connect to the MQTT broker on the AWS endpoint we defined earlier
    Jclient.begin(AWS_IOT_ENDPOINT, 8883, net);

    // Create a message handler
    Jclient.onMessage(messageHandler);

    Serial.print("Connecting to AWS IOT");

    while (!Jclient.connect(JTHINGNAME)) {
        Serial.print(".");
        delay(100);
    }

    if(!Jclient.connected()){
        Serial.println("AWS IoT Timeout!");
        return;
    }

    // Subscribe to a topic
    Jclient.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

    Serial.println("AWS IoT Connected!");
}

// void JpublishMessage(String str)
// {
//     JsonDocument doc;
//     doc["time"] = millis();
//     doc["publisher"] = "J";
//     doc["subscriber"] = "C";
//     doc["msg"] = str;
//     // doc["msg"] = "yo";

//     char jsonBuffer[512];
//     serializeJson(doc, jsonBuffer); // print to client

//     Jclient.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
//     Serial.println("Message Sent");
// }

void JpublishMessage(int str)
{
    JsonDocument doc;
    char jsonBuffer[512];
    doc["time"] = millis();
    doc["publisher"] = "J";
    doc["subscriber"] = "C";
    doc["msg"] = str;
    // doc["msg"] = "yo";

    serializeJson(doc, jsonBuffer); // print to client

    Jclient.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
    Serial.println("Message Sent");
}



void messageHandler(String &topic, String &payload) {
    JsonDocument recdoc;
    deserializeJson(recdoc, payload);
    String st = recdoc["subscriber"];
    Serial.println(st);
    if(strcmp(recdoc["subscriber"], "J") == 0 ){
        Serial.println("message recieved");
        displayMsg(recdoc["msg"]);
    }
  
}
