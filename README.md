# การเขียนโปรแกรมควบคุมรถหุ่นยนต์อัจฉริยะ (Smart Robot Car - Igniter Camp 2026)

คลังรวบรวมโค้ดตัวอย่างสำหรับอบรมการเขียนโปรแกรมควบคุมรถหุ่นยนต์อัจฉริยะ (**LAFVIN WiFi Camera Smart Robot Car**) ด้วยโปรแกรม **Arduino IDE** โดยแบ่งออกเป็น 13 บทเรียนย่อยตามลำดับในเอกสารประกอบการอบรม

📄 **เอกสารประกอบการอบรม (PDF):** [การเขียนโปรแกรมควบคุมรถหุ่นยนต์อัจฉริยะ.pdf](./การเขียนโปรแกรมควบคุมรถหุ่นยนต์อัจฉริยะ.pdf)

---

## อุปกรณ์และขาเชื่อมต่อหลัก (Pin Mapping)

รถหุ่นยนต์ประกอบด้วยไมโครคอนโทรลเลอร์ 2 บอร์ดที่ทำงานร่วมกัน:

### 1. บอร์ด Arduino Uno (ควบคุมล้อและเซ็นเซอร์)
| อุปกรณ์ | ขาพิน (Pin) | โหมด | คำอธิบาย |
| :--- | :---: | :---: | :--- |
| **LED บนบอร์ด** | `Pin 13` | `OUTPUT` | ไฟ LED มาตรฐานบนบอร์ด Arduino Uno |
| **ทิศทางล้อซ้าย (`LEFT_WHEELS`)** | `Pin 2` | `OUTPUT` | `HIGH` = หมุนเดินหน้า, `LOW` = หมุนถอยหลัง |
| **ความเร็วล้อซ้าย (`LEFT_WHEELS_SPEED`)** | `Pin 5` (PWM) | `OUTPUT` | กำหนดความเร็วด้วย `analogWrite` ค่า `0 - 255` |
| **ทิศทางล้อขวา (`RIGHT_WHEELS`)** | `Pin 4` | `OUTPUT` | `LOW` = หมุนเดินหน้า, `HIGH` = หมุนถอยหลัง *(กลับด้านกับล้อซ้าย)* |
| **ความเร็วล้อขวา (`RIGHT_WHEELS_SPEED`)** | `Pin 6` (PWM) | `OUTPUT` | กำหนดความเร็วด้วย `analogWrite` ค่า `0 - 255` |
| **เซ็นเซอร์เดินตามเส้น (ซ้าย / กลาง / ขวา)** | `Pin 7, 8, 9` | `INPUT_PULLUP` | อ่านค่า `0` = พื้นสีขาว (สะท้อนแสง), `1` = เส้นสีดำ หรือลอยในอากาศ |
| **เซ็นเซอร์อัลตราโซนิค (`Trig` / `Echo`)** | `Pin 12 / 13` | `OUTPUT / INPUT` | `Pin 12` ส่งคลื่นเสียง (`Trig`), `Pin 13` รับเสียงสะท้อน (`Echo`) |
| **รับคำสั่งจาก ESP32-CAM (`RX`)** | `Pin 0 (RX)` | `Serial` | รับอักษรคำสั่ง (`F`, `B`, `L`, `R`, `S`) ที่ความเร็ว `115200 baud` |

### 2. บอร์ด AI Thinker ESP32-CAM (กล้องวิดีโอและ WiFi Web Server)
- เชื่อมต่อ WiFi ได้ทั้งแบบ **Infrastructure Mode** (เกาะ WiFi บ้าน/โรงเรียน) และ **Access Point (AP) Mode** (ปล่อยสัญญาณ WiFi เองจากตัวรถ)
- ส่งคำสั่งควบคุมล้อผ่านขา **`TX Pin 13`** (`Serial1` ที่ความเร็ว `115200 baud`) ไปยังขา `RX Pin 0` ของ Arduino Uno
- **การตั้งค่า Additional Boards Manager URL ใน Arduino IDE สำหรับ ESP32:**
  ```text
  https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
  ```

