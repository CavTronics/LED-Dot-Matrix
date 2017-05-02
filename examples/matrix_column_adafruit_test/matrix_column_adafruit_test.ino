/*
  Blink test matrix
  Turns on an LED matrix column on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
  */

// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
//
/* rows
// Digital  |       |       | Led matrix | Adafruit library 
// ide pin  | gpio  | pos   | pin        | pinout
// ========================================
// pin 2    | pd2   | row1  | 9           | dp0
// pin 7    | pd7   | row2  | 14          | dp4
// pin 19   | a5    | row3  | 8           | dp19 (a5)
// pin 5    | pd5   | row4  | 12          | dp18 (a4)
// pin 10   | pd10  | row5  | 1           | dp17 (a3)
// pin 18   | a4    | row6  | 7           | dp16 (a2)
// pin 11   | pd11  | row7  | 2           | dp15 (a1)
// pin 16   | a2    | row8  | 5           | dp14 (a0)
*/
// Arduino pin definitions - (ordered to keep wiring tidy)
// int row[] = {14,10,4,12,9,5,8,6};    //rows - driven LOW for on
// int col[] = {17,16,13,2,15,3,7,11};  //columns - driven HIGH for on
// top left light which is row1 col1

#include "LED_Matrix.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <TimerOne.h>


// ==========================| merv merlin pins
// int ledrow1 = 0;     // row 1 dp0
// int ledrow2 = 4;     // row 2 dp4
// int ledrow3 = 19;   // row 3 dp19
// int ledrow4 = 18;     // row 4 dp18
// int ledrow5 = 17;   // row 5 dp17
// int ledrow6 = 16;   // row 6 dp16
// int ledrow7 = 15;   // row 7 dp15
// int ledrow8 = 14;   // row 8 dp14

// 
 // GPIO_pin_t column_pins[] = {  0,  4, A5, A4, A3, A2, A1, A0,

// mervmerlin

// GPIO_pin_t line_pins[] = { DP5, DP6, DP7, DP8, DP12, DP11, DP10, DP9 };

// GPIO_pin_t column_pins[] = {  DP0,  DP4, DP19, DP18, DP17, DP16, DP15, DP14,

// int col[] = {6,12,13,3,17,4,8,9};  //columns - driven HIGH for on

// 2,7,19,5,10,18,11,16
/*
// columns
// Digital  |       |
// ide pin  | gpio  | pos   | led matrix pin
// ==================================
// pin 6    | pd6   | col1  | 13
// pin 12   | pd12  | col2  | 3
// pin 13   | pd13  | col3  | 4
// pin 3    | pd3   | col4  | 10
// pin 17   | a10  | col5   | 6
// pin 4    | pd4   | col6  | 11
// pin 8    | pd8   | col7  | 15
// pin 9    | pd9   | col8  | 16
*/

// int ledcol1 = 5; // col 1 dp5
// int ledcol2 = 6; // col 2 dp6
// int ledcol3 = 7; // col 3 dp7
// int ledcol4 = 8; // col 4 dp8
// int ledcol5 = 12; // col 5 dp12
// int ledcol6 =11; // col 6 dp11
// int ledcol7 = 10; // col 7 dp10
// int ledcol8 = 9; // col 8 dp9

//
// GPIO_pin_t line_pins[] = { 5, 6, 7, 8, 12, 11, 10, 9 };
#define DATA_PIN DINV
#define CLK_PIN DINV
#define LATCH1_PIN DINV
#define LATCH2_PIN DINV
#define LATCH3_PIN DINV

  GPIO_pin_t line_pins[] = { DP5, DP6, DP7, DP8, DP12, DP11, DP10, DP9 };

  GPIO_pin_t column_pins[] = {  DP0,  DP4, DP19, DP18, DP17, DP16, DP15, DP14,
                              DINV, DINV, DINV, DINV, DINV, DINV, DINV, DINV,
                              DINV, DINV, DINV, DINV, DINV, DINV, DINV, DINV, };

  GPIO_pin_t sr_pins[] = { DINV, DINV, DINV, DATA_PIN, CLK_PIN };
  PWMDirectMatrix *matrix;



