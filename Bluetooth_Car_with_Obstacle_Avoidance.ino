/*RLR INVENTIONS
 PLEASE SUBSCRIBE
*/
int val1 = 0;
int val2 = 0;
int val3 = 0;
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop() {
  val1 = digitalRead(6);
  val2 = digitalRead(7);
  val3 = digitalRead(8); 
  if (Serial.available() > 0) {
    char value = Serial.read();
    Serial.println(value);

    if (value == 'F' && val1 == 1 ) {
      forward();
    } else if (value == 'B') {
      backward();
    } else if (value == 'L' && val2 == 1) {
      left();
    } else if (value == 'R' && val3 == 1) {
      right();
    } else {
      Stop();
    }
  }
}

void forward() {
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.print("Front");
  
}
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.print("Back");
}
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.print("Left");
}
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.print("Right");
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
