#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "Arduino.h"
#include "WiFi.h"
#include "AsyncUDP.h"

class Connector{
    public: const char * ssid = "ZAQK";
    public: const char * password = "199zia66";
    AsyncUDP udp;
    int port = 7000;

    Connector (){
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid,password);
    }

    void broadcast(String message){
        udp.broadcastTo(message.c_str(), port);
    }
};

#endif