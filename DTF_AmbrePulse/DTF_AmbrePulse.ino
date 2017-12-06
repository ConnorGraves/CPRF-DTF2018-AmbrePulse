//Connor Graves
//Cal Poly Rose Float
//Dreams Take Flight (2018)
//Cloud Light Mech - Ambre Pulse

#include <Adafruit_NeoPixel.h>

#define LED_PIN 7 //the pin the signal wire (green) on the LED strip is attached to
#define NUM_PIXELS 150 //the number of LEDs on the strip
#define DELAY_VAL 8 //amount of time delay (milliseconds) between loops. Change to adjust speed of animation

//storage for the color of each pixel
int red[NUM_PIXELS];
int green[NUM_PIXELS];
int blue[NUM_PIXELS];

//change these values to choose the color that fades to white along the strip
int redInit = 255, greenInit = 0, blueInit= 0;


int count = 0; //all lights with adresses less than count will be on, more than count will be off
int offset = 1; //increment count by offset each loop. Value is inverted to change the direction when all lights are turned on or all lights are turned off.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(9600);
  Serial.println("Strip Initialized");
  while (not Serial);
}

void loop() {

  count += offset;
  
  if(count >= 150 || count < 0){
    offset *= -1;
  }
  
  //Serial.println(count);
  for (int i = 0; i < count; i++) {//turn lights below count on
    red[i]   = redInit + ((255 - redInit)/(NUM_PIXELS - 2) * i);
    green[i] = greenInit + ((255 - greenInit)/(NUM_PIXELS - 2) * i);
    blue[i]  = blueInit + ((255 - blueInit)/(NUM_PIXELS - 2) * i);
    pixels.setPixelColor(i, red[i],green[i],blue[i]);
    }
  for (int i = count; i < NUM_PIXELS; i++) {//turn lights above count off
    red[i]   = 0;
    green[i] = 0;
    blue[i]  = 0;
    pixels.setPixelColor(i, red[i],green[i],blue[i]);
    }
    
  delay(DELAY_VAL);
    pixels.show();
}
