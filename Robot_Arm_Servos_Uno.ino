#include <Servo.h>
#include <IRremote.h>
 
// Define the number of finger servos
#define SERVOS 4
 
// Define the number of states
#define STATES 7
 
// Create the servo objects.
Servo myservo[SERVOS];
Servo thumb;  
 
// Attach servos to digital pins on the Arduino 
int servo_pins[SERVOS] = {3,5,6,9}; 

//Attach IR Receiver
int ir_pin = 11;

// create instance of 'irrecv'
IRrecv irrecv(ir_pin); 

// create instance of 'decode_results'
decode_results results;
 
void setup() {
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  for(int i = 0; i < SERVOS; i++) {
     
    // Attach the servo to the servo object 
    myservo[i].attach(servo_pins[i]); 
 
    // Wait 500 milliseconds 
    delay(500);  
  }

  thumb.attach(10);
  
}
  
void loop() {
  
  if (irrecv.decode(&results)) {

  // Results of decoding are stored in result.value
  int readResults = results.value;
  // Prints the value as a button press
  Serial.println(readResults);

  // Button 0
  // Reset position
  switch(readResults) {
    case 26775:
    for (int i = 0; i < SERVOS; i++) {
      myservo[i].write(0);
      delay(100);
    }
    thumb.write(0);
    delay(100);
  }
  
  // Button 1
  switch(readResults) {
    case 12495:
    // Move in one direction.
    for (int i = 0; i <= 180; i = i + 1) {
      myservo[0].write(i);
      delay(15);
    }
    delay(500);
    // Move in the other direction
    for (int i = 180; i >= 0; i = i - 1) {
      myservo[0].write(i);
      delay(15);
    }
  }

  // Button 2
  switch(readResults) {
    case 6375:
    for (int i = 0; i <= 180; i = i + 1) {
      myservo[1].write(i);
      delay(15);
    }
    delay(500);
    for (int i = 180; i >= 0; i = i - 1) {
      myservo[1].write(i);
      delay(15);
    }
  }

  // Button 3
  switch(readResults) {
    case 31365:
    for (int i = 0; i <= 180; i = i + 1) {
      myservo[2].write(i);
      delay(15);
    }
    delay(500);
    for (int i = 180; i >= 0; i = i - 1) {
      myservo[2].write(i);
      delay(15);
    }
  }

  // Button 4
  switch(readResults) {
    case 4335:
    for (int i = 0; i <= 180; i = i + 1) {
      myservo[3].write(i);
      delay(15);
    }
    delay(500);
    for (int i = 180; i >= 0; i = i - 1) {
      myservo[3].write(i);
      delay(15);
    }
  }

  // Button 5
  switch(readResults) {
    case 14535:
    for (int i = 0; i <= 45; i = i + 1) {
      thumb.write(i);
      delay(15);
    }
    delay(500);
    for (int i = 45; i >= 0; i = i - 1) {
      thumb.write(i);
      delay(15);
    }
  }

  // Button 6
  switch(readResults) {
    case 23205:
    for (int i = 0; i < SERVOS; i++) {
      for (int j = 0; j <= 180; j = j + 1) {
        myservo[i].write(j);
        delay(15);
      }
    }
    for (int k = 0; k <= 45; k = k + 1){
      thumb.write(k);
      delay(15);
    }

    delay(500);
    
    for (int a = 0; a < SERVOS; a++) {
      for (int b = 180; b >= 0; b = b - 1){
        myservo[a].write(b);
        delay(15);
      }
    }
    for (int c = 45; c >= 0; c = c - 1) {
      thumb.write(c);
      delay(15);
    }
  }

  // Button 7
  switch(readResults) {
    case 17085:
    for (int i = 1; i < 3; i++) {
      for (int j = 0; j <= 180; j = j + 1) {
        myservo[i].write(j);
        delay(15);
      }
      }
    delay(500);
    for (int a = 1; a < 3; a++) {
      for (int b = 180; b >= 0; b = b - 1){
        myservo[a].write(b);
        delay(15);
      }
    }
  }

  // Button 8
  switch(readResults) {
    case 19125:
    for (int i = 0; i <= 180; i = i + 1) {
       myservo[2].write(i);
       delay(15);
    }
    delay(500);
    for (int i = 180; i >= 0; i = i - 1) {
      myservo[2].write(i);
      delay(15);
    }
  }
  
  // Restart the ISR state machine and Receive the next value
  irrecv.resume();
  }   
}   
