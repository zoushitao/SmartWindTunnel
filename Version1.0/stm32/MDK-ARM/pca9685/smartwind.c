//
//  smartwind.c
//  easyparser
//
//  Created by 邹世韬 on 2023/7/23.
//

#include "smartwind.h"
#include "string.h"
#define debug 0
static char data_buffer[100];
char tBuf[256];
void fan_buf_clear(void){
	memset((void *)tBuf, 0x00, 256);
}


void fan_init(fan_handle *fan_conf,I2C_HandleTypeDef *left,I2C_HandleTypeDef *right ,float freq){
	fan_conf->left_i2c=left;
	fan_conf->right_i2c=right;
	fan_conf->pwm_frequency=freq;
	/*Check i2c connection*/
	
	uint8_t devices = 0u;
 

 
	
	
	/******************/
	fan_device_detect(fan_conf);
	
	/*Set frequency*/
	unsigned start_address,end_address,channel;
	start_address = 0x40;
  end_address = 0x72;
	//left i2c
	unsigned i;
	
	for(i=start_address;i<=end_address;i++){
		 pca9685_handle_t pca_handle;
		pca_handle.i2c_handle = fan_conf->left_i2c;
    pca_handle.device_address=i<<1;
	 pca_handle.inverted=false;
	pca9685_init(&pca_handle);
	pca9685_set_pwm_frequency(&pca_handle,fan_conf->pwm_frequency);	
	}
	//right i2c
	for(i=start_address;i<=end_address;i++){
		 pca9685_handle_t pca_handle;
		pca_handle.i2c_handle = fan_conf->right_i2c;
    pca_handle.device_address=i<<1;
	 pca_handle.inverted=false;
	pca9685_init(&pca_handle);
	pca9685_set_pwm_frequency(&pca_handle,fan_conf->pwm_frequency);	
	}
	
	
	//Step3 : Callibration
	fan_callibration(fan_conf);
};


int fan_set_pwm(fan_handle *fan_conf,uint8_t row,uint8_t col,unsigned pwm_dowm,unsigned pwm_up){
    //validator
    if(row>40 && col>40)return -1;
    unsigned address,channel;
    
    const unsigned channel_map[]={0,1,6,7
        ,2,3,4,5,
        10,11,12,13,
        8,9,14,15};
    
    I2C_HandleTypeDef *i2c;

    if(col/4 <= 5){
        //Left
        address = 0x40+(row-1)/4*5+(col-1)/4;
        channel = channel_map[(row-1)%4*4+(col-1)%4];
        //set i2c handle = left handle
        i2c = fan_conf->left_i2c;
			
			//check valid
			//if(check_device(fan_conf,'l',address)==0)return 0;
        
    }else{
			//Right
        
        address = 0x40+(row-1)/4*5+(40-col)/4;       
        channel = channel_map[(row-1)%4*4+(col-1)%4];
			
			//helper
			
			//check valid
			//if(check_device(fan_conf,'r',address)==0)return 0;
       //set i2c handle = right handle
			i2c = fan_conf->right_i2c;
        
    }
    
    pca9685_handle_t pca_handle;
		
    
    //address=address<<1;
    
    //stm 32 optimizer
		pca_handle.i2c_handle = i2c;
    pca_handle.device_address=address<<1;
	 pca_handle.inverted=false;
		
  


  
    return  pca9685_set_channel_pwm_times(&pca_handle, channel, pwm_dowm, pwm_up);
    
};

void fan_wave_initialize(fan_handle * fan_conf,uint32_t wave_period,uint16_t pwm_scalar,unsigned mode){
		//do something
	if(fan_conf->wave_handle.mode == mode && fan_conf->wave_handle.pwm_scalar == pwm_scalar 
		&& fan_conf->wave_handle.wave_period==wave_period){
			return;
	}
	
		fan_conf->wave_handle.mode = mode;
	fan_conf->wave_handle.pwm_scalar = pwm_scalar ;
	fan_conf->wave_handle.wave_period=wave_period;
	
	
    wave_period /=2;
    float step=3.1415926535f/((float)wave_period);
    int i=0;
    for(i=0;i<40;i++){
        fan_conf->wave_handle.wave_array[i] = (uint16_t)(fabs(sin(i*step))*pwm_scalar);
    }
    fan_conf->wave_handle.position=0;
    //1 for horizonal,0 for vertical
    fan_conf->wave_handle.mode= mode;
    fan_conf->wave_handle.initialized_flag = 1;
    
}

void fan_wave_update(fan_handle * fan_conf){
    if(fan_conf->wave_handle.initialized_flag != 1 ){
        return;
    }
    
    int r,c;
    //Horizonal
    if(fan_conf->wave_handle.mode == 1){
        for(c=1;c<=40;c++){
            fan_set_col(fan_conf,c,0,fan_conf->wave_handle.wave_array[(c+fan_conf->wave_handle.position)%40]);
					
        }
    }
    //Vertical
    if(fan_conf->wave_handle.mode == 0){
        for(r=1;r<=40;r++){
            fan_set_row(fan_conf,r,0,fan_conf->wave_handle.wave_array[(r+fan_conf->wave_handle.position)%40]);
					
        }
    }
    fan_conf->wave_handle.position ++;
    
}

void fan_set_all(fan_handle * fan_conf,unsigned pwm_down,unsigned pwm_up){
	
	
    int r,c;
    for(r=1;r<=40;r++){
        for(c=1;c<=40;c++){
					fan_set_pwm(fan_conf,r, c, pwm_down, pwm_up);
					 
           
        }
        
    }
		printf("m$2,0,%d,%d$ \n",pwm_down,pwm_up);
		HAL_Delay(3);	
}

