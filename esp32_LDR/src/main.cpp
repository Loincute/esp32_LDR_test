#include <Arduino.h>

#define LDR_PIN 34  // Chân ADC đọc tín hiệu từ LDR

void setup() {
  Serial.begin(115200);  // Mở UART để gửi dữ liệu
  delay(1000);
  Serial.println("Bắt đầu đo ánh sáng...");
}

void loop() {
  int value = analogRead(34);   // đọc LDR
  Serial.printf(">light:%d\n", value);
  delay(2000);
}