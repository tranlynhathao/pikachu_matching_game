#pragma once
#include "Lib.h"

// Contribute Check functions to move
bool checkI(char** a, int x1, int y1, int x2, int y2);
bool checkL(char** a, int x1, int y1, int x2, int y2);
bool checkZ(char** a, int x1, int y1, int x2, int y2);
bool checkU(char** a, int x1, int y1, int x2, int y2);
bool checkValidPairs(char** a);
bool checkEmpty(char** a);