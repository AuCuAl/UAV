#ifndef _PID_H
#define _PID_H

typedef struct
{
	float Kp, Ki, Kd;
	float err;
	float err_last;
	float integral;
	float maxi;
	float target_value;
	float output_value;
	float output_max;

} PID;

void PID_Init(PID *pid, float p, float i, float d, float maxI, float maxOut);
void pid_caculate(PID *pid, float reference, float feedback);

#endif
