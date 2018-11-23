/*

    File    : key.h
    
    ADT Key untuk menerima masukan
    keyboard dalam bentuk apapun
    (termasuk arrow keys).

*/

#ifndef key_H
#define key_H

#include <conio.h>
#include <stdio.h>

#define clrscr() system("cls")
#define KEY_ARROW 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_BACKSPACE 8
#define KEY_ENTER 13
#define KEY_SPACE 32

int getKey();
/* getKey menerima input dari pengguna
termasuk arrow keys */

#endif
