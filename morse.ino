#include <LiquidCrystal.h>

#define LED_PIN 13
#define LCD_RS_PIN 16
#define LCD_ENABLE_PIN 17
#define LCD_D04_PIN 23
#define LCD_D05_PIN 25
#define LCD_D06_PIN 27
#define LCD_D07_PIN 29
#define BTN_PIN 41
#define BEEP_PIN 37

LiquidCrystal lcd(
  LCD_RS_PIN,
  LCD_ENABLE_PIN,
  LCD_D04_PIN,
  LCD_D05_PIN,
  LCD_D06_PIN,
  LCD_D07_PIN
);

void beep(int duration = 50) {
  digitalWrite(BEEP_PIN, HIGH);
  delay(duration);
  digitalWrite(BEEP_PIN, LOW);
}

void blinky(int duration = 50) {
  analogWrite(LED_PIN, 255);
  delay(duration);
  digitalWrite(LED_PIN, LOW);
}

void beepblink(int duration) {
  analogWrite(LED_PIN, 255);
  digitalWrite(BEEP_PIN, HIGH);
  delay(duration);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BEEP_PIN, LOW);
}

String toMorse(String inputText) {
  inputText.toLowerCase();
  String morseCode = "";
  
  for (int i = 0; i < inputText.length(); i++) {
    switch (inputText[i]) {
      case 'a':
        morseCode += ".-/";
        break;
      case 'b':
        morseCode += "-.../";
        break;
      case 'c':
        morseCode += "-.-./";
        break;
      case 'd':
        morseCode += "-../";
        break;
      case 'e':
        morseCode += "./";
        break;
      case 'f':
        morseCode += "..-./";
        break;
      case 'g':
        morseCode += "--./";
        break;
      case 'h':
        morseCode += "..../";
        break;
      case 'i':
        morseCode += "../";
        break;
      case 'j':
        morseCode += ".---/";
        break;
      case 'k':
        morseCode += "-.-/";
        break;
      case 'l':
        morseCode += ".-../";
        break;
      case 'm':
        morseCode += "--/";
        break;
      case 'n':
        morseCode += "-./";
        break;
      case 'o':
        morseCode += "---/";
        break;
      case 'p':
        morseCode += ".--./";
        break;
      case 'q':
        morseCode += "--.-/";
        break;
      case 'r':
        morseCode += ".-./";
        break;
      case 's':
        morseCode += ".../";
        break;
      case 't':
        morseCode += "-/";
        break;
      case 'u':
        morseCode += "..-/";
        break;
      case 'v':
        morseCode += "...-/";
        break;
      case 'w':
        morseCode += ".--/";
        break;
      case 'x':
        morseCode += "-..-/";
        break;
      case 'y':
        morseCode += "-.--/";
        break;
      case 'z':
        morseCode += "--../";
        break;
      case '0':
        morseCode += "-----/";
        break;
      case '1':
        morseCode += ".----/";
        break;
      case '2':
        morseCode += "..---/";
        break;
      case '3':
        morseCode += "...--/";
        break;
      case '4':
        morseCode += "....-/";
        break;
      case '5':
        morseCode += "...../";
        break;
      case '6':
        morseCode += "-..../";
        break;
      case '7':
        morseCode += "--.../";
        break;
      case '8':
        morseCode += "---../";
        break;
      case '9':
        morseCode += "----./";
        break;
      case '.':
        morseCode += ".-.-.-./";
        break;
      case '?':
        morseCode += "..--../";
        break;
      case '!':
        morseCode += "--..-/";
        break;
      default:
        lcd.clear();
        lcd.home();
        lcd.print("Cannot encode:");
        lcd.setCursor(0, 1);
        lcd.print(inputText[i]);
    }
  }
  
  return morseCode;
}

void setup() {
  // Init display
  lcd.begin(20, 4);
  
  // Indicate that NEW program is running
  //beep();
  
  // Activate button
  digitalWrite(BTN_PIN, HIGH);
  
  String buff = "";
  String morse = toMorse("a");
  for (int i = 0; i < morse.length(); i++) {
    if (morse[i] != '/') {
      buff += morse[i];
    } else {
      for (int j = 0; j < buff.length(); j++) {
        lcd.write(buff[j]);
        if (buff[j] == '.') {
          beepblink(100);
        } else {
          beepblink(400);
        }
        
        delay(500);
      }
      
      if (i != morse.length() - 1) {
        lcd.write('/');
      }
      buff = "";
      delay(1000);
    }
  }
}

void loop() {
}
