/* ADT Pohon Biner Untuk Tubes */

#ifndef _TREE_
#define _TREE_

#include <string.h>
#include "boolean.h"
#include "stack.h"


#define Niil NULL

typedef int infotype;

typedef struct tNode *addrNode;
typedef struct tNode{
  infotype info;
  addrNode left;
  addrNode right;
} Node;

typedef addrNode BinTree;

extern BinTree temptree[30];
extern BinTree treemakanan;
extern Infotype arrmakanan[30];

#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right


void BuatTree(BinTree parent, BinTree l, BinTree r);

void BuildTree(BinTree *P);
/* I.S P adalah tree kosong */
/* F.S P adalah tree berisi bahan makanan dari restoran engi kitchen */

/* Manajemen Memory */
addrNode AlokNode(infotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Niil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Niil, Right(P)=Niil */
/* Jika alokasi gagal, mengirimkan Niil */

void DealokNode(addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */


/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/*fungsi untuk mencari bahan makanan*/
int cariIndeks(Infotype bahanmakanan);

/*fungsi untuk mencari keuntungan dari makanan yang dihasilkan */
int keuntungan(BinTree Pohon, Infotype bahanmakanan);

/*fungsi untuk mengecek apakah ada suatu elemen x pada sebuah binary tree P*/
boolean isada(BinTree P, infotype X);

/*fungsi untuk mencari kedalaman makanan dari tree */
int carikedalaman(BinTree Pohon, int depth, int indeks);

/*fungsi untuk mengecek apakah X parent dari Y atau bukan */
boolean isparent(BinTree Now, BinTree X, BinTree Y);

/*fungsi untuk mengecek apakah suatu makanan adalah leave dari tree atau bukan */
boolean isjadimakanan(Infotype bahan);


#endif