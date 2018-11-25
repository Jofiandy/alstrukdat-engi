#include "../key_linux/key.h"
#include<stdio.h>

int main(){

	char c;
	while (1){
		c = getKey();
		printf("Kamu memasukkan %c!\n", c);
	}
	
}