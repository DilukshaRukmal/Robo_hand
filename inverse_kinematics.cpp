#include "inverse_kinematics.h"
#include <math.h>
#include <Arduino.h>

//Function to calculate O_c from EE position
float *calculate_Oc(float x, float y, float z)
{
    float *O_c = new float[3];
    O_c[0] = x;
    O_c[1] = y;
    O_c[2] = z+17.5;
    return O_c;
}


float *inverse_pos_kinematics(float x, float y, float z)
{
    float *angles = new float[3];
    float *O_c = calculate_Oc(x, y, z);
    float x_c = O_c[0];
    float y_c = O_c[1];
    float z_c = O_c[2];
    float r_2 = (x_c * x_c + y_c * y_c);
    float r = sqrt(r_2);
    float s = z_c - 7;
    
    
    float ang = (-(r * r) - (s * s) + (L_1 * L_1) + (L_2 * L_2)) / (2 * L_1 * L_2);

    angles[0] = angle_to_degree(atan(y / x));
    angles[2] = angle_to_degree(acos(ang));
    float p = atan(L_2 * sin(*(angles + 2) / 180 * M_PI) / (L_1 - L_2 * cos(*(angles + 2) / 180 * M_PI)));
    float q = atan(s /r);
    angles[1] = angle_to_degree(p)+angle_to_degree(q);
    return &angles[0];
}
