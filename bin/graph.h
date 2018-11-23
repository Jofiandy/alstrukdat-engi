#ifndef GRAPH_H
#define GRAPH_H

#include "point.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct {
	int to;
	POINT pto;
} teleport;

typedef struct {
	teleport tp[5][16][16];
} graph;

void initTp(graph * g, char * source);
/*	Memasukkan isi graf dari source (nama file) berbentuk
	beberapa baris yang berisikan:
	
	A X1 Y1 B X2 Y2
	
	A: Room dari
	B: Room destinasi
	X1 Y1: Titik dari room A
	X2 Y2: Titik destinasi room B
*/

#endif