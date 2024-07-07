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




// Function to move a servo from startAngle to endAngle with a specific step delay
void smoothMove(Servo &servo, int startAngle, int endAngle, int stepDelay) {
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
  // Step 1: Lift the leg by moving the foot up
  smoothMove(footServo1, 90, 45, 5);
  
  // Step 2: Move the leg forward by moving the hip forward
  smoothMove(hipServo1, 90, 120, 5);

  // Step 3: Straighten the knee to extend the leg
  smoothMove(kneeServo1, 90, 45, 5);
  
  // Step 4: Adjust the ankle to place the foot correctly
  smoothMove(ankleServo1, 90, 120, 5);
  
  // Step 5: Lower the foot to the ground
  smoothMove(footServo1, 45, 90, 5);
  
  // Step 6: Bend the knee to prepare for the next step
  smoothMove(kneeServo1, 45, 90, 5);
  
  // Step 7: Move the hip back to original position
  smoothMove(hipServo1, 120, 90, 5);
  
  // Step 8: Reset the ankle
  smoothMove(ankleServo1, 120, 90, 5);
  
  // Delay before starting the next cycle
  delay(500);

//--------------------------------------------------------------------------------------

// Step 1: Lift the leg by moving the foot up
  smoothMove(footServo2, 90, 45, 5);
  
  // Step 2: Move the leg forward by moving the hip forward
  smoothMove(hipServo2, 90, 120, 5);

  // Step 3: Straighten the knee to extend the leg
  smoothMove(kneeServo2, 90, 45, 5);
  
  // Step 4: Adjust the ankle to place the foot correctly
  smoothMove(ankleServo2, 90, 120, 5);
  
  // Step 5: Lower the foot to the ground
  smoothMove(footServo2, 45, 90, 5);
  
  // Step 6: Bend the knee to prepare for the next step
  smoothMove(kneeServo2, 45, 90, 5);
  
  // Step 7: Move the hip back to original position
  smoothMove(hipServo2, 120, 90, 5);
  
  // Step 8: Reset the ankle
  smoothMove(ankleServo2, 120, 90, 5);
  
  // Delay before starting the next cycle
  delay(500);


}
