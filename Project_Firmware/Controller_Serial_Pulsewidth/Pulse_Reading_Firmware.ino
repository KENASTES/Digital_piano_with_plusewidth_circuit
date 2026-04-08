const byte PWM_pin = 5;
int Digital_Read = 5;
int Cool_Down = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PWM_pin, INPUT_PULLUP);
  pinMode(Digital_Read, INPUT);
}

void loop() {
  unsigned long high = pulseIn(PWM_pin, HIGH);
  unsigned long low = pulseIn(PWM_pin, LOW);
  int Read = digitalRead(Digital_Read);
  int Key_value = high*2;
  Serial.println(Key_value);
  
  if(Key_value >= 90 && Key_value <= 98){
    Serial.println("A");
  }else if(Key_value >= 100 && Key_value <= 115){
    Serial.println("B");
  }else if(Key_value >= 120 && Key_value <= 125){
    Serial.println("C");
  }else if(Key_value >= 140 && Key_value <= 150){
    Serial.println("D");
  }else if(Key_value >= 160 && Key_value <= 170){
    Serial.println("E");
  }else if(Key_value >= 176 && Key_value <= 180){
    Serial.println("F");
  }else if(Key_value >= 198 && Key_value <= 210){
    Serial.println("G");
  }else if(Key_value >= 220 && Key_value <= 230){
    Serial.println("H");
  }else if(Key_value >= 246 && Key_value <= 260){
    Serial.println("I");
  }else if(Key_value >= 265 && Key_value <= 285){
    Serial.println("J");
  }else if(Key_value >= 295 && Key_value <= 310){
    Serial.println("K");
  }else if(Key_value >= 320 && Key_value <= 340){
    Serial.println("L");
  }else if(Key_value >= 348 && Key_value <= 360){
    Serial.println("M");
  }else if(Key_value >= 375 && Key_value <= 390){
    Serial.println("N");
  }else if(Key_value >= 399 && Key_value <= 435){
    Serial.println("N");
  }else if(Key_value >= 450 && Key_value <= 470){
    Serial.println("O");
  }else if(Key_value >= 480 && Key_value <= 510){
    Serial.println("P");
  }
  delay(500);
}
