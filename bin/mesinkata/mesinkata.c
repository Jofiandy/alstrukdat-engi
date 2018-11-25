/* File: mesinkata.c */
/* Implementasi Mesin Kata: Model Akuisisi Versi I */

#include "../mesinkata/mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
	while ((CC == BLANK) && (CC != MARK))
		ADV();
}

void STARTKATA(char * namafile){
	START(namafile);
	IgnoreBlank();
	if (CC == MARK)
		EndKata = true;
	else {
		EndKata = false;
		SalinKata();
		IgnoreBlank();
		if (CC == MARK)
			EndKata = true;
	}
}

void ADVKATA(){
	IgnoreBlank();
	if (CC == MARK)
		EndKata = true;
	else {
		SalinKata();
		IgnoreBlank();
		if (CC == MARK)
			EndKata = true;
	}
}

void SalinKata(){
	int i = 1;
	boolean STOP;
	do {
		CKata.TabKata[i] = CC;
		ADV();
		STOP = ((CC == MARK) || (CC == BLANK) || (i == NMax));
		if (!STOP)
			i++;
	} while (!STOP);
	CKata.Length = i;
}
