#include <Servo.h>

// Define servo objects for left leg
Servo hipServo1;
Servo kneeServo1;
Servo ankleServo1;
Servo footServo1;

// Define servo objects for right leg
Servo hipServo2;
Servo kneeServo2;
Servo ankleServo2;
Servo footServo2;


void smoothMove1(Servo &servo, int startAngle, int endAngle, int stepDelay) {
  if (startAngle < endAngle) {
    for (int i = startAngle; i <= endAngle; i++) {
      servo.write(i);
      delay(stepDelay);
    }
  } else {
    for (int i = startAngle; i >= endAngle; i--) {
      servo.write(i);
      delay(stepDelay);
    }
  }
}


// Function to move a servo from startAngle to endAngle with a specific step delay
void smoothMove2(Servo &servo, int startAngle, int endAngle, int stepDelay) {
  if (startAngle > endAngle) {
    for (int i = startAngle; i >= endAngle; i--) {
      servo.write(i);
      delay(stepDelay);
    }
    
  } else {
    for (int i = startAngle; i <= endAngle; i++) {
      servo.write(i);
      delay(stepDelay);
    }
  }
}




void setup() {
  // Attach the servo objects to specific pins
  hipServo1.attach(2);
  kneeServo1.attach(3);
  ankleServo1.attach(4);
  footServo1.attach(5);

  hipServo2.attach(6);
  kneeServo2.attach(7);
  ankleServo2.attach(8);
  footServo2.attach(9);
}

void loop() {

//************************* Left ************************

  // Step 1: Lift the leg by moving the foot up
  smoothMove1(footServo1, 90, 45, 5);
  
  // Step 2: Move the leg forward by moving the hip forward
  smoothMove1(hipServo1, 90, 60, 5);


  // Step 3: Straighten the knee to extend the leg
  smoothMove1(kneeServo1, 90, 135, 5);
  
  // Step 4: Adjust the ankle to place the foot correctly
  smoothMove1(ankleServo1, 90, 60, 5);
  
  // Step 5: Lower the foot to the ground
  smoothMove1(footServo1, 45, 90, 5);
  
  // Step 6: Bend the knee to prepare for the next step
  smoothMove1(kneeServo1, 135, 90, 5);
  
  // Step 7: Move the hip back to original position
  smoothMove1(hipServo1, 60, 90, 5);
  
  // Step 8: Reset the ankle
  smoothMove1(ankleServo1, 60, 90, 5);
  
  // Delay before starting the next cycle
  delay(500);

//--------------------------------------------------------------------------------------
  //************************* Right ************************


// Step 1: Lift the leg by moving the foot up
  smoothMove2(footServo2, 90, 45, 5);
  
  // Step 2: Move the leg forward by moving the hip forward
  smoothMove2(hipServo2, 90, 120, 5);

  // Step 3: Straighten the knee to extend the leg
  smoothMove2(kneeServo2, 90, 45, 5);
  
  // Step 4: Adjust the ankle to place the foot correctly
  smoothMove2(ankleServo2, 90, 120, 5);
  
  // Step 5: Lower the foot to the ground
  smoothMove2(footServo2, 45, 90, 5);
  
  // Step 6: Bend the knee to prepare for the next step
  smoothMove2(kneeServo2, 45, 90, 5);
  
  // Step 7: Move the hip back to original position
  smoothMove2(hipServo2, 120, 90, 5);
  
  // Step 8: Reset the ankle
  smoothMove2(ankleServo2, 120, 90, 5);
  
  // Delay before starting the next cycle
  delay(500);


}
