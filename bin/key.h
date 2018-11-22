/*

    File    : key.h
    
    ADT Key untuk menerima masukan
    keyboard dalam bentuk apapun
    (termasuk arrow keys).

*/

#ifndef key_H
#define key_H

#include <curses.h>
#include <stdio.h>

#define clrscr() printf("\033[H\033[J")
#define KEY_SPACE ' '

int getKey();
/* getKey menerima input dari pengguna
termasuk arrow keys */

#endif
