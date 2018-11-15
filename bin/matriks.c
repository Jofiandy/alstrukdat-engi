// Nama / NIM	: Faiz Muhammad Muflich / 13517093

#include "boolean.h"
#include "matriks.h"
#include "mesinkar.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) {
	NBrsEff(*M) = NB;
 	NKolEff(*M) = NK;
} 

/* *** Selektor "DUNIA MATRIKS" *** */
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
boolean IsIdxValid (int i, int j) {
	return ((i<=BrsMax) && (i>=BrsMin) && (j>=KolMin) && (j<=KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxBrs (MATRIKS M) {
	return BrsMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetFirstIdxKol (MATRIKS M) {
	return KolMin;
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxBrs (MATRIKS M) {
	return (NBrsEff(M)+GetFirstIdxBrs(M)-1);
}
/* Mengirimkan indeks kolom terbesar M */
indeks GetLastIdxKol (MATRIKS M) {
	return (NKolEff(M)+GetFirstIdxKol(M)-1);
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j) {
	return ((GetFirstIdxBrs(M)<=i) && (i<=GetLastIdxBrs(M)) && (GetFirstIdxKol(M)<=j) && (j<=GetLastIdxKol(M)));
}

/* ********** Assignment  MATRIKS ********** */
/* Melakukan assignment MHsl  MIn */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl) {
	NBrsEff(*MHsl) = NBrsEff(MIn);
  	NKolEff(*MHsl) = NKolEff(MIn);
	for(int i=GetFirstIdxBrs(MIn); i<=GetLastIdxBrs(MIn); i++)
		for (int j=GetFirstIdxKol(MIn); j<=GetLastIdxKol(MIn); j++)
			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/

void BacaMATRIKS (MATRIKS * M, char * namafile) {
	
	int nb = 1;
	int nk = 0;
	
	START(namafile);
	while (!EOP){
		if (CC == '\n'){
			nb++;
			nk = 0;
		} else
			nk++;
		Elmt(*M, nb, nk) = CC;
		ADV();
	}
	
	NBrsEff(*M) = nb;
 	NKolEff(*M) = nk;
	
}

/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M) {
	for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++) {
		for (int j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
			if(j!=GetLastIdxKol(M)) printf("%c ", Elmt(M, i, j));
			else printf("%c", Elmt(M, i, j));
		}
		if(i!=GetLastIdxBrs(M)) printf("\n");
	}
}


/* ********** Operasi lain ********** */
/* Mengirimkan banyaknya elemen M */
int NBElmt (MATRIKS M) {
	return (GetLastIdxBrs(M)*GetLastIdxKol(M));
}

