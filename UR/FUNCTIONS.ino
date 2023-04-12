
long durationI = 0;
int distanceI = 0;
long durationII = 0;
int distanceII = 0;
unsigned long loopCount;
//unsigned long startTime;

void StartUR(){
  Serial.begin(57600);
  pinMode(TrigI, OUTPUT);
  pinMode(EchoI, INPUT);
  pinMode(TrigII, OUTPUT);
  pinMode(EchoII, INPUT);
  startTime = millis();
  delay(750);
  Serial.println("HOSHH");























   
}

int chkDistanceOne(int TRIGGER, int ECHO, int rawMin, int rawMax){

  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  long dur = pulseIn(ECHO, HIGH);
  int dist = dur * 0.034 / 2;
  dist = constrain(dist,rawMin,rawMax);
  delay(2);
  Serial.println(dist);
  return dist;
}
int averageValue(int INVAL, int NUMREADINGS, int StabilityDelay){
int readIndexI =0;
int readingsI[NUMREADINGS];  // the readings from the analog input
//int totalI = ;              // the running total
//int averageI = ; 
 for (int i = 0; i < numReadings; i++) {
    readingsI[i] = 0;
  }
int totalI = totalI - readingsI[readIndexI];
  readingsI[readIndexI] = INVAL;
  totalI = totalI + readingsI[readIndexI];
  readIndexI = readIndexI + 1;
  if (readIndexI >= numReadings) {
    readIndexI = 0;
  }
 int averageI = totalI / numReadings;
  delay(StabilityDelay);
  return averageI;
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