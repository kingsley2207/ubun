/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Int8.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::Int8& toggle_msg){
  if(toggle_msg.data==9)
  {
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
  }
}

ros::Subscriber<std_msgs::Int8> sub("goal_indicate", &messageCb );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(500);
}
