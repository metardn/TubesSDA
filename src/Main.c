/*=========================================================
	Nama			: Aulia Rahmi (191524035)
				: Meta Arda Nabila (191524048)
	Kelas			: 1B D4-Teknik Informatika
	File			: Main.c
	Deskripsi		: implementasi expression binary tree
	Tanggal & versi	: 19-07-2020/ versi 7
	Sumber			: Github Josué Pedroza (jpp08)
				: Github Luka Kralj (lukakralj)
=========================================================*/

#include <math.h>
#include <ctype.h>
#include "Stack.h"


/*************VARIABEL GLOBAL*************/
char string;		//variabel input string
Tree *T;
Stack *stack;


/********MODUL KALKULATOR TAMBAHAN********/
/*****************************************/

/***************SPESIFIKASI***************/
void PrintError();
/*
   Menampilkan Pemberitahuan jika user melakukan input
   yang tidak sesuai.
*/

void CheckAndGetChar(char temp);
/* Memeriksa apakah char string input sama dengan char temp */

double count();
/*
   Melakukan Push node ke Stack dengan urutan Postfix.
   dan melakukan operasi perhitungan pertambahan dan pengurangan.
*/

double multiple();
/*
   Melakukan Push node ke Stack dengan urutan Postfix.
   dan melakukan operasi perpangkatan, perkalian dan pembagian.
*/

double identify();
/*
   Melakukan Push node ke Stack dengan urutan Postfix.
   melakukan perhitungan dan membaca symbol pada string.
   berupa ( dan ) sebagai tanda kurung;
   		  - sebagai bilangan negatif;
   		  v sebagai akar kuadrat;
   		  V sebagai akar kubik;
   		  s sebagai sinus;
   		  c sebagai cos;
   		  t sebagai tan; dan
   		  L sebagai logaritma10.
*/

/***************** MAIN *****************/
/****************************************/
int main(){
	double value;
	StackNode temp;
	Node *tn = NULL;
	printf(" ---------------------------------\n");
	printf("  Program Kalkulator Kelompok 11  \n");
	printf(" ---------------------------------\n");
	printf(" Keterangan: \n");
	printf(" 1.  + untuk penjumlahan  -> 3+8 = 11\n");
	printf(" 2.  - untuk pengurangan  -> 12-9 = 3\n");
	printf(" 3.  * untuk perkalian    -> 6*4 = 24\n");
	printf(" 4.  / untuk pembagian    -> 48/8 = 6\n");
	printf(" 5.  ^ untuk pangkat      -> 2^5 = 32\n");
	printf(" 6.  v untuk akar kuadrat -> v4 = 2\n");
	printf(" 7.  V untuk akar kubik   -> v8 = 2\n");
	printf(" 8.  s untuk sin          -> s90 = 0.893997\n");
	printf(" 9.  c untuk cos          -> c90 = - 0.448074\n");
	printf(" 10. t untuk tan          -> t90 = - 1.9952\n");
	printf(" 11. L untuk log10        -> L10 = 1\n\n");
	printf(" Contoh input: (3+5)*4/2+2^0-v25+L10\n");
	printf(" Input: ");
	
	/* Membuat Struktur Data yang dibutuhkan */
	T = CreateTree();
	stack = CreateStack();
    string = getchar();
    value = count();
    
	/* Membuat Expression Tree*/
	while(!isEmptyStack(stack)){							//insert node ke Tree sampai Stack kosong
		temp = pop(stack);
		while(temp.symbol){									//selama info node berisi operator
			tn = InsertChild(tn, temp.info, temp.symbol);	//insert operator
			if(T->root == NULL)	T->root = tn;
			temp = pop(stack);
		}
		tn = InsertChild(tn, temp.info, temp.symbol);		//insert operand
		if(T->root == NULL)	T->root = tn;
	}
    printf("\nPrefix	: ");
    PreOrder(T->root);
    printf("\nInfix	: ");  
    InOrder(T->root);
    printf("\nPostfix	: ");
    PostOrder(T->root);
    printf("\nHasil	: %g\n", value);

    DeleteNode(T->root);									//menghapus Tree
    return 0;
}





/************IMPLEMENTASI SPEK************/
void PrintError(){
	printf("\nInput yang anda masukkan salah");
	exit(1);
}

void CheckAndGetChar(char temp){
	if(temp != string){
		PrintError();
	}
	string = getchar();
}

double count(){
	double temp = multiple();
	infotype info;
	while(string == '+' || string == '-'){
		if(string == '+'){
			info.opr = '+';
			CheckAndGetChar('+');
			temp += multiple();
			Push(stack, info, true);
		}
		else if(string == '-'){
			info.opr = '-';
			CheckAndGetChar('-');
			temp -= multiple();
			Push(stack, info, true);
		}
	}
	return temp;
}

double multiple(){
	double temp = identify();
	infotype info;
	while(string == '^' || (string == '*' || string == '/')){
		if(string == '^'){
			info.opr = '^';
			CheckAndGetChar('^');
			temp = pow(temp, identify());
			Push(stack, info, true);
		}
		else if(string == '*'){
			info.opr = '*';
			CheckAndGetChar('*');
			temp *= identify();
			Push(stack, info, true);
		}
		else if(string == '/'){
			info.opr = '/';
			CheckAndGetChar('/');
			temp /= identify();
			Push(stack, info, true);
		}
	}
	return temp;
}

double identify(){
	double temp = 0.0;
	infotype info;
	switch(string){
		case '(' : // tanda kurung
					CheckAndGetChar('(');
					temp = count();
					CheckAndGetChar(')');
					break;
		case '-' : // negatif
					CheckAndGetChar('-');
					info.opr = '-';
					temp = -identify();
					Push(stack, info, true);
					return temp;
					break;
		case 'v' : // akar kuadrat
					CheckAndGetChar('v');
					info.opr = 'v';
					temp = sqrt(identify());
					Push(stack, info, true);
					return temp;
					break;
		case 'V' : // akar kubik
					CheckAndGetChar('V');
					info.opr = 'V';
					temp = cbrt(identify());
					Push(stack, info, true);
					return temp;
					break;
		case 's' : // sin
					CheckAndGetChar('s');
					info.opr = 's';
					temp = sin(identify());
					Push(stack, info, true);
					return temp;
					break;
		case 'c' : // cos
					CheckAndGetChar('c');
					info.opr = 'c';
					temp = cos(identify());
					Push(stack, info, true);
					return temp;
					break;
		case 't' : // tan
					CheckAndGetChar('t');
					info.opr = 't';
					temp = tan(identify());
					Push(stack, info, true);
					return temp;
					break;
		case 'L' : // log10
					CheckAndGetChar('L');
					info.opr = 'L';
					temp = log(identify());
					Push(stack, info, true);
					return temp;
					break;
		case '+' : //notasi bilangan positif
					CheckAndGetChar('+');
					return identify();
					break;
		default :
					if(isdigit(string)){
						ungetc(string, stdin);
						scanf("%lf", &temp);
						info.num = temp;
						Push(stack, info, false);
						string = getchar();
					}else
					PrintError(); break;
	}
	return temp;
}
