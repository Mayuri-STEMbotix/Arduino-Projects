//L298N motor control pins
const int LeftMotorForward = A0;
const int LeftMotorBackward = A2;
const int RightMotorForward = A4;
const int RightMotorBackward = A5;
 
//Utrasonic sensor pins
#define trig_pin 4 //analog input 1
#define echo_pin 2 //analog input 2

//IR sensor pins
#define ir_out 8

boolean goesForward = false;
int distance = 0;

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  pinMode(trig_pin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echo_pin, INPUT); // Sets the echoPin as an INPUT

  pinMode(ir_out, INPUT); // Sets the IR output pin as an INPUT  
}

void loop(){

  distance = readPing();
    
  if (distance <= 30){
    moveStop();
    delay(600);
    moveBackward();
    delay(600);
    moveStop();
    delay(600);

    turnLeft();

    moveForward(); 
  }

  delay(100);
}

int readPing(){
  int cm = 0;
  long duration = 0;
    // Clears the trig_pin condition
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  // Sets the trig_pin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  // Reads the echo_pin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_pin, HIGH);
  // Calculating the distance
  cm = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

/*  if(digitalRead(ir_out)==1)
  {
  
  }*/
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
/*  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);*/
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
/*  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);*/
}
