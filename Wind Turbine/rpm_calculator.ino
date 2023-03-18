#include <TM1637Display.h>

int hallSensorPin = 2; // GPIO pin # used to sample output from hall effect sensor
int hallSensorValue;
int CLK = 5; // GPIO pin # used to drive clock from arduino to seven segment display
int DIO = 6; // GPIO pin # used to send value to drive on seven segment display

TM1637Display display = TM1637Display(CLK, DIO);

void setup()
{
  // put your setup code here, to run once:
  pinMode(hallSensorPin, INPUT); // configure hallSensorPin as input
  display.setBrightness(2);      // set brightness; 0-7
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  float start_time = micros();
  bool on_state = false;
  hallSensorValue = digitalRead(hallSensorPin);
  float counter = 1.0;
  while (true)
  {
    if (hallSensorValue == 0)
    {
      if (on_state == false)
      {
        on_state = true;
        counter = counter + 1.0;
      }
    }
    else
    {
      on_state = false;
    }
  }

  float end_time = micros();
  float time_passed = ((end_time - start_time) / 1000000.0);
  Serial.print("Time Passed: ");
  Serial.print(time_passed);
  float rpm_val = (counter / time_passed) * 60.0;
  Serial.print(rpm_val);
  Serial.println(" RPM");
  delay(1); // for stability
  display.showNumberDec(rpm_val);
}
