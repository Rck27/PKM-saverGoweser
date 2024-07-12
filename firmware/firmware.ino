/////////////////////////SUMMARY
/*
there's two sensor that can be used to read bpm, to choose which one to use,  useIRsensor variable is used, 1 for IR sensor, 0 for AD8232
there's also an option to choose where can we get the KM/H reading, useHallEffect variable is used, false for reading fromm app, 1 to read using hall effect
those 2 variables were able to be altered using firebase, and would be read once every boot, so to change it  you need to restart the device first
there's  also debug variable that can make the device spit out random number (also checked on boot)

*/


#define PINMonitor 21
#define LOM 20 //lead off Plus pin
#define LOP 10 //lead offf Min Pin (high when lead is disconected)
#define SDN 9

bool useHallEffect = false; // decide whether the KM/H is obtained from the  sensor or the app
bool useIRsensor = 1; //1 for ir sensor, 0 for ads2822
bool isSending  = 1; //1  for updating the value  to firebase.
bool debug = 0; char isDebug;
float Distance = 0;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x25,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display



#include <Arduino.h>
////////////////////////////////////////////// heart rate sensor
#include "MAX30105.h"

#include "heartRate.h"
#include "time.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
char isLead;
int irValue;
float beatsPerMinute;
int beatAvg;












/////////////////////////////////////////// wifi stuff here


#include <WiFi.h>
#include <FirebaseClient.h>
#include <WiFiClientSecure.h>
#include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <ElegantOTA.h>

#define WIFI_SSID "ini  wifii"
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

// Function that gets current epoch time
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    //Serial.println("Failed to obtain time");
    return(0);
  }
  time(&now);
  return now;
}

// AsyncWebServer server(80);


void printError(int code, const String &msg)
{
    Firebase.printf("Error, msg: %s, code: %d\n", msg.c_str(), code);
}

void initwifi() {
  String wifiText = "ini wifii 12345678     ";
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  lcd.setCursor(0,0);
  int index = 0;
  while (WiFi.status() != WL_CONNECTED) {
    lcd.clear();
    lcd.setCursor(0,0);
    for(int i = 0; i <9 ; i++){
      lcd.print((char)wifiText[i]);
      delay(100);
    }
    lcd.setCursor(0,1);
    for(int i = 9; i <19; i++){
      lcd.print((char)wifiText[i]);
      delay(100);
    }
    delay(1000);
  }
  lcd.clear();
  if(WiFi.status() != WL_CONNECTED){
    lcd.print("Wifi not found \n debug mode ON");
    delay(700);
    debug = 1;
  }
  WiFi.setSleep(false);
  Serial.print(WiFi.localIP());
  lcd.print(WiFi.localIP());
}


//////////////////////////////////////////

////////////////////////////////////////////
unsigned long waktu, waktuS, waktuT, waktuV;
int speedKmh, bpm, bpm2;
char s[20];

////////////////////////////////////////////

#define HALL_SENSOR_PIN 2  // Pin where the Hall effect sensor is connected

unsigned long pulseCount = 0;  // To store pulse count
unsigned long lastCalculationTime = 0;  // To track the last RPM calculation time
unsigned long lastPulseTime = 0;  // To track the last pulse time
bool lastSensorState = LOW;  // To track the last sensor state

const float tireDiameter = 0.7;  // Tire diameter in meters
const float tireCircumference = tireDiameter * PI;  // Calculate tire circumference
const unsigned long intervalMs = 1000;  // Interval for RPM calculation in milliseconds
// unsigned long ota_progress_millis = 0;


float readRPM() {
    unsigned long currentTime = millis();
    if (currentTime - lastCalculationTime >= intervalMs) {
        unsigned long pulses = pulseCount;  // Copy the pulse count
        pulseCount = 0;  // Reset pulse count

        lastCalculationTime = currentTime;  // Update last calculation time
        return (pulses * 60000.0) / intervalMs;  // Calculate RPM
    }
    return 0;  // Return 0 RPM if interval hasn't passed
}

float calculateSpeed(float rpm) {
    return (rpm * tireCircumference * 3.6) / 60.0;  // Convert RPM to KM/H
}


// void onOTAStart() {
//   // Log when OTA has started
//   Serial.println("OTA update started!");
//   // <Add your own code here>
// }

// void onOTAProgress(size_t current, size_t final) {
//   // Log every 1 second
//   if (millis() - ota_progress_millis > 1000) {
//     ota_progress_millis = millis();
//     Serial.printf("OTA Progress Current: %u bytes, Final: %u bytes\n", current, final);
//   }
// }

