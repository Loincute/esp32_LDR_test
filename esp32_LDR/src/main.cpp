#include <Arduino.h>

const int LDR_PIN = 34;   // Chân ADC đọc cảm biến ánh sáng
const int LED_PIN = 26;   // Chân điều khiển LED ngoài

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int lightValue = analogRead(LDR_PIN); // Đọc giá trị ánh sáng (0 - 4095)

  // Gửi dữ liệu sang Teleplot
  Serial.print(">light:");
  Serial.println(lightValue);

  // Nếu ánh sáng yếu (giá trị nhỏ), bật LED; nếu sáng mạnh, tắt LED
  if (lightValue < 3000) {
    digitalWrite(LED_PIN, HIGH); // Bật LED
  } else {
    digitalWrite(LED_PIN, LOW);  // Tắt LED
  }

  delay(200); // Cập nhật mỗi 200ms
}
