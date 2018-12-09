#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //TX, RX respetively
String readdata;
// defines pins numbers
const int trigPin = 4;
const int echoPin = 3;
// defines variables
long duration;
float distance;


void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(8, OUTPUT);  //in1
  pinMode(9, OUTPUT);  //in2
  pinMode(5, OUTPUT);  //in3
  pinMode(6, OUTPUT);   //in4
  pinMode(12, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

}
//-----------------------------------------------------------------------//
void loop()
{

  //digitalWrite(12, HIGH);
  while (BT.available())
  {
    //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = BT.read(); //Conduct a serial read
    if (c == '#') {
      break; //Exit the loop when the # is detected after the word
    }
    readdata += c; //build the string- "forward", "reverse", "left" and "right"
  }
  if (readdata.length() > 0)
  {

    if (readdata == "*turn right" || readdata == "right")
    {
      digitalWrite(8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(100);
    }

    else if (readdata == "*turn left" || readdata == "left")
    {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      delay(100);
    }

    else if (readdata == "*go ahead" || readdata == "forward")
    {
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite (5, HIGH);
      digitalWrite (6, LOW);
      delay (100);

    }

    else if ( readdata == "*go back" || readdata == "reverse")
    {
      digitalWrite (8, LOW);
      digitalWrite (9, HIGH);
      digitalWrite (5, LOW);
      digitalWrite (6, HIGH);
      delay (100);
    }

    else if (readdata == "*stop" || readdata == "stop")
    {
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
      delay (100);
    }

    else if (readdata == "*hello")
    {
      for (int i = 0; i < 4; ++i)
      {
        digitalWrite(8, HIGH);
        digitalWrite (9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay (100);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);

        delay(100);
      }

      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
      delay (100);
    }

    else if (readdata == "*good boy" || readdata == "*lovely boy")
    {
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite (5, HIGH);
      digitalWrite (6, LOW);
      delay (500);
      digitalWrite (8, LOW);
      digitalWrite (9, HIGH);
      digitalWrite (5, LOW);
      digitalWrite (6, HIGH);
      delay (500);
      digitalWrite(8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(1500);
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
    }

    while (readdata == "*automatic" || readdata == "auto")
    {
      // Clears the trigPin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance = (duration / 2) / 29;

      Serial.println(distance);

      if (distance >= 25)
      {
        digitalWrite (8, HIGH);
        digitalWrite (9, LOW);
        digitalWrite (5, HIGH);
        digitalWrite (6, LOW);
      }

      else if (distance < 25)
      {
        digitalWrite (8, LOW);
        digitalWrite (9, LOW);
        digitalWrite (5, LOW);
        digitalWrite (6, LOW);
        delay (1000);

        digitalWrite (8, LOW);
        digitalWrite (9, HIGH);
        digitalWrite (5, LOW);
        digitalWrite (6, HIGH);
        delay (1000);


        digitalWrite(8, HIGH);
        digitalWrite (9, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(1000);

        digitalWrite (8, LOW);
        digitalWrite (9, LOW);
        digitalWrite (5, LOW);
        digitalWrite (6, LOW);
        delay (1000);

        // Clears the trigPin
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(echoPin, HIGH);
        // Calculating the distance
        distance = (duration / 2) / 29;
        delay(2000);

        if (distance < 25)
        {
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(6, LOW);
          delay(2000);

          digitalWrite (8, LOW);
          digitalWrite (9, LOW);
          digitalWrite (5, LOW);
          digitalWrite (6, LOW);
          delay (1000);


          // Clears the trigPin
          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);
          // Sets the trigPin on HIGH state for 10 micro seconds
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          // Reads the echoPin, returns the sound wave travel time in microseconds
          duration = pulseIn(echoPin, HIGH);
          // Calculating the distance
          distance = (duration / 2) / 29;
          delay(2000);
        }

        else if (distance < 25)
        {
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(6, LOW);
          delay(1000);
        }
      }
    }


    readdata = "";
  }
} //Reset the variable
