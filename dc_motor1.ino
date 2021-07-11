// C++ code

// rotation direction
int rot_direction1_a = 5;
int rot_direction2_a = 6;
int rot_direction1_b = 10;
int rot_direction2_b = 9;
int potntiometerA0 = A0;

void setup()
{
  // Serial.begin(9600);
  pinMode(potntiometerA0, INPUT);
  pinMode(rot_direction1_b, OUTPUT);
  pinMode(rot_direction2_b, OUTPUT);
}

void loop()
{
  if (analogRead(0) >= 512){
    
    int speed = map(analogRead(potntiometerA0), 512, 1023, 0, 255);
    
    analogWrite(rot_direction1_a, speed);
  	analogWrite(rot_direction2_a, 0);
    analogWrite(rot_direction1_b, speed);
  	analogWrite(rot_direction2_b, 0);
  }
  
  else{
    
  	int speed = map(analogRead(potntiometerA0), 0, 512, 0, 255);
    
    analogWrite(rot_direction1_a, 0);
  	analogWrite(rot_direction2_a, speed);
    analogWrite(rot_direction1_b, 0);
    analogWrite(rot_direction2_b, speed);
    
  }
}