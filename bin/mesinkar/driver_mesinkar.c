#include <stdio.h>
#include "../mesinkar/mesinkar.h"

int main(){
    START("TEST.txt");
    while (!EOP){
        printf("%c\n", CC);
        ADV();
    }
    return 0;
}