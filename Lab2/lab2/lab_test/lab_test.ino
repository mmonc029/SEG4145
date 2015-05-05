
/*
Names: Jeremy Sivaneswaran 3116318, Martin Monicon 6146324
Course Code: SEG 4145
Lab Number: 2
File name: sketch_lab2
Date: Feb 11, 2015
Description: Instructions for the robot to complete lab 1
*/

#include <SoftwareSerial.h>
#include <Servo.h>

//Define constants 
#define BOARD_LED 13
#define LCD_PIN 18
#define LEFT_MOTOR 45
#define RIGHT_MOTOR 8
#define RIGHT_SENSOR 49
#define LEFT_SENSOR 48

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

 
  clearScreen();
  delay(1000);
  displayStudentNumbers();
  delay(1000);
  moveForward(2);
  rotateRight(90);
  moveForward(2);
  rotateRight(90);
  moveForward(3);
  rotateRight(90);
  moveForward(3);
  rotateRight(90);
  moveForward(2);
  rotateLeft(45);
  moveDiagonal(1);
  rotateLeft(135);
  moveForward(4);
  rotateLeft(90);
  moveForward(2);
  rotateLeft(90);
  moveForward(2);
  delay(10000); 
}
void rotateRight(int x){
  clearScreen();
  String d = "Right ";
  d.concat(x);
  printMessage("Rotating", 4, 0);
  printMessage(d, 4, 1);
  flashLED(3);
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  delay(1000);
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(120);
  Left_Motor.write(120);
  while ((left_count <= (x/45)*24) || (right_count <= (x/45)*24)){
        //Serial.print(left_count);
        //Serial.print(" ");
        //Serial.println(right_count);
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
void rotateLeft(int x){
  clearScreen();
  String d = "Left ";
  d.concat(x);
  printMessage("Rotating", 4, 0);
  printMessage(d, 4, 1);
  flashLED(3);
  
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  delay(1000);
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
  Left_Motor.write(0);
  while ((left_count <= (x/45)*25) || (right_count <= (x/45)*25)){
        //Serial.print(left_count);
        //Serial.print(" ");
        //Serial.println(right_count);
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

void moveDiagonal(int x){
  
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  delay(1000);
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
  Left_Motor.write(90);
  while ((left_count <= x*160) || (right_count <= x*160)){
        //Serial.print(left_count);
        //Serial.print(" ");
        //Serial.println(right_count);
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

void moveForward(int x){
  
    clearScreen();
    String  d="Forward ";
    d.concat(x);
    printMessage("Moving", 5, 0);
    printMessage(d, 4, 1);
    flashLED(3);
  
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  delay(1000);
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
  Left_Motor.write(90);
  while ((left_count <= x*111) || (right_count <= x*111)){
        //Serial.print(left_count);
        //Serial.print(" ");
        //Serial.println(right_count);
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

void diagonal(int x)
{
    clearScreen();
    String d= "Diagonal ";
    d.concat(x);
    printMessage("Moving", 5, 0);
    printMessage(d, 3, 1);
    flashLED(3);
    Servo Right_Motor;
    Servo Left_Motor;
    Left_Motor.attach(LEFT_MOTOR);
    Right_Motor.attach(RIGHT_MOTOR);
    Right_Motor.write(0);
    Left_Motor.write(90);
    
    
    int count = 0;
    int new_sensor;
    int old_sensor = digitalRead(LEFT_SENSOR);
    //int old_sensor = digitalRead(RIGHT_SENSOR);
    for(int i = 0; i<1950 * x; i++)
    {
      new_sensor = digitalRead(LEFT_SENSOR);
      //new_sensor = digitalRead(RIGHT_SENSOR);
      //Serial.print(new_sensor);
      if (new_sensor != old_sensor){
        count++;
      }
      old_sensor = new_sensor;
      delay(1);
    }
    //Serial.print("\n");
    Serial.println(count);
    Left_Motor.detach();
    Right_Motor.detach();
    delay(2000);  
}


void reverseForward(int x){
  
    clearScreen();
    String  d="Forward ";
    d.concat(x);
    printMessage("Moving", 5, 0);
    printMessage(d, 4, 1);
    flashLED(3);
  
  Servo Left_Motor, Right_Motor;
  int left_sensor, right_sensor, old_left_sensor, old_right_sensor, left_count, right_count, count;
  boolean right_active, left_active;
  delay(1000);
  left_count = 0;
  right_count = 0;
  left_active = false;
  right_active = false;
  old_left_sensor = digitalRead(LEFT_SENSOR);
  old_right_sensor = digitalRead(RIGHT_SENSOR);
  Right_Motor.write(0);
  Left_Motor.write(90);
  while ((left_count <= x*111) || (right_count <= x*111)){
        //Serial.print(left_count);
        //Serial.print(" ");
        //Serial.println(right_count);
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

void forward(int x)
{
    clearScreen();
    String  d="Forward ";
    d.concat(x);
    printMessage("Moving", 5, 0);
    printMessage(d, 4, 1);
    flashLED(3);
  
    Servo Right_Motor;
    Servo Left_Motor;
    Left_Motor.attach(LEFT_MOTOR);
    Right_Motor.attach(RIGHT_MOTOR);
    Right_Motor.write(0);
    Left_Motor.write(90);
    
    
    int count = 0;
    int new_sensor;
    int old_sensor = digitalRead(LEFT_SENSOR);
    //int old_sensor = digitalRead(RIGHT_SENSOR);
    for(int i = 0; i<1375 *x; i++)
    {
      new_sensor = digitalRead(LEFT_SENSOR);
      //new_sensor = digitalRead(RIGHT_SENSOR);
      //Serial.print(new_sensor);
      if (new_sensor != old_sensor){
        count++;
      }
      old_sensor = new_sensor;
      delay(1);
    }
    //Serial.print("\n");
    Serial.println(count);
    Left_Motor.detach();
    Right_Motor.detach();
    delay(2000);  
  
}

void reversediagonal()
{
    Servo Right_Motor;
    Servo Left_Motor;
    Left_Motor.attach(LEFT_MOTOR);
    Right_Motor.attach(RIGHT_MOTOR);
    Right_Motor.write(120);
    Left_Motor.write(0);
    
    
    int count = 0;
    int new_sensor;
    int old_sensor = digitalRead(LEFT_SENSOR);
    //int old_sensor = digitalRead(RIGHT_SENSOR);
    for(int i = 0; i<1925; i++)
    {
      new_sensor = digitalRead(LEFT_SENSOR);
      //new_sensor = digitalRead(RIGHT_SENSOR);
      //Serial.print(new_sensor);
      if (new_sensor != old_sensor){
        count++;
      }
      old_sensor = new_sensor;
      delay(1);
    }
    //Serial.print("\n");
    Serial.println(count);
    Left_Motor.detach();
    Right_Motor.detach();
    delay(2000);  
}

void reverseforward()
{
  
    Servo Right_Motor;
    Servo Left_Motor;
    Left_Motor.attach(LEFT_MOTOR);
    Right_Motor.attach(RIGHT_MOTOR);
    Right_Motor.write(120);
    Left_Motor.write(0);
    
    
    int count = 0;
    int new_sensor;
    int old_sensor = digitalRead(LEFT_SENSOR);
    //int old_sensor = digitalRead(RIGHT_SENSOR);
    for(int i = 0; i<1325; i++)
    {
      new_sensor = digitalRead(LEFT_SENSOR);
      //new_sensor = digitalRead(RIGHT_SENSOR);
      //Serial.print(new_sensor);
      if (new_sensor != old_sensor){
        count++;
      }
      old_sensor = new_sensor;
      delay(1);
    }
    //Serial.print("\n");
    Serial.println(count);
    Left_Motor.detach();
    Right_Motor.detach();
    delay(2000);  
  
}











/*
Name: printStopMessage 
Description: Prints a stop message on the LCD display
Parameters: none
Return: none
*/
void printStopMessage(){
  clearScreen();
  printMessage("Stopped", 5, 0);
  flashLED(3);
  delay(3000);
}

/*
Name: printMessage 
Description: Prints a given message to the LCD display 
Parameters:
text - String - In - the message to print
col - int - In - the column of the display to start the message at
row - int - In - the row of the display used to display the message
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
Parameters: x - int - In - the number of seconds to blink the LED
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



