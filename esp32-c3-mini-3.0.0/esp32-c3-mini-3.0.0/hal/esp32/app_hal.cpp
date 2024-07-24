/*
   MIT License

  Copyright (c) 2023 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ______________  _____
  ___  __/___  /_ ___(_)_____ _______ _______
  __  /_  __  __ \__  / _  _ \__  __ `/_  __ \
  _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
  /_/     /_.___/ /_/   \___/ _\__, /  \____/
                              /____/

*/

#include <WiFi.h>
#include <FirebaseClient.h>
#include <WiFiClientSecure.h>
#include <AsyncTCP.h>

#define WIFI_SSID "goweser"
#define WIFI_PASSWORD "12345678"

#define DATABASE_URL "https://savergowes-default-rtdb.asia-southeast1.firebasedatabase.app/"
String name;
WiFiClientSecure ssl;
DefaultNetwork network;
AsyncClientClass client(ssl, getNetwork(network));

FirebaseApp app;
RealtimeDatabase Database;
AsyncResult result;
NoAuth noAuth;

// Variable to save current epoch time
unsigned long epochTime; 



#define LGFX_USE_V1
#include "Arduino.h"
#include <LovyanGFX.hpp>
#include "CST816D.h"
#include <ESP32Time.h>
#include <NimBLEDevice.h>
#include <ChronosESP32.h>
#include <Timber.h>
#include <Preferences.h>
#include "app_hal.h"


// #include "DFRobot_BloodOxygen_S.h"
// DFRobot_BloodOxygen_S_I2C MAX30102(&Wire1 ,0x57);

#include <Wire.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"
#include "heartRate.h"

MAX30105 particleSensor;
uint32_t irBuffer[50]; //infrared LED sensor data
uint32_t redBuffer[50];  //red LED sensor data
int32_t bufferLength; //data length
int32_t spo2; //SPO2 value
int8_t validSPO2; //indicator to show if the SPO2 calculation is valid
int32_t heartRate; //heart rate value
int8_t validHeartRate; //indicator to show if the heart 



const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
char isLead;
int irValue;
float beatsPerMinute;
int beatAvg;
float Distance;


int kcal, bpm, oxygen, steps;
unsigned long curTime, lTime;
int32_t sample[20];


#include <SPI.h>


#include <lvgl.h>
#include "ui/ui.h"

#include "main.h"

#define buf_size 10


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

void dbCall(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println(WiFi.getSleep());
  
  WiFi.setSleep(false);
  WiFi.reconnect();
  Distance =  Database.get<float>(client, "/Distance");
  Database.set<int>(client, "/bpm",bpm);
  Database.set<int>(client, "/spo", oxygen);
  WiFi.setSleep(true);

  
}
void initwifi() {
  // String wifiText = "ini wifii 12345678     ";
  Serial.printf("this task running on core %d\n", xPortGetCoreID());
  // WiFi.reconnect();

  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int index = 0;
  tft.setFont(&fonts::Font4);
  tft.drawString("SSID:goweser", 20, 50);
  tft.drawString("pw:12345678", 20, 100);

  while (WiFi.status() != WL_CONNECTED) {
  Serial.print("."); delay(500);
  }
  tft.clear();

  Serial.print(WiFi.localIP());


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
  dbCall();
  // useIRsensor = Database.get<bool>(client, "/useIRsensor");
  // debug = Database.get<bool>(client, "/Debug");
  // Distance =  Database.get<float>(client, "/Distance");
  // Serial.printf("distance is %d\n", Distance);

}



CST816D touch(I2C_SDA, I2C_SCL, TP_RST, TP_INT);
ChronosESP32 watch("Chronos C3");
Preferences prefs;

static const uint32_t screenWidth = WIDTH;
static const uint32_t screenHeight = HEIGHT;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][screenWidth * buf_size];

bool weatherUpdate = true, notificationsUpdate = true;



ChronosTimer screenTimer;
ChronosTimer alertTimer;
ChronosTimer searchTimer;

lv_obj_t *lastActScr;

bool circular = false;
bool alertSwitch = false;
bool gameActive = false;

