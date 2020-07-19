/*=========================================================
	Nama			: Aulia Rahmi (191524035)
					: Meta Arda Nabila (191524048)
	Kelas			: 1B D4-Teknik Informatika
	File			: binTree.c
	Deskripsi		: body header binTree.h
	Tanggal & versi	: 19-07-2020/ versi 7
	Sumber			: Github Josué Pedroza (jpp08)
				: Github Luka Kralj (lukakralj)
=========================================================*/

#include "binTree.h"

/**************** ALOKASI ****************/
Tree* CreateTree(){
	Tree* temp = (Tree*)calloc(sizeof(Tree), 1);
	if(!temp) {
		printf("Alokasi gagal");
		return;
	}
	return temp;
}

Node* CreateNode(){
	Node* temp = (Node*)calloc(sizeof(Node), 1);
	if(!temp){
		printf("Alokasi gagal");
		return;
	}
	return temp;
}

Node* InsertChild(Node *node, infotype info, int symbol){
	if(!node){	
		node = CreateNode();
		node->info = info;
		node->symbol = symbol;
		return node;
	}
	if(node->left && node->right){
		node = node->parent;
		if(!node)	return NULL;
		return InsertChild(node, info, symbol);
	}

	if(!symbol){									//jika bukan symbol
		if(node->right){							//insert dari sebelah kanan
			InsertLeft(node, info, symbol);			//insert dari leaf kiri
		}
		else{
			InsertRight(node, info, symbol);
		}
		return node;								//mengembalikan alamat node
	}
	else{	
		if(node->left){								//insert dari sebelah kanan
			InsertRight(node, info, symbol);		//insert dari leaf kiri
			return node->right;						//mengembalikan alamat child-node
		}
		else{
			InsertLeft(node, info, symbol);
			return node->left;						//mengembalikan alamat child-node
		}
	}
}

void InsertLeft(Node *node, infotype info, int symbol){
	Node* temp = CreateNode();
	if(!temp)	return;
	temp->info = info;								//assignment
	temp->symbol = symbol;
	node->left = temp;
	temp->parent = node;
}

void InsertRight(Node *node, infotype info, int symbol){
	Node* temp = CreateNode();
	if(!temp)	return;
	temp->info = info;								//assignment
	temp->symbol = symbol;
	node->right = temp;
	temp->parent = node;
}


/*************** DEALOKASI ***************/
void DeleteNode(Node *node);
/* 
   Menghapus Node pada Tree secara Rekursif
   Modul tambahan khusus pada file body header
*/

void DeleteNode(Node *node){
	if(!node)	return;
	DeleteNode(node->left);
	DeleteNode(node->right);
	free(node);										//menghapus memori
}

void DeleteTree(Tree* T){
	DeleteNode(T->root);
}


/*************** TRAVERSAL ***************/
void PrintData(infotype info, int symbol){
	if(symbol) printf("%c", info.opr);
	else printf("%g", info.num);
}

void PreOrder(address P){
	if(!P)	return;
	PrintData(P->info, P->symbol);					//menampilkan info node
	PreOrder(P->left);								//rekursif terhadap left
	PreOrder(P->right);								//rekursif terhadap right
}

void InOrder(address P){
	if(!P)	return;
	InOrder(P->left);								//rekursif terhadap left
	PrintData(P->info, P->symbol);					//menampilkan info node
	InOrder(P->right);								//rekursif terhadap left
}

void PostOrder(address P){
	if(!P)	return;
	PostOrder(P->left);								//rekursif terhadap left
	PostOrder(P->right);							//rekursif terhadap left
	PrintData(P->info, P->symbol);					//menampilkan info node
}

