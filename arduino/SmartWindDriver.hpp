#include "Adafruit_PWMServoDriver.h"

typedef uint8_t addr_type;
typedef uint8_t channel_type;
typedef uint16_t pwm_type;

typedef enum { horizonal,
               vertical } direction_type;

class SmartWindDriver {

private:
  /*PCA9685 Interface*/
  //pca codes here
  Adafruit_PWMServoDriver _leftPCA[50];
  Adafruit_PWMServoDriver _rightPCA[50];
  void _PCAInit(void);



  /*Low Level Interface*/
  void _setSingleFan(int row, int col, pwm_type on, pwm_type off);

  /*SmartWind Mode Handle*/
  struct {
    unsigned wave_array[40];
    direction_type direction;
    unsigned position;
    bool initialized_flag = false;


    uint32_t wave_period;
    uint16_t pwm_scalar;

  } _waveHandle;

  struct {
    uint16_t pwm_up;
    uint16_t pwm_down;
    uint32_t step;
    unsigned up_down_flag;
    uint32_t period;
    uint16_t counter;
    unsigned initialized_flag;
  } _gustHandle;


  /*SmartWind Mode Function*/
public:
  void setAll(pwm_type on, pwm_type off);
  void setRow(int row, pwm_type on, pwm_type off);
  void setCol(int col, pwm_type on, pwm_type off);

  /*Mode Handle*/
  void waveModeInit(unsigned int spatialPeriod, pwm_type pwmScalar, direction_type direction);
  void waveModeUpdate(void);
  /*Report Functions*/
private:
  inline void reportAllSet(pwm_type on, pwm_type off);
  inline void reportRowSet(int row, pwm_type on, pwm_type off);
  inline void reportColSet(int col, pwm_type on, pwm_type off);
};
