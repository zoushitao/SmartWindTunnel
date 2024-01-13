

#ifndef smartwind_h
#define smartwind_h

#include <stdio.h>
#include <math.h>
#include "i2c.h"
#include "pca9685.h"
#include "usart.h"

typedef struct {
    unsigned wave_array[40];
    unsigned mode;
    unsigned position;
    unsigned initialized_flag;
	
	
	uint32_t wave_period;uint16_t pwm_scalar;
	
}wave_handle;

typedef struct {
    uint16_t pwm_up;
	uint16_t pwm_down;
	uint32_t step;
	unsigned up_down_flag;
	uint32_t period;
	uint16_t counter;
    unsigned initialized_flag;
}gust_handle;


typedef enum {report='r',paused='p',even='e',gust='g',steer='s',wave='w',echo='e',idle='i'}instruction;

typedef struct {
	//handles
	I2C_HandleTypeDef *left_i2c;
	I2C_HandleTypeDef *right_i2c;
	//pwm parameter
	float pwm_frequency;
	//runtime parameter
	uint32_t time_consumption;
	//status
	
	//wave mode
	wave_handle wave_handle;
	gust_handle gust_handle;
	

	
}fan_handle;




void fan_init(fan_handle *,I2C_HandleTypeDef *,I2C_HandleTypeDef *,float);
int fan_set_pwm(fan_handle *,uint8_t,uint8_t,unsigned,unsigned);
void fan_wave_initialize(fan_handle *,uint32_t wave_period,uint16_t pwm_scalar,unsigned mode);
void fan_wave_update(fan_handle *);
void fan_set_all(fan_handle *,unsigned,unsigned );
void fan_stop(fan_handle *);
void fan_device_detect(fan_handle *);
void fan_callibration(fan_handle *);
int check_device(fan_handle *,char,unsigned);
void fan_gust_initialize(fan_handle *,uint32_t gust_period,uint16_t pwm_up,uint16_t pwm_down);
//even mode
void fan_mode_echo(void);
void fan_gust_update(fan_handle *);

void fan_set_row(fan_handle *,unsigned,uint16_t,uint16_t);
void fan_set_col(fan_handle *,unsigned,uint16_t,uint16_t);
#endif /* smartwind_h */
