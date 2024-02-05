// TestTask2.h
#ifndef TEST_TASK_2_H
#define TEST_TASK_2_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Function to run as a FreeRTOS task for Test Task 2.
void TestTask2(void *pvParameters);

#endif // TEST_TASK_2_H
