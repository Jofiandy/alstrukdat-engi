#include "../matriks/matriks.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	
	MATRIKS m;
	BacaMATRIKS(&m, "../src/1.txt");
	
	MATRIKS n;
	CopyMATRIKS(m, &n);
	
	Elmt(n, 1, 1) = 'S';
	Elmt(n, 1, 2) = 'O';
	Elmt(n, 1, 3) = 'S';
	
	TulisMATRIKS(m);
	printf("\n");
	TulisMATRIKS(n);
	printf("\n%d\n", NBElmt(m));
	
}