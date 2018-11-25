#include <stdio.h>
#include "../stack/stack.h"


int main(){
    Infotype X;
    Stack St;
    scanf("%s", &X);
    CreateEmpty(&St);
    Push(&St, X);
    printf("%s\n", InfoTop(St));

    Pop(&St, &X);
    printf("%d\n", NbElmtSt(St));
    return 0;
}