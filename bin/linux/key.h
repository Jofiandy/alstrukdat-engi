/*

    File    : key.h
    
    ADT Key untuk menerima masukan
    keyboard dalam bentuk apapun
    (termasuk arrow keys).

*/

#ifndef key_H
#define key_H

#include <stdio.h>

#define clrscr() system("clear")
#define KEY_UP 'A'
#define KEY_DOWN 'B'
#define KEY_RIGHT 'C'
#define KEY_LEFT 'D'
#define KEY_BACKSPACE '\b'
#define KEY_ENTER '\n'
#define KEY_SPACE ' '

int getKey();
/* getKey menerima input dari pengguna
termasuk arrow keys */

#endif