// GPIO_pin_t line_pins[] = { DP5, DP6, DP7, DP8, DP12, DP11, DP10, DP9 };
// int row[] = {2,7,19,5,10,18,11,16};    //rows - driven LOW for on


#define DEBUG 1
#define TESTCOL 1

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.


// These go to ground:
// GPIO_pin_t line_pins[] = { 5, 6, 7, 8, 12, 11, 10, 9 };
// Those go to V+
// A6 and A7 do NOT work as digital pins on Arduino Nano
// Red LEDs are directly connected.
// Green LEDs are connected via shift register
// GPIO_pin_t column_pins[] = {  0,  4, A5, A4, A3, A2, A1, A0,
//                              DINV, DINV, DINV, DINV, DINV, DINV, DINV, DINV,
//                              DINV, DINV, DINV, DINV, DINV, DINV, DINV, DINV, };
//
// ----------------------------------------------------------------------------
// ........................R1...R2...R3...R4...R5....R6....R7....R8
// GPIO_pin_t line_pins[] = { DP5, DP6, DP7, DP8, DP12, DP11, DP10, DP9 };

// ...........................C1....C2....C3....C4...C5....C6.....C7...C8
// GPIO_pin_t column_pins[] = {  DP0,  DP4, DP19, DP18, DP17, DP16, DP15, DP14,
//                              DINV, DINV, DINV, DINV, DINV, DINV, DINV, DINV,
 //                             DINV, DINV, DINV, DINV, DINV, DINV, DINV, DINV, };
// ----------------------------------------------------------------------------

// no shift register in single color test, all latches are set to invalid pin
// GPIO_pin_t sr_pins[] = { DINV, DINV, DINV, DATA_PIN, CLK_PIN };

     // void setup() {
    // Initializing serial breaks one row (shared pin)
    if (DEBUG) Serial.begin(9600);
    if (DEBUG) while (!Serial);
    if (DEBUG) Serial.println("Matrix led Test");
    if (DEBUG) Serial.println("Rows");
    if (DEBUG) Serial.println("Digital  |       |");
    if (DEBUG) Serial.println("ide pin  | gpio  | pos   | led matrix pin");
    if (DEBUG) Serial.println("==================================");
    if (DEBUG) Serial.println("pin 0    | dp0   | row1  | 9");
    if (DEBUG) Serial.println("pin 4    | dp4   | row2  | 14");
    if (DEBUG) Serial.println("pin 19   | a5    | row3  | 8");
    if (DEBUG) Serial.println("pin 18   | a4    | row4  | 12");
    if (DEBUG) Serial.println("pin 17   | a3    | row5  | 1");
    if (DEBUG) Serial.println("pin 16   | a2    | row6  | 7");
    if (DEBUG) Serial.println("pin 15   | a1    | row7  | 2");
    if (DEBUG) Serial.println("pin 14   | a0    | row8  | 5");
    if (DEBUG) Serial.println("");
    

    if (DEBUG) Serial.println("columns");
    if (DEBUG) Serial.println("Digital  |       |");
    if (DEBUG) Serial.println("ide pin  | gpio  | pos   | led matrix pin");
    if (DEBUG) Serial.println("==================================");
    if (DEBUG) Serial.println("pin 5    | dp5   | col1  | 13");
    if (DEBUG) Serial.println("pin 6    | dp6   | col2  | 3");
    if (DEBUG) Serial.println("pin 7    | dp7   | col3  | 4");
    if (DEBUG) Serial.println("pin 8    | dp8   | col4  | 10");
    if (DEBUG) Serial.println("pin 12   | dp12  | col5  | 6");
    if (DEBUG) Serial.println("pin 11   | dp11  | col6  | 11");
    if (DEBUG) Serial.println("pin 10   | dp10  | col7  | 15");
    if (DEBUG) Serial.println("pin 9    | pdp9  | col8  | 16");
    if (DEBUG) Serial.println("Columns should be flashing");


      matrix = new PWMDirectMatrix(8, 8, 1);
    // The ISR frequency is doubled 3 times to create 4 PWM values
    // and will run at x, x*2, x*4, x*16 to simulate 16 levels of
    // intensity without causing 16 interrupts at x, leaving more
    // time for the main loop and causing less intensity loss.
    // 200 flickers a bit for me due to the 1600us 4th scan, 200 removes
    // the flicker for my eyes.
    matrix->begin(line_pins, column_pins, sr_pins, 200);
}

    static const uint8_t PROGMEM
    smile_bmp[] =
    { B00111100,
        B01000010,
        B10100101,
        B10000001,
        B10100101,
        B10011001,
        B01000010,
        B00111100 },
    neutral_bmp[] =
    { B00111100,
        B01000010,
        B10100101,
        B10000001,
        B10111101,
        B10000001,
        B01000010,
        B00111100 },
    frown_bmp[] =
    { B00111100,
        B01000010,
        B10100101,
        B10000001,
        B10011001,
        B10100101,
        B01000010,
        B00111100 };

