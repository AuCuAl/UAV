#include "motor.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mpu6050.h"
#define motor_lf_pwm 900
#define motor_lr_pwm 900
#define motor_rf_pwm 900
#define motor_rr_pwm 900
extern float roll, pitch, yaw;
float motor_lf = 0;
float motor_lr = 0;
float motor_rf = 0;
float motor_rr = 0;

// void output_roll(PID *pid,signed short gx)
//{
//     if(gx>0&&gx<3.14)
//     {
//         pid_caculate(pid,gx_l, gx);
//     }
//     else
//     {

//         pid_caculate(pid,gx_l, gx-6.28);
//    }
//
//}
// void output_pitch(PID *pid,signed short gy)
//{
//
//}

// 计算pid
void text(PID *pid_roll, PID *pid_pitch)
{
    mpu_dmp_get_data(&pitch, &roll, &yaw);

    pid_caculate(pid_roll, 0, roll);
    pid_caculate(pid_pitch, 0, pitch);

    // 解算与赋值
    motor_lf = motor_lf_pwm - pid_roll->output_value - pid_pitch->output_value;
    motor_lr = motor_lf_pwm - pid_roll->output_value + pid_pitch->output_value;
    motor_rf = motor_lf_pwm + pid_roll->output_value - pid_pitch->output_value;
    motor_rr = motor_lf_pwm + pid_roll->output_value + pid_pitch->output_value;
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, motor_lf);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, motor_lr);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, motor_rf);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, motor_rr);
}
