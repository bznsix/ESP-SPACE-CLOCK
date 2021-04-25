/*
 * @Author: your name
 * @Date: 2021-04-11 18:38:04
 * @LastEditTime: 2021-04-12 11:47:53
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\Users\86155\Desktop\mqtt\wifi.h
 */
#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void wifi_init();
String ReturnHttpPayload(String link);
