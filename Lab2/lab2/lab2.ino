
/*
Names: Jeremy Sivaneswaran 3116318, Martin Monicon 6146324
Course Code: SEG 4145
Lab Number: 2
File name: lab2
Date: Feb 11, 2015
Description: Instructions for the robot to complete lab 2
*/

#include <SoftwareSerial.h>
#include <Servo.h>

//Define constants 
#define BOARD_LED 13
#define LCD_PIN 18
#define LEFT_MOTOR 2
#define RIGHT_MOTOR 4
#define RIGHT_SENSOR 28
#define LEFT_SENSOR 26

SoftwareSerial LCD(0, LCD_PIN);

/*
Name: setup
Description: Initialize the robot 
Parameters: none
Return: none
*/
void setup() {  
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(BOARD_LED, OUTPUT);
  pinMode(LCD_PIN, OUTPUT);
  Serial.begin(9600);
  LCD.begin(9600);
}

/*
Name: loop
Description: The main program 
Parameters: none
Return: none
*/
void loop() {


  displayStudentNumbers();
<<<<<<< HEAD

  delay(100);
=======
  
  delay(100);
  
>>>>>>> 257b6e6e01409498f4d7b756a8b78cd53269c6cd
  forward(2);
  rotateRight(90);
  forward(2);
  rotateRight(90);
  forward(3);
  rotateRight(90);
  forward(3);
  rotateRight(90);
  forward(2);
  rotateLeft(45);
  diagonal(1);
  rotateLeft(135);
  forward(4);
  rotateLeft(90);
  forward(2);
  rotateLeft(2);
  forward(2);
<<<<<<< HEAD
  clearScreen();
  delay(10000);  
=======
>>>>>>> 257b6e6e01409498f4d7b756a8b78cd53269c6cd
  
  printStopMessage(10);
}

/*
Name: rotateRight
Description: Rotate the robot x degrees to the right
Parameters: int x - the degree to rotate the robot
Return: none
*/
void rotateRight(int x){
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  
  clearScreen();
  String s = "Right ";
  s.concat(x);
  printMessage("Rotating", 4, 0);
  printMessage(s, 4, 1);
  flashLED(3);
  
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(120);
  Left_Motor.write(120);
  while ((left_count <= (x/45)*26) || (right_count <= (x/45)*26)){
	left_sensor = digitalRead(LEFT_SENSOR);
	right_sensor = digitalRead(RIGHT_SENSOR);
	if(old_left_sensor != left_sensor){
		left_count++;
	}
	if(old_right_sensor != right_sensor){
		right_count++;
	}
	old_left_sensor = left_sensor;
	old_right_sensor = right_sensor;
	if (left_active){
		if(left_count > right_count){
			Left_Motor.detach();
			left_active = false;
		}
	}else{
		if(! (left_count > right_count)){
			Left_Motor.attach(LEFT_MOTOR);
                        Left_Motor.write(120);
			left_active = true;
		}
	}
	if (right_active){
		if(right_count>left_count){
			Right_Motor.detach();
			right_active = false;
		}
	}else{
		if(!(right_count > left_count)){
			Right_Motor.attach(RIGHT_MOTOR);
                        Right_Motor.write(120);
			right_active = true;
		}
	}
	delay(1);
  }
  Right_Motor.detach();
  Left_Motor.detach();
  delay(1000);
}

