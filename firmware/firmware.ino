#define HALL_SENSOR_PIN 2
#define TireDiameter 0.7
#define PINMonitor 21
#define LOM 20 //lead off Plus pin
#define LOP 10 //lead offf Min Pin (high when lead is disconected)
#define SDN 9

#include <Arduino.h>

////////////////////////////////////////////// heart rate sensor
#include "MAX30105.h"

#include "heartRate.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
char isLead;

float beatsPerMinute;
int beatAvg;












/////////////////////////////////////////// wifi stuff here


// #if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
// #include <WiFi.h>
// #elif defined(ESP8266)
// #include <ESP8266WiFi.h>
// #endif

// #include <FirebaseClient.h>
// #include <WiFiClientSecure.h>

// #define WIFI_SSID "ini  wifii"
// #define WIFI_PASSWORD "12345678"

// #define DATABASE_URL "https://savergowes-default-rtdb.asia-southeast1.firebasedatabase.app/"
// String name;
// WiFiClientSecure ssl;
// DefaultNetwork network;
// AsyncClientClass client(ssl, getNetwork(network));

// FirebaseApp app;
// RealtimeDatabase Database;
// AsyncResult result;
// NoAuth noAuth;

// void printError(int code, const String &msg)
// {
//     Firebase.printf("Error, msg: %s, code: %d\n", msg.c_str(), code);
// }

// void initwifi() {
//   WiFi.setAutoReconnect(true);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   lcd.setCursor(0,0);
//   int index = 0;
//   while (WiFi.status() != WL_CONNECTED) {
//     if(index <= 19) lcd.print(wifiText[index]+wifiText[index+1]);
//     index += 2;
//     delay(500);
//   }
//     WiFi.setSleep(false);
//   Serial.print(WiFi.localIP());
// }


//////////////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x25,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


String wifiText = "ini_wifii 12345678";
////////////////////////////////////////////
unsigned long waktu, waktuS, waktuT;
int speedKmh, bpm, bpm2;
char s[20];

////////////////////////////////////////////


///////////////////////////////////////////


////////////////////////////////////////////


void setup() {
  Wire.begin(1, 0);
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
  delay(1000);


  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    lcd.print("sensor not found!");
    while (1);
  }
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED


  ////////////////////////////////////////// wifi stufff

  // initwifi();
  // Firebase.printf("Firebase Client v%s\n", FIREBASE_CLIENT_VERSION);
  // ssl.setInsecure();
  // initializeApp(client, app, getAuth(noAuth));
  // // Binding the authentication handler with your Database class object.
  // app.getApp<RealtimeDatabase>(Database);
  // // Set your database URL
  // Database.url(DATABASE_URL);
  // // In sync functions, we have to set the operating result for the client that works with the function.
  // client.setAsyncResult(result);


  //////////////////////////////////////////////
  lcd.clear();
  screenRoutine();

}


void screenRoutine() {
    lcd.clear();
    sprintf(s, "%d KMH - %d BPM",speedKmh, bpm2);
    lcd.print(s);
    lcd.setCursor(5,1);
    sprintf(s, "  %d BPM %c", bpm, isLead);
    lcd.print(s);
}

void loop() {
  unsigned long waktu = millis();

 
long irValue = particleSensor.getIR();
  if(digitalRead(LOP) && digitalRead(LOM)){ isLead = '!';
  }else{ isLead = '*';}
  if (checkForBeat(irValue))
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
      bpm2 = beatAvg;
      Serial.println(bpm2);
    }
  }

  if(waktu  - waktuS >= 2000UL){
    Serial.println("2 seconds interval");
    // Database.set<int>(client, "/Speed", speedKmh);
    // Database.set<int>(client, "/Speed", bpm);
    waktuS = waktu;
  }
  if(waktu - waktuT >= 200UL){
    bpm = analogRead(PINMonitor);
    screenRoutine();
    waktuT = waktu;
  }

} 
