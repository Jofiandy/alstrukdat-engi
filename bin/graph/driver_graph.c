#include "../graph/graph.h"
#include "../point/point.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	
	Graph g;
	InitGraph(&g, "../src/g.txt");
	/* Initgraph = mencakup insert dll */
	
	infotypeGraph a, b;
	a.room = 696969; b.room = 123123;
	a.p = MakePOINT(-1, -100); b.p = MakePOINT(100, 1);
	
	InsertEdge(&g, a, b);
	
	/* Print all edges */
	adrNode P = First(g);
	while(P != NilGraph){
		infotypeGraph Id1 = Id(P);
		adrSuccNode Ps = Trail(P);
		while (Ps != NilGraph){
			infotypeGraph Id2 = Id(Succ(Ps));
			printf("%d %d %d %d %d %d\n", Id1.room, Absis(Id1.p), Ordinat(Id1.p), Id2.room, Absis(Id2.p), Ordinat(Id2.p));
			Ps = Next(Ps);
		}
		P = Next(P);
	}
	
}