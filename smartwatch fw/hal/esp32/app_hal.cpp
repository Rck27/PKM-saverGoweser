
#define LGFX_USE_V1
#include "Arduino.h"
#include <LovyanGFX.hpp>
#include "CST816D.h"
uint8_t br = 255;

#include <Arduino.h>
////////////////////////////////////////////// heart rate sensor
#include <Wire.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"
#include "heartRate.h"

unsigned long sensorInterval = 2000UL; // default interval 2 seconds
unsigned long lastActivityTime = 0;
const unsigned long inactivityThreshold = 120000UL; // 5 minutes
float batteryVoltage;


MAX30105 particleSensor;
uint32_t irBuffer[50]; //infrared LED sensor data
uint32_t redBuffer[50];  //red LED sensor data
int32_t bufferLength; //data length
int32_t spo2; //SPO2 value
int8_t validSPO2; //indicator to show if the SPO2 calculation is valid
int32_t heartRate; //heart rate value
int8_t validHeartRate; //indicator to show if the heart 

#include <ESP32Time.h>
#include "app_hal.h"

#include <lvgl.h>
#include "ui/ui.h"

#include "main.h"
#include <Wire.h>
#include <WiFi.h>
#include <FirebaseClient.h>
#include <WiFiClientSecure.h>
#include <AsyncTCP.h>
#include <WiFiUdp.h>
// void sendNTPpacket(IPAddress);
void SyncRTC(void);
unsigned long int getNtpTime(void);


#define WIFI_SSID "Goweser"
#define WIFI_PASSWORD "Goweser123"

#define DATABASE_URL "https://savergowes-default-rtdb.asia-southeast1.firebasedatabase.app/"

WiFiUDP Udp;
String name;
WiFiClientSecure ssl;
DefaultNetwork network;
AsyncClientClass client(ssl, getNetwork(network));


FirebaseApp app;
RealtimeDatabase Database;
AsyncResult result;
NoAuth noAuth;
ESP32Time rtc(0);  // offset in seconds GMT+1


unsigned long timerNow, timerLast;
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
char isLead;
int irValue, H, M, S, beatAvg;
float Distance;  int BPM, SPO;
bool isStart;
bool screenOn;


#define buf_size 10




void initwifi() {
  // String wifiText = "ini wifii 12345678     ";
  Serial.println("init wifi");
  WiFi.mode(WIFI_MODE_STA);
  WiFi.setAutoReconnect(true);
  // WiFi.set
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // WiFi.setTxPower(WIFI_POWER_MINUS_1dBm);
  Serial.println(WiFi.getTxPower());


while(WiFi.status() !=  WL_CONNECTED){
  delay(5);
}
//  for (int i = 0; i <= 254; i++) {
//   if (WiFi.status() == WL_CONNECTED) {
//     break;
//   }
//   delay(5);  // Delay for 5 milliseconds
// }
  Serial.println(WiFi.setTxPower(WIFI_POWER_2dBm));
  Serial.println(WiFi.getTxPower());
  Serial.println("->");  
  Udp.begin(8888);
  WiFi.setSleep(false);
  // lv_disp_load_scr(ui_Screen1);

}



class LGFX : public lgfx::LGFX_Device
{

  lgfx::Panel_GC9A01 _panel_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Bus_SPI _bus_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();

