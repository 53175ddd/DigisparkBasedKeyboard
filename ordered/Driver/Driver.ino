uint8_t LED_Status;

#define RED_LED    1
#define GREEN_LED  5

void LED_Toggle(const uint8_t led) {
  switch(led){
    case RED_LED:
      if((LED_Status & 0b10) == 0b10) {
        digitalWrite(led,  LOW);
        LED_Status = LED_Status - 0b10;
      }else{
        digitalWrite(led, HIGH);
        LED_Status = LED_Status + 0b10;
      }
    break;

    case GREEN_LED:
      if((LED_Status & 0b01) == 0b01) {
        digitalWrite(led,  LOW);
        LED_Status = LED_Status - 0b01;
      }else{
        digitalWrite(led, HIGH);
        LED_Status = LED_Status + 0b01;
      }
    break;
  }
}

void LED_ON(const uint8_t led) {
  digitalWrite(led, HIGH);
}

void LED_OFF(const uint8_t led) {
  digitalWrite(led,  LOW);
}

void LED_Test(const uint16_t longness) {
  for(uint16_t i = 0; i < longness; i++) {
    digitalWrite(RED_LED  , HIGH);
    digitalWrite(GREEN_LED,  LOW);
    delay(75);
    digitalWrite(RED_LED  ,  LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(75);
  }

  delay(500);

  for(uint16_t i = 0; i < longness; i++) {
    digitalWrite(RED_LED  , HIGH);
    digitalWrite(GREEN_LED, HIGH);
    delay(75);
    digitalWrite(RED_LED  ,  LOW);
    digitalWrite(GREEN_LED,  LOW);
    delay(75);
  }

  delay(500);
}

