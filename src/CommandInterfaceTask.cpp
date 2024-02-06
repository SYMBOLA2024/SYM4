// Copyright (C) 2024 Symbola
// This code is licensed under the GNU General Public License version 3.0
// You can find the full text of the license at https://www.gnu.org/licenses/gpl-3.0.html
// For inquiries or additional permissions, please contact at symbola.co.uk/contact

// CommandInterfaceTask.cpp
#include "CommandInterfaceTask.h"

void CommandInterfaceTask(void *pvParameters) {
  // Sends a welcome message and instructions over serial upon task start.
  Serial.println("Welcome to the ESP32 Command Interface!");
  Serial.println("Type 'help' for assistance or 'commands' to list all commands.");
  Serial.print("> ");

  // Variables for managing command input and parsing.
  static String inputLine = ""; 
  static bool inQuotes = false; 
  static bool validCommand = true; 

  // Loop to continuously check for and process serial input.
  while (1) {
    // Check if data is available to read from the serial port.
    if (Serial.available() > 0) {
      // Read the next character from the serial port.
      char incomingChar = Serial.read();

      // Check if the character signifies the end of a command.
      if (incomingChar == '\n' || incomingChar == '\r') {
        // Move to a new line on the serial output.
        Serial.println();

        // Prepare for a new command input.
        validCommand = true;
        // Check if any input was collected before the newline character.
        if (inputLine.length() > 0) {
          // Prepare to parse the collected input.
          int argc = 0;
          String argv[maxArgs]; 
          String currentArg = ""; 
          inQuotes = false; 

          // Parse the input line character by character.
          for (int i = 0; i < inputLine.length(); i++) {
            char c = inputLine[i];

            // Manage quote-enclosed arguments.
            if (c == '\"') {
              inQuotes = !inQuotes;
              // Finalize the current argument when closing quotes.
              if (!inQuotes && currentArg.length() > 0) {
                if (argc >= maxArgs) {
                  // Handle exceeding the maximum number of arguments.
                  Serial.println("Error: Too many arguments.");
                  validCommand = false;
                  break;
                }
                // Store the completed argument.
                argv[argc++] = currentArg;
                currentArg = ""; 
              }
            } else if (c == ' ' && !inQuotes) {
              // Handle space as a delimiter outside of quotes.
              if (currentArg.length() > 0) {
                if (argc >= maxArgs) {
                  Serial.println("Error: Too many arguments.");
                  validCommand = false;
                  break;
                }
                argv[argc++] = currentArg;
                currentArg = ""; 
              }
            } else {
              // Accumulate characters into the current argument.
              currentArg += c;
            }
          }

          // Add the last argument to the array if it's not empty.
          if (currentArg.length() > 0 && argc <= maxArgs) {
            argv[argc++] = currentArg;
          }

          // Execute the parsed command if valid.
          if (validCommand && argc > 0) {
            // Compare the command against known commands and execute the corresponding function.
            if (argv[0] == "help") {
              displayHelp();
            } else if (argv[0] == "commands") {
              displayCommands();
            } else if (argv[0] == "test1") {
              testFunction1(argv, argc);
            } else if (argv[0] == "test2") {
              testFunction2(argv, argc);
            } else if (argv[0] == "test3") {
              testFunction3(argv, argc);
            }
          }

          // Reset the input line for the next command.
          inputLine = "";
        }
        // Prompt the user for the next command.
        Serial.print("> ");
      } else {
        // Add non-newline characters to the current input line and echo them back.
        if (incomingChar != '\r') {
          inputLine += incomingChar;
          Serial.print(incomingChar);
        }
      }
    }

    // Pause briefly to allow the system to handle other tasks.
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

// Function to display help message.
void displayHelp() {
  Serial.println("Help will be added soon");
}

// Function to display available commands.
void displayCommands() {
  Serial.println("Available commands:");
  Serial.println("  help");
  Serial.println("  commands");
  Serial.println("  test1");
  Serial.println("  test2");
  Serial.println("  test3");
}

// Test function implementations.
void testFunction1(String args[], int argCount) {
  Serial.println("Executing testFunction1");
  for (int i = 1; i < argCount; i++) {
    Serial.print("Arg ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(args[i]);
  }
}

void testFunction2(String args[], int argCount) {
  Serial.println("Executing testFunction2");
  for (int i = 1; i < argCount; i++) {
    Serial.print("Arg ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(args[i]);
  }
}

void testFunction3(String args[], int argCount) {
  Serial.println("Executing testFunction3");
  for (int i = 1; i < argCount; i++) {
    Serial.print("Arg ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(args[i]);
  }
}
