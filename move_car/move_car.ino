#include <ros.h>
#include <std_msgs/Int16.h>
ros::NodeHandle nh;
int ENA = 5; 
int IN1 =6;
int IN2 =7;
int IN3 = 8;
int IN4 = 9;
int ENB = 11; 
int maxSpeed = 200; //range is 0 - 255


void messageCb(const std_msgs::Int16& msg){
  nh.loginfo("recieved vel_cmnd");
  
  if(msg.data == 1){
   moveForward();
  }
  else if(msg.data == 0){
   stop_car();
  }
    else if(msg.data == 2){
   moveBackward();
  }
    else if(msg.data == 6){
   turn_right();
  }
    else if(msg.data == 7){
   turn_left();
  }
  
  
  
  
  
     


}

ros::Subscriber<std_msgs::Int16> sub("vel_cmnd", &messageCb);

void setup()
{
    pinMode(ENA,OUTPUT);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    pinMode(ENA,OUTPUT);
    
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    nh.initNode();
    nh.subscribe(sub);
   
}

void loop(){
  
  nh.spinOnce();
      //delay(1);

  
}



void moveForward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
  for(int i = 0; i < maxSpeed; i++){
     analogWrite(ENA,i);
     analogWrite(ENB,i);
  }
//  delay(500);
}

void moveBackward(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  for(int i = 0; i < maxSpeed; i++){
     analogWrite(ENA,i);
     analogWrite(ENB,i);
  }
//  delay(500);
}

void turn_left(){
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,maxSpeed);
  analogWrite(ENB,120);
  
  //delay(500);
}
void turn_right(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,120);
  analogWrite(ENB,maxSpeed);
  //delay(500);

}
void stop_car(){
digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

}