static const uint16_t PROGMEM
    RGB_bmp[][64] = {
      // 16 shades repeated 4 times for 64 LEDs
      { 0x000, 0x000, 0x000, 0x000, 0x001, 0x001, 0x001, 0x001, 
        0x002, 0x002, 0x002, 0x002, 0x003, 0x003, 0x003, 0x003, 
  0x004, 0x004, 0x004, 0x004, 0x005, 0x005, 0x005, 0x005, 
  0x006, 0x006, 0x006, 0x006, 0x007, 0x007, 0x007, 0x007, 
  0x008, 0x008, 0x008, 0x008, 0x009, 0x009, 0x009, 0x009, 
  0x00A, 0x00A, 0x00A, 0x00A, 0x00B, 0x00B, 0x00B, 0x00B, 
  0x00C, 0x00C, 0x00C, 0x00C, 0x00D, 0x00D, 0x00D, 0x00D, 
  0x00E, 0x00E, 0x00E, 0x00E, 0x00F, 0x00F, 0x00F, 0x00F, } };

void show_isr() {
    if (DEBUG) Serial.print  (F("ISR runtime: "));
    if (DEBUG) Serial.print  (matrix->ISR_runtime());
    if (DEBUG) Serial.print  (F(" and latency: "));
    if (DEBUG) Serial.println(matrix->ISR_latency());
}

// rows
    // pinMode(ledrow1, OUTPUT);  // row1
    // pinMode(ledrow2, OUTPUT);  // row2
    // pinMode(ledrow3, OUTPUT); // row3
    // pinMode(ledrow4, OUTPUT);  // row4
    // pinMode(ledrow5, OUTPUT); // row5 
    // pinMode(ledrow6, OUTPUT); // row6
    // pinMode(ledrow7, OUTPUT); // row7
    // pinMode(ledrow8, OUTPUT); // row8

// columns
    // pinMode(ledcol1, OUTPUT); 
    // pinMode(ledcol2, OUTPUT); 
    // pinMode(ledcol3, OUTPUT); 
    // pinMode(ledcol4, OUTPUT); 
    // pinMode(ledcol5, OUTPUT); 
    // pinMode(ledcol6, OUTPUT);
    // pinMode(ledcol7, OUTPUT); 
    // pinMode(ledcol8, OUTPUT); 

//}