      // SPIバスの設定
      cfg.spi_host = SPI; // 使用するSPIを選択  ESP32-S2,C3 : SPI2_HOST or SPI3_HOST / ESP32 : VSPI_HOST or HSPI_HOST
      // ※ ESP-IDFバージョンアップに伴い、VSPI_HOST , HSPI_HOSTの記述は非推奨になるため、エラーが出る場合は代わりにSPI2_HOST , SPI3_HOSTを使用してください。
      cfg.spi_mode = 0;                  // SPI通信モードを設定 (0 ~ 3)
      cfg.freq_write = 80000000;         // 传输时的SPI时钟（最高80MHz，四舍五入为80MHz除以整数得到的值）
      cfg.freq_read = 20000000;          // 接收时的SPI时钟
      cfg.spi_3wire = true;              // 受信をMOSIピンで行う場合はtrueを設定
      cfg.use_lock = true;               // 使用事务锁时设置为 true
      cfg.dma_channel = SPI_DMA_CH_AUTO; // 使用するDMAチャンネルを設定 (0=DMA不使用 / 1=1ch / 2=ch / SPI_DMA_CH_AUTO=自動設定)
      // ※ ESP-IDFバージョンアップに伴い、DMAチャンネルはSPI_DMA_CH_AUTO(自動設定)が推奨になりました。1ch,2chの指定は非推奨になります。
      cfg.pin_sclk = SCLK; // SPIのSCLKピン番号を設定
      cfg.pin_mosi = MOSI; // SPIのCLKピン番号を設定
      cfg.pin_miso = MISO; // SPIのMISOピン番号を設定 (-1 = disable)
      cfg.pin_dc = DC;     // SPIのD/Cピン番号を設定  (-1 = disable)

      _bus_instance.config(cfg);              // 設定値をバスに反映します。
      _panel_instance.setBus(&_bus_instance); // バスをパネルにセットします。
    }

    {                                      // 表示パネル制御の設定を行います。
      auto cfg = _panel_instance.config(); // 表示パネル設定用の構造体を取得します。

      cfg.pin_cs = CS;   // CSが接続されているピン番号   (-1 = disable)
      cfg.pin_rst = RST; // RSTが接続されているピン番号  (-1 = disable)
      cfg.pin_busy = -1; // BUSYが接続されているピン番号 (-1 = disable)

      // ※ 以下の設定値はパネル毎に一般的な初期値が設定さ BUSYが接続されているピン番号 (-1 = disable)れていますので、不明な項目はコメントアウトして試してみてください。

      cfg.memory_width = WIDTH;   // ドライバICがサポートしている最大の幅
      cfg.memory_height = HEIGHT;  // ドライバICがサポートしている最大の高さ
      cfg.panel_width = WIDTH;    // 実際に表示可能な幅
      cfg.panel_height = HEIGHT;   // 実際に表示可能な高さ
      cfg.offset_x = OFFSET_X;         // パネルのX方向オフセット量
      cfg.offset_y = OFFSET_Y;         // パネルのY方向オフセット量
      cfg.offset_rotation = 0;  // 值在旋转方向的偏移0~7（4~7是倒置的）
      cfg.dummy_read_pixel = 8; // 在读取像素之前读取的虚拟位数
      cfg.dummy_read_bits = 1;  // 读取像素以外的数据之前的虚拟读取位数
      cfg.readable = false;     // 如果可以读取数据，则设置为 true
      cfg.invert = true;        // 如果面板的明暗反转，则设置为 true
      cfg.rgb_order = RGB_ORDER;    // 如果面板的红色和蓝色被交换，则设置为 true
      cfg.dlen_16bit = false;   // 对于以 16 位单位发送数据长度的面板，设置为 true
      cfg.bus_shared = false;   // 如果总线与 SD 卡共享，则设置为 true（使用 drawJpgFile 等执行总线控制）

      _panel_instance.config(cfg);
    }

    {                                      // Set backlight control. (delete if not necessary)
      auto cfg = _light_instance.config(); // Get the structure for backlight configuration.

      cfg.pin_bl = BL;     // pin number to which the backlight is connected
      cfg.invert = false;  // true to invert backlight brightness
      cfg.freq = 44100;    // backlight PWM frequency
      cfg.pwm_channel = 1; // PWM channel number to use

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); // Sets the backlight to the panel.
    }

    setPanel(&_panel_instance); // 使用するパネルをセットします。
                                //    { // バックライト制御の設定を行います。(必要なければ削除）
                                //    auto cfg = _light_instance.config();// バックライト設定用の構造体を取得します。
                                //    cfg.pin_bl = 8;             // バックライトが接続されているピン番号 BL
                                //    cfg.invert = false;          // バックライトの輝度を反転させる場合 true
                                //    cfg.freq   = 44100;          // バックライトのPWM周波数
                                //    cfg.pwm_channel = 7;         // 使用するPWMのチャンネル番号
                                //    _light_instance.config(cfg);
                                //    _panel_instance.setLight(&_light_instance);//バックライトをパネルにセットします。
                                //    }
  }
};

