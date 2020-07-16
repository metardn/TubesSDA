/*===========================================
	Nama	: Aulia Rahmi (191524035)
			: Meta Arda Nabila (191524048)
	Kelas	: 1B D4-Teknik Informatika
	File	: main.c
	Sumber	: Github Josué Pedroza (jpp08)
===========================================*/

#include <ctype.h>	// untuk fungsi 'isdigit()'
#include "Tree.h"
#include "Stack.h"

char readChar;	// variabel untuk membaca karakter
Root *root;
Stack *st;

void PesanError(){
	printf("\nError!\nSilakan periksa input kembali.");
	exit(1);
}

void CheckAndGetChar(char tmp){
	if(tmp != readChar){
		PesanError();
	}
	readChar = getchar();
}

double term();
double sum();
double factor();

int main(){
	double value;
	StackNode tmp;
	TreeNode *tn = NULL;
	printf("****************************\n");
	printf("*                          *\n");
	printf("*    Program Kalkulator    *\n");
	printf("*        Kelompok 11       *\n");
	printf("*                          *\n");
	printf("****************************\n\n");
	printf("Contoh input : (3+5)*4-6/2\n");
	printf("Input	: ");
	
	// membuat struktur data untuk setiap kasus
	root = MakeRoot();
	st = MakeStack();
    readChar = getchar();
    value = sum();
    
	// construct tree
	while(!isEmpty(st)){
		// tiap stack dihapus, dibuat tree
		tmp = pop(st);
		while(tmp.isChar){
			// operator
			tn = MakeChild(tn, tmp.data, tmp.isChar);
			if(root->root == NULL)	root->root = tn;
			tmp = pop(st);
		}
		// angka
		tn = MakeChild(tn, tmp.data, tmp.isChar);
		if(root->root == NULL)	root->root = tn;
	}
    printf("\nPrefix	: ");
    Traversal(root, PREORDER);
    printf("\nInfix	: ");  
    Traversal(root, INORDER);
    printf("\nPostfix	: ");
    Traversal(root, POSTORDER);
    printf("\nHasil	: %g\n", value);

    // hapus
    DeleteAll(root);
    return 0;
}

/*************************************************
 * Push data di stack dengan method Postfix
 * Fungsi menghitung penjumlahan dan pengurangan
 *************************************************/
 
double sum(){
	double temp = term();
	Data datum;
	while(readChar == '+' || readChar == '-'){
		if(readChar == '+'){
			datum.opr = '+';
			CheckAndGetChar('+');
			temp += term();
			Push(st, datum, TRUE);
		}
		else if(readChar == '-'){
			datum.opr = '-';
			CheckAndGetChar('-');
			temp -= term();
			Push(st, datum, TRUE);
		}
	}
	return temp;
}

/*************************************************
 * Push data di stack dengan method Postfix
 * Fungsi menghitung perkalian dan pembagian
 *************************************************/
 
double term(){
	double temp = factor();
	Data datum;
	while(readChar == '*' || readChar == '/'){
		if(readChar == '*'){
			datum.opr = '*';
			CheckAndGetChar('*');
			temp *= factor();
			Push(st, datum, TRUE);
		}
		else if(readChar == '/'){
			datum.opr = '/';
			CheckAndGetChar('/');
			temp /= factor();
			Push(st, datum, TRUE);
		}
	}
	return temp;
}

/***************************************************
 * Push data di stack dengan method Postfix
 * Fungsi membaca tanda kurung, negatif dan positif
 ***************************************************/
 
double factor(){
	double temp = 0.0;
	Data datum;
	if(readChar == '('){
		// tanda kurung
		CheckAndGetChar('(');
		temp = sum();
		CheckAndGetChar(')');
	}
	else if(readChar == '-'){
		// negatif
		CheckAndGetChar('-');
		datum.opr = '-';
		temp = -factor();
		Push(st, datum, TRUE);
		return temp;
	}
	else if(isdigit(readChar)){
		ungetc(readChar, stdin);
		scanf("%lf", &temp);
		datum.num = temp;
		Push(st, datum, FALSE);
		readChar = getchar();
	}
	else PesanError();
	return temp;
}
