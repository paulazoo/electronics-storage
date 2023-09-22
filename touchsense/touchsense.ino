#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); // 10M between pins 4 & 2, pin 2 is sensor pin, add wire, foil

void setup(){
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  Serial.begin(9600);
}

void loop(){

  long start = millis();

  long total1 = cs_4_2.capacitiveSensor(30);

  //Serial.print(millis() - start); // check on performance in milliseconds
  //Serial.print("\t"); // tab character for debug window spacing
  Serial.println(total1); // print sensor output 1

  delay(30); // arbitrary delay to limit data to serial port

}