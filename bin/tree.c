#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BinTree temptree[30];
BinTree treemakanan;
Infotype arrmakanan[30] = {"Piring", "Sendok", "Garpu", "Es Krim", "Nasi", "Roti", "Spaghetti", "Pisang", 
                            "Stroberi", "Telur", "Ayam Goreng", "Patty", "Sosis", "Bolognese", "Carbonara",
                            "Banana Split", "Sundae", "Nasi telur dadar", "Nasi Ayam Goreng", "Burger", "Hot Dog", 
                            "Keju", "Spaghetti Carbonara", "Spaghetii Bolognese"};  

void buatTree(BinTree parent,BinTree l, BinTree r){
    Left(parent) = l;
    Right(parent) = r;
}

void BuildTree(BinTree *P)
/* I.S P adalah tree kosong */
/* F.S P adalah tree berisi bahan makanan dari restoran engi kitchen */
{
    for (int i = 0; i < 24; i++)
        temptree[i] = AlokNode(i);
    buatTree(temptree[0], temptree[1], temptree[2]);
    buatTree(temptree[1], temptree[3], temptree[4]);
    buatTree(temptree[3], temptree[7], temptree[8]);
    buatTree(temptree[7], temptree[15], Nil);
    buatTree(temptree[8], temptree[16], Nil);
    buatTree(temptree[4], temptree[9], temptree[10]);
    buatTree(temptree[9], temptree[17], Nil);
    buatTree(temptree[10], temptree[18], Nil);
    buatTree(temptree[2], temptree[5], temptree[6]);
    buatTree(temptree[5], temptree[11], temptree[12]);
    buatTree(temptree[11],temptree[19], Nil);
    buatTree(temptree[12],temptree[20], Nil);
    buatTree(temptree[6], temptree[13], temptree[14]);
    buatTree(temptree[13],temptree[21], Nil);
    buatTree(temptree[14],temptree[22], Nil);
    buatTree(temptree[21], temptree[23], Nil);
    *P = temptree[0];
}


/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrNode P;
    P = (addrNode)malloc(sizeof(Node));
    if (P != Nil){
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}


/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (P ==  Nil);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (IsTreeEmpty(P)) return false;
    else {
        if (Left(P) == Nil && Right(P) == Nil)
            return true;
        else return false;
    }
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    if (!IsTreeEmpty(P)) {
        if (Left(P) != Nil && Right(P) == Nil) 
            return true;
        return false;
    }
    return false;
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    if (!IsTreeEmpty(P)){
        if (Right(P) != Nil && Left(P) == Nil)
            return true;
        return false;
    }
    return false;
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    if (!IsTreeEmpty(P)) {
        if (Left(P) != Nil && Right(P) != Nil) return true;
        return false; 
    }
    return false;
}

/*fungsi untuk mencari bahan makanan */
int cariIndeks(Infotype bahanmakanan){
    int ret = -1;
    for (int i = 0; i < 24 && ret != -1; i++){
        if (strcmp(bahanmakanan, arrmakanan[i]) == 0){
            ret = i;
        }
    }
    return ret;
}


// int getDepth(Infotype bahanmakanan){

// }