#include <pid.h>






void PID_Init(PID *pid,float p,float i,float d,float maxI,float maxOut)
{
    pid->Kd=p;
    pid->Ki=i;
    pid->Kd=d;
    pid->maxi=maxI;
    pid->output_max=maxOut;

}

void pid_caculate(PID *pid,float reference,float feedback)
{
	pid->err_last=pid->err;
	pid->err=reference-feedback;
	float dout=(pid->err-pid->err_last)*pid->Kd;
	float pout=pid->err*pid->Kp;
	pid->integral+=pid->err*pid->Ki;
    if(pid->integral>pid->maxi) pid->integral=pid->maxi;
	else if(pid->integral<-pid->maxi) pid->integral=-pid->maxi; 


	pid->output_value=dout+pout+pid->integral;

	if(pid->output_value>pid->output_max) pid->output_value=pid->output_max;  
	else if(pid->output_value<-pid->output_max) pid->output_value=-pid->output_max;  


}







