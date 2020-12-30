// Made for 28BYJ-48 step motor.
// 04.03.2019
// Ahmet N. YILDIRIM

// ensure this library description is only included once
#ifndef StepMotor_h
#define StepMotor_h

// include Arduino API
#include "Arduino.h"

// library interface description

class StepMotor
{
  // user-accessible "public" interface
  public:
    StepMotor(int,int,int,int);
    StepMotor(int,int,int,int,float,int);
    int pins[4];
    
    void set_delay(float);
    float get_delay(void);
    void set_direction(bool);
    bool get_direction(void);
    void set_steps_for_rev(int);
    int get_steps_for_rev(void);

    void one_step(void);
    void one_step_wo_flush(void);
    void flush(void);
    void step(int);
    void revolve(void);
    void revolve(int);


  // library-accessible "private" interface
  private:
    int _pin0, _pin1, _pin2, _pin3;

    void _flush_pins(void);
    void _step(void);

    float _delay = 10.0;  // milliseconds between every signals
    bool _direction = true;  // true: cw rotation, false: ccw rotation
    int _steps_for_rev = 512;  // step count for 360 degree turn of the motor

    int _logic_map[8][4]= {  // values sent to motor controller
      {LOW, LOW, LOW, HIGH},
      {LOW, LOW, HIGH, HIGH},
      {LOW, LOW, HIGH, LOW},
      {LOW, HIGH, HIGH, LOW},
      {LOW, HIGH, LOW, LOW},
      {HIGH, HIGH, LOW, LOW},
      {HIGH, LOW, LOW, LOW},
      {HIGH, LOW, LOW, HIGH}}; 
    
};

#endif
