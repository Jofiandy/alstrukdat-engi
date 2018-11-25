#include <stdio.h>
#include "array.h"

TabChar arr;

int main(){
    MakeEmpty(&arr);
    
    ElType T1 = "tubes";
    AddAsLastEl(&arr, T1);
    if (SearchB(arr, "tugas"))
        printf("tidak ditemukan!\n");
    else printf("ditemukan\n");

    AddAsLastEl(&arr, "besar");
    printf("%d\n", Neff(arr));
    printf("%s\n", Elmt(arr, 1));

    TulisIsiTab(arr);
    printf("\n");
    printf("%d %d\n", GetFirstIdx(arr), GetLastIdx(arr));

    return 0;
}