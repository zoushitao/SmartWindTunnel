#include <Arduino_JSON.h>
#include "SmartWindDriver.hpp"


void SmartWindDriver::_setSingleFan(int row, int col, pwm_type on, pwm_type off){
  

};



void SmartWindDriver::setAll(pwm_type on, pwm_type off) {
  reportAllSet(on, off);
  int r, c;
  for (r = 1; r <= 40; r++) {
    for (c = 1; c <= 40; c++) {
      _setSingleFan(r, c, on, off);
    }
  }
  return;
}



void SmartWindDriver::setRow(int row, pwm_type on, pwm_type off) {
  reportRowSet(row, on, off);

  int r, c;
  r = row;
  for (c = 1; c <= 40; c++) {
    _setSingleFan(r, c, on, off);
  }

  return;
}

void SmartWindDriver::waveModeInit(unsigned int spatialPeriod,pwm_type pwmScalar,direction_type direction){
  if(_waveHandle.direction == direction and _waveHandle.pwm_scalar == pwmScalar 
		and _waveHandle.wave_period==spatialPeriod){

      Serial.println("sdsd ");
			return;
	}
	
		_waveHandle.direction = direction;
	_waveHandle.pwm_scalar = pwmScalar;
 _waveHandle.wave_period=spatialPeriod;
	
	Serial.println("sucess");
    spatialPeriod /=2;
    double step=3.1415926535f/(double(spatialPeriod));
    int i=0;
    for(i=0;i<40;i++){
        _waveHandle.wave_array[i] = (uint16_t)(fabs(sin(i*step))*pwmScalar);
    }
    _waveHandle.position=0;
    //1 for horizonal,0 for vertical
    _waveHandle.direction= direction;
    _waveHandle.initialized_flag = true;

    
    return;
};


void SmartWindDriver::waveModeUpdate(void){
  if(not _waveHandle.initialized_flag  ){
    
        return;
        
    }
    Serial.println("fuck adad");
    int r,c;
    //Horizonal
    if(_waveHandle.direction == horizonal){
        for(c=1;c<=40;c++){
            setCol(c,0,_waveHandle.wave_array[(c+_waveHandle.position)%40]);
					
        }
    }
    //Vertical
    if(_waveHandle.direction == vertical){
        for(r=1;r<=40;r++){
            setCol(r,0,_waveHandle.wave_array[(r+_waveHandle.position)%40]);
					
        }
    }
    _waveHandle.position ++;
}

void SmartWindDriver::setCol(int col, pwm_type on, pwm_type off) {
  reportColSet(col, on, off);

  int r, c;
  c = col;
  for (r = 1; r <= 40; r++) {
    _setSingleFan(r, c, on, off);
  }
}


void SmartWindDriver::reportAllSet(pwm_type on, pwm_type off) {
  JSONVar reportJSON;
  reportJSON["type"] = "pwm_report";
  reportJSON["range"] = "all";
  reportJSON["value"] = off - on;
  Serial.println(reportJSON);
}

void SmartWindDriver::reportRowSet(int row, pwm_type on, pwm_type off) {
  JSONVar reportJSON;
  reportJSON["type"] = "pwm_report";
  reportJSON["range"] = "row";
  reportJSON["position"] = row;
  reportJSON["value"] = off - on;
  Serial.println(reportJSON);
}

void SmartWindDriver::reportColSet(int col, pwm_type on, pwm_type off) {
  JSONVar reportJSON;
  reportJSON["type"] = "pwm_report";
  reportJSON["range"] = "col";
  reportJSON["position"] = col;
  reportJSON["value"] = off - on;
  Serial.println(reportJSON);
}


void SmartWindDriver::_PCAInit(void){
  for (int i=0;i<50;++i){
    //_leftPCA[i] = Adafruit_PWMServoDriver( PCA9685_I2C_ADDRESS + 1, TwoWire);
  }
}