#include <stdio.h>
#include <string.h>

#define infotype char

typedef struct paket{
	infotype info[105];
	int nilai;
}paket;

void makePaket(infotype x[105], int y, paket *calon){
	(*calon).nilai = y;
	strcpy((*calon).info, x);
}

paket calon;

// int main(){
// 	int x;
// 	infotype tmp[105];
// 	scanf("%d", &x);
// 	scanf("%s", &tmp);
// 	makePaket(tmp, x, &calon);
// 	printf("%s\n", calon.info);
// 	// char arr[5], brr[5];
// 	// scanf("%s", &arr);
// 	// strcpy(brr, arr);
// 	// printf("%s\n", brr);
// }