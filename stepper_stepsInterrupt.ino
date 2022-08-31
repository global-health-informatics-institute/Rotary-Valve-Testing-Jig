// defines pins numbers
const int stepPin = 11; // STEP PIN
const int dirPin = 12; // DIRECTION PIN

const byte ledPin = 2; // LED PIN

const byte interruptPin = 3; // HALL EFFECT SENSOR PIN

volatile byte state = HIGH;

int val = 0;

void homefunction() {

  // Move motor until home position reached
  while (digitalRead(interruptPin) == 1) {


    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
}


void setup() {
  pinMode(ledPin, OUTPUT);

  pinMode(interruptPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin), halt, CHANGE);
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction, LOW OR HIGH
  digitalWrite(ledPin, state); //Led has the declared state value

  homefunction();
  delay(2000) ;
}

void loop() {

  stepper(380) ; //1520 steps for a full rotation, 380 steps for 90 degrees
  delay(3000) ;

}

void stepper (int x) {
  for (int counter = 0; counter < x; counter ++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000); // USED TO CHANGE SPEED (1000 FOR THE DELVIBISS STEPPER MOTOR)
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
}
void halt() {

  state = !state ;  // Toggle the state of the led when the interrupt occurs
  digitalWrite(ledPin, state) ;
  /*while (digitalRead(interruptPin) == 0) { // switch off motor when magnet is detected
    digitalWrite(stepPin, HIGH) ;
    }*/
  // delay(2000);
  // val++;
}
