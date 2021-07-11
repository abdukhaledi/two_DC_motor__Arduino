# two_DC_motor__Arduino :robot:
![Screenshot (422)](https://user-images.githubusercontent.com/85647212/122826601-056bd580-d2ec-11eb-861c-d2ad363812e0.png)

DC motors circuit to control the robot wheel on Smart Methods company. Wheels will be controlled by 250 kΩ potentiometer, turning the potentiometer to the right side will move the motor clockwise, and left side to move the motor counter clockwise. the simulation of the circuit is done by using Tinkercad

Components of this task:
* Arduino Uno R3
* 9V Battery
* Two DC Motors
* L293D H-bridge Motor Driver
* 250 kΩ Potentiometer

## Circuit link:
https://www.tinkercad.com/things/hiG2SU9dF87-dc-motor/editel

## Circuit figure:
![DC Motor](https://user-images.githubusercontent.com/85647212/122827144-ac507180-d2ec-11eb-9285-5f16ea983307.png)

## Arduino code:
Add digital inputs 5, 6, 9, and 10 of the motor. Add analog pin A0 of the potentiometer.
```C++
int rot_direction1_a = 5;
int rot_direction2_a = 6;
int rot_direction1_b = 10;
int rot_direction2_b = 9;
int potntiometerA0 = A0;
```

Set potentiometer variable as input, and motor rotation as output.
```C++
void setup()
{
  pinMode(potntiometerA0, INPUT);
  pinMode(rot_direction1_a, OUTPUT);
  pinMode(rot_direction2_a, OUTPUT);
  pinMode(rot_direction1_b, OUTPUT);
  pinMode(rot_direction2_b, OUTPUT);
}
```

now the motor rotate direction is on clockwise if the potentiometer is on the right dirction, and on counter clockwise if potentiometer is on the left dirction
```C++
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
```

## Circuit video:
https://user-images.githubusercontent.com/85647212/122829275-79f44380-d2ef-11eb-9956-a007cbe51155.mp4
