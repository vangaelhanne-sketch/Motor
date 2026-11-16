// Zelfrijdende auto met L298N H-brug (6 draden)
// Volgorde: 2 s vooruit -> 2 s links -> 2 s rechts -> 2 s achteruit -> herhalen
//
// Aansluiting L298N -> Arduino (draden van links naar rechts):
//   ENA (linkste draad) -> pin 9   aan/uit motor 1
//   IN1                 -> pin 5   motor 1
//   IN2                 -> pin 6   motor 1
//   IN3                 -> pin 4   motor 2
//   IN4                 -> pin 3   motor 2
//   ENB (rechtse draad) -> pin 10  aan/uit motor 2
//   GND van de L298N ook verbinden met GND van de Arduino!
//
// Zitten jullie draden op andere pinnen? Pas dan alleen de nummers hieronder aan.

const int ENA = 9;
const int IN1 = 6;
const int IN2 = 5;
const int IN3 = 4;
const int IN4 = 3;
const int ENB = 10;

const int TIJD = 2000;   // 2 seconden

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  //digitalWrite(ENA, HIGH);   // motor 1 aanzetten
  //digitalWrite(ENB, HIGH);   // motor 2 aanzetten

  stoppen();
  delay(1000);               // 1 s wachten voor de start
}

void loop() {
  vooruit();
  delay(2000);
  delay(TIJD);

  links();                   // motor 1 vooruit, motor 2 achteruit
  delay(TIJD);

  rechts();                  // motor 1 achteruit, motor 2 vooruit
  delay(TIJD);

  achteruit();
  delay(TIJD);

  stoppen();
  delay(1000);               // korte pauze, daarna opnieuw
  
}

// ---------- bewegingen ----------

void vooruit() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void achteruit() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void rechts() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, HIGH);   // motor 1 vooruit
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);    // motor 2 achteruit
  digitalWrite(IN4, HIGH);
}

void links() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);    // motor 1 achteruit
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);   // motor 2 vooruit
  digitalWrite(IN4, LOW);
}

void stoppen() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}