// void onOTAEnd(bool success) {
//   // Log when OTA has finished
//   if (success) {
//     Serial.println("OTA update finished successfully!");
//   } else {
//     Serial.println("There was an error during OTA update!");
//   }
//   // <Add your own code here>
// }

///////////////////////////////////////////


////////////////////////////////////////////


void setup() {
  Wire.begin(1, 0);
    randomSeed(analogRead(8));

  pinMode(LOM, INPUT_PULLDOWN);
  pinMode(LOP, INPUT);
  pinMode(SDN, OUTPUT);
  pinMode(PINMonitor, INPUT);
  digitalWrite(SDN, HIGH);
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);

  lcd.print("Saver Gowesser");
  if(debug) lcd.print("Debug Mode");
  delay(1000);


  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    lcd.print("sensor not found!");
    delay(500);
    useIRsensor = 0;
  }
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED


  ////////////////////////////////////////// wifi stufff

  initwifi();

  configTime(0, 0, ntpServer);

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

  useHallEffect = Database.get<bool>(client, "/UseHallEffect");
  useIRsensor = Database.get<bool>(client, "/useIRsensor");
  debug = Database.get<bool>(client, "/Debug");
  Distance =  Database.get<float>(client, "/Distance");

  // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
  // request->send(200, "text/plain", "Hi! I am ESP32.");
  // });


  // ElegantOTA.begin(&server);    // Start ElegantOTA
  // // ElegantOTA callbacks
  // ElegantOTA.onStart(onOTAStart);
  // ElegantOTA.onProgress(onOTAProgress);
  // ElegantOTA.onEnd(onOTAEnd);
  // server.begin();
  
  isDebug = debug ? 'B'  : 'A' ;
  lcd.clear();
  screenRoutine();
}


void screenRoutine() {
    lcd.clear();
    lcd.setCursor(0,0);
    sprintf(s, "%d KMH<->%d BPM",speedKmh, bpm);
    lcd.print(s);
    Serial.println(s);

    lcd.setCursor(0,1);
    sprintf(s, " %.2f KM %c %c %d %d",Distance,isDebug, isLead, useIRsensor, useHallEffect);
    Serial.println(s);
    lcd.print(s);
}

void loop() {
  unsigned long waktu = millis();
  // ElegantOTA.loop();

 
  if(useIRsensor) irValue = particleSensor.getIR(); //if using the IR sensor

  if(useHallEffect){
    bool currentSensorState = digitalRead(HALL_SENSOR_PIN);

      // Check if the sensor state has changed from LOW to HIGH (pulse detected)
      if (currentSensorState == HIGH && lastSensorState == LOW) {
          pulseCount++;  // Increment pulse count
          lastPulseTime = waktu;  // Update the last pulse time
      }
      
      // Update the last sensor state
      lastSensorState = currentSensorState;

      // Calculate RPM and speed if the interval has passed
      float rpm = readRPM();
      if (rpm > 0) float speedKmh = calculateSpeed(rpm);
  }
  if(!useIRsensor){
  if(digitalRead(LOP) && digitalRead(LOM)){
    isLead = '!';
  } else  {
    isLead = '*';
  }
  }

  if (checkForBeat(irValue) && useIRsensor)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (int x = 0 ; x < RATE_SIZE ; x++)
       beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
      bpm = beatAvg;
      Serial.println(bpm);
    }
  }

  if(waktu  - waktuS >= 2000UL){
    ///pretty  much all the sending/receiving stuff happened here, once every two second
    // if(debug){
    //   speedKmh = random(1, 200);
    //   bpm = random(1, 400);
    // }
    Serial.println("2 seconds interval");

    Distance = debug ? random(0.1, 100.1) : Database.get<float>(client, "/Distance");
    if(debug){
      speedKmh = random(1, 69);
      bpm = random(1, 200);
    } else {
      if(!useHallEffect) speedKmh = Database.get<int>(client, "/Speed");
      if(useHallEffect && isSending) Database.set<int>(client, "/Speed", speedKmh);
    }

    if(isSending) Database.set<int>(client, "/bpm", bpm);


    // Database.set<int>(client, "/Speed", speedKmh);
    waktuS = waktu;
  }
  if(waktu - waktuT >= 200UL){
    if(!useIRsensor) bpm = analogRead(PINMonitor);
    screenRoutine();
    waktuT = waktu;
  }
  if(waktu waktuV >= 1000UL){
    epochTime = getTime();
    Database.set<String>(client, "/TimeStamp");
    isSending = Database.get<bool>(clieint, "/isSending");
    waktuV = waktu;
  }

} 
