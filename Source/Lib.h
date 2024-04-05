// Lib.h - Header file for library functions

// Include guard to prevent multiple inclusion of this header file
#ifndef LIB_H
#define LIB_H

// Suppress warnings for CRT_SECURE_NO_WARNINGS (specific to MSVC compiler)
#define _CRT_SECURE_NO_WARNINGS

// Standard C++ header files
#include <iostream>   // For input/output streams
#include <string>     // For string manipulation
#include <conio.h>    // For console input/output
#include <Windows.h>  // For Windows API functions
#include <fstream>    // For file input/output
#include <cstring>    // For C-style string manipulation functions
#include <stdio.h>	  // For input/output

#pragma comment(lib, "Winmm.lib") // 

// Namespace declaration to avoid explicit qualification of standard library symbols
using namespace std;

// End of include guard
#endif // LIB_H
