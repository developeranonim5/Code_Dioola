//DS18B20
#include <Wire.h>
#include <DallasTemperature.h>
#define Pin_Temp D3
OneWire oneWire(Pin_Temp);
DallasTemperature sensor_Ds(&oneWire);

// VL53l0x
#include <VL53L0X.h>
#define distance_media 27.0
VL53L0X sensor_Vl;

//DHT Humidity
#include <DHT.h>
DHT sensor_Dht(D5, DHT22);

// Soil V.2
const int sensor_pin = A0;

// LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

float Read_Sen[4];
String label = String(" ");
int k = 3;
unsigned long time_start, time_end, result_time;

//Firebase
//#include <ESP8266WiFi.h>
//#include <FirebaseArduino.h>
//
//#define HOST_FIREBASE "trashvee-bsf-ec6cf.firebaseio.com"
//#define AUTH_FIREBASE "mIdcVEaVEFnhPpZs5x0iep7r5WiRyQldoPc4gOSu"
//
//#define SSID_WIFI "Redmi"
//#define PASSWORD_WIFI "alfifikri"

void setup() {
  Serial.begin(9600);
  Wire.begin();
  sensor_Ds.begin();           // DS18B20
  sensor_Vl.init();           //  VL53L0X
  sensor_Vl.setTimeout(500);
  sensor_Vl.startContinuous();
  sensor_Dht.begin();         // DHT22
  lcd.begin();
  pinMode(D7, OUTPUT);

  // Firebase
//    WiFi.begin(SSID_WIFI, PASSWORD_WIFI);
//    Serial.print("Connecting to ");
//    Serial.print(SSID_WIFI);
//    while (WiFi.status() != WL_CONNECTED) {
//      Serial.print(".");
//      delay(500);
//    }
//    Serial.println();
//    Serial.print("Connected to ");
//    Serial.println(SSID_WIFI);
//    Serial.print("IP Address is : ");
//    Serial.println(WiFi.localIP());
//    Firebase.begin(HOST_FIREBASE,AUTH_FIREBASE);
}

void loop() {
  Temp_Sen();
  Dist_Sen();
  Humi_Sen();
  Soil();
  Actuator();
  
outsystem();
//  Normalization();
//  KNNv2();
//  Class();
//  firebase();

}
