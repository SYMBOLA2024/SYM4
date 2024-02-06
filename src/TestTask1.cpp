// Copyright (C) 2024 Symbola
// This code is licensed under the GNU General Public License version 3.0
// You can find the full text of the license at https://www.gnu.org/licenses/gpl-3.0.html
// For inquiries or additional permissions, please contact at symbola.co.uk/contact

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
