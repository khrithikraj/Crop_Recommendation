#define BLYNK_TEMPLATE_ID "TMPLVn9nDBuQ"
#define BLYNK_TEMPLATE_NAME "Crop 2"
#define BLYNK_AUTH_TOKEN "Hezr5qf6cZ7iElCY6XYCzAKzdEjrB1qD"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 

#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "SSN";  // type your wifi name
char pass[] = "Ssn1!Som2@Sase3#";  // type your wifi password

#define DHTPIN 1          // Mention the digital pin where you connected 
#define DHTTYPE DHT11     // DHT 11  
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println(t);
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);


  if(t > 30){
   // Blynk.email("shameer50@gmail.com", "Alert", "Temperature over 28C!");
    Blynk.logEvent("temp_alert","Temp above 30 degree");
  }
}

void setup(){
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
