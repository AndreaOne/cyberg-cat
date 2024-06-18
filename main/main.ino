#include "Quadruped.h"
#include <NewPing.h>  //Ultrasonic sensor function library. You must install this library

//ultrasonic pins
//#define trig_pin A0  //analog input 0
//#define echo_pin A1  //analog input 1
int trigPin=A0;
int echoPin=A1;
int pinTravelTime;
float pinTravelDistance;
float d2target;

//#define maximum_distance 200
//boolean goesForward = false;
//int distance = 100;

//NewPing sonar(trig_pin, echo_pin, maximum_distance);  //sensor function

Quadruped robot(48.302, 91, 15.151, 40, 40);

void setup() {
  Serial.begin(9600);

  //ultrasonic
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  //  robot.init_initialise();
  robot.initialise();

  // delay(10);
  // robot.translate_cog_on_support_polygon("rf");
  // //  delay(1000);
  // robot.IK_one_leg("rf", 0, 20, 10);
  // delay(10);
  // robot.IK_one_leg("rf", 0, -20, 5);

  // delay(10);
  // robot.translate_cog_on_support_polygon("lb");
  // //  delay(1000);
  // robot.IK_one_leg("lb", 0, 20, 10);
  // delay(10);
  // robot.IK_one_leg("lb", 0, -20, 5);

  // delay(10);
  // robot.translate_cog_on_support_polygon("lf");
  // //  delay(1000);
  // robot.IK_one_leg("lf", 0, 20, 20);
  // delay(10);
  // robot.IK_one_leg("lf", 0, -20, 10);

  // delay(10);
  // robot.translate_cog_on_support_polygon("rb");
  // //  delay(1000);
  // robot.IK_one_leg("rb", 0, 20, 20);
  // delay(10);
  // robot.IK_one_leg("rb", 0, -20, 10);
}

void loop() {

  //ultra
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pinTravelTime=pulseIn(echoPin,HIGH);
  delay(10);

  // Serial.print(pinTravelTime);

  pinTravelDistance=(pinTravelTime*765.*5280.*12)/(3600.1000000);
  d2target=(pinTravelDistance/2);

  Serial.println(d2target);
  // Serial.print("inches");

  // put your main code here, to run repeatedly:
  if (d2target >= 5000000) {

    delay(10);
    robot.translate_cog_on_support_polygon("rf");
    //  delay(1000);
    robot.IK_one_leg("rf", 0, 20, 20);
    delay(10);
    robot.IK_one_leg("rf", 0, -20, 10);

    delay(10);
    robot.translate_cog_on_support_polygon("lb");
    //  delay(1000);
    robot.IK_one_leg("lb", 0, 20, 20);
    delay(10);
    robot.IK_one_leg("lb", 0, -20, 10);

    delay(10);
    robot.translate_cog_on_support_polygon("lf");
    //  delay(1000);
    robot.IK_one_leg("lf", 0, 20, 20);
    delay(10);
    robot.IK_one_leg("lf", 0, -20, 10);

    delay(10);
    robot.translate_cog_on_support_polygon("rb");
    //  delay(1000);
    robot.IK_one_leg("rb", 0, 20, 20);
    delay(10);
    robot.IK_one_leg("rb", 0, -20, 10);
  } 
  else {
    // delay(10);
    // robot.translate_cog_on_support_polygon("rb");
    // //  delay(1000);
    // robot.IK_one_leg("rb", 0, 20, -10);
    // delay(10);
    // robot.IK_one_leg("rb", 0, -20, -20);

    // delay(10);
    // robot.translate_cog_on_support_polygon("lf");
    // //  delay(1000);
    // robot.IK_one_leg("lf", 0, 20, -10);
    // delay(10);
    // robot.IK_one_leg("lf", 0, -20, -20);

    // delay(10);
    // robot.translate_cog_on_support_polygon("lb");
    // //  delay(1000);
    // robot.IK_one_leg("lb", 0, 20, -10);
    // delay(10);
    // robot.IK_one_leg("lb", 0, -20, -20);
    
    // delay(10);
    // robot.translate_cog_on_support_polygon("rf");
    // //  delay(1000);
    // robot.IK_one_leg("rf", 0, 20, -10);
    // delay(10);
    // robot.IK_one_leg("rf", 0, -20, -20);
  }
}