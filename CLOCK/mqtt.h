/*
 * @Author: your name
 * @Date: 2021-04-18 23:25:00
 * @LastEditTime: 2021-04-19 11:27:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CLOCK\mqtt.h
 */
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
typedef struct {
        String price;
        String precent;
}mqttData;

extern mqttData globalData;
void parseMqtt();