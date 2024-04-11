#pragma once
#include "Struct.h"

// Linked List Function to Undo
Node* createNode(char** temp);
void addHead(Node*& pHead, char** temp);
void removeHead(Node*& pHead);
void removeAll(Node*& pHead);
void undo(Node* pHead, char** a);