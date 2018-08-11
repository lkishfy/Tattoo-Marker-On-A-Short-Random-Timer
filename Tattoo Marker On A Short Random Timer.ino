#include <Wire.h>
#include <SoftwareSerial.h>
const int rx = 3;
const int tx = 4;

SoftwareSerial mySerial(rx, tx);

long randOn = 0;

int STBY = 2; //standby

//Motor A
int PWMA = 1; //Speed control
int AIN1 = 0; //Direction
int LED = 4;



void setup() {
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);

}

void loop() {
randOn = random (3000, 5000);    // generate ON time between 3 and 5 seconds
move(1,255,1);
delay(randOn);
LEDcode();
stop();
delay(5000);
}


void move(int motor, int speed, int direction) {
  //Move specific motor at speed and direction
  //motor: 0 for B 1 for A
  //speed: 0 is off, and 255 is full speed
  //direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (direction == 1) {
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if (motor == 1) {
    digitalWrite(AIN1, inPin1);
    analogWrite(PWMA, speed);
  
  }
}

void stop() {
  //enable standby
  digitalWrite(STBY, LOW);
}


void LEDcode() {
digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(1000);              // wait for a second
digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(250); 
digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
delay(250); 
digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(250); 
digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
delay(100); 
digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(100); 
digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
delay(100); 
digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(100); 
digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
delay(100); 
digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(100); 
digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
delay(75); 
digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(75); 
digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
delay(75); 
digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(75); 
}
    
   


