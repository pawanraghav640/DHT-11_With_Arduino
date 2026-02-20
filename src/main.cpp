#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    while (!Serial);   // good practice for Uno R4
    dht.begin();
    Serial.println("DHT11 Sensor Initialized");
}

void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature(); // Celsius by default

    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print("%\t||\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println("°C");

    delay(2000);
}