#include <CapacitiveSensor.h>
#include <Tone.h>
Tone tone1;

#define DO 130
#define RE 147
#define MI 165
#define FA 174
#define SOL 196
#define LA 220
#define SI 247

float i;
float st;
int led = 4;// LED connected to digital pin 4
int flag;

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_3 = CapacitiveSensor(4,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired


   int seq;
void setup()                    
{
   seq = 0;
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   tone1.begin(11);//Playback on Pin 11, change to whatever you may need
   flag = 0;
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_3.capacitiveSensor(30);
    long total3 =  cs_4_5.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");                  // print sensor output 1
    Serial.print(total2);                  // print sensor output 1
    Serial.print("\t");                  // print sensor output 1
    Serial.println(total3);                  // print sensor output 1
    if (total1 > 350) tone1.play(330,40);
    if (total2 > 800) tone1.play(440,40);
    if (total3 > 800) tone1.play(660,40);

    delay(10);                             // arbitrary delay to limit data to serial port 
}
