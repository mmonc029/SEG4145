/*
Names: Jeremy Sivaneswaran 3116318, Martin Monicon 6146324
Course Code: SEG 4145
Lab Number: 1
File name: sketch_lab1
Date: January 22, 2013
Description: Instructions for the robot to complete lab 1
*/

#include <SoftwareSerial.h>
#include <Servo.h>

//Define constants 
#define BOARD_LED 13
#define LCD_PIN 18
#define LEFT_MOTOR 2
#define RIGHT_MOTOR 4
#define STOP 0
#define LEFT_FORWARD 191.5
#define LEFT_BACKWARD 10
#define RIGHT_FORWARD 10
#define SECOND_RIGHT_FORWARD 9
#define RIGHT_BACKWARD 191.5
#define RIGHT_MOTOR_ROTATE_RIGHT 191.5
#define LEFT_MOTOR_ROTATE_RIGHT 183
#define RIGHT_MOTOR_ROTATE_LEFT 10
#define LEFT_MOTOR_ROTATE_LEFT 10
#define RIGHT_BACKWARD 191.5
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
  /*
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  */
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
    for(int i = 0; i<1400; i++)
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
Name: path1
Description: Instructions to traverse path 1 
Parameters: none
Return: none
*/
void path1(){
  clearScreen();
  printMessage("Path 1", 5, 0);
  flashLED(3); 
  clearScreen();
  forward(5);
  rotateLeft90(); 
  forward(5);
  rotateRight90();
  forward(5);
  rotateRight90();
  forward(5);
  rotateLeft90(); 
  forward(5);
}

/*
Name: reversePath1
Description: Instructions to traverse path 1 in reverse
Parameters: none
Return: none
*/
void reversePath1(){
  clearScreen();
  reverse(5);
  rotateRight90(); 
  reverse(5);
  rotateLeft90();
  reverse(5);
  rotateLeft90();
  reverse(5);
  rotateRight90(); 
  reverse(5);
}

/*
Name: path2
Description: Instructions to traverse path 2
Parameters: none
Return: none
*/
void path2(){
  clearScreen();
  printMessage("Path 1", 5, 0);
  flashLED(3); 
  clearScreen();
  forward(5);
  rotateRight90(); 
  forward(5);
  rotateLeft90();
  rotateLeft45();
  forward(5);
  rotateRight90();
  rotateRight45();
  forward(5);
  rotateLeft90(); 
  forward(5);
}

/*
Name: reversePath2
Description: Instructions to traverse path 2 in reverse
Parameters: none
Return: none
*/
void reversePath2() {
  clearScreen();
  reverse(5);
  rotateLeft90(); 
  reverse(5);
  rotateRight90();
  rotateRight45();
  reverse(5);
  rotateLeft90();
  rotateLeft45();
  reverse(5);
  rotateRight90(); 
  reverse(5);
}

/*
Name: rotateLeft90
Description: Instructions to rotate 90 degrees to the left
Parameters: none
Return: none
*/
void rotateLeft90(){
  clearScreen();
  printMessage("Rotating", 4, 0);
  printMessage("Left", 6, 1);
  flashLED(3);
  analogWrite(LEFT_MOTOR, LEFT_MOTOR_ROTATE_LEFT);
  analogWrite(RIGHT_MOTOR, RIGHT_MOTOR_ROTATE_LEFT);
  delay(800);
  analogWrite(LEFT_MOTOR, STOP); 
  analogWrite(RIGHT_MOTOR, STOP);
  printStopMessage();  
}

/*
Name: rotateLeft45
Description: Instructions to rotate 45 degrees to the left
Parameters: none
Return: none
*/
void rotateLeft45(){
  clearScreen();
  printMessage("Rotating", 4, 0);
  printMessage("Left", 6, 1);
  flashLED(3);
  analogWrite(LEFT_MOTOR, LEFT_MOTOR_ROTATE_LEFT);
  analogWrite(RIGHT_MOTOR, RIGHT_MOTOR_ROTATE_LEFT);
  delay(400);
  analogWrite(LEFT_MOTOR, STOP); 
  analogWrite(RIGHT_MOTOR, STOP);
  printStopMessage();
}

/*
Name: rotateRight90
Description: Instructions to rotate to the right 90 degrees
Parameters: none
Return: none
*/
void rotateRight90(){
  clearScreen();
  printMessage("Rotating", 4, 0);
  printMessage("Right", 5, 1);
  flashLED(3);
  analogWrite(RIGHT_MOTOR, RIGHT_MOTOR_ROTATE_RIGHT);
  analogWrite(LEFT_MOTOR, LEFT_MOTOR_ROTATE_RIGHT);
  delay(1100);
  analogWrite(RIGHT_MOTOR, STOP);
  analogWrite(LEFT_MOTOR, STOP);
  printStopMessage();
}

/*
Name: rotateRight45
Description: Instructions to rotate to the right 45 degrees
Parameters: none
Return: none
*/
void rotateRight45(){
  clearScreen();
  printMessage("Rotating", 4, 0);
  printMessage("Right", 5, 1);
  flashLED(3);
  analogWrite(RIGHT_MOTOR, RIGHT_MOTOR_ROTATE_RIGHT);
  analogWrite(LEFT_MOTOR, LEFT_MOTOR_ROTATE_RIGHT);
  delay(550);
  analogWrite(RIGHT_MOTOR, STOP);
  analogWrite(LEFT_MOTOR, STOP);
  printStopMessage();
}

/*
Name: forward 
Description: Instructions to move forward
Parameters: x - int - In - the number of seconds to move forward
Return: none
*/
void forward(int x){
  delay(1000);
  clearScreen();
  printMessage("Moving", 5, 0);
  printMessage("Forward", 4, 1);
  flashLED(3);
  analogWrite(RIGHT_MOTOR, RIGHT_FORWARD);
   //delay(100);
  analogWrite(LEFT_MOTOR, LEFT_FORWARD);
  delay(x*1000);

  analogWrite(RIGHT_MOTOR, STOP);
 // delay(100);
  analogWrite(LEFT_MOTOR, STOP);
  printStopMessage();
}

/*
Name: reverse
Description: Instructions to move backwards
Parameters: x - int - In - number of seconds to move backwards
Return: none
*/
void reverse(int x){
  clearScreen();
  printMessage("Moving", 5, 0);
  printMessage("Backward", 4, 1);
  flashLED(3);
  analogWrite(RIGHT_MOTOR, RIGHT_BACKWARD);
  analogWrite(LEFT_MOTOR, LEFT_BACKWARD);
  delay(x*1000);
  analogWrite(RIGHT_MOTOR, STOP);
  analogWrite(LEFT_MOTOR, STOP);
  printStopMessage();
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


