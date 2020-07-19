/*=========================================================
	Nama			: Aulia Rahmi (191524035)
				: Meta Arda Nabila (191524048)
	Kelas			: 1B D4-Teknik Informatika
	File			: Stack.c
	Deskripsi		: body header Stack.h
	Tanggal & versi		: 19-07-2020/ versi 7
	Sumber			: Github Josué Pedroza (jpp08)
				: Github Luka Kralj (lukakralj)
=========================================================*/

#include "Stack.h"

/**************** ALOKASI ****************/
Stack* CreateStack(){
	Stack *temp = (Stack*)calloc(sizeof(Stack), 1);
	if(!temp) {
		printf("Alokasi gagal");
		return;
	}
	return temp;
}

StackNode* CreateStackNode(){
	StackNode *temp = (StackNode*)calloc(sizeof(StackNode), 1);
	if(!temp){
		printf("Alokasi gagal");
		return;
	}
	return temp;
}

void Push(Stack *stack, infotype info, int symbol){
	StackNode *node = CreateStackNode();			//alokasi
	if(!node) {
		printf("Push gagal");
		return;
	}
	node->info = info;								//assignment
	node->symbol = symbol;
	node->next = stack->top;
	stack->top = node;
}

/*************** DEALOKASI ***************/
StackNode pop(Stack *stack){
	StackNode node;
	infotype nilData = {0};							//variabel kosong
	
	node.info = nilData;
	node.symbol = false;
	
	if(!stack || isEmptyStack(stack))				//jika Stack kosong
		return node;
		
	node = *(stack->top);							//memindahkan top Stack
	StackNode *temp = stack->top;
	stack->top = temp->next;
	free(temp);										//menghapus memori
	return node;
}

void DeleteStack(Stack *stack){
	StackNode node;
	while(!isEmptyStack(stack)) {
		node = pop(stack);
		PrintStack(&node);
	}
}

/*********** CEK DAN LAIN-LAIN ***********/
int isEmptyStack(Stack *stack){
	if(!stack) {
		printf("Stack kosong");
		return true;
	}
	return stack->top == NULL;
}


void PrintStack(StackNode *node){
	if(!node)	return;
	if(node->symbol){
		printf("%c", node->info.opr);
	}
	else{
		printf("%g", node->info.num);
	}
}