/*
Name: rotateLeft
Description: Rotate the robot x degrees to the left
Parameters: int x - the degree to rotate the robot
Return: none
*/
void rotateLeft(int x){
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;

  clearScreen();
  String s = "Left ";
  s.concat(x);
  printMessage("Rotating", 4, 0);
  printMessage(s, 4, 1);
  flashLED(3);
  
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
  Left_Motor.write(0);
  while ((left_count <= (x/45)*26) || (right_count <= (x/45)*26)){
	left_sensor = digitalRead(LEFT_SENSOR);
	right_sensor = digitalRead(RIGHT_SENSOR);
	if(old_left_sensor != left_sensor){
		left_count++;
	}
	if(old_right_sensor != right_sensor){
		right_count++;
	}
	old_left_sensor = left_sensor;
	old_right_sensor = right_sensor;
	if (left_active){
		if(left_count > right_count){
			Left_Motor.detach();
			left_active = false;
		}
	}else{
		if(! (left_count > right_count)){
			Left_Motor.attach(LEFT_MOTOR);
                        Left_Motor.write(0);
			left_active = true;
		}
	}
	if (right_active){
		if(right_count>left_count){
			Right_Motor.detach();
			right_active = false;
		}
	}else{
		if(!(right_count > left_count)){
			Right_Motor.attach(RIGHT_MOTOR);
                        Right_Motor.write(0);
			right_active = true;
		}
	}
	delay(1);
  }
  Right_Motor.detach();
  Left_Motor.detach();
  delay(1000);
}

/*
Name: diagonal
Description: Moves the robot diagonally x number of squares
Parameters: int x - the number of squares to move the robot
Return: none
*/
void diagonal(int x){
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  
  clearScreen();
  String s = "Diagonal ";
  s.concat(x);
  printMessage("Moving", 5, 0);
  printMessage(s, 4, 1);
  flashLED(3);
  
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
  Left_Motor.write(90);
  while ((left_count <= x*160) || (right_count <= x*160)){
	left_sensor = digitalRead(LEFT_SENSOR);
	right_sensor = digitalRead(RIGHT_SENSOR);
	if(old_left_sensor != left_sensor){
		left_count++;
	}
	if(old_right_sensor != right_sensor){
		right_count++;
	}
	old_left_sensor = left_sensor;
	old_right_sensor = right_sensor;
	if (left_active){
		if(left_count > right_count){
			Left_Motor.detach();
			left_active = false;
		}
	}else{
		if(! (left_count > right_count)){
			Left_Motor.attach(LEFT_MOTOR);
                        Left_Motor.write(90);
			left_active = true;
		}
	}
	if (right_active){
		if(right_count>left_count){
			Right_Motor.detach();
			right_active = false;
		}
	}else{
		if(!(right_count > left_count)){
			Right_Motor.attach(RIGHT_MOTOR);
                        Right_Motor.write(0);
			right_active = true;
		}
	}
	delay(1);
  }
  Right_Motor.detach();
  Left_Motor.detach();
  delay(1000);
}

/*
Name: forward
Description: Moves the robot forward x number of squares
Parameters: int x - The number of squares to move the robot forward
Return: none
*/
void forward(int x){
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  
  clearScreen();
  String s = "Forward ";
  s.concat(x);
  printMessage("Moving", 5, 0);
  printMessage(s, 4, 1);
  flashLED(3);
  
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
<<<<<<< HEAD
  Left_Motor.write(0);
  delay(x *350);
  Left_Motor.detach();
  Right_Motor.detach();

}


/*
Name: rotateLeft13
Description: Instructions to rotate 45 degrees to the left
Parameters: none
Return: none
*/
void rotateLeft135(){
  clearScreen();
  String d = "Left ";
  //d.concat(x*45);
  printMessage("Rotating", 4, 0);
  printMessage(d, 4, 1);
  flashLED(3);
  Servo Right_Motor;
  Servo Left_Motor;
  Left_Motor.attach(LEFT_MOTOR);
  Right_Motor.attach(RIGHT_MOTOR);
  Right_Motor.write(0);
  Left_Motor.write(0);
  delay(1050);
  Left_Motor.detach();
=======
  Left_Motor.write(90);
  while ((left_count <= x*113) || (right_count <= x*113)){
	left_sensor = digitalRead(LEFT_SENSOR);
	right_sensor = digitalRead(RIGHT_SENSOR);
	if(old_left_sensor != left_sensor){
		left_count++;
	}
	if(old_right_sensor != right_sensor){
		right_count++;
	}
	old_left_sensor = left_sensor;
	old_right_sensor = right_sensor;
	if (left_active){
		if(left_count > right_count){
			Left_Motor.detach();
			left_active = false;
		}
	}else{
		if(! (left_count > right_count)){
			Left_Motor.attach(LEFT_MOTOR);
                        Left_Motor.write(90);
			left_active = true;
		}
	}
	if (right_active){
		if(right_count>left_count){
			Right_Motor.detach();
			right_active = false;
		}
	}else{
		if(!(right_count > left_count)){
			Right_Motor.attach(RIGHT_MOTOR);
                        Right_Motor.write(0);
			right_active = true;
		}
	}
	delay(1);
  }
>>>>>>> 257b6e6e01409498f4d7b756a8b78cd53269c6cd
  Right_Motor.detach();
  Left_Motor.detach();
  delay(1000);
}

