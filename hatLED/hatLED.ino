// constants won't change. They're used here to set pin numbers:

const int front_light = 0;      // the number of the LED pin
const int rear_light = 1;      // the number of the LED pin
const int buttonPin = 2;    // the number of the pushbutton pin
const int speakerPin = 3;    // the number of the speaker pin

int counter = 0;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(front_light, OUTPUT);

  // set initial LED state
  //  analogWrite(front_light, 255*ledState);

  // get initial button press position
  lastButtonState = digitalRead(buttonPin);
}

void loop() {
  //  analogWrite(speakerPin, 255);
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      //      // only toggle the LED if the new button state is HIGH
      //      if (buttonState == HIGH) {
      ledState = !ledState;
      counter += 1;
      play_tone(counter);
      //      }
    }
  }


  if (counter == 1) {
    front_light_on();
  }

  else if (counter == 2) {
    rear_light_on();
  }

  else if (counter == 3) {
    flash_rear_light();
  }

  else if (counter == 4) {
    both_lights_off();
    counter = 0;
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

void play_tone(int counter)
{
  if (counter == 4) {
    analogWrite(speakerPin, 180);
    delay(400);
    analogWrite(speakerPin, 0);
  }
  else {

    for (int i = 0; i < counter; i++) {
      analogWrite(speakerPin, 180);
      delay(80);
      analogWrite(speakerPin, 0);
      delay(80);
    }
  }
}

void front_light_on()
{
  analogWrite(front_light, 255);
}

void rear_light_on()
{
  analogWrite(rear_light, 255);
}

void front_light_off()
{
  analogWrite(front_light, 0);
}

void rear_light_off()
{
  analogWrite(rear_light, 0);
}

void both_lights_off()
{
  analogWrite(rear_light, 0);
  analogWrite(front_light, 0);
}

void both_lights_on()
{
  analogWrite(rear_light, 255);
  analogWrite(front_light, 255);
}


void flash_rear_light()
{
  int delay_val = 100;
  analogWrite(rear_light, 255);
  delay(delay_val);
  analogWrite(rear_light, 0);
  delay(delay_val);
}
