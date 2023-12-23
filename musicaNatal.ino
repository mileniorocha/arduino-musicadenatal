// Definição de pinos
const int buzzer = 8;
const int led1 = 6;
const int led2 = 7;

// Definição de constantes
const int flag_comprimento = 26;
const char notes[] = "eeeeeeegcde fffffeeeeddedg";
const int beats[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
const int tempo = 300;

boolean ledOn = true;

// Protótipos de funções
void playTone(int tone, int duracao);
void playNote(char note, int duracao);
void setupPins();
void blinky();

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  for (int i = 0; i < flag_comprimento; i++) {
    if (notes[i] == ' ') {
      // Descanso
      delay(beats[i] * tempo);
      blinky();
    } else {
      playNote(notes[i], beats[i] * tempo);
      blinky();
    }

    // Pausa entre as notas
    delay(tempo / 3);
  }
}

void playTone(int tone, int duracao) {
  for (long i = 0; i < duracao * 1000L; i += tone * 2) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duracao) {
  const char noteNames[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
  const int noteTones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};

  // Toca a nota correspondente ao nome da nota
  for (int i = 0; i < 8; i++) {
    if (noteNames[i] == note) {
      playTone(noteTones[i], duracao);
    }
  }
}

void blinky() {
  if (ledOn) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
  }
  ledOn = !ledOn;
}