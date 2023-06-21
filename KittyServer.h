#ifndef KITTYSERVER_H
#define KITTYSERVER_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>        

class KittyServer {
  public:
  KittyServer();
  void setup();
  void handleClient();

  private:
  String header;
};

#endif
