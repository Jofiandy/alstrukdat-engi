#include "graph.h"
#include "point.h"
#include <stdlib.h>
#include <stdio.h>

void initTp(graph * g, char * source){
	FILE * gf = fopen(source,"r");
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 16; j++)
			for (int k = 0; k < 16; k++){
				g->tp[i][j][k].to = -1;
				g->tp[i][j][k].pto = MakePOINT(-1,-1);
			}
	
	int x[6];
	while (fscanf(gf, "%d", &x[0]) == 1){
		for (int i = 1; i < 6; i++)
			fscanf(gf, "%d", &x[i]);
		g->tp[x[0]][x[1]][x[2]].to = x[3];
		g->tp[x[0]][x[1]][x[2]].pto = MakePOINT(x[4], x[5]);
	}
	fclose(gf);
}