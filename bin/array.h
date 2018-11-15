#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include "boolean.h"

/*  Kamus Umum */
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMax 100
/* Indeks minimum array */
#define IdxMin 1
/* Indeks tak terdefinisi*/
#define IdxUndef -999


/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef char ElType[105]; /* type elemen tabel */
typedef struct {
	ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabChar;

/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
void MakeEmpty (TabChar * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabChar T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

int MaxNbEl (TabChar T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

IdxType GetFirstIdx (TabChar T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxType GetLastIdx (TabChar T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabChar T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabChar T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTab (TabChar T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search (TabChar T, ElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

boolean SearchB (TabChar T, ElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabChar * T, ElType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabChar * T, ElType * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

#endif // ARRAY_H_INCLUDED
