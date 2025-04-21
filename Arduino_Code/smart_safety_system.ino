#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

SoftwareSerial btSerial(10, 11); // RX, TX for Bluetooth

const int gasPin = A0;        // MQ-135 Analog Output
const int flamePin = 9;       // Flame sensor Digital Output
const int buzzerPin = 8;      // Buzzer

int gasThreshold = 600;       // Adjust based on AQI
int flameDetected = LOW;

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);

  // OLED Initialization
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED init failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("System Booting...");
  display.display();
  delay(1500);
}

void loop() {
  int gasValue = analogRead(gasPin);
  flameDetected = digitalRead(flamePin);
  bool alert = false;

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);

  // --- Gas Detection ---
  if (gasValue > gasThreshold) {
    Serial.println("ALERT: GAS DETECTED 💨");
    btSerial.println("ALERT: GAS DETECTED 💨");
    display.println("Gas: DANGER 💨");
    alert = true;
  } else {
    display.println("Gas: Safe ✅");
  }

  // --- Flame Detection ---
  if (flameDetected == LOW) { // LOW = Flame Detected
    Serial.println("ALERT: FLAME DETECTED 🔥");
    btSerial.println("ALERT: FLAME DETECTED 🔥");
    display.println("Flame: DETECTED 🔥");
    alert = true;
  } else {
    display.println("Flame: None");
  }

  // --- Show Sensor Values ---
  display.print("Gas Value: ");
  display.println(gasValue);
  display.display();

  // --- Buzzer with Tone ---
  if (alert) {
    tone(buzzerPin, 1000); // 1 kHz sound
  } else {
    noTone(buzzerPin);
  }

  delay(1000);
}
