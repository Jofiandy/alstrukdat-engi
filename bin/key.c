/*

    File    : key.c
    
    ADT Key untuk menerima masukan
    keyboard dalam bentuk apapun
    (termasuk arrow keys).

*/

#include "key.h"
#include <curses.h>
#include <stdio.h>

int getKey(){
	
    initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
    int key = getch();
	endwin();
	return key;

}