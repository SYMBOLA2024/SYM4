// Copyright (C) 2024 Symbola
// This code is licensed under the GNU General Public License version 3.0
// You can find the full text of the license at https://www.gnu.org/licenses/gpl-3.0.html
// For inquiries or additional permissions, please contact at symbola.co.uk/contact

// TestTask2.h
#ifndef TEST_TASK_2_H
#define TEST_TASK_2_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Function to run as a FreeRTOS task for Test Task 2.
void TestTask2(void *pvParameters);

#endif // TEST_TASK_2_H
