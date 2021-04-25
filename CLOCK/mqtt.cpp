/*
 * @Author: your name
 * @Date: 2021-04-18 23:24:07
 * @LastEditTime: 2021-04-22 19:37:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CLOCK\mqtt.cpp
 */
#include "mqtt.h"
mqttData globalData;
const char* mqtt_server = "104.160.34.42";                     // 使用HIVEMQ 的信息中转服务
const char* TOPIC = "jiucai";                     // 订阅信息主题
const char* client_id = "8873";                   // 标识当前设备的客户端编号，随便填
WiFiClient espClient;                             // 定义wifiClient实例
PubSubClient client(espClient);                   // 定义PubSubClient的实例
long lastMsg = 0;                                 // 记录上一次发送信息的时长


mqttData parsePayload(String s){
  mqttData result;
  unsigned int split;
  char symbol[] = "&";
  split = s.indexOf(symbol);
  result.price = s.substring(0, split);
  result.precent = s.substring((split+1),(s.length()));
  return result;
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(client_id)) {
      Serial.println("connected");
      // 连接成功时订阅主题
      client.subscribe(TOPIC);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String temp;
  // Serial.print("Message arrived [");
  // Serial.print(topic);   // 打印主题信息
  // Serial.print("] ");
  for (int i = 0; i < length; i++) {
    // Serial.print((char)payload[i]); // 打印主题内容
    temp = temp + (char)payload[i];
  }
   globalData = parsePayload(temp);
}

void parseMqtt(){
  client.setServer(mqtt_server, 1883);                              //设定MQTT服务器与使用的端口，1883是默认的MQTT端口
  client.setCallback(callback);                                          //设定回调方式，当ESP8266收到订阅消息时会调用此方法
  if (!client.connected()) {
      reconnect();
    }
    client.loop();

    long now = millis();
    if (now - lastMsg > 2000) {
      lastMsg = now;
    }
}