void fan_stop(fan_handle * fan_conf){
    fan_set_all(fan_conf,0, 0);
};

void fan_device_detect(fan_handle * fan_conf)
{
	
	fan_buf_clear();
	
	//left 
	
	
  uint8_t devices = 0u;
  I2C_HandleTypeDef *hi2c2=fan_conf->left_i2c;
	#if debug
  printf("Left:Searching for I2C devices on the bus...\n");
	#endif 
  /* Values outside 0x03 and 0x77 are invalid. */
  for (uint8_t i = 0x40; i < 0x72; i++)
  {
    uint8_t address = i << 1 ;
    /* In case there is a positive feedback, print it out. */
    if (HAL_OK == HAL_I2C_IsDeviceReady(hi2c2, address, 3u, 10u))
    {
			
			
			#if debug
			printf("Left Device found: 0x%02X\n", address>>1);      
			#endif
			
			devices++;
    }else{
			
			printf("q$%i,%i$\n",0,address>>1);
		}
  }
  /* Feedback of the total number of devices. */

	
	//Right
	
	
  hi2c2=fan_conf->right_i2c;
	
	#if debug
  printf("Right:Searching for I2C devices on the bus...\n");
	#endif 
  /* Values outside 0x03 and 0x77 are invalid. */
  for (uint8_t i = 0x40; i < 0x72; i++)
  {
    uint8_t address = i << 1 ;
    /* In case there is a positive feedback, print it out. */
    if (HAL_OK == HAL_I2C_IsDeviceReady(hi2c2, address, 3u, 10u))
    {
			
			#if debug
			//printf("Device found: 0x%02X\n", address>>1);
      
			#endif
			
			devices++;
    }else{
			printf("q$%i,%i$\n",1,address>>1);
		}
  }
  /* Feedback of the total number of devices. */
  if (0u == devices)
  {
		#if debug
		printf("No device found.\n");
		#endif
  }
  else
  {
		#if debug
   printf("Total found devices: %d\n", devices);
		#endif
		
  }
	//report sending....

	
	//sprintf(tBuf,"t$left mising total");
	
}

void fan_callibration(fan_handle * fan_conf){
	uint32_t start,end;//unit : ms
	start=HAL_GetTick();
	fan_set_all(fan_conf,0,3000);
	fan_set_all(fan_conf,0,0);
	
	end = HAL_GetTick();
	
	fan_conf->time_consumption = (end-start)/2;
	printf("time : %i",fan_conf->time_consumption);
}

void fan_mode_echo(void){
	char echo_text[30];
	scanf("%s",echo_text);
	printf("%s",echo_text);
};

void fan_gust_initialize(fan_handle * fan_conf,uint32_t gust_period,uint16_t pwm_up,uint16_t pwm_down){
	if(fan_conf->gust_handle.initialized_flag==1 && fan_conf->gust_handle.pwm_up == pwm_up && fan_conf->gust_handle.pwm_down == 
			pwm_down && fan_conf->gust_handle.period == gust_period)return;
	fan_conf->gust_handle.pwm_down = pwm_down;
	fan_conf->gust_handle.pwm_up = pwm_up;
	double temp=(double)pwm_up-(double)pwm_down;
	
	temp = temp/((double)gust_period);
	
	temp = temp*((double)fan_conf->time_consumption);
		
	fan_conf->gust_handle.step = (uint32_t)temp;
	fan_conf->gust_handle.initialized_flag=1;
	fan_conf->gust_handle.counter = 0;
	//0 for up 1 for down
	fan_conf->gust_handle.up_down_flag = 0;
	fan_conf->gust_handle.period = gust_period;
	
};

void fan_gust_update(fan_handle *fan_conf){
	
	if(fan_conf->gust_handle.up_down_flag == 0){
		fan_conf->gust_handle.counter = fan_conf->gust_handle.counter+fan_conf->gust_handle.step;
		if(fan_conf->gust_handle.counter >= fan_conf->gust_handle.pwm_up){
			fan_conf->gust_handle.up_down_flag = 1;
			return;
		}
		//printf("@@counter:%i \n",fan_conf->gust_handle.counter);
	}else{		
		if(fan_conf->gust_handle.counter <fan_conf->gust_handle.pwm_down){
			fan_conf->gust_handle.up_down_flag = 0;
			return;
			//overflow process
		}
		
		if(fan_conf->gust_handle.counter <=fan_conf->gust_handle.step){
			fan_conf->gust_handle.up_down_flag = 0;
			return;
		}
		fan_conf->gust_handle.counter -= fan_conf->gust_handle.step;
	}
	
	fan_set_all(fan_conf,0,fan_conf->gust_handle.counter);
	
};

void fan_set_row(fan_handle *fan_conf,unsigned row,uint16_t pwm_down,uint16_t pwm_up){
	  
	
	
	
	int r,c;
	r=row;
        for(c=1;c<=40;c++){
					fan_set_pwm(fan_conf,r, c, pwm_down, pwm_up); 
           
        }
        
   printf("m$0,%d,%d,%d$ \n",row,pwm_down,pwm_up); 
		HAL_Delay(3);		
				
};

void fan_set_col(fan_handle *fan_conf,unsigned col,uint16_t pwm_down,uint16_t pwm_up){
	
	int r,c;
	c=col;
        for(r=1;r<=40;r++){
					fan_set_pwm(fan_conf,r, c, pwm_down, pwm_up); 
           
        }
        
    printf("m$1,%d,%d,%d$ \n",col,pwm_down,pwm_up);
				HAL_Delay(3);
};
/**
 * @brief   This is needed by printf().
 * @param   file
 * @param   *data
 * @param   len
 * @return  len
 */
