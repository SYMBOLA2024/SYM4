// TestTask2.cpp
#include "TestTask2.h"

void TestTask2(void *pvParameters) {
  (void) pvParameters; // This line prevents unused variable warnings.

  while (1) {
    // Implement the functionality of Test Task 2 here.
//  Serial.println("Test Task 2 is running");

    // Delay for a period of time (e.g., 2 seconds).
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}
