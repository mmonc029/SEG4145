
/*
Names: Jeremy Sivaneswaran 3116318, Martin Monicon 6146324
Course Code: SEG 4145
Lab Number: 3
File name: lab_3
Date: March 10, 2015
Description: Instructions for the robot to complete lab 3
*/

#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>



//Define constants 
#define TEMPSENSOR 0x68 
#define SONAR_SENSOR 22
#define BOARD_LED 13
#define LCD_PIN 18
#define LEFT_MOTOR 45
#define RIGHT_MOTOR 8
#define RIGHT_SENSOR 49
#define LEFT_SENSOR 48
#define CENTER_MOTOR 7


SoftwareSerial LCD(0, LCD_PIN);

int reg = 0x01; // Ambient temperature = 0x01


/*
Name: setup
Description: Initialize the robot 
Parameters: none
Return: none
*/
void setup() {  
  Wire.begin(); // Join I2C bus
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(SONAR_SENSOR, OUTPUT);
  pinMode(BOARD_LED, OUTPUT);
  pinMode(LCD_PIN, OUTPUT);
  pinMode(CENTER_MOTOR, OUTPUT);
  Serial.begin(9600);
  LCD.begin(9600);
  Servo Center ;
  Center.attach(CENTER_MOTOR);
  Center.write(82);
}

/*
Name: loop
Description: The main program 
Parameters: none
Return: none
*/
void loop() {
  int dist;
  clearScreen();
  delay(1000);
  displayStudentNumbers();
  delay(1000);
  while(1)
  {
    dist = getSonarDistance();
    
    while( dist > 41){
      moveForward(1);
      dist = getSonarDistance();
    }
    displayTemperature();
    moveBackward(1);
    rotateRight(90);
    moveForward(2);
    rotateLeft(90);
  }
}
/*
Name: getSonarDistance 
Description: find the distance to how close the robot is to objects in fron of it
Parameters: none
Return: the distance away from any obstruction that the sonar has found
*/
int getSonarDistance(){
  pinMode(SONAR_SENSOR, OUTPUT);
  digitalWrite(SONAR_SENSOR, LOW);
    delay(2);
    // Write a HIGH value to sonar
    digitalWrite(SONAR_SENSOR, HIGH); 
    delay(5);
    digitalWrite(SONAR_SENSOR, LOW);
    pinMode(SONAR_SENSOR, INPUT);
    unsigned long duration = pulseIn(SONAR_SENSOR, HIGH);
    return duration / (29 * 2) ;
}
/*
Name: rotateLeft 
Description: rotate the robot by x degress
Parameters: input is the degrees of the rotation
Return: none
*/
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
/*
Name: rotateLeft 
Description: rotate the robot by x degress
Parameters: input is the degrees of the rotation
Return: none
*/
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
/*
Name: movediagonal 
Description: move the robot Dagonal across a certain number of tiles diagonal lengths
Parameters: input is number of tiles to traverse 
Return: none
*/
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
/*
Name: moveforward 
Description: move the robot forward across a certain number of tiles
Parameters: input is number of tiles to traverse 
Return: none
*/
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
/*
Name: diagonal 
Description: move the robot Dagonal across a certain number of tiles diagonal lengths
Parameters: input is number of tiles to traverse 
Return: none
*/
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

/*
Name: movebackward 
Description: move the robot backards across a certain number of tiles
Parameters: input is number of tiles to traverse 
Return: none
*/
void moveBackward(int x){
  
    clearScreen();
    String  d="Backward ";
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
  Right_Motor.write(90);
  Left_Motor.write(0);
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
                        Right_Motor.write(90);
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
Description: move the robot forward across a certain number of tiles
Parameters: input is number of tiles to traverse 
Return: none
*/
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
Name: displayTemperature
Description: Instructions to display the scurrent room temperature on the LCD screen
Parameters: none
Return: none
*/
void displayTemperature(){
  Wire.beginTransmission(TEMPSENSOR);
  Wire.write(reg); // Indicate temperature value to read
  Wire.endTransmission();
  Wire.requestFrom(TEMPSENSOR, 1); // Request data
  while(Wire.available() < 1); // Wait for data
  byte temperatureData = Wire.read(); // Temp. value
  clearScreen();
  printMessage("Temperature", 2, 0);
  printMessage(String(temperatureData) + " Degrees", 2, 1);
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



