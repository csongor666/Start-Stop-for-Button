int reading = LOW;
int state = HIGH;
int previous = LOW;
int buttonPin = 2;
int stateTime = 0;
int debounce = 100;


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the pushbutton input pin
  reading = digitalRead(buttonPin);


  // determine if the button is pressed with debounce
  if (reading == HIGH && previous == LOW && (millis() - stateTime) > debounce)
  {
    Serial.println("Button PUSHED");
    if (state == HIGH)
    {
      state = LOW;
      Serial.println("Status changed to LOW");
    }
    else {
      state = HIGH;
      Serial.println("Status changed to HIGH");
    }
    stateTime = millis();
  }

  
  if (state == LOW)
  {
    Serial.println("PROGRAM RUNNING"); //Put here the program you want to run till button pushed again 

  }

  // update previous button state reading
  previous = reading;
}
