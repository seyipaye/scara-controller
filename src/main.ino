#include <Arduino.h>
#include <SoftwareSerial.h>
// SoftwareSerial esp8266(2, 3);
#define serialCommunicationSpeed 115200
#define DEBUG true
int delay_time = 0;

// Uplaod to UNO

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(serialCommunicationSpeed);
  // esp8266.begin(serialCommunicationSpeed);
  pinMode(LED_BUILTIN, OUTPUT);
}

int data;
// String mee;
// char x;

void loop()
{
  // bool isCommand = false;
  if (Serial.available() > 0)
  {
    int receivedInt;

    // Read the integer from the Serial Monitor
    receivedInt = Serial.parseInt();

    delay_time = receivedInt;
    blink(delay_time);

    // Check if a valid integer was received
    if ((!Serial.available() || Serial.peek() == '\n') && receivedInt != 0)
    {
      // Echo the received integer back to the Serial Monitor
      // Serial.print("You entered: ");
      // Serial.println(receivedInt);
      // delay_time = receivedInt;
      // blink(delay_time);
      // Optionally, you can perform some actions based on the received integer here
    }
  }

  // blink(delay_time);

  //  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  //  delay(delay_time * 1000);                      // wait for a second
  //  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  //  delay(1000);

  // if ((char)x == '\n') {
  //   data = mee.toInt();
  //   Serial.println(data);
  //   mee = "";
  // }

  // if (mySUART.available() > 0)
  // {
  //   Serial.write((char)mySUART.read());
  // }
}

void blink(int numberOfBlinks)
{
  int blinkInterval = 100;

  for (int i = 0; i < numberOfBlinks; i++)
  {
    // Turn the LED on
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(blinkInterval);

    // Turn the LED off
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    delay(200);
  }
}
