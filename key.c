/*

    File    : key.c
    
    ADT Key untuk menerima masukan
    keyboard dalam bentuk apapun
    (termasuk arrow keys).

*/

#include "key.h"
#include <conio.h>
#include <stdio.h>

int getKey(){
    int c;
    c = getch();
    if (c == KEY_ARROW)
        c = getch();
    return c;
}