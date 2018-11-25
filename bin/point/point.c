#include <math.h>
#include <stdio.h>
#include "../point/point.h"
#include "../boolean/boolean.h"


/* *** Konstruktor membentuk POINT *** */
/* Membentuk sebuah POINT dari komponen-komponennya */
POINT MakePOINT (int X, int Y) {
	/* KAMUS LOKAL */
	POINT temp;
	Absis(temp) = X;
	Ordinat(temp) = Y;
	return temp;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void BacaPOINT (POINT * P) {
	/* KAMUS LOKAL */
	/* ALGORITMA */
	scanf("%d %d", &Absis(*P), &Ordinat(*P));
} 

/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
void TulisPOINT (POINT P) {
	/* KAMUS LOKAL */
	/* ALGORITMA */
	printf("(%d,%d)", Absis(P), Ordinat(P));
}


/* I.S. P terdefinisi */	
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void Geser (POINT *P, int deltaX, int deltaY) {
	Absis(*P)+= deltaX;
	Ordinat(*P)+= deltaY;
}

void Naik (POINT *P) {
	Geser (P, 0, 1);
}

void Turun (POINT *P) {
	Geser (P, 0, -1);
}
	
void KeKiri (POINT *P) {
	Geser (P, -1, 0);
}

void KeKanan (POINT *P) {
	Geser (P, 1, 0) ;
}

// nanti disesuaikan posisi awal dari pemain
void PosisiAwal (POINT *P) {
	Absis(*P) = 0;
	Ordinat(*P) = 0;
}