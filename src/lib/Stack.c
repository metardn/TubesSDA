/*===========================================
	Nama	: Aulia Rahmi (191524035)
			: Meta Arda Nabila (191524048)
	Kelas	: 1B D4-Teknik Informatika
	File	: Stack.c
	Sumber	: Github Josué Pedroza (jpp08)
===========================================*/

#include "Stack.h"

int isEmpty(Stack *stack){
	if(!stack) {
		printf("Stack tidak ada.");
		return TRUE;
	}
	return stack->topNode == NULL;
}

StackNode* MakeStackNode(){
	StackNode *tmp = (StackNode*)calloc(sizeof(StackNode), 1);
	if(!tmp){
		printf("Penyimpanan penuh.");
		exit(1);
	}
	return tmp;
}

Stack* MakeStack(){
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		printf("Penyimpanan penuh.");
		exit(1);
	}
	return tmp;
}

void PrintStack(StackNode *tNode){
	if(!tNode)	return;
	if(tNode->isChar){
		printf("%c", tNode->data.opr);
	}
	else{
		printf("%g", tNode->data.num);
	}
}

void Push(Stack *stack, Data datum, int isChar){
	StackNode *tmp = MakeStackNode();
	if(!tmp) {
		printf("Penyimpanan penuh.");
		exit(1);
	}
	tmp->data = datum;
	tmp->isChar = isChar;
	tmp->pNode = stack->topNode;
	stack->topNode = tmp;
}

StackNode pop(Stack *stack){
	StackNode res;
	res.data = sample;
	res.isChar = FALSE;
	if(!stack || isEmpty(stack))	return res;
	res = *(stack->topNode);
	StackNode *tmp = stack->topNode;
	stack->topNode = tmp->pNode;
	free(tmp);
	return res;
}

void DeleteStack(Stack *stack){
	StackNode sn;
	while(!isEmpty(stack)) {
		sn = pop(stack);
		PrintStack(&sn);
	}
}
