// CommandInterfaceTask.h
#ifndef COMMAND_INTERFACE_TASK_H
#define COMMAND_INTERFACE_TASK_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Maximum number of arguments a command can have.
const int maxArgs = 10;

// Function to run as a FreeRTOS task for handling command interface.
void CommandInterfaceTask(void *pvParameters);

// Declaration of functions to be used in the command interface.
void displayHelp();
void displayCommands();
void testFunction1(String args[], int argCount);
void testFunction2(String args[], int argCount);
void testFunction3(String args[], int argCount);

#endif
