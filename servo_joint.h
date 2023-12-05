#ifndef _SERVO_JOINT_H_
#define _SERVO_JOINT_H_
#include <Servo.h>

class servo_joint {
  Servo joint;
private:
  int init_pos; //start position angle
  int end_pos; //final position angle
  int fixed_angle; // fixed position angle
  int tim_delay; //time step between each consecative link positions
  int pin;
public:
  servo_joint(int fixed_angle_, int pin_);
  int rotate(int init_pos_, int end_pos_, int tim_delay_, int count);
  int clockwise_rotate(int init_pos_, int end_pos_, int tim_delay_, int count) ;
  int counter_clockwise_rotate(int init_pos_, int end_pos_, int tim_delay_,int count) ;
  void fixed_to_init(int fixed_angle, int init_pos);
} ;
#endif