LGFX tft;
CST816D touch(I2C_SDA, I2C_SCL, TP_RST, TP_INT);
// ChronosESP32 watch("Chronos C3");
// Preferences prefs;

static const uint32_t screenWidth = WIDTH;
static const uint32_t screenHeight = HEIGHT;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][screenWidth * buf_size];
lv_obj_t *lastActScr;

bool circular = false;
bool alertSwitch = false;
bool gameActive = false;


void hal_setup(void);
void hal_loop(void);

TaskHandle_t sensorTask;
// void update_faces();
// void updateQrLinks();


void logMemoryUsage() {
  Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
}


/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  if (tft.getStartCount() == 0)
  {
    tft.endWrite();
  }

  tft.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::swap565_t *)&color_p->full);
  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

void adjustSensorInterval() {
  if (millis() - lastActivityTime > inactivityThreshold) {
    sensorInterval = 3000UL; // Increase interval to 1 minute during inactivity
  } else {
    sensorInterval = 1000UL; // Reset to default interval during activity 2s
  }
}

unsigned long int getNtpTime()
{
  IPAddress ntpServerIP; // NTP server's ip address

  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  // Serial.println("Transmit NTP Request");
  // get a random server from the pool
  WiFi.hostByName("id.pool.ntp.org", ntpServerIP);
  // Serial.print(ntpServerName);
  // Serial.print(": ");
  // Serial.println(ntpServerIP);
  // sendNTPpacket(ntpServerIP);

  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(ntpServerIP, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();

  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      // Serial.println("Receive NTP Response");
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + 7 * 3600UL;
    }
  }
  Serial.println("No NTP Response :-(");
  return 0; // return 0 if unable to get the time
}

// // send an NTP request to the time server at the given address
// void sendNTPpacket(IPAddress &address)
// {
//   // set all bytes in the buffer to 0
//   memset(packetBuffer, 0, NTP_PACKET_SIZE);
//   // Initialize values needed to form NTP request
//   // (see URL above for details on the packets)
//   packetBuffer[0] = 0b11100011;   // LI, Version, Mode
//   packetBuffer[1] = 0;     // Stratum, or type of clock
//   packetBuffer[2] = 6;     // Polling Interval
//   packetBuffer[3] = 0xEC;  // Peer Clock Precision
//   // 8 bytes of zero for Root Delay & Root Dispersion
//   packetBuffer[12] = 49;
//   packetBuffer[13] = 0x4E;
//   packetBuffer[14] = 49;
//   packetBuffer[15] = 52;
//   // all NTP fields have been given values, now
//   // you can send a packet requesting a timestamp:
//   Udp.beginPacket(address, 123); //NTP requests are to port 123
//   Udp.write(packetBuffer, NTP_PACKET_SIZE);
//   Udp.endPacket();
// }
/*Read the touchpad*/
bool turnScreenOn =  false;

void IRAM_ATTR isr() {
  turnScreenOn = 1;
}


void turnOn(){
  if(!turnScreenOn){
    timerLast  = timerNow;
    // tft.setBrightness(br);
    turnScreenOn =  1;
    Serial.println("screen is ON");
    // tft.powerSaveOff();
    tft.setBrightness(90);
    }
    lastActivityTime = millis();
  }

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{

  bool touched;
  uint8_t gesture;
  uint16_t touchX, touchY;


    touched = touch.getTouch(&touchX, &touchY, &gesture);


  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
                     /*Restart the timer where lv_tick_inc() is called*/
lv_task_handler();
    // turnScreenOn =  true;
    turnOn();
}
}
void dataCallback(uint8_t *data, int length)
{
  // Serial.println("Received Data");
  // for (int i = 0; i < length; i++)
  // {
  //   Serial.printf("%02X ", data[i]);
  // }
  // Serial.println();
}

