// Copyright (C) 2024 Symbola
// This code is licensed under the GNU General Public License version 3.0
// You can find the full text of the license at https://www.gnu.org/licenses/gpl-3.0.html
// For inquiries or additional permissions, please contact at symbola.co.uk/contact

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
