//박수로 LED 껐다 키기

const int pinLED = 11;
const int pinVOL = A0;
const int pinMIC = A1;

const int clap = 200;

void setup(void) {
  pinMode(pinLED, OUTPUT);
  pinMode(pinVOL, INPUT);
  pinMode(pinMIC, INPUT);

  Serial.begin(9600);
}

  unsigned static int status_led = 0;

void loop(void) {
  unsigned int volum_mic = analogRead(pinMIC);
  unsigned int volum_vol = analogRead(pinVOL);

  if(volum_mic > clap){
    if(status_led == 0) status_led = 1;
    else                status_led = 0;

     if(status_led == 0) {
      volum_vol = map(volum_vol, 0, 1023, 100, 255);
      analogWrite(pinLED, 255);
      Serial.println("ON");
     }
     else {
      analogWrite(pinLED, 0);
      Serial.println("OFF");
     }
     
     delay(500);
    }

    if(status_led == 0) {
      volum_vol = map(volum_vol, 0, 1023, 100, 255);
      analogWrite(pinLED, volum_vol);
     }


  /*
  Serial.print("MIC = ");
  Serial.print(volum_mic);
  Serial.print(" VOL = ");
  Serial.println(volum_vol);
  */
}
