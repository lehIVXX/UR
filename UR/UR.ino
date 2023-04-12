#define TrigI 9
#define TrigII 11
#define EchoI 10
#define EchoII 12

const int numReadings = 10;
unsigned long startTime;

void setup() {
  //Define inputs and outputs
  StartUR();
}

void loop() {
  int rawValue1= chkDistanceOne(TrigI, EchoI, 5, 255);
  int adjustedValue1= averageValue(rawValue1, 10, 5);
  analogWrite(13,adjustedValue1);

  int rawValue2= chkDistanceOne(TrigII, EchoII, 5, 255);
  int adjustedValue2= averageValue(rawValue2, 20, 2);
  analogWrite(7,adjustedValue1);

/*
  if ( (millis()-startTime)>550 ) {
        Serial.print("Raw1 = ");
        Serial.print(rawValue1);
        Serial.print("Average2 = ");
        Serial.println(adjustedValue1);
        Serial.print("Raw2 = ");
        Serial.print(rawValue2);
        Serial.print("Average2 = ");
        Serial.println(adjustedValue2);
        startTime = millis();
    }*/
  delay(2);
}
/*
void chkDistanceTwo(){
  digitalWrite(TrigII, LOW);
  delayMicroseconds(5);
  digitalWrite(TrigII, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigII, LOW);
  durationII = pulseIn(EchoII, HIGH);
  distanceII = durationII * 0.034 / 2;
  distanceII=constrain(distanceII,10,100);
  int distII=map(distanceII,10,100,8,255);
  distII=constrain(distII,8,255);
}*/