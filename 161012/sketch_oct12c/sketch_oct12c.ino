void setup(void) {
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop(void) {
  unsigned int i = analogRead(A0); //i는 0~1023

  /*
  if(i>900) {
    analogWrite(11, 255);
    Serial.println("4");
  }
  else if (i>700) {
    analogWrite(11, 180);
    Serial.println("3");
  }
  else if (i>500) {
    analogWrite(11, 120);
    Serial.println("2");
  }
  else if (i>300){
    analogWrite(11, 60);
    Serial.println("1");
  }
  else {
    analogWrite(11, 0);
    Serial.println("0");
  }
  */

  i = map(i, 0, 1023, 0, 3); //0부터 1023까지의 값을 0부터 3으로
  Serial.println(i);
  i=map(i, 0, 3, 0, 255);
  analogWrite(11, i);
  

  delay(100);
}
