int trig=13;
int echo=12;
int sig1=10;
int sig2=9;

void setup()
{
  Serial.begin (9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(sig1,OUTPUT);
  pinMode(sig2,OUTPUT);
}

void loop()
{
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
  if (distance<15){ 
    digitalWrite(sig2, LOW);
    digitalWrite(sig1, HIGH);
  }
  else { 
    digitalWrite(sig1, LOW);
    digitalWrite(sig2, HIGH);
    }
  
}

