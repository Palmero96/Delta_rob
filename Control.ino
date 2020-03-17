// Pinout utilizado
#define step_en 8
#define pulse_x 5
#define dir_x 2
// Paso utilizado 16th

void setup() {
  Serial.begin(9600);
  pinMode(pulse_x, OUTPUT);
  pinMode(dir_x, OUTPUT);
  pinMode(step_en, OUTPUT);

  // Init conf
  digitalWrite(step_en, HIGH);
  digitalWrite(dir_x, LOW);
  digitalWrite(pulse_x, LOW);

  Serial.println("Init - Steppers disabled");
}

bool flag = false;

void loop() {
  // Lectura del puerto serie para la ejecucción de acciones
  if (Serial.available() > 0){
    char a;
    a = Serial.read();

    switch(a){
      case 's':
      case 'S':
        Serial.println("Enable steppers");
        digitalWrite(step_en, LOW);
        break;
      case 'a':
      case 'A':
        Serial.println("Disable steppers");
        digitalWrite(step_en, HIGH);
        break;
      case '0':
        Serial.println("Dirección 0");
        digitalWrite(dir_x, LOW);
        break;
      case '1':
        Serial.println("Dirección 1");
        digitalWrite(dir_x, HIGH);
        break;
      case '2':
        Serial.println("Move");
        flag = true;
        break;
    }
  }

  // Ejecución de movimientos
  if (flag==true){
    for (int i=0; i<200; i++){
      digitalWrite(pulse_x, HIGH);
      delay(1);
      digitalWrite(pulse_x, LOW);
      delay(1);
    }

    flag = false;
  }
}
