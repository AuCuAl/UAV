#include"motor.h"

#include "mpu6050.h"
#define motor_lf_pwm 900
#define motor_lr_pwm 900
#define motor_rf_pwm 900
#define motor_rr_pwm 900

float motor_lf=0;
float motor_lr=0;
float motor_rf=0;
float motor_rr=0;

//void output_roll(PID *pid,signed short gx)
//{
//    if(gx>0&&gx<3.14)
//    {
//        pid_caculate(pid,gx_l, gx);
//    }
//    else 
//    {

//         pid_caculate(pid,gx_l, gx-6.28);
//    }
//	
//}
//void output_pitch(PID *pid,signed short gy)
//{
// 
//}




 void text(PID *pid_roll,PID *pid_pitch)
 {
     Read_Mpu_Gyro();
	if(gx>0&&gx<3.14)
    {
        pid_caculate(pid_roll,gx_l, gx);
    }
    else 
    {

         pid_caculate(pid_roll,gx_l, gx-6.28);
    }
	
	if(gy>0&&gy<3.14)
    {
        pid_caculate(pid_pitch,gy_l, gy);
    }
    else 
    {

        pid_caculate(pid_pitch,gy_l, gy-6.28);
    }
	
 motor_lf = motor_lf_pwm - pid_roll->output_value-pid_pitch->output_value;
 motor_lr = motor_lf_pwm - pid_roll->output_value+pid_pitch->output_value;
 motor_rf = motor_lf_pwm +pid_roll->output_value-pid_pitch->output_value;
 motor_rr = motor_lf_pwm + pid_roll->output_value+pid_pitch->output_value;
   __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, motor_lf); 
   __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, motor_lr); 
   __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, motor_rf); 
   __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, motor_rr);
 }





