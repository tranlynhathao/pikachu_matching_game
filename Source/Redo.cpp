#include "Redo.h"

Node* createNode(char** temp)
{
	Node* pNode = new Node;
	// store 2D array and pNext
	pNode->b = new char* [10];
	for (int i = 0; i < 10; i++)
	{
		pNode->b[i] = new char[10];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			pNode->b[i][j] = temp[i][j];
		}
	}
	pNode->pNext = nullptr;
	return pNode;
}
void addHead(Node*& pHead, char** temp)
{
	// add head so when redo, the latest 2D array will go first
	Node* pNode = createNode(temp);
	if (pHead == nullptr)
	{
		pHead = pNode;
		return;
	}
	pNode->pNext = pHead;
	pHead = pNode;
	return;
}
void removeHead(Node*& pHead)
{
	// when redo finish remove the array was redo
	if (pHead == nullptr)
	{
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		delete[] pHead->b[i];
	}
	delete[] pHead->b;
	Node* pCur = pHead->pNext;
	delete pHead;
	pHead = pCur;
}
void removeAll(Node*& pHead)
{
	// if game over remove all
	if (pHead == nullptr)
	{
		return;
	}
	Node* pCur = pHead;
	while (pCur)
	{
		removeHead(pCur);
	}
}
