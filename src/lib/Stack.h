/*=========================================================
	Nama			: Aulia Rahmi (191524035)
				: Meta Arda Nabila (191524048)
	Kelas			: 1B D4-Teknik Informatika
	File			: Stack.h
	Deskripsi		: spesifikasi ADT stack dinamis
	Tanggal & versi		: 19-07-2020/ versi 7
	Sumber			: Github Josué Pedroza (jpp08)
				: Github Luka Kralj (lukakralj)
=========================================================*/

#ifndef STACK_H
#define STACK_H

#include "binTree.h"

typedef struct StackNode *addrs;
typedef struct StackNode{
	int symbol;
	infotype info;
	addrs next;
} StackNode;

typedef struct Stack{
	addrs top;
} Stack;

/**************** ALOKASI ****************/
Stack* CreateStack();
/*
   Mengalokasi Stack Baru, jika gagal modul menampilkan 
   pemberitahuan di layar.
*/

StackNode* CreateStackNode();
/*
   Mengalokasi Node Baru, jika gagal modul menampilkan 
   pemberitahuan di layar.
*/

void Push(Stack *stack, infotype info, int symbol);
/*
   Memasukkan node baru ke dalam Stack sebagai top, dengan
   infotype info dan int symbol untuk menentukan jenis value 
   yang masuk ke info pada node berupa operator atau operand.
*/


/*************** DEALOKASI ***************/
StackNode pop(Stack *stack);
/*
   Menghapus node top pada Stack dan mengembalikan node 
   sebelumnya sebagai top. Jika Stack kosong, modul hanya
   mengembalikkan node.
*/

void DeleteStack(Stack *stack);
/* Menghapus Stack */


/*********** CEK DAN LAIN-LAIN ***********/
int isEmptyStack(Stack *stack);
/* Mengembalikan true jika Stack kosong */

void PrintStack(StackNode *node);
/* Menampilkan infotype node ke layar sesuai tipe datanya */


#endif
