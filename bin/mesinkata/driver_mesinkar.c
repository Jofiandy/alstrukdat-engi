#include <stdio.h>
#include "../mesinkata/mesinkata.h"

int main(){
    STARTKATA("TEST.txt");
    while (!EndKata){
        for (int i = 1; i <= CKata.Length; i++)
			printf("%c", CKata.TabKata[i]);
		printf("\n");
        ADVKATA();
    }
	for (int i = 1; i <= CKata.Length; i++)
		printf("%c", CKata.TabKata[i]);
	printf("\n");
    return 0;
}