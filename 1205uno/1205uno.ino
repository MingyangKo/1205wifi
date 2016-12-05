#include <Wire.h>

#define LEDR 5
#define LEDG 6
#define LEDB 3

void turnoff(){
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
}

void setup() {
  Wire.begin(8); // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200); // start serial for output
}


void loop() {
delay(100);
}


// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {

int r = Wire.read(); // receive byte as an integer
Serial.println(r); // print the integer
int g = Wire.read(); // receive byte as an integer
Serial.println(g); // print the integer
int b = Wire.read(); // receive byte as an integer
Serial.println(b); // print the integer

analogWrite(LEDR,r);
analogWrite(LEDG,g);
analogWrite(LEDB,b);
}

