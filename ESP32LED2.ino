

#include <WiFi.h>
#include "FirebaseESP32.h"

// Credenciales wifi
#define WIFI_SSID "INFINITUMD1A2_2.4"
#define WIFI_PASSWORD "9A2jMDq4B2"

// Credenciales Proyecto Firebase

#define FIREBASE_HOST "https://esp32led-6ab41-default-rtdb.firebaseio.com"             // the project name address from firebase id
#define FIREBASE_AUTH "bI0GJeYB5IWilWVstavcXmXBR2NdKQVquzQxaiLN"       // the secret key generated from firebase

FirebaseData firebaseData;
String path = "/Test";

void setup() {

  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(19,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("[Wi-Fi]...Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Firewall that allows only GET and POST requests
  //Firebase.enableClassicRequest(firebaseData, true);
}

void loop() {
  Firebase.getInt(firebaseData, path + "/LED");
  Serial.println("Data= " + String(firebaseData.intData()));
  delay(200);
  if(firebaseData.intData()==1)
  {
    digitalWrite(2,HIGH);
    digitalWrite(27,HIGH);
    digitalWrite(15,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(19,HIGH);
  }
  else{
    digitalWrite(2,LOW);
    digitalWrite(27,LOW);
    digitalWrite(15,LOW);
    digitalWrite(5,LOW);
    digitalWrite(19,LOW);
  }
}
 // Fir