// void logCallback(Level level, unsigned long time, String message)
// {
//   Serial.print(message);
// }
void syncRTC(){
    // int hours, minutes, seconds;
    if(WiFi.status() == WL_CONNECTED){
    Serial.println("syncing time");
    unsigned long int t = getNtpTime();
    // unsigned long int seconds_since_midnight = t % (24 * 3600);
    // H = seconds_since_midnight / 3600;
    // M = (seconds_since_midnight % 3600) / 60;
    // S = seconds_since_midnight % 60;
    if(t > 0 ) rtc.setTime(t);  // 17th Jan 2021 15:24:30
    else Serial.println("RTC NTP FAILED");
    Serial.printf("%d %d %d %d\n", rtc.getHour(), rtc.getMinute(), rtc.getSecond(), rtc.getDay());

    // rtc.setHour(byte(H), byte(M), byte(S));
    }
    else{
      Serial.println("Wifi not connected :( ");
    }
    }


void heartRateLoop()  {
    particleSensor.wakeUp();
    particleSensor.setup(60, 4, 2, 50, 215, 4096); //Configure sensor with default settings
  // particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
    Serial.printf("Heart rate Loop\n");
    bufferLength = 50; //buffer length of 100 stores 4 seconds of samples running at 25sps
    for(int i = 0;  i < 50; i++){ //Check the sensor for new data
    // particleSensor.setPulseAmplitudeRed(0x64); //Turn Red LED to low to indicate sensor is running
    particleSensor.check();
    // Serial.print(".");
    // particleSensor.setPulseAmplitudeRed(80); //Turn Red LED to low to indicate sensor is running
    // particleSensor.setPulseAmplitudeIR(80); //Turn Red LED to low to indicate sensor is running

    redBuffer[i] = particleSensor.getRed();
    irBuffer[i] = particleSensor.getIR();
    // particleSensor.setPulseAmplitudeRed(0); //Turn Red LED to low to indicate sensor is running

    particleSensor.nextSample(); //We're finished with this sample so move to next sample
    // Serial.print(i);
    // Serial.print(F(" red="));
    // Serial.print(redBuffer[i], DEC);
    // Serial.print(F(", ir="));
    // Serial.println(irBuffer[i], DEC);
    vTaskDelay(1);
    // delay(2);
    particleSensor.setPulseAmplitudeRed(0); //Turn Red LED to low to indicate sensor is running
    particleSensor.setPulseAmplitudeIR(0); //Turn Red LED to low to indicate sensor is running

    }
  //  long irValue = particleSensor.getIR();

        // particleSensor.beat);
//   //calculate heart rate and SpO2 after first 100 samples (first 4 seconds of samples)
    maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);


    SPO = validSPO2 ? spo2 : 0;
    BPM = validHeartRate ? heartRate : 0;

    Serial.printf("\nBPM:%d:%s SPO2:%d:%s Temp:%d", BPM,  validHeartRate ? "valid" : "invalid", SPO, validSPO2 ? "valid" : "invalid \n", particleSensor.readTemperature());
    // Serial.println("4 seconds interval");
    // particleSensor.setPulseAmplitudeRed(0); //Turn Red LED to low to indicate sensor is running
    particleSensor.setPulseAmplitudeRed(0); //Turn Red LED to low to indicate sensor is running
    particleSensor.setPulseAmplitudeIR(0); //Turn Red LED to low to indicate sensor is running

    particleSensor.shutDown();
  }


void my_log_cb(const char *buf)
{
  Serial.write(buf, strlen(buf));
}
// void hal_setup(){
//   Serial.begin(115200);
//   pinMode(5, INPUT);
// }

// void hal_loop(){
//   Serial.println(digitalRead(5));
// }

void monitorBatteryLevel() {
  batteryVoltage = 3.3 / (1 << 12) * 3 * analogRead(1);
  lv_bar_set_value(ui_batteryBar, batteryVoltage, LV_ANIM_ON);
  Serial.printf("%d Battery voltage: %.2f\n",analogRead(1),   batteryVoltage);

  if (batteryVoltage < 3.5 || !isStart) { // Example threshold for low battery
    sensorInterval = 10000UL; // Increase interval to 10 seconds
  } else {
    sensorInterval = 2000UL; // Reset to default interval
  }
}


