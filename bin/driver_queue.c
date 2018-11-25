#include <stdio.h>
#include "queue.h"

int main(){
    infotypeQue X, Y, A, B, C, D;
    Queue Q;
    
    CreateEmptyQue(&Q, 5);
    A.Jam = CreateWaktu(0,1,6,0);
    A.id = 4;
    B.Jam = CreateWaktu(0,1,6,10);
    B.id = 4;
    C.Jam = CreateWaktu(0,1,8,0);
    C.id  = 4;
    X.Jam = CreateWaktu(0,1,9,0);
    X.id  = 4;
    Y.Jam = CreateWaktu(0,1,10,0);
    Y.id = 4;
    AddQue(&Q, A);
    AddQue(&Q, B);
    AddQue(&Q, C);
    printf("%d\n", NBElmtQue(Q));
    AddQue(&Q, X);
    AddQue(&Q, Y);
    infotypeQue P;
    Del2Que(&Q, &P);
    printf("%d\n", P.id);
    TulisWaktuKesabaran(P.Jam);
}