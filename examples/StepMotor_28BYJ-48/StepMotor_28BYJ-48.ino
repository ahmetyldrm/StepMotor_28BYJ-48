// Made for 28BYJ-48 step motor.
// 04.03.2019
// Ahmet N. YILDIRIM

#include <StepMotor.h>

StepMotor myStepMotor(4,5,6,7); // Set signal pins to 4, 5, 6, 7.

void setup() {
  //myStepMotor.set_steps_for_rev(8*64) // Set the steps count for one 360 degree turn.
  // Default value is 8*64. You can get the value by 
  // "myStepMotor.get_steps_for_rev()" function.
  
  myStepMotor.set_direction(false); // Set direction to counter-clockwise (ccw).
  myStepMotor.set_delay(1);         // 1 millisecond delay between each step.
                                    // Delay must be >= 1. Greater the value slower the motor.
                                    // 1 is the fastest. 
  myStepMotor.step(250);            // Make 250 steps ccw.
  delay(1000);                      // Wait 1000 milliseconds. (1 sec.)
  
  myStepMotor.set_direction(true);  // Set direction to clockwise (cw) direction.
  myStepMotor.revolve();            // Make one 360 degree turn.
  delay(250);
  
  myStepMotor.set_direction(!myStepMotor.get_direction()); // Set direction to opposite.
  myStepMotor.set_delay(4); // Make step motor slower. 1 step every 4 milliseconds.
  myStepMotor.revolve();    // Make one 360 degree turn.
  delay(250);
  
  myStepMotor.set_direction(!myStepMotor.get_direction());
  myStepMotor.set_delay(1);
  myStepMotor.revolve(2); // Make two 360 degree turns.
}

void loop() {

}
