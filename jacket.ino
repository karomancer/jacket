#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_NeoPixel.h>

/** 
 *  NTAG Reader pins
 *  Not defined here:
 *    SPI MOSI   D11
 *    SPI MISO   D12
 *    SPI SCK    D13
 */
#define SS_PIN 10
#define RST_PIN 9

/** 
 *  Light pins
 */
#define MATRIX_PIN 2
#define MATRIX_CNT 64

#define STRIP_PIN 3
#define STRIP_CNT 18

#define STRIP2_PIN 4
#define STRIP2_CNT 18

#define STRIP3_PIN 5
#define STRIP3_CNT 18

#define STRIP4_PIN 6
#define STRIP4_CNT 18

#define HOOD_PIN 7
#define HOOD_CNT 20


#define POLLING_MS 500

/**
   Instantiate NFC & light components
*/
MFRC522 rfid(SS_PIN, RST_PIN); 

Adafruit_NeoPixel flex = Adafruit_NeoPixel(MATRIX_CNT, MATRIX_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_CNT, STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(STRIP2_CNT, STRIP2_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(STRIP3_CNT, STRIP3_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(STRIP4_CNT, STRIP4_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel hoodStrip = Adafruit_NeoPixel(HOOD_CNT, HOOD_PIN, NEO_GRB + NEO_KHZ800);


/**
   Necessary variables for animations
*/
String animationType;
int timer;
