int a;
int b;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  a = 0;
  b = 1;
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(a += b);
  digitalWrite(LED_BUILTIN, LOW);
  delay(b += a);
}
