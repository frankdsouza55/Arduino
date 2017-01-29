int trig=13;
int echo=12;
int i;
//int led1,led2,led3,led4,led5,led6;

void setup() {
  Serial.begin (9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  for(i=30;i<=40;i=i+2)
  pinMode(i,OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
  
  if(distance<30){
    digitalWrite(30,HIGH);
    delay(10);
    digitalWrite(30,LOW);
  }
  if(distance<25){
    for(i=30;i<=32;i+=2)
    digitalWrite(i,HIGH);
    delay(10);
    for(i=30;i<=32;i+=2)
    digitalWrite(i,LOW);
  }
    if(distance<20){
    for(i=30;i<=34;i+=2)
    digitalWrite(i,HIGH);
    delay(10);
    for(i=30;i<=34;i+=2)
    digitalWrite(i,LOW);
  }
    if(distance<15){
    for(i=30;i<=36;i+=2)
    digitalWrite(i,HIGH);
    delay(10);
    for(i=30;i<=36;i+=2)
    digitalWrite(i,LOW);
  }
    if(distance<10){
    for(i=30;i<=38;i+=2)
    digitalWrite(i,HIGH);
    delay(10);
    for(i=30;i<=38;i+=2)
    digitalWrite(i,LOW);
  }
    if(distance<5){
    for(i=30;i<=40;i+=2)
    digitalWrite(i,HIGH);
    delay(10);
    for(i=30;i<=40;i+=2)
    digitalWrite(i,LOW);
  }
  }
  
