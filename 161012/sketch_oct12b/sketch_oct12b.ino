void setup(void) {
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop(void) {
  unsigned int i = analogRead(A0);

  analogWrite(11, i/4); //들어오는 값은 10bit인데 analogWrite는 8비트이므로 /4해야 에러가 나지 않는다.

  Serial.println(i);

  delay(100);

}