void sensorLoop(void* pvParameters){
  Serial.print("Task on core :");
  Serial.println(xPortGetCoreID());
  unsigned long curTime, lastTimeSensor, lastTimeTick;
  for(;;){
    curTime = millis();
  //   if(turnScreenOn){
  //   turnOn();
  //   screenOn =  1;
  //   turnScreenOn =  0;
  // }
    if(curTime - lastTimeSensor >= sensorInterval && batteryVoltage > 3.6){
    heartRateLoop();
    adjustSensorInterval();
    if(SPO !=  0) lv_label_set_text(ui_spoLabel, String(SPO).c_str());
    if(BPM != 0)  lv_label_set_text(ui_bpmLabel, String(BPM).c_str());
    // delay(sensorInterval);
    lastTimeSensor = curTime;
    }
  //   if((curTime - lastTimeTick >= 1000UL)){

  //   lastTimeTick = curTime;
  // //  logMemoryUsage();
  //   }

  }
}

void hal_setup()
{
  // ESP_RST_TASK_WDT
  // esp_task_wdt_init(5, true); // 5 seconds timeout
  // esp_task_wdt_add(NULL); // Add current task to the watchdog timer
  Serial.begin(115200); /* prepare for possible serial debug */
  // pinMode(5, INPUT_PULLUP);
  // esp_sleep_
  // esp_sleep_enable_ext0_wakeup(GPIO_NUM_5, 0);
  
  attachInterrupt(5, isr, FALLING);
  // gpio_wakeup_enable(GPIO_NUM_5, GPIO_INTR_LOW_LEVEL);
  // esp_sleep_enable_gpio_wakeup();
  // esp_sleep_enable_timer_wakeup(1000000UL);
  // delay(500);

  // gpio_wake
  tft.init();
  tft.initDMA();
  tft.startWrite();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(3);
  // tft.drawString("tes", 10, 10);
  delay(500);
  tft.clear();
  touch.begin();
  lv_init();
    // lv_disp_set_rotation(lv_disp_get_default(), LV_DISP_ROT_90);
  // delay(1000);
  // tft.setRotation(40);

  lv_disp_draw_buf_init(&draw_buf, buf[0], buf[1], screenWidth * buf_size);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
  lv_log_register_print_cb(my_log_cb);
  ui_init();
  // br = tft.getBrightness();
  lv_bar_set_range(ui_batteryBar, 3, 4.2);
  // Serial.println(tft.getBrightness());
  tft.setBrightness(90);
  // tft.print("Connect To Wifi\nSSID : Goweser\nPw : Goweser123");
  tft.setTextSize(2);
  tft.drawString("SSID:Goweser", 30, 100);
  tft.drawString("PW:Goweser123", 30, 150);
  // Serial.println(tft.getBrightness());
  // lv_disp_load_scr(ui_Screen2);
  // Serial.println(lv_disp_get_scr_act(NULL));
  if (!particleSensor.begin(Wire1, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("INIT FAILED ");
    lv_label_set_text(ui_wifiIndicator, "X");
  }
  particleSensor.setup(60, 4, 2, 50, 215, 4096); //Configure sensor with default settings
  // particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  // particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
  xTaskCreatePinnedToCore(sensorLoop, "SensorTask", 10000, NULL, 1, &sensorTask, 1);
  
  // xTaskCreatePinnedToCore(tickerLoop, "tickerTask", 10000, NULL, 1, &tickerTask, 1);


  initwifi();
  tft.clear();
  syncRTC();
  // lv_disp_set_rotation(NULL,  LV_DISP_ROT_90);
  lv_label_set_text_fmt(ui_uiclock, "%02d%c%02d", rtc.getHour(1), (rtc.getSecond() % 2) ? ':' : '.', rtc.getMinute());
  lv_disp_load_scr(ui_Screen1);

  Firebase.printf("Firebase Client v%s\n", FIREBASE_CLIENT_VERSION);
  ssl.setInsecure();
  initializeApp(client, app, getAuth(noAuth));
  // Binding the authentication handler with your Database class object.
  app.getApp<RealtimeDatabase>(Database);
  // Set your database URL
  Database.url(DATABASE_URL);
  // In sync functions, we have to set the operating result for the client that works with the function.
  client.setAsyncResult(result);
  //////////////////////////////////////////////
  Distance =  Database.get<float>(client, "/Distance");
  isStart = Database.get<bool>(client, "/App_on");
  tft.setRotation(3);

}
int rot;
void hal_looop(){
  rtc.getDate();
  tft.drawString(String(rot).c_str(), 30 , 100);
  tft.setRotation(rot);
  Serial.println(rot);
  rot+=1;
  // Serial.println(digitalRead(5) ? "HIGH" : "LOW");
  // Serial.println(touch.getTouch(120, 120, 0))
  delay(1000);
  tft.clear();

}
unsigned long ltimer1, ltimer2, ltimer3;
void hal_loop()
{ 
  lv_timer_handler_run_in_period(10);
  if(turnScreenOn ){
    turnOn();
    screenOn =  1;
    turnScreenOn =  0;
  }

  // lv_timer_handler();
  timerNow = millis();
  if(timerNow - ltimer1 >= 1000UL){

    // monitorBatteryLevel();
    if(screenOn){
    Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));   // (String) returns time with specified format 
    monitorBatteryLevel();
    lv_label_set_text_fmt(ui_uiclock, "%02d%c%02d", rtc.getHour(1), (rtc.getSecond() % 2) ? ':' : '.', rtc.getMinute());
    Serial.printf( "%02d%c%02d\n", rtc.getHour(1), (rtc.getSecond() % 2) ? ':' : '.', rtc.getMinute());
    }
    // if(!isStart){
    //   isStart = Database.get<bool>(client, "/isStart");
    //   Serial.println(isStart ? "Started" : "not started");
    // }
    ltimer1  = timerNow;
  }
