int servoPin = 9; //left servo
int servoPin2 = 10;//right servo
int IRled = 2; //the led that will transmit the IR light
int led = 12;
int IRrecieve = 7; //the IR reciever modole
int IRsignal; //the IR signal that the IR reciever modole return

void setup()
{
  pinMode(servoPin, OUTPUT);//left servo
  pinMode(servoPin2,OUTPUT);//right servo
  pinMode(IRled, OUTPUT);
  pinMode(led, OUTPUT); 
  pinMode(IRrecieve, INPUT); 
  digitalWrite(IRled,LOW);//set tehe IRled to off
  digitalWrite(led, LOW); //set the led to off  
  //Serial.begin(9600);
  
}
int IRreader()
{
   int halfPeriod = 13; // one period of 38kHz is about 26 microseconds
   int cycles = 38; //26 microseconds * 38 is about 1 millisecond
   for (int i = 0; i < cycles; i++)
   {
     digitalWrite(IRled, HIGH);
     delayMicroseconds(halfPeriod);
     digitalWrite(IRled, LOW);
     delayMicroseconds(halfPeriod - 1); //-1 to make up the delay in digitalWrite
    }
    return digitalRead(IRrecieve);
}

void loop()
{
  IRsignal = IRreader();
  if(IRsignal == 1)//if object is not detected
  {
    //The code to move foreard
    digitalWrite(servoPin,HIGH);
    delayMicroseconds(1700);
    digitalWrite(servoPin,LOW);
    digitalWrite(servoPin2,HIGH);
    delayMicroseconds(1300);
    digitalWrite(servoPin2,LOW);
    delay(100);
  }
  else
  {
    //backup
   // digitalWrite(servoPin,HIGH);
   // delayMicroseconds(1300);
    //digitalWrite(servoPin,LOW);
    //digitalWrite(servoPin2,HIGH);
    //delayMicroseconds(1700);
    //digitalWrite(servoPin2,LOW);
    //delay(100);
    
    //turn right
    digitalWrite(servoPin,HIGH);
    delayMicroseconds(1700);
    digitalWrite(servoPin,LOW);
    digitalWrite(servoPin2,HIGH);
    delayMicroseconds(1700);
    digitalWrite(servoPin2,LOW);
    delay(100);
  }

}
