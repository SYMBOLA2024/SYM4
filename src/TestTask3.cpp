// TestTask3.cpp
#include "TestTask3.h"

void TestTask3(void *pvParameters) {
  (void) pvParameters; // This line prevents unused variable warnings.

  while (1) {
    // Implement the functionality of Test Task 3 here.
//  Serial.println("Test Task 3 is running");

    // Delay for a period of time (e.g., 3 seconds).
    vTaskDelay(pdMS_TO_TICKS(3000));
  }
}
