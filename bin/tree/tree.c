#include <stdio.h>
#include <stdlib.h>
#include "../tree/tree.h"
BinTree temptree[30];
BinTree treemakanan;
Infotype arrmakanan[30] = {"Piring", "Sendok", "Garpu", "Es Krim", "Nasi", "Roti", "Spaghetti", "Pisang", 
                            "Stroberi", "Telur", "Ayam Goreng", "Patty", "Sosis", "Bolognese", "Carbonara",
                            "Banana Split", "Sundae", "Nasi telur dadar", "Nasi Ayam Goreng", "Burger", "Hot Dog", 
                            "Keju", "Spaghetti Carbonara", "Spaghetti Bolognese"};  
char istilahmakanan[30] = {'P', 'S', 'G', 'K', 'N', 'R', 'H', 'I', 'E', 'L', 'A', 'Y'
                            ,'O','B','C','-','-','-','-','-','-','J','-','-'};


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
    buatTree(temptree[7], temptree[15], Niil);
    buatTree(temptree[8], temptree[16], Niil);
    buatTree(temptree[4], temptree[9], temptree[10]);
    buatTree(temptree[9], temptree[17], Niil);
    buatTree(temptree[10], temptree[18], Niil);
    buatTree(temptree[2], temptree[5], temptree[6]);
    buatTree(temptree[5], temptree[11], temptree[12]);
    buatTree(temptree[11],temptree[19], Niil);
    buatTree(temptree[12],temptree[20], Niil);
    buatTree(temptree[6], temptree[13], temptree[14]);
    buatTree(temptree[13],temptree[21], Niil);
    buatTree(temptree[14],temptree[22], Niil);
    buatTree(temptree[21], temptree[23], Niil);
    *P = temptree[0];
}


/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Niil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Niil, Right(P)=Niil */
/* Jika alokasi gagal, mengirimkan Niil */
{
    addrNode P;
    P = (addrNode)malloc(sizeof(Node));
    if (P != Niil){
        Akar(P) = X;
        Left(P) = Niil;
        Right(P) = Niil;
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
    return (P ==  Niil);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (IsTreeEmpty(P)) return false;
    else {
        if (Left(P) == Niil && Right(P) == Niil)
            return true;
        else return false;
    }
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    if (!IsTreeEmpty(P)) {
        if (Left(P) != Niil && Right(P) == Niil) 
            return true;
        return false;
    }
    return false;
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    if (!IsTreeEmpty(P)){
        if (Right(P) != Niil && Left(P) == Niil)
            return true;
        return false;
    }
    return false;
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    if (!IsTreeEmpty(P)) {
        if (Left(P) != Niil && Right(P) != Niil) return true;
        return false; 
    }
    return false;
}

/*fungsi untuk mencari bahan makanan */
int cariIndeks(Infotype bahanmakanan){
    int ret = -1;
    for (int i = 0; i < 24 && ret == -1; i++){
        if (strcmp(bahanmakanan, arrmakanan[i]) == 0){
            ret = i;
        }
    }
    return ret;
}

boolean isada(BinTree Pohon,infotype X){
    if (IsTreeEmpty(Pohon)){
        return false;
    }else{
        if (Akar(Pohon) == X) 
            return true;
        else return isada(Left(Pohon), X) || isada(Right(Pohon), X);
    }
}

int carikedalaman(BinTree Pohon, int depth, int indeks){
    if (Akar(Pohon) == indeks) 
        return depth;
    else {
        if (isada(Left(Pohon), indeks)) 
            return carikedalaman(Left(Pohon), depth + 1, indeks);
        else 
            return carikedalaman(Right(Pohon), depth + 1, indeks);
    }
}

/*fungsi untuk mencari keuntungan dari makanan yang dihasilkan */
int keuntungan(BinTree Pohon, Infotype bahanmakanan){
    int idx = cariIndeks(bahanmakanan);
    return carikedalaman(Pohon, 1, idx) * 1000;
}

boolean isparent(BinTree Now, BinTree X, BinTree Y){
    if (Akar(Now) == Akar(X)) {
        if (Left(Now) != Niil) 
            if (Akar(Left(Now)) == Akar(Y))
                return true;
        if (Right(Now) != Niil)
            if (Akar(Right(Now)) == Akar(Y))
                return true;
        return false;        
    }else {
        if (isada(Left(Now), Akar(X)))
            return isparent(Left(Now), X, Y);
        else if (isada(Right(Now), Akar(X)))
            return isparent(Right(Now), X, Y);
        else return false;
    }
}

boolean isjadimakanan(Infotype bahan){
    int idx = cariIndeks(bahan);
    BinTree tmp = AlokNode(idx);
    return IsTreeOneElmt(tmp);
}

void DummyPrintTree(BinTree P, int h, int hc){
    if (!IsTreeEmpty(P)){
        char tmpch = istilahmakanan[Akar(P)];
		printf("                                           - ");
        if (tmpch == '-')
            printf("%s\n", arrmakanan[Akar(P)]);
        else 
            printf("%s (%c)\n", arrmakanan[Akar(P)], tmpch);
        if (!IsTreeEmpty(Left(P))){
            for (int i = 0; i < h; i++)
                printf(" ");
            DummyPrintTree(Left(P), h + hc, hc+1);
        }
        if (!IsTreeEmpty(Right(P))){
            for (int i = 0; i < h; i++)
                printf(" ");
            DummyPrintTree(Right(P), h + hc, hc+1);
        }
    }
}

void PrintTree(BinTree P, int h){
    DummyPrintTree(P, h, 1);
}