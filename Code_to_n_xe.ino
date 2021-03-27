const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04

#include <WiFi.h>
//
//  PSRAM IC required for UXGA resolution and high JPEG quality
//  Ensure ESP32 Wrover Module or other board with PSRAM is selected
//  Partial images will be transmitted if image exceeds buffer size
//

// Select camera model
#define CAMERA_MODEL_WROVER_KIT // Has PSRAM
//#define CAMERA_MODEL_ESP_EYE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_PSRAM // Has PSRAM
//#define CAMERA_MODEL_M5STACK_V2_PSRAM // M5Camera version B Has PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_ESP32CAM // No PSRAM
//#define CAMERA_MODEL_AI_THINKER // Has PSRAM
//#define CAMERA_MODEL_TTGO_T_JOURNAL // No PSRAM
//#include "camera_pins.h"

const char* ssid = "NHA HANG HOANG GIA";
const char* password = "88888888";

void startCameraServer(); 

#define MOTORLATCH 12 
#define MOTORCLK 4 
#define MOTORENABLE 7 
#define MOTORDATA 8 
#define MOTOR1_A 2 
#define MOTOR1_B 3 
#define MOTOR2_A 1 
#define MOTOR2_B 4 
#define MOTOR3_A 5 
#define MOTOR3_B 7 
#define MOTOR4_A 0 
#define MOTOR4_B 6 
#define MOTOR1_PWM 11 
#define MOTOR2_PWM 3 
#define MOTOR3_PWM 6 
#define MOTOR4_PWM 5 
#define SERVO1_PWM 10 
#define SERVO2_PWM 9 
#define FORWARD 1 
#define BACKWARD 2 
#define BRAKE 3 
#define RELEASE 4 
void setup() {
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
}
 
void loop()
{
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig

    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);

motor(1, FORWARD, 230);
motor(2, FORWARD, 230);
motor(3, FORWARD, 230);
motor(4, FORWARD, 230);
delay(2000);
motor(1, RELEASE, 0);
motor(2, RELEASE, 0);
motor(3, RELEASE, 0);
motor(4, RELEASE, 0);
delay(100);
motor(1, TURNRIGHT, 128);
motor(2, TURNRIGHT, 128);
motor(3, TURNRIGHT, 128);
motor(4, TURNRIGHT, 128);
delay(2000);
motor(1, RELEASE, 0);
motor(2, RELEASE, 0);
motor(3, RELEASE, 0);
motor(4, RELEASE, 0);
delay(100);
motor(1, FORWARD, 230); 
motor(2, FORWARD, 230);
motor(3, FORWARD, 230);
motor(4, FORWARD, 230);
delay(2000);
motor(1, RELEASE, 0);
motor(2, RELEASE, 0);
motor(3, RELEASE, 0);
motor(4, RELEASE, 0);
delay(100);
motor(1, TURNLEFT, 128);
motor(2, TURNLEFT, 128);
motor(3, TURNLEFT, 128);
motor(4, TURNLEFT, 128);
delay(2000);
case 1: 
  motorA = MOTOR1_A;
  motorB = MOTOR1_B;
  break; 
  case 2: 
  motorA = MOTOR2_A;
  motorB = MOTOR2_B;
  break; 
  case 3: 
  motorA = MOTOR3_A;
  motorB = MOTOR3_B;
  break; 
  case 4: 
  motorA = MOTOR4_A;
  motorB = MOTOR4_B;
  break; 
  default: 
  break; 
    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.println("cm");
    delay(200);
  
}

//
//  PSRAM IC required for UXGA resolution and high JPEG quality
//  Ensure ESP32 Wrover Module or other board with PSRAM is selected
//  Partial images will be transmitted if image exceeds buffer size
//

// Select camera model
#define CAMERA_MODEL_WROVER_KIT // Has PSRAM
//#define CAMERA_MODEL_ESP_EYE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_PSRAM // Has PSRAM
//#define CAMERA_MODEL_M5STACK_V2_PSRAM // M5Camera version B Has PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_ESP32CAM // No PSRAM
//#define CAMERA_MODEL_AI_THINKER // Has PSRAM
//#define CAMERA_MODEL_TTGO_T_JOURNAL // No PSRAM
void setup<2> {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  
  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

#if defined(CAMERA_MODEL_ESP_EYE)
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
#endif

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1); // flip it back
    s->set_brightness(s, 1); // up the brightness just a bit
    s->set_saturation(s, -2); // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  s->set_framesize(s, FRAMESIZE_QVGA);

#if defined(CAMERA_MODEL_M5STACK_WIDE) || defined(CAMERA_MODEL_M5STACK_ESP32CAM)
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);
#endif

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop(2) {
  // put your main code here, to run repeatedly:
  delay(10000);
}
