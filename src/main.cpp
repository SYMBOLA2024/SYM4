// Copyright (C) 2024 Symbola
// This code is licensed under the GNU General Public License version 3.0
// You can find the full text of the license at https://www.gnu.org/licenses/gpl-3.0.html
// For inquiries or additional permissions, please contact at symbola.co.uk/contact

// main.cpp
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "main.h"
#include "CommandInterfaceTask.h"
#include "TestTask1.h"
#include "TestTask2.h"
#include "TestTask3.h"

// Function prototype for createTasks.
void createTasks();

void setup() {
    // Initialize Serial port for CLI communication & debugging.
    Serial.begin(SERIAL_BAUD_RATE);

    // Wait for the Serial port to connect.
    while (!Serial) {
        delay(10);
    }

    // Notify about the start of the program.
    Serial.println("Starting FreeRTOS tasks...");

    // Create tasks.
    createTasks();

    // Start the scheduler.
    vTaskStartScheduler();
}

void loop() {
    // Empty loop - Execution should not reach here in FreeRTOS.
}

void createTasks() {
    // Create the Command Line Interface task.
    if (xTaskCreate(
            CommandInterfaceTask, 
            "CommandInterface", 
            COMMAND_INTERFACE_TASK_STACK_SIZE, 
            NULL, 
            COMMAND_INTERFACE_TASK_PRIORITY, 
            NULL
        ) != pdPASS) {
        Serial.println("Failed to create Command Interface task");
        return;
    }

    // Create Test Task 1.
    if (xTaskCreate(
            TestTask1, 
            "TestTask1", 
            TEST_TASK_STACK_SIZE, 
            NULL, 
            TEST_TASK_PRIORITY_START, 
            NULL
        ) != pdPASS) {
        Serial.println("Failed to create Test Task 1");
        return;
    }

    // Create Test Task 2.
    if (xTaskCreate(
            TestTask2, 
            "TestTask2", 
            TEST_TASK_STACK_SIZE, 
            NULL, 
            TEST_TASK_PRIORITY_START + 1, 
            NULL
        ) != pdPASS) {
        Serial.println("Failed to create Test Task 2");
        return;
    }

    // Create Test Task 3.
    if (xTaskCreate(
            TestTask3, 
            "TestTask3", 
            TEST_TASK_STACK_SIZE, 
            NULL, 
            TEST_TASK_PRIORITY_START + 2, 
            NULL
        ) != pdPASS) {
        Serial.println("Failed to create Test Task 3");
        return;
    }
}
