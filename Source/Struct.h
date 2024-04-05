// Struct.h - Header file for defining structures

// Include guard to prevent multiple inclusion of this header file
#ifndef STRUCT_H
#define STRUCT_H

// Definition of a structure to store player information
struct Storage {
    char name[100]; // Array to store player's name
    int score;     // Integer to store player's score
};

// Definition of a structure for a linked list node to Redo
struct Node {
    char** b; // 2D array to store data
    Node* pNext;    // Pointer to the next node in the linked list
};

// End of include guard
#endif // STRUCT_H
