#include <stdio.h>
#include "tree.h"

int main(){
    BinTree P;
    Infotype X, Y;

    BuildTree(&P);
    scanf("%s", &X);
    scanf("%s", &Y);
    printf("%d\n", cariIndeks(X));
    printf("%d\n", cariIndeks(Y));
    printf("%d\n", keuntungan(P, X));
    
    int tx, ty;
    scanf("%d %d", &tx, &ty);
    if (isparent(P, AlokNode(tx), AlokNode(ty)))
        printf("yes\n");
    if (isada(P, tx))
        printf("ada\n");
        
    PrintTree(P, 2);
    return 0;
}