#pragma once
#include "Struct.h"

// Linked List Function to Redo
Node* createNode(char** temp);
void addHead(Node*& pHead, char** temp);
void removeHead(Node*& pHead);
void removeAll(Node*& pHead);
void redo(Node* pHead, char** a);