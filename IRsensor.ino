//#include "Keyboard.h"
int ledPin1 =  5;// IR 1
int ledPin2 = 3 ;// IR 2
int led = 13;// IN built led
int sensorPin = 4; int sensorPin2 = 2;// Iput of sensors
int val = 0, val2 = 0;
int ledState1 = LOW;             // ledState used to set the LED1
int ledState2 = LOW;// ledState used to set the LED2
double previousMillis1 = 0;// will store time of LED2 was updated
double previousMillis2 = 0;        // will store time of LED2 was updated
double OnTime1 = ((1000.00 / 10) / 2);       // milliseconds of on-time
double OffTime1 = ((1000.00 / 10) / 2);      // milliseconds of off-time
int R = 0, L = 0;
int countL = 0, countR = 0;

int left(int x) {
  if (x == 1) {
    //Serial.print("Low");

    digitalWrite(led, LOW);

    delay(1);
    return 0;
  }
  if (x == 0 ) {


    digitalWrite(led, HIGH);

    delay(5);
    return 1;
  }

  Serial.println(val);
}

int right(int y) {
  if (y == 1) {
    digitalWrite(led, LOW);
    delay(1);
    return 0;
  }

  if (y == 0 ) {
    digitalWrite(led, HIGH);

    delay(5);
    return 1;
  }

  Serial.println(val);
}



void setup()
{
  //  Keyboard.begin();
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode( sensorPin2, INPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);      // open the serial port at 9600 bps:
}

void loop()
{
  // check to see if it's time to change the state of the LED

  double currentMillis = micros() / 1700.0;

  if ((ledState1 == HIGH ) && (currentMillis - previousMillis1 >= OnTime1))
  {
    ledState1 = LOW;

    // Turn it off
    previousMillis1 = currentMillis;  // Remember the time
    digitalWrite(ledPin1, ledState1);

    // Update the actual LED
    //Serial.print(previousMillis1);
  }

  else if ((ledState1 == LOW ) && (currentMillis - previousMillis1 >= OffTime1))
  {

    ledState1 = HIGH;  // turn it on

    previousMillis1 = currentMillis; // Remember the time

    digitalWrite(ledPin1, ledState1);      // Update the actual LED

  }
  double currentMillis2 = micros() / 1700.0;

  if ((ledState1 == HIGH ) && (currentMillis2 - previousMillis2 >= OnTime1))
  {
    ledState2 = LOW;

    // Turn it off
    previousMillis2 = currentMillis2;  // Remember the time
    digitalWrite(ledPin2, ledState2);

    // Update the actual LED
    //Serial.print(previousMillis1);
  }

  else if ((ledState1 == LOW ) && (currentMillis2 - previousMillis2 >= OffTime1))
  {

    ledState2 = HIGH;  // turn it on

    previousMillis2 = currentMillis2; // Remember the time

    digitalWrite(ledPin2, ledState2);      // Update the actual LED

  } delay(10);
  countL = 0;
  val = digitalRead(sensorPin);
  L = left(val);
  if (countL == 0)
    if ( ledState1 == HIGH && L == 1 ) {

      Serial.println("2");
      countL = 1;
    } else {
      Serial.println("0");
    }
  delay(8);
  countR = 0;
  val2 = digitalRead(sensorPin2);
  R = right(val2);
  if (countR == 0)
    if ( ledState2 == HIGH && R == 1 ) {
      countR = 1;
      Serial.println("1");

    } else {
      Serial.println("0");
    }

}
