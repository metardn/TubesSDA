/*===========================================
	Nama	: Aulia Rahmi (191524035)
			: Meta Arda Nabila (191524048)
	Kelas	: 1B D4-Teknik Informatika
	File	: Common.h
	Sumber	: Github Josué Pedroza (jpp08)
===========================================*/

#ifndef COMMON_H
#define COMMON_H

// File header ini berisi hal yang umum

#include <stdio.h>
#include <stdlib.h>

#define PREORDER	0
#define INORDER		1
#define POSTORDER	2
#define TRUE		1
#define FALSE	 	0

typedef union{
	double num;
	char opr;
} Data;
const static Data sample = {0};

#endif
