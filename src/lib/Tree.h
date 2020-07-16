/*===========================================
	Nama	: Aulia Rahmi (191524035)
			: Meta Arda Nabila (191524048)
	Kelas	: 1B D4-Teknik Informatika
	File	: Tree.h
	Sumber	: Github Josué Pedroza (jpp08)
===========================================*/

#ifndef TREE_H
#define TREE_H
#include "Common.h"

typedef struct Tree *address;
typedef struct TreeNode{
	int isChar;
	Data data;
	address parent, left, right;
} TreeNode;

typedef struct Root{
	address *root;
} Root;

Root* MakeRoot();
TreeNode* MakeTree();
TreeNode* MakeChild(TreeNode *parentNode, Data datum, int isChar);
void MakeLeftChild(TreeNode *parentNode, Data datum, int isChar);
void MakeRightChild(TreeNode *parentNode, Data datum, int isChar);
void PrintData(Data datum, int isChar);
void Traversal(Root *root, int mode);
void PreOrder(TreeNode *tNode);
void InOrder(TreeNode *tNode);
void PostOrder(TreeNode *tNode);
void DeleteTree(TreeNode *tNode);
void DeleteAll(Root* root);

#endif
