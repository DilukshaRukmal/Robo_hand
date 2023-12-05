#include "servo_joint.h"
#include "inverse_kinematics.h"

int count = 2;//Variable to keep track on first iteration

//Fixed configuration angles
int angle_1 = 90;
int angle_2 = 120;
int angle_3 = 90;
int angle_4 = 90;
int angle_5 = 0;
int angle_6 = 180;

int joint1_var = angle_1;
int joint2_var = angle_2;
int joint3_var = angle_3;
int joint4_var = angle_4;
int joint5_var = angle_5;
int joint6_var = angle_6;

//Gripper
int open_pos = 130;
int closed_pos = 150;

void setup() {
  Serial.begin(9600);




  //Move the arm to its initial position
  servo_joint joint1(angle_1, 3);
  servo_joint joint2(angle_2, 5);
  servo_joint joint3(angle_3, 6);
  servo_joint joint4(angle_4, 9);
  servo_joint joint5(angle_5, 10);
  servo_joint joint6(angle_6, 11);


  //start and end positions
  float x_init = 5;
  float y_init = 5;
  float z_init = 3;
  float psi_init = 0;
  float theta_init = 0;
  float phi_init = 0;

  float x_fin = 10;
  float y_fin = 0;
  float z_fin = 10;
  float psi_fin = 0;
  float theta_fin = 0;
  float phi_fin = 0;

  //calculating inverse kinematics
  float *init_joints_para = inverse_pos_kinematics( x_init,  y_init,  z_init);
  float *fin_joints_para = inverse_pos_kinematics( x_fin,  y_fin,  z_fin);

 
  //Go to start position from fixed initial position
  delay(500);
  angle_4 = joint4.rotate(angle_4, 0, 100,count);
  delay(500);
  angle_1 = joint1.rotate(angle_1, ((int)*init_joints_para)+90, 100,count);
  delay(500);
  angle_2 = joint2.rotate(angle_2, (int)*(init_joints_para+1), 100,count);
  delay(500);
  angle_6 = joint6.rotate(angle_6, open_pos, 50,count);
  delay(500);
  angle_3 = joint3.rotate(angle_3, ((int)*(init_joints_para+2))+10, 100,count);
  delay(500);
  angle_5 = joint5.rotate(angle_5, 90, 50,count);
  delay(500);
  angle_4 = joint4.rotate(angle_4, 90, 100,count);
  delay(500);

  //Go to end postion and drop the object
  angle_6 = joint6.rotate(angle_6, closed_pos, 50,count);
  delay(500);
  angle_2 = joint2.rotate(angle_2, 120, 100,count);
  delay(500);
  angle_5 = joint5.rotate(angle_5, 90, 50,count);
  delay(500);
  angle_4 = joint4.rotate(angle_4, 0, 100,count);
  delay(500);
  angle_1 = joint1.rotate(angle_1, (int)*fin_joints_para+90, 100,count);
  delay(500);
  angle_2 = joint2.rotate(angle_2, (int)*(fin_joints_para+1)+20, 100,count);
  delay(500);
  angle_3 = joint3.rotate(angle_3, (int)*(init_joints_para+2)+20, 100,count);
  delay(500);
  angle_5 = joint5.rotate(angle_5, 0, 50,count);
  delay(500);
  angle_4 = joint4.rotate(angle_4, 90, 100,count);
  delay(500);
  angle_6 = joint6.rotate(angle_6, open_pos, 50,count);
  delay(500);

  //Coming back to fixed position
  angle_2 = joint2.rotate(angle_2, 120, 100,count);
  delay(500);
  angle_1 = joint1.rotate(angle_1, 90, 100,count);
  delay(500);
  angle_3 = joint3.rotate(angle_3, 110, 100,count);
  delay(500);
  angle_4 = joint4.rotate(angle_4, 90, 100,count);
  delay(500);
  angle_5= joint5.rotate(angle_5, 0, 100,count);
  delay(500);
  angle_6 = joint6.rotate(angle_6, 180, 50,count);
  
  
  
}

void loop() {


}
