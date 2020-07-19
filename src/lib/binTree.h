/*=========================================================
	Nama			: Aulia Rahmi (191524035)
					: Meta Arda Nabila (191524048)
	Kelas			: 1B D4-Teknik Informatika
	File			: binTree.h
	Deskripsi		: spesifikasi ADT binary tree dinamis
	Tanggal & versi	: 19-07-2020/ versi 7
	Sumber			: Github Josué Pedroza (jpp08)
=========================================================*/

#ifndef BINTREE_H
#define BINTREE_H

#include "boolean.h"

#include <stdio.h>
#include <stdlib.h>


typedef union{
	double num;
	char opr;
} infotype;

typedef struct Node *address;
typedef struct Node{
	int symbol;
	infotype info;
	address parent, left, right;
} Node;

typedef struct{
	address *root;
} Tree;


/**************** ALOKASI ****************/
Tree* CreateTree();
/*
   Mengalokasi Tree Baru, jika gagal modul menampilkan 
   pemberitahuan di layar.
*/

Node* CreateNode();
/*
   Mengalokasi Node Baru, jika gagal modul menampilkan 
   pemberitahuan di layar.
*/

Node* InsertChild(Node *node, infotype info, int symbol);
/*
   Memasukkan node baru ke dalam tree, dengan infotype info dan
   int symbol untuk menentukan jenis value yang masuk ke info 
   pada node berupa operator atau operand. Dan mengembalikan
   alamat node.
   Untuk info berupa operator,insert dari sebelah kiri. Sedangkan
   untuk angka, insert dari sebelah kanan, namun dari leaf kiri.
*/

void InsertLeft(Node *node, infotype info, int symbol);
/*
   Memasukkan node baru ke dalam tree sebagai left child, dengan
   infotype info dan int symbol untuk menentukan jenis value yang
   masuk ke info pada node berupa operator atau operand.
*/

void InsertRight(Node *node, infotype info, int symbol);
/*
   Memasukkan node baru ke dalam tree sebagai right child, dengan
   infotype info dan int symbol untuk menentukan jenis value yang
   masuk ke info pada node berupa operator atau operand.
*/


/*************** DEALOKASI ***************/
void DeleteTree(Tree* T);
/* Menghapus Tree */


/*************** PENGECEKAN **************/
int isEmpty(Tree  T);
/* Mengembalikan true jika Tree kosong */


/*************** TRAVERSAL ***************/
void PrintData(infotype info, int symbol);
/* Menampilkan infotype node ke layar sesuai tipe datanya */

void PreOrder(address P);
/*
   Menampilkan node hasil penelusuran pre-order
   parent, left, right
*/

void InOrder(address P);
/*
   Menampilkan node hasil penelusuran in-order
   left, parent, right
*/

void PostOrder(address P);
/*
   Menampilkan node hasil penelusuran post-order
   left, right, parent
*/


#endif
