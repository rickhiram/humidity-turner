/* Blink without Delay

 Turns on and off a light emitting diode (LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 11 Nov 2013
 by Scott Fitzgerald
 
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to set a pin number :
const int ledPin2 =  12;      // the number of the LED pin
const int analogInPin = A0;
const int ledPin = 13; // Analog input pin that the potentiometer is attached to

const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int threshold = 40;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int outputValue2 = 0;
// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1800000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 100);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);
//analogWrite(analogOutPin2, outputValue);
  // print the results to the serial monitor:
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue); 
  
  if (outputValue < threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  
  
  // print the analog value:
  //Serial.println(analogValue);
  //delay(1);        // delay in between reads for stability


  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    //if (ledState == LOW)
      ledState = HIGH;
      digitalWrite(ledPin2, ledState);
      delay (5000);
  }
    else{
      ledState = LOW;
  
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin2, ledState);
    
  }
  
}

