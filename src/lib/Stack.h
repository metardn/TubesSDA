/*===========================================
	Nama	: Aulia Rahmi (191524035)
			: Meta Arda Nabila (191524048)
	Kelas	: 1B D4-Teknik Informatika
	File	: Stack.h
	Sumber	: Github Josué Pedroza (jpp08)
===========================================*/

#ifndef STACK_H
#define STACK_H

#include "Common.h"

typedef struct StackNode *addrs;
typedef struct StackNode{
	int isChar;
	Data data;
	addrs pNode;
} StackNode;

typedef struct Stack{
	addrs topNode;
} Stack;

int isEmpty(Stack *stack);
StackNode* MakeStackNode();
Stack* MakeStack();
void PrintStack(StackNode*);
void Push(Stack *stack, Data datum, int isChar);
StackNode pop(Stack *stack);
void DeleteStack(Stack *stack);

#endif
