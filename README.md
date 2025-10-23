# Dự án: Đọc giá trị quang trở (LDR) với ESP32 và hiển thị bằng Teleplot

## 1. Giới thiệu

Dự án này sử dụng **ESP32** để đọc giá trị ánh sáng môi trường thông qua **cảm biến quang trở (LDR)**, sau đó hiển thị dữ liệu thời gian thực bằng **Teleplot** – một công cụ vẽ đồ thị trực tiếp từ Serial.

Khi ánh sáng yếu, **LED** được bật; khi ánh sáng mạnh, **LED** sẽ tắt tự động.

---

## 2. Phần cứng sử dụng

| Thành phần | Chức năng |
|-------------|-----------|
| ESP32 Devkit | Vi điều khiển chính |
| LDR (Light Dependent Resistor) | Cảm biến đo cường độ sáng |
| Điện trở 10kΩ | Tạo cầu chia điện áp cho LDR |
| LED + Điện trở 220Ω | Hiển thị trạng thái sáng/tối |
| Dây nối Breadboard | Kết nối các linh kiện |

### Sơ đồ nối dây

- **LDR + 10kΩ** tạo cầu chia điện áp:  
  - Điểm giữa nối vào **chân ADC34** của ESP32  
  - Một đầu LDR nối **3.3V**, đầu còn lại nối **GND** qua điện trở 10kΩ  
- **LED** nối chân **GPIO26** qua điện trở 220Ω xuống **GND**

---
## 3. Kết quả hiển thị trên Teleplot

Ảnh dưới đây là **đồ thị cường độ sáng theo thời gian thực** khi chiếu đèn hoặc che tay lên cảm biến:
![image alt](https://github.com/Loincute/esp32_LDR_test/blob/166467d452f2ee06898360c906bd39d15e0c865e/teleplot_esp32.png)

## 4. Cách sử dụng

1. **Tạo dự án PlatformIO (ESP32)**  
2. **Sao chép mã vào file `src/main.cpp`**
   
### Nạp chương trình lên ESP32 và hiển thị với Teleplot

1. **Kết nối ESP32 với máy tính** qua cổng USB.  
2. Trong **PlatformIO**, nhấn **Upload** để nạp mã vào bo ESP32.  
3. **Cài plugin Teleplot** để hiển thị đồ thị:  
  (https://marketplace.visualstudio.com/items?itemName=alexnesnes.teleplot )
4. Sau khi cài, mở **Serial Monitor** trong VS Code.  
5. Bật **chế độ Teleplot** trong thanh công cụ Serial.  
6. Đặt tốc độ baudrate là **115200**.  
7. Quan sát **đồ thị ánh sáng và trạng thái LED** thay đổi theo thời gian thực khi bạn chiếu đèn hoặc che tay lên cảm biến.

##  5.Giải thích hoạt động

- **LDR (Light Dependent Resistor)** có điện trở thay đổi theo cường độ sáng của môi trường.  
- Khi **ánh sáng mạnh** → điện trở của LDR **giảm** → điện áp tại chân ADC **tăng** → giá trị đọc được từ `analogRead()` **cao**.  
- Khi **ánh sáng yếu** → điện trở của LDR **tăng** → điện áp tại chân ADC **giảm** → giá trị đọc được từ `analogRead()` **thấp**.  
- **ESP32** đọc giá trị ADC trong khoảng **0 – 4095** và gửi dữ liệu này sang **Teleplot** thông qua **UART (Serial)**.  
- **Teleplot** nhận dữ liệu dạng `>light:giá_trị` và vẽ **đồ thị cường độ sáng theo thời gian thực**.  
- Đồng thời, chương trình điều khiển **LED**:
  - Nếu ánh sáng **yếu** (giá trị ADC thấp) → **LED bật**.  
  - Nếu ánh sáng **mạnh** (giá trị ADC cao) → **LED tắt**.
