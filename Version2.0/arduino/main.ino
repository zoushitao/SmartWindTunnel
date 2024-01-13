#include <Arduino_JSON.h>



#include "SmartWindDriver.hpp"

String test = "sd ";

auto fan = SmartWindDriver();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);
  
  fan.waveModeInit(20, 4090, vertical);

}

void loop() {
  // put your main code here, to run repeatedly:
  //fan.waveModeUpdate();
  
  Serial.println(test);
  delay(1000);

}

void JsonTest(){
  JSONVar myObject;
  myObject["mode"] = "even";
  myObject["speed"][0] = 2455;
  myObject["speed"][1] = 245235;
  Serial.print("myObject = ");
  Serial.println(myObject);
}