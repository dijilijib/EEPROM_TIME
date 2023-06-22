#ifndef THINGS_H
#define THINGS_H

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #define THINGSBOARD_ENABLE_PROGMEM 0
#elif defined(ARDUINO_NANO_RP2040_CONNECT)
  #include <WiFiNINA_Generic.h>
#elif defined(ESP32) || defined(RASPBERRYPI_PICO) || defined(RASPBERRYPI_PICO_W)
  #include <WiFi.h>
  #include <WiFiClientSecure.h>
#endif
#include <Arduino.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <ThingsBoard.h>
#include <array>

// Function declarations
void InitWiFi();
const bool reconnect();
RPC_Response processButtonState(const RPC_Data &data); // RPC
void processSharedAttributes(const Shared_Attribute_Data &data);
void processClientAttributes(const Shared_Attribute_Data &data);
void thingsboard_setup();
void thingsboard_loop();
void sendMamaMiktari(float DISTANCE); 

// Constant definitions
extern WiFiUDP ntpUDP;
extern NTPClient timeClient;
extern const char WIFI_SSID[];
extern const char WIFI_PASSWORD[];
extern const char TOKEN[];
extern const char THINGSBOARD_SERVER[];
extern const uint16_t THINGSBOARD_PORT;
extern const uint32_t MAX_MESSAGE_SIZE;
extern const uint32_t SERIAL_DEBUG_BAUD;
extern WiFiClient wifiClient;
extern ThingsBoard tb;
extern const char BLINKING_INTERVAL_ATTR[];
extern const char LED_MODE_ATTR[];
extern const char LED_STATE_ATTR[];
extern bool subscribed;
extern volatile bool attributesChanged;
extern volatile int ledMode;
extern volatile bool ledState;
extern const uint16_t BLINKING_INTERVAL_MS_MIN;
extern const uint16_t BLINKING_INTERVAL_MS_MAX;
extern volatile uint16_t blinkingInterval;
extern uint32_t previousStateChange;
extern const int16_t telemetrySendInterval;
extern uint32_t previousDataSend;
extern const std::array<const char *, 2U> SHARED_ATTRIBUTES_LIST;
extern const std::array<const char *, 1U> CLIENT_ATTRIBUTES_LIST;
extern const std::array<RPC_Callback, 1U> callbacks;
extern const Shared_Attribute_Callback attributes_callback;
extern const Attribute_Request_Callback attribute_shared_request_callback;
extern const Attribute_Request_Callback attribute_client_request_callback;

#endif // THINGS_H
