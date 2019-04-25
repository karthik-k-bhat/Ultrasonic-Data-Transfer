#define echo 2
#define trig 3

long duration;
int distance;

void setup()
{
   pinMode(trig, OUTPUT);
   pinMode(echo, INPUT);
   Serial.begin(9600);
}

void loop()
{
   digitalWrite(trig, LOW);
   delayMicroseconds(2);   
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   duration = pulseIn(echo, HIGH);
   distance = duration*0.034/2;
   Serial.println(distance);
}