if(timerNow - ltimer3 >= 4000UL){
  // Serial.printf("%S\n", WiFi.setSleep(0) ? "on" : "on Failed");
  if(batteryVoltage > 3.6){
  initwifi();
  if(isStart){
   Database.set<int>(client, "/bpm", BPM);
   Database.set<int>(client, "/spo", SPO);
   Distance =  Database.get<float>(client, "/Distance");
  lv_label_set_text(ui_distanceLabel, String(Distance).c_str());
   Serial.println("is started");
  }
  if(!particleSensor.begin(Wire1, I2C_SPEED_FAST))Serial.println("Sensor  didnt found, check  wiring");
  Serial.println("4 seconds interval");
  isStart = Database.get<bool>(client, "/App_on");

  logMemoryUsage();
  Serial.println(isStart ? "Started" : "not started");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  // Serial.printf("%S\n", WiFi.setSleep(1) ? "sleep" : "sleep Failed");
  }
  lv_label_set_text(ui_wifiIndicator, String(batteryVoltage).c_str());

  // if(isStart)lv_label_set_text(ui_wifiIndicator, "o");
  // else  if(batteryVoltage < 3.6)     lv_label_set_text(ui_wifiIndicator, "---");
  // else lv_label_set_text(ui_wifiIndicator, "x");
  ltimer3 = timerNow;
}


if(timerNow - ltimer2 >=  30000UL){
  tft.setBrightness(0);
  turnScreenOn = 0;
  // Serial.printf("%S\n", WiFi.setSleep(0) ? "on" : "on Failed");
  initwifi();
  syncRTC();
  logMemoryUsage();
  Serial.println("30 seconds interval");
  // Ensure tasks are completed before entering sleep
  // Serial.printf("%S\n", WiFi.setSleep(1) ? "sleep" : "sleep Failed");
  // Serial.println("  will this be printed?");
  // ESP.restart();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  ltimer2 =  timerNow;


}
  
  if(timerNow - timerLast >= 7000UL && screenOn){
    tft.setBrightness(0);
    logMemoryUsage();
    Serial.println("Screen is  OFF");
    turnScreenOn = 0;
    screenOn = 0;
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    // WiFi.disconnect(1);
    // WiFi.setSleep(1);
  } 
}
