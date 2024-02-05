// TestTask1.cpp
#include "TestTask1.h"

void TestTask1(void *pvParameters) {
  (void) pvParameters; // This line prevents unused variable warning.

  while (1) {
    // Here, you can implement what you want this task to do.
//  Serial.println("Test Task 1 is running");

    // Delay for a period of time (e.g., 1 second).
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
