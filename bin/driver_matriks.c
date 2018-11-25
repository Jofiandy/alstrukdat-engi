#include <stdio.h>
#include "matriks.h"

MATRIKS M;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    MakeMATRIKS(n, m, &M);
    char src[] = "./src/1.txt"
    BacaMATRIKS(&M, src);
    return 0;
}