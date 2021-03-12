#define LED_PIN 13

///////////////////////////
// This is the message that
// will be transmitted.
char message[] = "Hello";
///////////////////////////

void parseMessage(char message[], int messageSize) {
   for (int i = 0; i < messageSize; i++) {
      char *command = getMorseCommand(message[i]);
      executeMorseCommand(command, strlen(command));
   }
}

// this can be optimized
char * getMorseCommand(char letter) {
  Serial.print(letter + " ");
  letter = toupper(letter);
  switch (letter) {
    case 'A' :
      return ".-";
    case 'B' :
      return "-...";
    case 'C' :
      return "-.-.";
    case 'D' : 
      return "-..";
    case 'E' :
      return ".";
    case 'F' :
      return "..-.";
    case 'G' : 
      return "--.";
    case 'H' :
      return "....";
    case 'I' : 
      return "..";
    case 'J' : 
      return ".---";
    case 'K' :
      return "-.-";
    case 'L' : 
      return ".-..";
    case 'M' :
      return "--";
    case 'N' :
      return "-.";
    case 'O' :
      return "---";
    case 'P' : 
      return ".--.";
    case 'Q' : 
      return "--.-";
    case 'R' :
      return ".-.";
    case 'S' :
      return "...";
    case 'T' :
      return "-";
    case 'U' :
      return "..-";
    case 'V' :
      return "...-";
    case 'W' :
      return ".--";
    case 'X' :
      return "-..-";
    case 'Y' :
      return "-.--";
    case 'Z' :
      return "--..";
    case ' ' :
      return " ";
  }
}

void executeMorseCommand(char command[], int commandSize) {
  for (int i = 0; i < commandSize; i++) {
    if (command[i] == '.') {
      dotBlink();
    }
    else if (command[i] == '-') {
      dashBlink();
    }
    else if (command[i] == ' ') {
      delay(7000); // 7 seconds between words
    }
  }
  delay(3000); // 3 seconds between letters
}

// dash = 3 second blink
void dashBlink() {
  digitalWrite(LED_PIN, HIGH);
  delay(3000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

// dot = 1 second blink
void dotBlink() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  parseMessage(message, sizeof(message) / sizeof(*message));
}
