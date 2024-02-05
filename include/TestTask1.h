// TestTask1.h
#ifndef TEST_TASK_1_H
#define TEST_TASK_1_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Function to run as a FreeRTOS task for Test Task 1.
void TestTask1(void *pvParameters);

#endif // TEST_TASK_1_H
