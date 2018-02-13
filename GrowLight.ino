/**
 * GrowLight 24 hour cycle using Common Cathode RGB LEDs
 *
 * This file and supporting library files can be found at:
 * http://www.insanegiantrobots.com/arduino/RgbLed.zip
 *
 * @author("Raymond Blum" <raymond@insanegiantrobots.com>) 
 **/

#include <RgbLed.h>

#define LED1_PIN_RED  0
#define LED1_PIN_BLUE  2
#define LED1_PIN_GREEN 1

#define LED2_PIN_RED 3
#define LED2_PIN_GREEN  4
#define LED2_PIN_BLUE 4

#define DURATION_BLINK 300
unsigned long DURATION_HOUR = 1000L*60L*60L;  // avoid delay() overflow errors
//#define DURATION_HOUR 1000L*10L

// create objects of the appropriate types for the connected LED
RgbLedCommonCathode led_rgb1(LED1_PIN_RED, LED1_PIN_GREEN, LED1_PIN_BLUE);
//RgbLedCommonCathode led_rgb2(LED2_PIN_RED, LED2_PIN_GREEN, LED2_PIN_BLUE);

void setup() {
  #ifdef _DEBUG
    Serial.begin(9600);
    Serial.print("blink is ");
    Serial.println(DURATION_BLINK);
    Serial.print("hour is ");
    Serial.println(DURATION_HOUR);
  #endif
  
  led_rgb1.setColor(Color::RED);
  delay(10000);
  led_rgb1.setColor(Color::GREEN);
  delay(10000);
  led_rgb1.setColor(Color::BLUE);
  delay(10000);

  led_rgb1.test();
  led_rgb1.setColor(Color::NONE);
}

void quickComplements() {
  #ifdef DEBUG
    Serial.print("changing at ");
    Serial.println(millis());
  #endif
  
  led_rgb1.setColor(Color::RED );
  delay(DURATION_BLINK);    

  led_rgb1.setColor(Color::BLUE);
  delay(DURATION_BLINK);
   
   led_rgb1.setColor(Color::GREEN);
  delay(DURATION_BLINK);

  led_rgb1.setColor(Color::CYAN);
  delay(DURATION_BLINK);
   
  led_rgb1.setColor(Color::YELLOW);
  delay(DURATION_BLINK);

  led_rgb1.setColor(Color::MAGENTA);
  delay(DURATION_BLINK);    
 
  led_rgb1.setColor(Color::WHITE);
  delay(DURATION_BLINK);       
}

void loop() {
  // 4 hours of morning light
  quickComplements();
  led_rgb1.setColor(Color::BLUE);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::CYAN);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::CYAN);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::WHITE);
  delay(DURATION_HOUR);
   
  // 5 hours of full light
  quickComplements();
  led_rgb1.setColor(Color::WHITE);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::WHITE);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::WHITE);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::WHITE);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::WHITE);
  delay(DURATION_HOUR);

  // 4 hours of dusk
  quickComplements();
  led_rgb1.setColor(Color::YELLOW);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::YELLOW);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::MAGENTA);
  delay(DURATION_HOUR);

  quickComplements();
  led_rgb1.setColor(Color::MAGENTA);
  delay(DURATION_HOUR);

  // 3 hours of twilight
  quickComplements();
  led_rgb1.setColor(Color::RED);
  delay(DURATION_HOUR);

  led_rgb1.setColor(Color::RED);
  delay(DURATION_HOUR);

  led_rgb1.setColor(Color::RED);
  delay(DURATION_HOUR);
 
  // 8 hours of night 
  led_rgb1.setColor(Color::NONE);
  delay(DURATION_HOUR);
  delay(DURATION_HOUR);
  delay(DURATION_HOUR);
  delay(DURATION_HOUR);
  delay(DURATION_HOUR);
  delay(DURATION_HOUR);
  delay(DURATION_HOUR);
  delay(DURATION_HOUR);
}
