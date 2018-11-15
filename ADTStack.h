/*
	File	: ADTStack.h
	Tanggal	: 1 November 2018
	Definisi ADT Stack
*/

#ifndef ADTSTACK_H
#define ADTSTACK_H
#define IdxMax 10

typedef char Infotype[105];
typedef int address;

/* Definisi Struct Stack */
typedef struct{
	Infotype TI[IdxMax+1];
	address TOP;
}Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).TI[Top(S)]

int IsEmpty(Stack S);
/*
	I.S	: Stack S sembarang
	F.S	: Mengembalikan nilai 1 bila stack kosong, 0 jika tidak
*/

void CreateEmpty(Stack *S);
/*
	I.S	: Stack S belum terdefinisi
	F.S	: Stack S terdefinisi sebagai stack kosong
*/

void Push(Stack *S, Infotype str);
/*
	I.S	: Stack S dan string str terdefinisi
	F.S	: Stack S terisi dengan str sebagai TOP
*/

void Pop(Stack *S, Infotype *str);
/*
	I.S	: Stack S terdefinisi, str kosong
	F.S	: Top Stack S berkurang 1 dan str berisi string Top sebelumnya
*/

void Reverse(Stack *S);
/*
	I.S	: Stack terdefinisi dan tidak kosong
	F.S	: Stack memiliki isi kebalikan dari stack input
*/

void PrintStack(Stack S);
/*
	I.S	: Stack terdefinisi dan tidak kosong
	F.S	: Seluruh isi stack tercetak di layar
*/

#endif
