/*
  Interactive Hello Demo
*/

#include "Modulino.h"

ModulinoDistance distance;

// Parametrization
#define ACTIVATION_DISTANCE                           300
#define GUARD_DISTANCE                                100
#define REP                                           5
#define INT_DELAY_MS                                  500

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(D12, OUTPUT);

  Serial.begin(9600);
  Modulino.begin();
  distance.begin();
}

// the loop function runs over and over again forever
void loop() {
  // Distance data
  int measure;
  uint8_t i;

  // Get distance from modulino
  if (distance.available()) {
    measure = distance.get();
    Serial.println(measure);
  }

  // If the distance is less thann the activation distance 
  if ((measure <= ACTIVATION_DISTANCE) && (measure > GUARD_DISTANCE))
  {
    for (i = 0; i < REP; i++)
    {
      digitalWrite(D12, HIGH);
      delay(INT_DELAY_MS);  
      digitalWrite(D12, LOW);
      delay(INT_DELAY_MS);
    }
  } 

  delay(10);
}
