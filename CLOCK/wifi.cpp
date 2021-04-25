/*
 * @Author: Pengxin
 * @Date: 2021-04-11 18:38:04
 * @LastEditTime: 2021-04-12 14:07:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\Users\86155\Desktop\mqtt\wifi.cpp
 */
#include "wifi.h"
//user defined parmas
char api_key[34] = "Your ApiKey";

void wifi_init(){
    //add user defined parmas here
    WiFiManagerParameter custom_apikey("apikey", "onenet apikey", api_key, 32);

    WiFiManager wm;
    WiFi.mode(WIFI_STA); 
    bool res;
    wm.addParameter(&custom_apikey);
    res = wm.autoConnect("jiucai123","12345678"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        ESP.restart();
    } 
    else {
        //once connected  
        Serial.println("connected...yeey :)");
        strcpy(api_key, custom_apikey.getValue());
        Serial.println(api_key);
    }
}



/**
 * @description:return http request 
 * @param {String} link
 * @return {*}
 * "https://api.huobi.pro/market/history/kline?symbol=" + uid + "&period=1day&size=1"
 */

String ReturnHttpPayload(String link)
{
	String payload = "";
	HTTPClient http;
	http.begin(link);

	// start connection and send HTTP headerFFF
	int httpCode = http.GET();

	// httpCode will be negative on error
	if (httpCode > 0)
	{
		// file found at server
		if (httpCode == HTTP_CODE_OK)
		{
			String payload = http.getString();
		}
	}
	else
	{
		Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
	}
	http.end();

    return payload;
}
