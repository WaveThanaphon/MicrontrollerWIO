#include <TFT_eSPI.h>  // Include the graphics library (this includes the sprite functions)
#include <Wire.h>
#include <Seeed_HM330X.h>

TFT_eSPI tft = TFT_eSPI();  // Create object "tft"
HM330X sensor;

void setup() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);

    Wire.begin();
    sensor.init();
}

void loop() {
    uint8_t buf[30];
    sensor.read_sensor_value(buf, 29);

    int heartRate = buf[10];  // Assuming heart rate data is at index 10

    tft.fillScreen(TFT_BLACK);
    tft.setCursor(10, 10);
    tft.print("Heart Rate: ");
    tft.print(heartRate);
    tft.print(" BPM");

    delay(1000);  // Update every second
}