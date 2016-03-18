// D4 == P0_21

volatile bool bbutton_status;

void button_status_isr() {
  bbutton_status = !bbutton_status;
}

void setup() {
  Serial.begin(115200);
  pinMode(D4, INPUT_PULLUP);
  /* attachInterrupt(D4, button_status_isr, FALLING);  // working */
  /* attachInterrupt(D4, button_status_isr, RISING);  // working  */
  attachInterrupt(D4, button_status_isr, CHANGE); // working
  
}

void loop() {
  Serial.print("button : ");
  Serial.println(bbutton_status);
  delay(1000);
}