TaskHandle_t gameHandle = NULL;

void showAlert();
bool isDay();
void setTimeout(int i);

void hal_setup(void);
void hal_loop(void);

void update_faces();
void updateQrLinks();

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

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{

  bool touched;
  uint8_t gesture;
  uint16_t touchX, touchY;
  RemoteTouch rt = watch.getTouch(); // remote touch
  if (rt.state)
  {
    // use remote touch when active
    touched = rt.state;
    touchX = rt.x;
    touchY = rt.y;
  }
  else
  {
    touched = touch.getTouch(&touchX, &touchY, &gesture);
  }

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
    screenTimer.time = millis();
    screenTimer.active = true;
  }
}

void connectionCallback(bool state)
{
  Timber.d("Connection change");
  if (state)
  {
    lv_obj_clear_state(ui_btStateButton, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_add_state(ui_btStateButton, LV_STATE_CHECKED);
  }
  lv_label_set_text_fmt(ui_appConnectionText, "Status\n%s", state ? "#19f736 Connected#" : "#f73619 Disconnected#");
}

void ringerCallback(String caller, bool state)
{
  lv_disp_t *display = lv_disp_get_default();
  lv_obj_t *actScr = lv_disp_get_scr_act(display);

  if (state)
  {
    screenTimer.time = millis() + 50;

    lastActScr = actScr;
    Serial.print("Ringer: Incoming call from ");
    Serial.println(caller);
    lv_label_set_text(ui_callName, caller.c_str());
    lv_scr_load_anim(ui_callScreen, LV_SCR_LOAD_ANIM_FADE_IN, 500, 0, false);
  }
  else
  {
    Serial.println("Ringer dismissed");
    // load last active screen
    if (actScr == ui_callScreen && lastActScr != nullptr)
    {
      lv_scr_load_anim(lastActScr, LV_SCR_LOAD_ANIM_FADE_OUT, 500, 0, false);
    }
  }
  screenTimer.active = true;
}

void notificationCallback(Notification notification)
{
  Timber.d("Notification Received from " + notification.app + " at " + notification.time);
  Timber.d(notification.message);
  notificationsUpdate = true;
  // onNotificationsOpen(click);
  showAlert();
}

void configCallback(Config config, uint32_t a, uint32_t b)
{
  switch (config)
  {
  case CF_WEATHER:

    if (a)
    {
      lv_label_set_text_fmt(ui_weatherTemp, "%d°C", watch.getWeatherAt(0).temp);
      // set icon ui_weatherIcon
      setWeatherIcon(ui_weatherIcon, watch.getWeatherAt(0).icon, isDay());
    }
    if (a == 2)
    {
      weatherUpdate = true;
    }

    break;
  case CF_FONT:
    screenTimer.time = millis();
    screenTimer.active = true;
    if (((b >> 16) & 0xFFFF) == 0x01)
    { // Style 1
      if ((b & 0xFFFF) == 0x01)
      { // TOP
        lv_obj_set_style_text_color(ui_hourLabel, lv_color_hex(a), LV_PART_MAIN | LV_STATE_DEFAULT);
      }
      if ((b & 0xFFFF) == 0x02)
      { // CENTER
        lv_obj_set_style_text_color(ui_minuteLabel, lv_color_hex(a), LV_PART_MAIN | LV_STATE_DEFAULT);
      }
      if ((b & 0xFFFF) == 0x03)
      { // BOTTOM
        lv_obj_set_style_text_color(ui_dayLabel, lv_color_hex(a), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_dateLabel, lv_color_hex(a), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_weatherTemp, lv_color_hex(a), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_amPmLabel, lv_color_hex(a), LV_PART_MAIN | LV_STATE_DEFAULT);
      }
    }

    break;
  case CF_CAMERA:
  {
    lv_disp_t *display = lv_disp_get_default();
    lv_obj_t *actScr = lv_disp_get_scr_act(display);

    if (b)
    {
      screenTimer.time = millis() + 50;
      lastActScr = actScr;
      lv_scr_load_anim(ui_cameraScreen, LV_SCR_LOAD_ANIM_FADE_IN, 500, 0, false);
      screenTimer.active = true;
    }
    else
    {
      if (actScr == ui_cameraScreen && lastActScr != nullptr)
      {
        lv_scr_load_anim(lastActScr, LV_SCR_LOAD_ANIM_FADE_OUT, 500, 0, false);
      }
      screenTimer.active = true;
    }
  }
  break;

  case CF_APP:
    // state is saved internally
    Serial.print("Chronos App; Code: ");
    Serial.print(a); // int code = watch.getAppCode();
    Serial.print(" Version: ");
    Serial.println(watch.getAppVersion());
    lv_label_set_text_fmt(ui_appDetailsText, "Chronos app\nv%s (%d)", watch.getAppVersion().c_str(), a);
    break;
  case CF_QR:
    if (a == 1){
      updateQrLinks();
    }
    break;
  }
}

void onMessageClick(lv_event_t *e)
{

  lv_disp_t *display = lv_disp_get_default();
  lv_obj_t *actScr = lv_disp_get_scr_act(display);
  if (actScr != ui_notificationScreen)
  {
    Timber.i("Message screen inactive");
    return;
  }
  // Your code here
  int index = (int)lv_event_get_user_data(e);

  index %= NOTIF_SIZE;
  Timber.i("Message clicked at index %d", index);

  lv_label_set_text(ui_messageTime, watch.getNotificationAt(index).time.c_str());
  lv_label_set_text(ui_messageContent, watch.getNotificationAt(index).message.c_str());
  setNotificationIcon(ui_messageIcon, watch.getNotificationAt(index).icon);

  lv_obj_scroll_to_y(ui_messagePanel, 0, LV_ANIM_ON);
  lv_obj_add_flag(ui_messageList, LV_OBJ_FLAG_HIDDEN);
  lv_obj_clear_flag(ui_messagePanel, LV_OBJ_FLAG_HIDDEN);
}

void onCaptureClick(lv_event_t *e)
{
  watch.capturePhoto();
}

void onForecastOpen(lv_event_t *e)
{
  lv_obj_scroll_to_y(ui_forecastPanel, 0, LV_ANIM_ON);
}

void onScrollMode(lv_event_t *e)
{
  prefs.putBool("circular", circular);
}

void onAlertState(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  alertSwitch = lv_obj_has_state(obj, LV_STATE_CHECKED);

  prefs.putBool("alerts", alertSwitch);
}

void onNotificationsOpen(lv_event_t *e)
{
  if (!notificationsUpdate)
  {
    return;
  }
  notificationsUpdate = false;

  lv_obj_clean(ui_messageList);
  int c = watch.getNotificationCount();
  for (int i = 0; i < c; i++)
  {
    addNotificationList(watch.getNotificationAt(i).icon, watch.getNotificationAt(i).message.c_str(), i);
  }
  // addNotificationList(watch.getNotificationAt(0).icon, watch.getNotificationAt(0).message.c_str(), i);

  lv_obj_scroll_to_y(ui_messageList, 1, LV_ANIM_ON);
  lv_obj_clear_flag(ui_messageList, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(ui_messagePanel, LV_OBJ_FLAG_HIDDEN);
}

void onWeatherLoad(lv_event_t *e)
{

  if (!weatherUpdate)
  {
    return;
  }
  weatherUpdate = false;

  // if (isDay())
  // {
  //   lv_obj_set_style_bg_img_src(ui_weatherScreen, &ui_img_857483832, LV_PART_MAIN | LV_STATE_DEFAULT);
  // }
  // else
  // {
  //   lv_obj_set_style_bg_img_src(ui_weatherScreen, &ui_img_753022056, LV_PART_MAIN | LV_STATE_DEFAULT);
  // }
  lv_obj_clear_flag(ui_weatherPanel, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(ui_forecastPanel, LV_OBJ_FLAG_HIDDEN);
  if (watch.getWeatherCount() > 0)
  {
    String updateTime = "Updated at\n" + watch.getWeatherTime();
    lv_label_set_text(ui_weatherCity, watch.getWeatherCity().c_str());
    lv_label_set_text(ui_weatherUpdateTime, updateTime.c_str());
    lv_label_set_text_fmt(ui_weatherCurrentTemp, "%d°C", watch.getWeatherAt(0).temp);
    setWeatherIcon(ui_weatherIcon, watch.getWeatherAt(0).icon, isDay());

    lv_obj_clean(ui_forecastList);
    int c = watch.getWeatherCount();
    for (int i = 0; i < c; i++)
    {
      addForecast(watch.getWeatherAt(i).day, watch.getWeatherAt(i).temp, watch.getWeatherAt(i).icon);
    }
  }
}

void onLoadHome(lv_event_t *e)
{
  // if (isDay())
  // {
  //   lv_obj_set_style_bg_img_src( ui_clockScreen, &ui_img_857483832, LV_PART_MAIN | LV_STATE_DEFAULT);
  // }
  // else
  // {
  //   lv_obj_set_style_bg_img_src( ui_clockScreen, &ui_img_753022056, LV_PART_MAIN | LV_STATE_DEFAULT);
  // }
}

void onBrightnessChange(lv_event_t *e)
{
  // Your code here
  lv_obj_t *slider = lv_event_get_target(e);
  int v = lv_slider_get_value(slider);
  tft.setBrightness(v);

  prefs.putInt("brightness", v);
}

void onFaceSelected(lv_event_t *e)
{
  int index = (int)lv_event_get_user_data(e);
  prefs.putInt("watchface", index);
}

void onBatteryChange(lv_event_t *e)
{
  uint8_t lvl = lv_slider_get_value(ui_batterySlider);
  watch.setBattery(lvl);
}

void onStartSearch(lv_event_t *e)
{
  watch.findPhone(true);
}

void onEndSearch(lv_event_t *e)
{
  watch.findPhone(false);
}

void onClickAlert(lv_event_t *e)
{

  // cancel alert timer
  alertTimer.active = false;
  // change screen to notifications
  lv_disp_load_scr(ui_notificationScreen);

  // enable screen for timeout + 5 seconds
  screenTimer.time = millis() + 5000;
  screenTimer.active = true;

  // load the last received message
  lv_label_set_text(ui_messageTime, watch.getNotificationAt(0).time.c_str());
  lv_label_set_text(ui_messageContent, watch.getNotificationAt(0).message.c_str());
  setNotificationIcon(ui_messageIcon, watch.getNotificationAt(0).icon);

  lv_obj_scroll_to_y(ui_messagePanel, 0, LV_ANIM_ON);
  lv_obj_add_flag(ui_messageList, LV_OBJ_FLAG_HIDDEN);
  lv_obj_clear_flag(ui_messagePanel, LV_OBJ_FLAG_HIDDEN);
}

void onTimeoutChange(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_target(e);
  uint16_t sel = lv_dropdown_get_selected(obj);
  Timber.i("Selected index: %d", sel);

  setTimeout(sel);
  prefs.putInt("timeout", sel);
}

void setTimeout(int i)
{
  if (i == 4)
  {
    screenTimer.duration = -1; // always on
  }
  else if (i == 0)
  {
    screenTimer.duration = 5000; // 5 seconds
    screenTimer.active = true;
  }
  else if (i < 4)
  {
    screenTimer.duration = 10000 * i; // 10, 20, 30 seconds
    screenTimer.active = true;
  }
}

void onMusicPlay(lv_event_t *e)
{
  watch.musicControl(MUSIC_TOGGLE);
}

void onMusicPrevious(lv_event_t *e)
{
  watch.musicControl(MUSIC_PREVIOUS);
}

void onMusicNext(lv_event_t *e)
{
  watch.musicControl(MUSIC_NEXT);
}

void onVolumeUp(lv_event_t *e)
{
  watch.musicControl(VOLUME_UP);
}

void onVolumeDown(lv_event_t *e)
{
  watch.musicControl(VOLUME_DOWN);
}

void updateQrLinks()
{
  lv_obj_clean(ui_qrPanel);
  for (int i = 0; i < 9; i++)
  {
    addQrList(i, watch.getQrAt(i).c_str());
  }
}

void gameLoop(void *pvParameters)
{
  for (;;)
  {
    ui_games_update();
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void heartRateLoop(void *pvParameters)
{
  for (;;)
  {
  Serial.printf("this loop task running on core %d\n", xPortGetCoreID());

  curTime = millis();
  if(curTime -  lTime >= 3000UL){
    Serial.println("a");
    bufferLength = 50; //buffer length of 100 stores 4 seconds of samples running at 25sps
    for(int i = 0;  i < 50; i++){ //Check the sensor for new data
    redBuffer[i] = particleSensor.getRed();
    irBuffer[i] = particleSensor.getIR();
    particleSensor.nextSample(); //We're finished with this sample so move to next sample
    Serial.print(i);
    Serial.print(F(" red="));
    Serial.print(redBuffer[i], DEC);
    Serial.print(F(", ir="));
    Serial.println(irBuffer[i], DEC);
    }
  //  long irValue = particleSensor.getIR();

        // particleSensor.beat);
//   //calculate heart rate and SpO2 after first 100 samples (first 4 seconds of samples)
    maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);


    oxygen = validSPO2 ? spo2 : 01;
    bpm = validHeartRate ? heartRate : 01;
    // steps = validHeartRate ? heartRate : 0;
    kcal = oxygen;
  // kcal = int(particleSensor.readTemperature());
    // steps = i;
    steps =  particleSensor.readTemperature();
    // Database.set<int>(client, "/bpm",bpm);
    // Database.set<int>(client, "/spo", oxygen);


    Serial.printf("BPM:%d:%s SPO2:%d:%s Temp:%d", bpm,  validHeartRate ? "valid" : "invalid", oxygen, validSPO2 ? "valid" : "invalid \n", steps);
    Serial.println("4 seconds interval");
    lTime = curTime;
  }
  }
}

void onGameOpened()
{
  gameActive = true;

  if (gameHandle == NULL)
  {
    // create task to run the game loop
    xTaskCreate(gameLoop, "Game Task", 8192, NULL, 1, &gameHandle);
  }
}

void onGameClosed()
{
  gameActive = false;

  if (gameHandle != NULL)
  {
    vTaskDelete(gameHandle);
    gameHandle = NULL;
  }
}

void showAlert()
{
  lv_disp_t *display = lv_disp_get_default();
  lv_obj_t *actScr = lv_disp_get_scr_act(display);
  if (actScr == ui_notificationScreen)
  {
    // at notifications screen, switch to message
    // enable screen for timeout + 5 seconds
    screenTimer.time = millis() + 5000;
    screenTimer.active = true;

    // load the last received message
    lv_label_set_text(ui_messageTime, watch.getNotificationAt(0).time.c_str());
    lv_label_set_text(ui_messageContent, watch.getNotificationAt(0).message.c_str());
    setNotificationIcon(ui_messageIcon, watch.getNotificationAt(0).icon);

    lv_obj_scroll_to_y(ui_messagePanel, 0, LV_ANIM_ON);
    lv_obj_add_flag(ui_messageList, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_messagePanel, LV_OBJ_FLAG_HIDDEN);
  }
  else
  {
    if (!alertSwitch)
    {
      return;
    }
    // attach the alert panel to current screen
    lv_obj_set_parent(ui_alertPanel, actScr);

    // load the last received message
    lv_label_set_text(ui_alertText, watch.getNotificationAt(0).message.c_str());
    setNotificationIcon(ui_alertIcon, watch.getNotificationAt(0).icon);

    // turn screen for timeout + 5 seconds
    screenTimer.time = millis() + 5000;
    screenTimer.active = true;

    alertTimer.time = millis();
    alertTimer.active = true;

    // show the alert
    lv_obj_clear_flag(ui_alertPanel, LV_OBJ_FLAG_HIDDEN);
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

void logCallback(Level level, unsigned long time, String message)
{
  Serial.print(message);
}

void my_log_cb(const char *buf)
{
  Serial.write(buf, strlen(buf));
}
long unblockedValue;
TaskHandle_t Task2;


void hal_setup()
{

  Serial.begin(115200); /* prepare for possible serial debug */
  tft.init();
  tft.initDMA();
  tft.startWrite();
  tft.fillScreen(TFT_BLACK);
  // particleSensor.heartrateAndOxygenSaturation(/**SPO2=*/&SPO2, /**SPO2Valid=*/&SPO2Valid, /**heartRate=*/&heartRate, /**heartRateValid=*/&heartRateValid);
 initwifi();
 touch.begin();

  lv_init();

 byte ledBrightness = 200; //Options: 0=Off to 255=50mA
  byte sampleAverage = 4; //Options: 1, 2, 4, 8, 16, 32
  byte ledMode = 2; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
  byte sampleRate = 50; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
  int pulseWidth = 411; //Options: 69, 118, 215, 411
  int adcRange = 4096; //Options: 2048, 4096, 8192, 16384

  Serial.println(particleSensor.begin(Wire1, I2C_SPEED_FAST) ? "success" : "failed" );
  particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Configure sensor with these settings
  particleSensor.enableDIETEMPRDY(); //Enable the temp ready interrupt. This is required.
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
  unblockedValue = 0;
  for (byte x = 0 ; x < 32 ; x++)
  {
    unblockedValue += particleSensor.getIR(); //Read the IR value
  }
  unblockedValue /= 32;
  Serial.printf("unblocked value is %d ", unblockedValue);
  Timber.setLogCallback(logCallback);

  Timber.i("Starting up device");

  prefs.begin("my-app");

  xTaskCreatePinnedToCore(
                    heartRateLoop,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    2,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */



  // memset(&bbi2c, 0, sizeof(bbi2c));
  // bbi2c.bWire = true; // use bit bang, not wire library
  // bbi2c.iSDA = 16;
  // bbi2c.iSCL = 15;
  // I2CInit(&bbi2c, 800000L);

  // useSensor = ps.begin(Wire1, I2C_SPEED_FAST) ? 1 : 0;
  // ps.setup(0xFF, 4, 2, 400, 411, 4096);



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

  int wf = prefs.getInt("watchface", 0);
  if (wf >= numFaces)
  {
    wf = 0; // default
  }
  ui_home = *faces[wf].watchface; // load saved watchface power on
  lv_disp_load_scr(ui_home);

  watch.setConnectionCallback(connectionCallback);
  watch.setNotificationCallback(notificationCallback);
  watch.setConfigurationCallback(configCallback);
  watch.setRingerCallback(ringerCallback);
  watch.setDataCallback(dataCallback);
  watch.begin();
  watch.set24Hour(true);
  watch.setBattery(85);

  String about = "v3.0 [fbiego]\nESP32 C3 Mini\n" + watch.getAddress();
  lv_label_set_text(ui_aboutText, about.c_str());

  // bool intro = prefs.getBool("intro", true);

  // if (intro)
  // {
  //   showAlert();
  //   prefs.putBool("intro", false);
  // }
  // else
  // {
  //   lv_obj_add_flag(ui_alertPanel, LV_OBJ_FLAG_HIDDEN);
  // }

  // load saved preferences
  int tm = prefs.getInt("timeout", 0);
  int br = prefs.getInt("brightness", 100);
  circular = prefs.getBool("circular", false);
  alertSwitch = prefs.getBool("alerts", false);

  lv_obj_scroll_to_y(ui_settingsList, 1, LV_ANIM_ON);
  lv_obj_scroll_to_y(ui_appList, 1, LV_ANIM_ON);
  lv_obj_scroll_to_y(ui_appInfoPanel, 1, LV_ANIM_ON);
  lv_obj_scroll_to_y(ui_gameList, 1, LV_ANIM_ON);

  if (tm > 4)
  {
    tm = 4;
  }
  else if (tm < 0)
  {
    tm = 0;
  }

  tft.setBrightness(br);

  lv_dropdown_set_selected(ui_timeoutSelect, tm);
  lv_slider_set_value(ui_brightnessSlider, br, LV_ANIM_OFF);
  if (circular)
  {
    lv_obj_add_state(ui_Switch2, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_clear_state(ui_Switch2, LV_STATE_CHECKED);
  }
  if (alertSwitch)
  {
    lv_obj_add_state(ui_alertStateSwitch, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_clear_state(ui_alertStateSwitch, LV_STATE_CHECKED);
  }

  screenTimer.active = true;
  screenTimer.time = millis();

  setTimeout(tm);

  Timber.i("Setup done");
  Timber.i(about);
}
unsigned long currentTime, lastTime;
void hal_loop()
{

  lv_timer_handler(); /* let the GUI do its work */
  currentTime = millis();
  if(currentTime - lastTime >= 3000UL){
    dbCall();
    // Distance = Database.get<float>(client, "/Distance");
    Serial.printf("Distance is %d\n", Distance);
    lastTime = currentTime;
  }
  if (gameActive)
  {
    // run only game in loop?
    // ui_games_update(); // not smooth, use separate task instead. see gameLoop()
  }
  else
  {
    // skip when game running
    delay(5);
    watch.loop();

    if (ui_home == ui_clockScreen && tft.getBrightness()!=0)
    {
      lv_label_set_text(ui_hourLabel, watch.getHourZ().c_str());
      lv_label_set_text(ui_dayLabel, watch.getTime("%A").c_str());
      lv_label_set_text(ui_minuteLabel, watch.getTime("%M").c_str());
      lv_label_set_text(ui_dateLabel, watch.getTime("%d\n%B").c_str());
      lv_label_set_text(ui_amPmLabel, watch.getAmPmC(false).c_str());
    }
    else
    {
      if(tft.getBrightness()!=0) update_faces();
    }

    lv_disp_t *display = lv_disp_get_default();
    lv_obj_t *actScr = lv_disp_get_scr_act(display);
    if (actScr != ui_home)
    {
    }

    if (actScr == ui_appInfoScreen)
    {
      lv_label_set_text_fmt(ui_appBatteryText, "Battery - %d%%", watch.getPhoneBattery());
      lv_bar_set_value(ui_appBatteryLevel, watch.getPhoneBattery(), LV_ANIM_OFF);
      if (watch.isPhoneCharging())
      {
        lv_img_set_src(ui_appBatteryIcon, &ui_img_battery_plugged_png);
      }
      else
      {
        lv_img_set_src(ui_appBatteryIcon, &ui_img_battery_state_png);
      }
    }

    if (alertTimer.active)
    {
      if (alertTimer.time + alertTimer.duration < millis())
      {
        alertTimer.active = false;
        lv_obj_add_flag(ui_alertPanel, LV_OBJ_FLAG_HIDDEN);
      }
    }

    if (screenTimer.active)
    {
      uint8_t lvl = lv_slider_get_value(ui_brightnessSlider);
      tft.setBrightness(lvl);

      if (screenTimer.duration < 0)
      {
        // Timber.w("Always On active");
        screenTimer.active = false;
      }
      else if (watch.isCameraReady())
      {
        screenTimer.active = false;
      }
      else if (screenTimer.time + screenTimer.duration < millis())
      {
        Timber.w("Screen timeout");
        screenTimer.active = false;
        tft.setBrightness(0);
        lv_disp_load_scr(ui_home);
      }
    }
  }
}

bool isDay()
{
  return watch.getHour(true) > 7 && watch.getHour(true) < 21;
}

void update_faces()
{



  // Serial.println("value is updated");
  int second = watch.getSecond();
  int minute = watch.getMinute();
  int hour = watch.getHourC();
  bool mode = watch.is24Hour();
  bool am = watch.getHour(true) < 12;
  int day = watch.getDay();
  int month = watch.getMonth() + 1;
  int year = watch.getYear();
  int weekday = watch.getDayofWeek();

  int temp = watch.getWeatherAt(0).temp;
  int icon = watch.getWeatherAt(0).icon;

  int battery = watch.getPhoneBattery();
  bool connection = watch.isConnected();

  int distance = random(10);

  // int bpm = random(20);
  // int oxygen = random(30);

  ui_update_watchfaces(second, minute, hour, mode, am, day, month, year, weekday,
                       temp, icon, battery, connection, steps, distance, kcal, bpm, oxygen);
}
