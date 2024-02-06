// Copyright (C) 2024 Symbola
// This code is licensed under the GNU General Public License version 3.0
// You can find the full text of the license at https://www.gnu.org/licenses/gpl-3.0.html
// For inquiries or additional permissions, please contact at symbola.co.uk/contact

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
