#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); // 10M between pins 4 & 2, pin 4 is recieve pin, pin 2 is sensor pin with wire/foil

int led = 9; // led pin
int state = HIGH;

boolean yes;
boolean previous = false;

long time = 0;
int debounce = 200;

void setup(){
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1
  Serial.begin(9600); // begin serial monitor

  pinMode(led, OUTPUT);
}

void loop(){
  long total1 = cs_4_2.capacitiveSensor(30); // capacitative sensor output

  Serial.println(total1); // print sensor output 1

  if (total1 > 1000){yes = true;} // set threshold experimentally
  else {yes = false;}

  if(yes == true && \
  previous == false && \
  (millis() - time) > debounce){
    if(state == LOW){
      state = HIGH;
    }
    else { 
      state = LOW;
      time = millis();    
    } 
  }
    
  digitalWrite(led, state);
  previous = yes;

  delay(30); // arbitrary delay to limit data to serial port
}