// the loop routine runs over and over again forever:
void loop() {

    // show_isr();
    // matrix->clear();
    // matrix->fillRect(0,0, 8,8, LED_RED_HIGH);
    // matrix->writeDisplay();
    // delay(3000);
    // new 
    matrix->clear();
    // matrix->fillRect(0,0, 8,8, LED_RED_VERYLOW);
    matrix->fillRect(0,0, 8, 0, LED_RED_VERYLOW);

    matrix->writeDisplay();
    delay(3000);


    // for (uint8_t i=0; i<=0; i++)
    //   {
    // show_isr();
    // matrix->clear();
    // matrix->drawRGBBitmap(0, 0, RGB_bmp[i], 8, 8);
    // matrix->writeDisplay();
    // delay(4000);
    //   }

    //   show_isr();
    //   matrix->clear();
    //   matrix->drawBitmap(0, 0, smile_bmp, 8, 8, LED_RED_HIGH);
    //   matrix->writeDisplay();
    //   delay(1000);

    //   show_isr();
    //   matrix->clear();
    //   matrix->drawBitmap(0, 0, neutral_bmp, 8, 8, LED_RED_MEDIUM);
    //   matrix->writeDisplay();
    //   delay(1000);

    //   show_isr();
    //   matrix->clear();
    //   matrix->drawBitmap(0, 0, frown_bmp, 8, 8, LED_RED_LOW);
    //   matrix->writeDisplay();
    //   delay(1000);

    //   show_isr();
    //   matrix->clear();
    //   matrix->drawCircle(3,3, 3, LED_RED_MEDIUM);
    //   matrix->writeDisplay();
    //   delay(500);

    //   matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
    //   matrix->setTextSize(1);
    //   matrix->setTextColor(LED_RED_HIGH);
    //   matrix->setRotation(3);
    //   for (int8_t x=7; x>=-36; x--) {
    //       matrix->clear();
    //       matrix->setCursor(x,0);
    //       matrix->print("Hello");
    //       matrix->writeDisplay();
    // delay(50);
    //   }
    //   delay(100);
    //   matrix->setRotation(0);
    //   matrix->setTextColor(LED_RED_LOW);
    //   for (int8_t x=7; x>=-36; x--) {
    //       matrix->clear();
    //       matrix->setCursor(x,0);
    //       matrix->print("World");
    //       matrix->writeDisplay();
    // delay(50);
    //   }
    //   matrix->setRotation(0);

 // rows
//   digitalWrite(ledrow1, HIGH);   // turn the LED on (HIGH is the voltage level)
//   digitalWrite(ledrow2, HIGH);   // turn the LED on (HIGH is the voltage level)
//   digitalWrite(ledrow3, HIGH);   // turn the LED on (HIGH is the voltage level)
//   digitalWrite(ledrow4, HIGH);   // turn the LED on (HIGH is the voltage level)
//   digitalWrite(ledrow5, HIGH);   // turn the LED on (HIGH is the voltage level)
//   digitalWrite(ledrow6, HIGH);   // turn the LED on (HIGH is the voltage level)
//   digitalWrite(ledrow7, HIGH);   // turn the LED on (HIGH is the voltage level)
//   digitalWrite(ledrow8, HIGH);   // turn the LED on (HIGH is the voltage level)

// // columns
//   digitalWrite(ledcol1, LOW);   // make the voltage LOW (for the other side of LED)
//   digitalWrite(ledcol2, LOW);   // make the voltage LOW (for the other side of LED)
//   digitalWrite(ledcol3, LOW);   // make the voltage LOW (for the other side of LED)
//   digitalWrite(ledcol4, LOW);   // make the voltage LOW (for the other side of LED)
//   digitalWrite(ledcol5, LOW);   // make the voltage LOW (for the other side of LED)
//   digitalWrite(ledcol6, LOW);   // make the voltage LOW (for the other side of LED)
//   digitalWrite(ledcol7, LOW);   // make the voltage LOW (for the other side of LED)
//   digitalWrite(ledcol8, LOW);   // make the voltage LOW (for the other side of LED)

// turn off one row at a time 
  // delay(1000);               // wait for a second
  //   digitalWrite(ledrow1, LOW);    // turn the LED off by making the voltage LOW
  //  delay(1000);               // wait for a second
  //   digitalWrite(ledrow2, LOW);    // turn the LED off by making the voltage LOW
  //   delay(1000);               // wait for a second
  //   digitalWrite(ledrow3, LOW);    // turn the LED off by making the voltage LOW
  //    delay(1000);               // wait for a second
  //   digitalWrite(ledrow4, LOW);    // turn the LED off by making the voltage LOW
  //    delay(1000);               // wait for a second
  //   digitalWrite(ledrow5, LOW);    // turn the LED off by making the voltage LOW
  //    delay(1000);               // wait for a second
  //   digitalWrite(ledrow6, LOW);    // turn the LED off by making the voltage LOW
  //    delay(1000);               // wait for a second
  //   digitalWrite(ledrow7, LOW);    // turn the LED off by making the voltage LOW
  //    delay(1000);               // wait for a second
  //   digitalWrite(ledrow8, LOW);    // turn the LED off by making the voltage LOW
  //   delay(1000);               // wait for a second
  }
