#include <Arduino.h>
#include <SoftwareSerial.h>

#define serialCommunicationSpeed 115200
bool debug = true;

// Uplaod to UNO

void setup()
{
  Serial.begin(serialCommunicationSpeed);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    String receivedString = Serial.readString(); // enter is automatically added to the back buffer '\n'

    // Check if a valid string was received
    Serial.print("You entered: ");
    Serial.println(receivedString);
    parse(receivedString);
  }
}

void parse(String content)
{

  // Send a message to the ESP8266
  // Serial.write("change");

  // Extract the data from the string and put into separate integer variables (data[] array)
  int values[10];

  for (int i = 0; i < 10; i++)
  {
    int index = content.indexOf(",");                      // locate the first ","
    values[i] = atol(content.substring(0, index).c_str()); // Extract the number from start to the ","
    content = content.substring(index + 1);                // Remove the number from the string
  }

  // Print the extracted integers
  for (int i = 0; i < 9; i++)
  {
    Serial.print("Value ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println();

    int value = values[i];
    blink(value);
    delay(500);
  }
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
