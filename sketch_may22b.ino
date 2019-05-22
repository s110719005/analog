#define high 920
#define low 700
const int analogPin = A0;
const int ledCount = 10;
int ledPins[] = {2,3,4,5,6,7,8,9,10,11};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int LED = 0;LED <ledCount;LED++){
    pinMode(ledPins[LED],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  int READ = analogRead(analogPin);
  //if(READ >high) READ = high;
  //if(READ < low) READ = low;
  int LEVEL = map(READ,low,high,0,ledCount);
  for(int LED = 0;LED<ledCount;LED++){
    if(LED<=LEVEL){
      digitalWrite(ledPins[LED],HIGH);  
  }
  else{
    digitalWrite(ledPins[LED],LOW);
  }
    
  }
  Serial.println(value);
  delay(1);
}
