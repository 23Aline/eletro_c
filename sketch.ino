const int ledPin = 17;
int piscar = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  pinMode(ledPin, OUTPUT);  //Configura o pino do LED como saída

  Serial.println("Insira o número de vezes que deseja que o Led pisque: ");

}

void loop() {
  //Verifica se há dados disponíveis na serial
  if (Serial.available() > 0) {
    piscar = Serial.parseInt();

    // Verifica se o número é válido (maior que 0)
    if (piscar > 0) {
      Serial.print("Piscar o LED " + String(piscar) + " vezes.");

      // Pisca o LED o número de vezes especificado
      for (int i = 0; i < piscar; i++) {
        digitalWrite(ledPin, HIGH); 
        Serial.println("LED ON");
        delay(500);                  
        digitalWrite(ledPin, LOW);  
        Serial.println("LED OFF"); 
        delay(500);                  
      }
    } else {
      // Caso o usuário insira um valor inválido
      Serial.println("Número inválido, por favor insira um valor maior que 0!");
    }
    Serial.println("Digite quantas vezes deseja que o Led pisque novamente: ");
  }
}

