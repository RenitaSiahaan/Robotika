// 1. PASTE 3 BARIS KODE DARI BLYNK CONSOLE DI SINI:
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// 2. ISIKAN NAMA WIFI DAN PASSWORD YANG DIGUNAKAN (Misal Hotspot HP):
char ssid[] = "";
char pass[] = "";

#define LED_PIN 2 // Pin LED internal ESP32

// Fungsi berjalan saat tombol di aplikasi Blynk ditekan
BLYNK_WRITE(V0) {
  int value = param.asInt(); // Membaca nilai dari widget Switch (0 atau 1)
  digitalWrite(LED_PIN, value); // Menyala jika 1, Mati jika 0
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  // Mengkoneksikan ESP32 ke Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run(); // Menjalankan fungsi Blynk
}
