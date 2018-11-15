/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "boolean.h"
#include "queue.h"
#include <stdlib.h>
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	if((Head(Q) == Nil) && (Tail(Q) == Nil)){
		return true;
	} else {
		return false;
	}
}

boolean IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	if(Head(Q) == 1){
		return (Tail(Q) == MaxEl(Q));
	} else return (Tail(Q) == (Head(Q) - 1));
}

int NBElmt (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if(IsEmpty(Q)){
		return 0;
	} else {
		if(Tail(Q) >= Head(Q))
			return (Tail(Q) - Head(Q) + 1);
		else 
			return (MaxEl(Q) - Head(Q) + Tail(Q) + 1);
	}
}
/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	(*Q).T = (int *) malloc ((Max+1) * sizeof(int));
	if ((*Q).T != NULL) {
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	} else /* alokasi gagal */ {
		MaxEl(*Q) = 0;
	}
}
/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	MaxEl(*Q) = 0;
	free((*Q).T); 
}
/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
	address i, j;
	 /* Algoritma */
	if (IsEmpty(*Q)) {
		Head(*Q)=1;
	} else /* Q tidak kosong */ {
		if(Tail(*Q) == MaxEl(*Q)){
			Tail(*Q) = 0;
		}
	}
	Tail(*Q)++;
	InfoTail(*Q)=X;
}

void Del (Queue * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
	 *X = InfoHead(*Q);
	 if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
	 	CreateEmpty(Q,MaxEl(*Q));
	 }
	 else {
	 	if(Head(*Q) == MaxEl(*Q)) Head(*Q) = 1;
	 	else Head(*Q)++;
	 }
}