// Made for 28BYJ-48 step motor.
// 04.03.2019
// Ahmet N. YILDIRIM

#include "Arduino.h"
#include "StepMotor.h"

// Class constructor
StepMotor::StepMotor(int pin0, int pin1, int pin2, int pin3)
{
  pins[0] = _pin0 = pin0;
  pins[1] = _pin1 = pin1;
  pins[2] = _pin2 = pin2;
  pins[3] = _pin3 = pin3;

  for (int i; i<4; i++)
    pinMode(pins[i], OUTPUT);
}


// Getters and setters
void StepMotor::set_delay(float delay){
  _delay = delay;}  // Milliseconds between every step. Must be ">=1"

float StepMotor::get_delay(){
  return _delay;}

void StepMotor::set_direction(bool dir){
  _direction = dir;}  // true: cw rotation, false: ccw rotation

bool StepMotor::get_direction(){
  return _direction;}

void StepMotor::set_steps_for_rev(int i){
  _steps_for_rev = i;}  // Step count for 360 degree turn of the motor

int StepMotor::get_steps_for_rev(){
  return _steps_for_rev;}


// Step motor funcs
void StepMotor::_flush_pins(void)
{
  // Sets the pins LOW.
  for (int i=0; i<4; i++)
    digitalWrite(pins[i], LOW);
}

void StepMotor::_step(void)
  // Writes values to pins based on "_logic_map" and "_direction" continiously.
  // After setting values for all 4 pins, waits "_delay" millisconds.
{
  if (! _direction){  // cw rotation
    for (int i=0; i<8; i++){
      for (int j=0; j<4; j++){
	digitalWrite(pins[j], _logic_map[i][j]);
      }
      delay(_delay);
    }
  }
  else {  // ccw rotation
    for (int i=7; i>=0; i--){
      for (int j=0; j<4; j++){
	digitalWrite(pins[j], _logic_map[i][j]);
      }
      delay(_delay);
    }
  }
}

void StepMotor::one_step(void)
  // Makes one step and sets pins LOW.
  // Not efficient in loops.
  // If you want continious rotation, use "step(int)" instead.
{
  _step();
  _flush_pins();
}

void StepMotor::one_step_wo_flush(void)
  // Makes one step without setting the pins LOW.
  // Can be used in loops. For example: no delay loops.
{
  _step();
}

void StepMotor::flush(void)
  // Sets pins' value to LOW.
{
  _flush_pins();
}

void StepMotor::step(int count)
  // Steps up to given value and flushes pins.
  // Not flushing after every "_step()" makes this function 
  // efficient for continious rotation.
{
  for (int i=0; i<count; i++)
    _step();       
  _flush_pins();  // Attention! "_flush_pins()" is out of for loop.
}

void StepMotor::revolve(void)
  // Makes one 360 degree rotation.
{
  step(_steps_for_rev);
}

void StepMotor::revolve(int count)
  // Makes 360 degree rotations by given number.
{
  for (int i=0; i<count; i++)
    revolve();
}


