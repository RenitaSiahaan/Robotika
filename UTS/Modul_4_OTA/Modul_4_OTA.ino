#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_FIRMWARE_VERSION        "0.1.3" 

#define BLYNK_PRINT Serial
#define APP_DEBUG

#ifndef BLYNK_WIFI_SSID
  #define BLYNK_WIFI_SSID ""
#endif
#ifndef BLYNK_WIFI_PASS
  #define BLYNK_WIFI_PASS ""
#endif

#include <Arduino.h>
#include <WiFi.h>
#include "BlynkEdgent.h"

#define LED_PIN 2 // Pin LED internal ESP32

BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(LED_PIN, value);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  pinMode(LED_PIN, OUTPUT); 

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
