
#define BLYNK_TEMPLATE_ID "Your Template ID"
#define BLYNK_TEMPLATE_NAME "Your Template Name"
#define BLYNK_AUTH_TOKEN "Your Authentication Token"

#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = ""; // Enter your WIFI SSID
char pass[] = ""; // Enter your WIFI Password
// Connect DHT Temperature and Humidity Sensor's Output pin to D4 pin of NodeMCU ESP8266
// Connect Soil Moisture Sensor's A0 pin to A0 pin of NodeMCU ESP8266
// Connect LCD's SCL to D1 pin of NodeMCU ESP8266
// Connect LCD's SDA to D2 pin of NodeMCU ESP8266

DHT dht(D4, DHT11);
BlynkTimer timer;

#define soil A0
double T, P;
char status;

void setup()
{
    Serial.begin(9600);

    lcd.begin(16, 2);
    lcd.backlight();

    Blynk.begin(auth, ssid, pass);

    dht.begin();

    lcd.setCursor(0, 0);
    lcd.print("  Initializing  ");
    for (int a = 5; a <= 10; a++)
    {
        lcd.setCursor(a, 1);
        lcd.print(".");
        delay(500);
    }

    lcd.clear();
    lcd.setCursor(11, 1);
    lcd.print("W:OFF");

    // Call the function
    timer.setInterval(100L, soilMoistureSensor);
    timer.setInterval(100L, DHT11sensor);
}

void DHT11sensor()
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t))
    {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);

    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(t);

    lcd.setCursor(8, 0);
    lcd.print("H:");
    lcd.print(h);
}

void soilMoistureSensor()
{
    int value = analogRead(soil);
    value = map(value, 0, 1024, 0, 100);
    value = (value - 100) * -1;
    if (value < 50)
    {
        Blynk.logEvent("soil", "WARNNG! Please water the plants"); // Enter your Event Name
    }
    Blynk.virtualWrite(V3, value);
    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.print(value);
    lcd.print(" ");
}

void loop()
{
    Blynk.run(); // Run the Blynk library
    timer.run(); // Run the Blynk timer
}