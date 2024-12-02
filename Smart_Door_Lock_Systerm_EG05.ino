#include <Servo.h>
#include <LiquidCrystal.h>
#include "Keypad.h"

// LCD initialization
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Servo motor initialization
Servo myservo;

// Keypad setup
const byte Rows = 4; // Four rows
const byte Cols = 4; // Four columns for a 4x4 keypad
char keys[Rows][Cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[Rows] = {11, 12, 13, A0}; // Connect to the row pinouts of the keypad
byte colPins[Cols] = {8, 9, 10, A1};   // Connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, Rows, Cols);

// Variables for password handling
String keypressed, finalkey;
String password = "1234"; // Set the correct password here

int incorrectAttempts = 0; // Variable to track incorrect password attempts

void setup() {
  Serial.begin(9600);
  myservo.attach(A2); // Attach the servo to pin A2
  lcd.begin(16, 2);
  lcd.print("Device Control");
  lcd.setCursor(0, 1);
  lcd.print("Through Keypad");
  delay(1000);
  lcd.clear();
  lcd.print("Enter Password");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key != '=') {
      finalkey += key;
      lcd.setCursor(finalkey.length() - 1, 1);
      lcd.print("*");
      delay(100);
    } else {
      if (finalkey == password) {
        lcd.clear();
        lcd.print("Correct password");
        lcd.setCursor(0, 1);
        lcd.print("Gate is opening");
        delay(500);        // Wait for 5 seconds to simulate door opening
        myservo.write(90);  // Rotate the servo to 90 degrees (open the door)
        delay(1500);       // Wait for 10 seconds while the door is open
        myservo.write(0);   // Rotate the servo back to 0 degrees (close the door)
        lcd.clear();
        lcd.print("Door is closed");
        delay(1000);        // Wait for 2 seconds to show the door is closed message
        lcd.clear();
        lcd.print("Enter Password");
        incorrectAttempts = 0; // Reset incorrect attempts after successful entry
      } else {
        lcd.clear();
        lcd.print("Wrong Password");
        delay(1000);
        incorrectAttempts++; // Increment incorrect attempts
        if (incorrectAttempts >= 3) { // Check if incorrect attempts exceed threshold
          SendMessage();
          incorrectAttempts = 0; // Reset incorrect attempts after sending message
        }
        lcd.clear();
        lcd.print("Enter Password");
      }
      delay(100);
      finalkey = "";
    }
  }
}

void SendMessage() {
  Serial.println("AT+CMGF=1");    // Sets the GSM Module in Text Mode
  delay(100);  // Delay of 100 milliseconds
  Serial.println("AT+CMGS=\"+94777928321\"\r"); 
  delay(100);
  Serial.println("Unknown person try"); // The SMS text you want to send
  Serial.println("to open your door");  // The SMS text you want to send
  delay(100);
  Serial.write(26); // ASCII code for Ctrl+Z
  delay(1000);
}
