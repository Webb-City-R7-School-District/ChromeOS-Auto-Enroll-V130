#include <Keyboard.h> // keyboard library

// Variables
#define wifi_name "---"
#define wifi_pass "---"
#define wifi_security 2
#define username "---"
#define password "---"
#define slowMode 1
#define update_wait_time 10

// Special characters
#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT  0x81
#define KEY_LEFT_ALT    0x82
#define KEY_RIGHT_CTRL  0x84
#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB         0xB3
#define KEY_ENTER       0xB0
#define KEY_ESC         0xB1
#define KEY_CAPS_LOCK   0xC1

const int buttonPin = 2;   // Button connected to pin 2
const int RXLED = 17;      // LED connected to pin 9

// Flag to control state of the program
bool buttonPressed = false;
bool isEnrollmentComplete = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Button pin set as input with internal pull-up resistor
  pinMode(RXLED, OUTPUT);           // LED pin set as output
  Keyboard.begin();
  wait(5);
  
    // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = true;  // Button is pressed (LOW since it's wired to ground)
  }
}

void loop() {
  
    if (buttonPressed) {
  // Blink the LED 3 times
  for (int i = 0; i < 3; i++) {
    digitalWrite(RXLED, LOW);  // Turn the LED on (LOW turns it on if it's active LOW)
    delay(100);                 // Wait for 250ms
    digitalWrite(RXLED, HIGH); // Turn the LED off
    delay(100);                 // Wait for 250ms
  }
    delay(2000);                 // Wait for 1 second
    return;  // Exit the current iteration of loop() and restart from the top
  }

  if (!isEnrollmentComplete) {
    // Perform Wi-Fi setup and enrollment process
//    setWifi();
    postWifi();
    enterEnrollment();
    
    // After completing the tasks, set the flag to true
    isEnrollmentComplete = true;
  } else {
    // Start blinking the LED every 50ms
    finishLED();
  }
}

// Helper functions

void repeatKey(byte key, int num) {
  for (int i = 0; i < num; i++) {
    Keyboard.write(key);
    wait(1);
  }
}

void wait(int cycles) {
  for (int i = 0; i < cycles; i++) {
    blink();
    if (slowMode) {
      delay(250);
    }
  }
}

void setWifi() {
  repeatKey(KEY_TAB, 3);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(2);
  repeatKey(KEY_TAB, 3);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(1);
  Keyboard.write(KEY_ENTER);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(1);
  Keyboard.write(KEY_ENTER);
  wait(1);
  Keyboard.print(wifi_name);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(2);
  repeatKey(KEY_DOWN_ARROW, 2);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(2);
  Keyboard.print(wifi_pass);
  wait(2);
  repeatKey(KEY_TAB, 3);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(30);
}

void postWifi() {
//  repeatKey(KEY_TAB, 3);
//  wait(1);
//  Keyboard.write(KEY_ENTER);
//  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(15);
}

void enterEnrollment() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('e');
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.release(KEY_LEFT_CTRL);
  wait(5);
  Keyboard.print(username);
  repeatKey(KEY_TAB, 2);
  Keyboard.write(KEY_ENTER);
  wait(5);
  Keyboard.print(password);
  repeatKey(KEY_TAB, 4);
  Keyboard.write(KEY_ENTER);
  wait(1);
}

void blink() {
  digitalWrite(RXLED, LOW);
  delay(250);
  digitalWrite(RXLED, HIGH);
  delay(250);
}

void finishLED() {
  digitalWrite(RXLED, LOW);  // Turn LED on
}
