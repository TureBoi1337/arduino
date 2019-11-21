const int btnPin = 2;
const int greenPin = 13;
const int yellowPin = 12;
const int redPin = 11;

int btnState = 0;


void setup() {
  Serial.begin(9600);
  pinMode(btnPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  (btnState = digitalRead(btnPin));

  if(btnState == HIGH)
  {
  ledOff(greenPin);
  ledOn(yellowPin);
  delay(1000);
  ledOff(yellowPin);
  ledOn(redPin);
  delay(4000);
  ledOn(yellowPin);
  delay(1000);
  } else {
    ledOff(redPin);
    ledOff(yellowPin);
    ledOn(greenPin);
  }
}

void ledOn(int pin) {
  digitalWrite(pin, HIGH);
  Serial.print("ledPin : ");
  Serial.print(pin);
  Serial.print("is on");

}
void ledOff (int pin) {
  digitalWrite(pin, LOW);
  Serial.print("LedPin : ");
  Serial.print(pin);
  Serial.println(" is off");
}

void blinkLed(int pin, int millisec) {
  ledOn(pin);
  delay(millisec);
  ledOff(pin);
  delay(millisec);

}