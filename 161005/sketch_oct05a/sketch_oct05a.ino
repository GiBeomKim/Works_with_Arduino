void setup() {
   pinMode(11, OUTPUT);
   pinMode(7, INPUT);
}

void loop() {
  if(digitalRead(7)==LOW){
    while(!digitalRead(7));
    digitalWrite(11,!digitalRead(11));
    }
  else if(digitalRead(7)==HIGH){
    digitalWrite(11,HIGH);
    }
   else {
    digitalWrite(11,LOW);
    }
}
