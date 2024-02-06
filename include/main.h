// Copyright (C) 2024 Symbola
// This code is licensed under the GNU General Public License version 3.0
// You can find the full text of the license at https://www.gnu.org/licenses/gpl-3.0.html
// For inquiries or additional permissions, please contact at symbola.co.uk/contact

// main.h
#ifndef MAIN_H
#define MAIN_H

// Constants.
const int SERIAL_BAUD_RATE = 115200;

const int COMMAND_INTERFACE_TASK_STACK_SIZE = 2048;
const int TEST_TASK_STACK_SIZE = 1024;
const int COMMAND_INTERFACE_TASK_PRIORITY = 1;
const int TEST_TASK_PRIORITY_START = 2;

#endif // MAIN_H