/*
Name: reverse
Description: Moves the robot backwards x squares
Parameters: int x - the number of squares to move the robot backwards
Return: none
*/
void reverse(int x){
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  
  clearScreen();
  String s = "Forward ";
  s.concat(x);
  printMessage("Moving", 5, 0);
  printMessage(s, 4, 1);
  flashLED(3);
<<<<<<< HEAD
  Servo Right_Motor;
  Servo Left_Motor;
  Left_Motor.attach(LEFT_MOTOR);
  Right_Motor.attach(RIGHT_MOTOR);
  Right_Motor.write(180);
  Left_Motor.write(180);
  delay(x*350);
  Left_Motor.detach();
  Right_Motor.detach();
=======
  delay(1000);
>>>>>>> 257b6e6e01409498f4d7b756a8b78cd53269c6cd
  
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
  Left_Motor.write(90);
  while ((left_count <= x*113) || (right_count <= x*113)){
	left_sensor = digitalRead(LEFT_SENSOR);
	right_sensor = digitalRead(RIGHT_SENSOR);
	if(old_left_sensor != left_sensor){
		left_count++;
	}
	if(old_right_sensor != right_sensor){
		right_count++;
	}
	old_left_sensor = left_sensor;
	old_right_sensor = right_sensor;
	if (left_active){
		if(left_count > right_count){
			Left_Motor.detach();
			left_active = false;
		}
	}else{
		if(! (left_count > right_count)){
			Left_Motor.attach(LEFT_MOTOR);
                        Left_Motor.write(90);
			left_active = true;
		}
	}
	if (right_active){
		if(right_count>left_count){
			Right_Motor.detach();
			right_active = false;
		}
	}else{
		if(!(right_count > left_count)){
			Right_Motor.attach(RIGHT_MOTOR);
                        Right_Motor.write(0);
			right_active = true;
		}
	}
	delay(1);
  }
  Right_Motor.detach();
  Left_Motor.detach();
  delay(1000);
}

/*
Name: printStopMessage 
Description: Prints a stop message on the LCD display
Parameters: int x - the number of seconds to display the message
Return: none
*/
void printStopMessage(int x){
  clearScreen();
  printMessage("Stopped", 5, 0);
  flashLED(x);
}

/*
Name: printMessage 
Description: Prints a given message to the LCD display 
Parameters:
text - String - the message to print
col - int - the column of the display to start the message at
row - int - the row of the display used to display the message
Return: none
*/
void printMessage(String text, int col, int row){
  LCD.write(0xFE);
  LCD.write(col + row * 64 + 128);
  LCD.print(text);
}

/*
Name: flashLED 
Description: Instructions to blink the LED light for a certain period of time
Parameters: x - int - the number of seconds to blink the LED
Return: none
*/
void flashLED(int x) {
  for (int a = x; a > 0; a--){
    digitalWrite(BOARD_LED, HIGH);
    delay(500);
    digitalWrite(BOARD_LED, LOW);
    delay(500);
  }
}

/*
Name: displayStudentNumbers
Description: Instructions to display the student numbers on the LCD screen
Parameters: none
Return: none
*/
void displayStudentNumbers(){
  clearScreen();
  printMessage("3116318", 5, 0);
  printMessage("6146324", 5, 1);
  flashLED(5);
}

/*
Name: clearScreen
Description: Instructions to clear the LCD display screen
Parameters: none
Return: none
*/
void clearScreen (){
  LCD.write(0xFE);
  LCD.write(0x01);
  delay(10);
}


