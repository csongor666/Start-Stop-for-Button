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


  // determine if the button is pressed and assign button state
  if (reading == HIGH && previous == LOW && (millis() - stateTime) > debounce)
  {
    Serial.println("Bunnon PUSHED");
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

  // start/stop writing data to SD card when button is pressed
  if (state == LOW)
  {
    Serial.println("PROGRAM RUNNING");

  }

  // update previous button state reading
  previous = reading;
}
