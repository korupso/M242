int IN1 = 1;
int IN2 = 2;
int IN3 = 3;
int IN4 = 4;

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(500);
}

void loop()
{
    digitalWrite(IN1, LOW);
    delay(1000);
    digitalWrite(IN1, HIGH);
    delay(1000);
    digitalWrite(IN2, LOW);
    delay(1000);
    digitalWrite(IN2, HIGH);
    delay(1000);
    digitalWrite(IN3, LOW);
    delay(1000);
    digitalWrite(IN3, HIGH);
    delay(1000);
    digitalWrite(IN4, LOW);
    delay(1000);
    digitalWrite(IN4, HIGH);
    delay(1000);
}