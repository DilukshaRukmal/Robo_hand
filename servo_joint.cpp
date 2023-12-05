#include "servo_joint.h"
#include <Arduino.h>

//set the joint to its fixed configuration
  servo_joint::servo_joint(int fixed_angle_, int pin_) {

    fixed_angle = fixed_angle_;
    pin = pin_;
    joint.attach(pin);
    joint.write(fixed_angle);
  }

//rotate the joint by given angle
  int servo_joint::rotate(int init_pos_, int end_pos_, int tim_delay_, int count){
    if(init_pos_<= end_pos_){
      return clockwise_rotate(init_pos_, end_pos_, tim_delay_, count);
    }
    else if(end_pos_< init_pos_){
      return counter_clockwise_rotate(init_pos_, end_pos_, tim_delay_, count);
    }

  }

//clockwise rotation
  int servo_joint::clockwise_rotate(int init_pos_, int end_pos_, int tim_delay_, int count) {
    
    init_pos = init_pos_;
    end_pos = end_pos_;
    tim_delay = tim_delay_;
    if(count == 1){
      fixed_to_init(fixed_angle,init_pos);
    }
    if(init_pos == end_pos){
      joint.write(init_pos);
    }
    else{
    for (int pos = init_pos; pos <= end_pos; pos += 1) {
      joint.write(pos);
      delay(tim_delay);
    }
    }
    return end_pos;
  }

//anti-clockwise rotation
  int servo_joint::counter_clockwise_rotate(int init_pos_, int end_pos_, int tim_delay_,int count) {
    
    init_pos = init_pos_;
    end_pos = end_pos_;
    tim_delay = tim_delay_;
    if(count == 1){
      fixed_to_init(fixed_angle,init_pos);
    }
    for (int pos = init_pos; pos >= end_pos; pos -= 1) {
      joint.write(pos);
      delay(tim_delay);
    }
    return end_pos;
  }

//function to go from fixed config to task starting position
  void servo_joint::fixed_to_init(int fixed_angle, int init_pos) {
    if (fixed_angle > init_pos) {
      for (int pos = fixed_angle; pos >= init_pos; pos -= 1) {
        joint.write(pos);
        delay(tim_delay);
      }
    } else if(fixed_angle < init_pos) {
      for (int pos = fixed_angle; pos <= init_pos; pos += 1) {
        joint.write(pos);
        delay(tim_delay);
      }
    }
  }
;
