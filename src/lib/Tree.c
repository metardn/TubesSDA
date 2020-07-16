/*===========================================
	Nama	: Aulia Rahmi (191524035)
			: Meta Arda Nabila (191524048)
	Kelas	: 1B D4-Teknik Informatika
	File	: Tree.c
	Sumber	: Github Josué Pedroza (jpp08)
===========================================*/

#include "Tree.h"

Root* MakeRoot(){
	Root* tmp = (Root*)calloc(sizeof(Root), 1);
	if(!tmp) {
		printf("Penyimpanan penuh.");
		exit(1);
	}
	return tmp;
}

TreeNode* MakeTree(){
	TreeNode* tmp = (TreeNode*)calloc(sizeof(TreeNode), 1);
	if(!tmp){
		printf("Penyimpanan penuh.");
		exit(1);
	}
	return tmp;
}

/*************************************************
 * parameter datum  : input data 1
 * parameter isChar : input data 2
 * return self node atau new child node
 *************************************************/
 
TreeNode* MakeChild(TreeNode *parentNode, Data datum, int isChar){
	if(!parentNode){
		parentNode = MakeTree();
		parentNode->data = datum;
		parentNode->isChar = isChar;
		return parentNode;
	}
	if(parentNode->left && parentNode->right){
		parentNode = parentNode->parent;
		if(!parentNode)	return NULL;
		return MakeChild(parentNode, datum, isChar);
	}

	if(!isChar){
		// angka, dari kana. return self node pointer.
		if(parentNode->right){
			MakeLeftChild(parentNode, datum, isChar);
		}
		else{
			MakeRightChild(parentNode, datum, isChar);
		}
		return parentNode;
	}
	else{	
		// operator, dari kiri. return its child node pointer.
		if(parentNode->left){
			MakeRightChild(parentNode, datum, isChar);
			return parentNode->right;
		}
		else{
			MakeLeftChild(parentNode, datum, isChar);
			return parentNode->left;
		}
	}
}

void MakeLeftChild(TreeNode *parentNode, Data datum, int isChar){
	TreeNode* tmp = MakeTree();
	if(!tmp)	return;
	tmp->data = datum;
	tmp->isChar = isChar;
	parentNode->left = tmp;
	tmp->parent = parentNode;
}

void MakeRightChild(TreeNode *parentNode, Data datum, int isChar){
	TreeNode* tmp = MakeTree();
	if(!tmp)	return;
	tmp->data = datum;
	tmp->isChar = isChar;
	parentNode->right = tmp;
	tmp->parent = parentNode;
}

void PrintData(Data datum, int isChar){
	if(isChar) {
		printf("%c", datum.opr);
	}
	else {
		printf("%g", datum.num);
	}
}

void Traversal(Root *root, int mode){
	TreeNode *tmp = root->root;
	switch(mode){
		case PREORDER:
			PreOrder(tmp);
			break;
		case INORDER:
			InOrder(tmp);
			break;
		case POSTORDER:
			PostOrder(tmp);
			break;
	}
}

void PreOrder(TreeNode *tNode){
	if(!tNode)	return;
	PrintData(tNode->data, tNode->isChar);
	PreOrder(tNode->left);
	PreOrder(tNode->right);
}

void InOrder(TreeNode *tNode){
	if(!tNode)	return;
	InOrder(tNode->left);
	PrintData(tNode->data, tNode->isChar);
	InOrder(tNode->right);
}

void PostOrder(TreeNode *tNode){
	if(!tNode)	return;
	PostOrder(tNode->left);
	PostOrder(tNode->right);
	PrintData(tNode->data, tNode->isChar);
}

void DeleteTree(TreeNode *tNode){
	if(!tNode)	return;
	DeleteTree(tNode->left);
	DeleteTree(tNode->right);
	free(tNode);
}

void DeleteAll(Root* root){
	DeleteTree(root->root);
}
