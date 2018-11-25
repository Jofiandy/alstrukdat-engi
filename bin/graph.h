#include "point.h"
#include "boolean.h"


#ifndef GRAPH_H
#define GRAPH_H

#define NilGraph NULL

typedef struct {
	int room;
	POINT p;
} infotypeGraph;

typedef struct tNodeGraph* adrNode;
typedef struct tSuccNode* adrSuccNode;
typedef struct tNodeGraph
{
	infotypeGraph Id;
	int NPred;
    adrSuccNode Trail;
    adrNode Next;
} NodeGraph;
typedef struct tSuccNode
{
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;

typedef struct
{
    adrNode First;
} Graph;

/* ----- SELEKTOR ----- */
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define Trail(Pn) (Pn)->Trail
#define Succ(Pn) (Pn)->Succ
#define NPred(Pn) (Pn)->NPred
#define Next(Pn) (Pn)->Next

/* ----- KONSTRUKTOR ----- */
void CreateGraph(infotypeGraph X, Graph* G); // membuat graph baru
void InitGraph(Graph* G, char* source); // load graph dari ext

/* ----- MANAJEMEN MEMORI ----- */
adrNode AlokNodeGraph(infotypeGraph X); // mengembalikan hasil alokasi simpul
void DeAlokNodeGraph(adrNode P); // mengembalikan simpul ke sistem
adrSuccNode AlokSuccNode(adrNode Pn); // mengembalikan hasil alokasi succ simpul
void DealokSuccNode(adrSuccNode P); // mengembalikan succ simpul ke sistem

/* ----- OPERASI GRAF ----- */
boolean isNodeEqual(adrNode P, infotypeGraph X); // mengembalikan apakah P memiliki Id X
adrNode SearchNode(Graph G, infotypeGraph X); // mencari X pada G, return nil jika tiada
adrSuccNode SearchEdge(Graph G, infotypeGraph prec, infotypeGraph succ); // mencari succ dari prec pada G, return nil jika tiada
void InsertNode(Graph* G, infotypeGraph X, adrNode* Pn); // memasang X ke akhir G
void InsertEdge(Graph* G, infotypeGraph prec, infotypeGraph succ); // memasang succ ke akhir prec
infotypeGraph GetFirstSuccInfo(Graph G, infotypeGraph prec); // mencari info succ simpul pertama dari node

#endif