
#include <IRremote.hpp>
#define irpin 1

IRrecv irrecv(irpin);
decode_results results;

void setup() {
  irrecv.enableIRIn();
}

void loop() {
    if(irrecv.decode(&results)) {
      Serial.println(results.value, HEX);
      irrecv.resume();
    }
}
