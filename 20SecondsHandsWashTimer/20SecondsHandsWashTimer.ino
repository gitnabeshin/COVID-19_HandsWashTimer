/**************************************************
* 20seconds Washing hands Timer
* - MAX7219 8x8 LED DotMatrix (https://github.com/wayoda/LedControl)
* - Speaker
* - Distance sensor
***************************************************/
#include "LedControl.h"

#define PIN_TRIG 8
#define PIN_ECHO 9
#define PIN_SPEAKER 2

#define COUNT_FREQ 440
#define COUNT_DOWN_FREQ 740

/*
 MAX7219.
 ----------------------------------
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 */
LedControl lc=LedControl(12,11,10,1);

// time between updates of the display
unsigned long delaytime=1000;

void setup() {
  lc.shutdown(0, false);
  //Set the brightness
  lc.setIntensity(0,2);
  //clear the display
  lc.clearDisplay(0);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

//20 Second Counter (Not for countdowm)
void delayTimes(unsigned int frequency) {
  tone(PIN_SPEAKER,frequency,500);
  delay(200);
  noTone(PIN_SPEAKER);
  delay(800);
}

void drawHeart(){
  lc.clearDisplay(0);
  lc.setColumn(0,0,B00000000);
  lc.setColumn(0,1,B01100110);
  lc.setColumn(0,2,B11111111);
  lc.setColumn(0,3,B11111111);
  lc.setColumn(0,4,B11111111);
  lc.setColumn(0,5,B01111110);
  lc.setColumn(0,6,B00111100);
  lc.setColumn(0,7,B00011000);
}

void startCount() { 

  //Startup (Smile)
  lc.setColumn(0,0,B00000000);
  lc.setColumn(0,1,B00100100);
  lc.setColumn(0,2,B00100100);
  lc.setColumn(0,3,B00000000);
  lc.setColumn(0,4,B00000000);
  lc.setColumn(0,5,B01000010);
  lc.setColumn(0,6,B00111100);
  lc.setColumn(0,7,B00000000);
  tone(PIN_SPEAKER, 659, 200);
  delay(200);
  lc.setColumn(0,4,B01000010);
  lc.setColumn(0,5,B00111100);
  lc.setColumn(0,6,B00000000);
  tone(PIN_SPEAKER, 1047, 200);
  delay(200);
  lc.setColumn(0,4,B00000000);
  lc.setColumn(0,5,B01000010);
  lc.setColumn(0,6,B00111100);
  tone(PIN_SPEAKER, 2093, 200);
  delay(400);
  lc.setColumn(0,4,B00011000);
  lc.setColumn(0,5,B00100100);
  lc.setColumn(0,6,B00011000);
  noTone(PIN_SPEAKER);
  delay(500);
  lc.clearDisplay(0);

  //Count 20
  //1
  lc.setRow(0,0,B11000000);
  lc.setRow(0,1,B10000000);
  delayTimes(COUNT_FREQ);
  //2
  lc.setRow(0,1,B11000000);
  lc.setRow(0,2,B11000000);
  delayTimes(COUNT_FREQ);
  //2
  lc.setRow(0,3,B11000000);
  lc.setRow(0,4,B10000000);
  delayTimes(COUNT_FREQ);
  //4
  lc.setRow(0,4,B11000000);
  lc.setRow(0,5,B11000000);
  delayTimes(COUNT_FREQ);
  //5
  lc.setRow(0,6,B11000000);
  lc.setRow(0,7,B10000000);
  delayTimes(COUNT_FREQ);
  //6
  lc.setRow(0,6,B11100000);
  lc.setRow(0,7,B11100000);
  delayTimes(COUNT_FREQ);
  //7
  lc.setRow(0,6,B11110000);
  lc.setRow(0,7,B11111000);
  delayTimes(COUNT_FREQ);
  //8
  lc.setRow(0,6,B11111100);
  lc.setRow(0,7,B11111100);
  delayTimes(COUNT_FREQ);
  //9
  lc.setRow(0,6,B11111110);
  lc.setRow(0,7,B11111111);
  delayTimes(COUNT_FREQ);
  //10
  lc.setRow(0,5,B11000011);
  lc.setRow(0,6,B11111111);
  delayTimes(COUNT_FREQ);
  //11
  lc.setRow(0,3,B11000001);
  lc.setRow(0,4,B11000011);
  delayTimes(COUNT_FREQ);
  //12
  lc.setRow(0,2,B11000011);
  lc.setRow(0,3,B11000011);
  delayTimes(COUNT_FREQ);
  //13
  lc.setRow(0,0,B11000001);
  lc.setRow(0,1,B11000011);
  delayTimes(COUNT_FREQ);
  //14
  lc.setRow(0,0,B11000111);
  lc.setRow(0,1,B11000111);
  delayTimes(COUNT_FREQ);
  //15
  lc.setRow(0,0,B11001111);
  lc.setRow(0,1,B11011111);
  delayTimes(COUNT_FREQ);
  //16
  lc.setRow(0,0,B11111111);
  lc.setRow(0,1,B11111111);
  delayTimes(COUNT_FREQ);
  //17 (3: countdown)
  lc.clearDisplay(0);
  lc.setColumn(0,0,B00000000);
  lc.setColumn(0,1,B00011100);
  lc.setColumn(0,2,B00100000);
  lc.setColumn(0,3,B00011000);
  lc.setColumn(0,4,B00100000);
  lc.setColumn(0,5,B00100100);
  lc.setColumn(0,6,B00011000);
  lc.setColumn(0,7,B00000000);
  delayTimes(COUNT_DOWN_FREQ);
  //18 (2: countdown)
  lc.clearDisplay(0);
  lc.setColumn(0,0,B00000000);
  lc.setColumn(0,1,B00011000);
  lc.setColumn(0,2,B00100100);
  lc.setColumn(0,3,B00100000);
  lc.setColumn(0,4,B00010000);
  lc.setColumn(0,5,B00001000);
  lc.setColumn(0,6,B00111100);
  lc.setColumn(0,7,B00000000);
  delayTimes(COUNT_DOWN_FREQ);
  //19 (1: countdown)
  lc.clearDisplay(0);
  lc.setColumn(0,0,B00000000);
  lc.setColumn(0,1,B00010000);
  lc.setColumn(0,2,B00011000);
  lc.setColumn(0,3,B00010000);
  lc.setColumn(0,4,B00010000);
  lc.setColumn(0,5,B00010000);
  lc.setColumn(0,6,B00111000);
  lc.setColumn(0,7,B00000000);
  delayTimes(COUNT_DOWN_FREQ);

  //Show Heart for Finishing
  drawHeart();
  delay(400);
  tone(PIN_SPEAKER, 1480, 200);
  lc.clearDisplay(0);
  delay(200);
  tone(PIN_SPEAKER, 1047, 200);
  delay(200);
  tone(PIN_SPEAKER, 1480, 200);
  drawHeart();
  delay(200);
  tone(PIN_SPEAKER, 1047, 200);
  delay(200);
  tone(PIN_SPEAKER, 1480, 200);
  lc.clearDisplay(0);
  delay(200);
  noTone(PIN_SPEAKER);
  tone(PIN_SPEAKER, 1661, 200);
  drawHeart();
  delay(400);
  tone(PIN_SPEAKER, 1865, 200);
  delay(400);
  tone(PIN_SPEAKER, 2349, 200);
  lc.clearDisplay(0);
  delay(200);
  tone(PIN_SPEAKER, 2637, 200);
  delay(200);
  drawHeart();
  noTone(PIN_SPEAKER);
  delay(500);
  lc.clearDisplay(0);
}

void loop() {

  //Get Distance
  digitalWrite(PIN_TRIG,LOW);
  delayMicroseconds(1);
  digitalWrite(PIN_TRIG,HIGH);
  delayMicroseconds(11);
  digitalWrite(PIN_TRIG, LOW);
  int t = pulseIn(PIN_ECHO, HIGH);
  float distance = t*0.017;

  //Timer starts under 16cm 
  if( distance < 16 ) {
    //Count 20 seconds
    startCount();
  }
  
  delay(2000);
}
