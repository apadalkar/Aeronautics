#include <TM1637Display.h>

int hallSensorPin = 2; //GPIO pin # used to sample output from hall effect sensor     
int hallSensorValue;
int CLK = 5; //GPIO pin # used to drive clock from arduino to seven segment display
int DIO = 6; //GPIO pin # used to send value to drive on seven segment display


TM1637Display display = TM1637Display(CLK, DIO);


void setup() {
  // put your setup code here, to run once:
  pinMode(hallSensorPin, INPUT); //configure hallSensorPin as input
  display.setBrightness(2);// set brightness; 0-7
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  hallSensorValue = digitalRead(hallSensorPin);
  int counter = 0;
  if (hallSensorValue == 0) {
    counter = counter + 1;
    }
  else {
    counter = counter;
  }
  display.showNumberDec(counter);
  Serial.println(counter);
}