---

## รายการโค้ดตัวอย่างทั้ง 13 บทเรียน

| ลำดับ | โฟลเดอร์ / ไฟล์ | บอร์ดที่ใช้อัปโหลด | คำอธิบายการทำงาน |
| :-: | :--- | :---: | :--- |
| **01** | [`01_led_blink`](./01_led_blink/01_led_blink.ino) | Arduino Uno | **พื้นฐาน Arduino:** สั่งให้ไฟ LED บนบอร์ด (`Pin 13`) กระพริบติด 1 วินาที สลับกับดับ 1 วินาที |
| **02** | [`02_wheel_control_basic`](./02_wheel_control_basic/02_wheel_control_basic.ino) | Arduino Uno | **การควบคุมล้อเบื้องต้น:** สั่งให้ล้อซ้าย (ความเร็ว `127`) และล้อขวา (ความเร็ว `200`) หมุนเดินหน้าในฟังก์ชัน `setup()` *(ต้องใส่ถ่านและเปิดสวิตช์สีฟ้าบนบอร์ดล้อจึงจะหมุน)* |
| **03** | [`03_wheel_control_function`](./03_wheel_control_function/03_wheel_control_function.ino) | Arduino Uno | **การสร้างฟังก์ชันควบคุมล้อ:** แยกคำสั่งหมุนล้อออกมาเป็นฟังก์ชัน `car_forward(left_speed, right_speed)` เพื่อเรียกใช้งานซ้ำได้สะดวก |
| **04** | [`04_line_detect`](./04_line_detect/04_line_detect.ino) | Arduino Uno | **ทดสอบเซ็นเซอร์ตรวจจับเส้น:** อ่านค่าจากเซ็นเซอร์อินฟราเรดตัวซ้าย (`Pin 7`) แล้วแสดงผลค่า `0` (พื้นขาว) หรือ `1` (เส้นดำ/ลอย) ออกทาง Serial Monitor (`57600 baud`) |
| **05** | [`05_line_tracking`](./05_line_tracking/05_line_tracking.ino) | Arduino Uno | **ระบบเดินตามเส้นอัตโนมัติ:** ใช้เซ็นเซอร์ 3 ตัว (`Pin 7, 8, 9`) ตรวจจับเส้นเทปสีดำ หากเส้นอยู่ตรงกลาง (`0, 1, 0`) ให้เดินหน้าตรง หากเบี่ยงซ้ายหรือขวาให้ชะลอล้อข้างนั้นเพื่อเลี้ยวกลับเข้าเส้น |
| **06** | [`06_ultra_sound`](./06_ultra_sound/06_ultra_sound.ino) | Arduino Uno | **ทดสอบวัดระยะทางด้วยคลื่นอัลตราโซนิค:** ส่งคลื่นเสียงออกทาง `Pin 12` และจับเวลาสะท้อนกลับทาง `Pin 13` ด้วยคำสั่ง `pulseIn()` แปลงเป็นหน่วยเซนติเมตร (`cm`) แสดงผลทาง Serial Monitor (`57600 baud`) |
| **07** | [`07_object_avoidance`](./07_object_avoidance/07_object_avoidance.ino) | Arduino Uno | **ระบบเดินหลบหลีกสิ่งกีดขวาง:** สั่งให้รถเดินหน้าไปเรื่อย ๆ และเมื่อตรวจพบวัตถุด้านหน้าในระยะน้อยกว่า `20 cm` จะสุ่มหมุนตัวไปทางซ้ายหรือขวาเป็นเวลา 0.5 วินาทีแล้วเดินหน้าต่อ |
| **08** | [`08_esp32cam_send_hello`](./08_esp32cam_send_hello/08_esp32cam_send_hello.ino) | ESP32-CAM | **ทดสอบส่งข้อมูลจาก ESP32-CAM:** ส่งข้อความ `"Hello"` ทุก ๆ 0.5 วินาทีผ่าน `Serial1` (`TX Pin 13`, `115200 baud`) ไปยังบอร์ด Arduino Uno |
| **09** | [`09_arduino_receive_hello`](./09_arduino_receive_hello/09_arduino_receive_hello.ino) | Arduino Uno | **ทดสอบรับข้อมูลบน Arduino Uno:** รับข้อความ `"Hello"` ที่ส่งมาจากบอร์ด ESP32-CAM ผ่านทาง `Serial` (`115200 baud`) แล้วนำมาแสดงผลบน Serial Monitor |
| **10** | [`10_esp32cam_infra_wifi_mode`](./10_esp32cam_infra_wifi_mode/10_esp32cam_infra_wifi_mode.ino) | ESP32-CAM | **การเชื่อมต่อ WiFi แบบ Infrastructure Mode:** ให้ ESP32-CAM เชื่อมต่อเข้ากับ WiFi ที่มีอยู่แล้ว (เช่น Router หรือ Hotspot มือถือ) พร้อมแสดงหมายเลข IP Address ทาง Serial Monitor (`57600 baud`) |
| **11** | [`11_esp32cam_ap_wifi_mode`](./11_esp32cam_ap_wifi_mode/11_esp32cam_ap_wifi_mode.ino) | ESP32-CAM | **การเชื่อมต่อ WiFi แบบ Access Point (AP) Mode:** ตั้งค่าให้ ESP32-CAM ปล่อยสัญญาณ WiFi ของตัวเอง (`SSID: ESP32-CAM_AP`, รหัสผ่าน `12345678`) โดยมี IP มาตรฐานคือ `192.168.4.1` |
| **12** | [`12_wifi_controlled_smart_robot_car`](./12_wifi_controlled_smart_robot_car/12_wifi_controlled_smart_robot_car.ino) | ESP32-CAM | **ระบบ Web Server + กล้องสตรีมวิดีโอและปุ่มควบคุมรถ:** แสดงภาพสดจากกล้องบนหน้าเว็บเบราว์เซอร์ พร้อมปุ่มกดควบคุม 5 ทิศทาง (`Forward`, `Left`, `Stop`, `Right`, `Backward`) ซึ่งจะส่งรหัส `F`, `L`, `S`, `R`, `B` ไปให้ Arduino Uno |
| **13** | [`13_control_wheels_from_esp32cam`](./13_control_wheels_from_esp32cam/13_control_wheels_from_esp32cam.ino) | Arduino Uno | **โปรแกรมรับคำสั่งขับเคลื่อนล้อจาก ESP32-CAM:** รอรับรหัสตัวอักษร `F`, `B`, `L`, `R`, `S` จากบอร์ด ESP32-CAM ผ่าน `Serial` (`115200 baud`) เพื่อสั่งให้ล้อหมุนเดินหน้า ถอยหลัง เลี้ยวซ้าย เลี้ยวขวา หรือหยุด |

---

## ข้อควรระวังในการใช้งาน
1. **การหมุนของล้อ:** การเสียบสาย USB เพียงอย่างเดียวสามารถอัปโหลดโค้ดและอ่านค่าเซ็นเซอร์ได้ แต่**มอเตอร์ล้อจะหมุนก็ต่อเมื่อใส่แบตเตอรี่และกดเปิดสวิตช์สีฟ้าบนบอร์ดขยาย (Shield) เท่านั้น**
2. **การตั้งค่า Baud Rate ใน Serial Monitor:** ตรวจสอบให้ตรงกับค่าใน `Serial.begin(...)` ของแต่ละโปรแกรมเสมอ (`57600` หรือ `115200`) มิฉะนั้นข้อความจะแสดงผลเป็นตัวอักษรอ่านไม่ออก
3. **การอัปโหลดโค้ดลง Arduino Uno เมื่อต่อร่วมกับ ESP32-CAM:** หากอัปโหลดไม่ผ่าน ให้ปิดสวิตช์ไฟสีฟ้าชั่วคราวขณะอัปโหลด เพื่อป้องกันไม่ให้บอร์ด ESP32-CAM ส่งข้อมูลรบกวนขา `Pin 0 (RX)` ของ Arduino Uno
