#ifndef inverse_kinematics_h
#define inverse_kinematics_h

#define L_1 10.5 //link2 length
#define L_2 15.0 //link3 length
#define angle_to_degree(val) (val * 180 / 3.14159265358979323846)

extern float *calculate_Oc(float x, float y, float z);
extern float *inverse_pos_kinematics(float x, float y, float z);

#endif
