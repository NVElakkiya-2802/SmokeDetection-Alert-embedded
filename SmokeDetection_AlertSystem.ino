#include <LiquidCrystal.h>
#include <Servo.h>

// Pin definitions
#define GAS_SENSOR A1      // Analog pin for MQ-2 gas sensor
#define BUZZER 8           // Digital pin for buzzer
#define LED_YELLOW 10      // Yellow LED for gas alert
#define SERVO_PIN 7        // Servo motor for ventilation simulation

// LCD pins (optional, for displaying alerts)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize servo object
Servo ventilationServo;

// Threshold for gas detection (adjust based on sensor calibration in Wokwi)
#define GAS_THRESHOLD 400  // Higher values indicate hazardous gas levels

void setup() {
  // Initialize pins
  pinMode(GAS_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  // Attach servo to pin
  ventilationServo.attach(SERVO_PIN);
  ventilationServo.write(0);  // Start at 0 degrees (fan "off")

  // Initialize Serial for debugging
  Serial.begin(9600);

  // Initialize LCD (optional)
  lcd.begin(16, 2);
  lcd.print("Gas Detection");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(GAS_SENSOR);

  // Reset outputs
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED_YELLOW, LOW);
  ventilationServo.write(0);  // Servo to 0 degrees (fan "off")
  lcd.clear();

  // Gas detection
  if (gasValue > GAS_THRESHOLD) {
    Serial.println("Gas Detected!");
    digitalWrite(BUZZER, HIGH);      // Activate buzzer
    digitalWrite(LED_YELLOW, HIGH);  // Yellow LED for gas
    ventilationServo.write(90);     // Rotate servo to 90 degrees (fan "on")
    lcd.setCursor(0, 0);
    lcd.print("Gas Detected!");
    lcd.setCursor(0, 1);
    lcd.print("Ventilation ON");
    delay(1000); // Simulate alarm duration
  } else {
    Serial.println("All Clear");
    lcd.setCursor(0, 0);
    lcd.print("All Clear");
  }

  // Print sensor value for debugging
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  delay(500); // Delay for readability
}
