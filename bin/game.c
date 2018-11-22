#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "key.h"
#include "matriks.h"
#include "point.h"
#include "jam.h"
#include "queue.h"

#define STATE_MENU 0
#define STATE_NAME 1
#define STATE_LOAD 2
#define STATE_GAME 3

#define OPTION_NEW 0
#define OPTION_START 1
#define OPTION_LOAD 2
#define OPTION_EXIT 3

/* fjiodsjiofjioafjsijfaisjifas temporary */

typedef struct {
	int to;
	POINT pto;
} teleport;

typedef struct {
	teleport tp[5][16][16];
} graph;

void initTp(graph * g){
	FILE * gf = fopen("./src/g.txt","r");
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

graph g;
/* -----dsaijisjdajjakdkjasjkdljladjlkasd---- */

const char *not_found = "Player name not found, press any key to go back";
const char *opt[] = {" New Game"," Start   "," Load    "," Exit    "};

int state, option;
char name[100], name_load[100];

int current_room;
MATRIKS room[5], gameRoom;
POINT p_pos;
Waktu Jam;
Queue Customer;
int life = 3;
int money = 0;

void emptyString(char* s){
    for (int i = 0; i < 100; i++)
        s[i] = 0;
}

void displayCustomer(){
    printf("Id : %d ", InfoTailQue(Customer).id);
    printf("Jumlah : %d ", NBElmtQue(Customer));
}

void updateCustomer(int number)
{
    infotypeQue orang;
    int jumlah;
    if (Sec(Jam) % 21 == 0 || Sec(Jam) == 1)
    {
        orang.id = (rand() % (number+2))*2;
        printf("%d\n", orang.id);
        orang.Jam.S = 10;
        AddQue(&Customer, orang);
    }
}

void newSave(){
	CreateStart(&Jam);
    CreateEmptyQue(&Customer, 10);
	p_pos = MakePOINT(7, 7);
	current_room = 1;
	for (char c = '1'; c <= '4'; c++){
		char src[] = "./src/1.txt";
		src[6] = c;
		BacaMATRIKS(&room[c - '0'], src);
	}
	initTp(&g); // temporary
}

void firstSetup(){
	
    emptyString(name);
    state = STATE_MENU;
    option = OPTION_NEW;

}

void keyGame(char key){
	
	if (key == KEY_UP && (Elmt(gameRoom, Absis(p_pos)-1, Ordinat(p_pos)) == ' ')){	
		UpDate(&Jam,1);
        updateCustomer(1);
		Absis(p_pos)--;
	} else if (key == KEY_DOWN && (Elmt(gameRoom, Absis(p_pos)+1, Ordinat(p_pos)) == ' ')){
		UpDate(&Jam,1);
        updateCustomer(1);
		Absis(p_pos)++;
	} else if (key == KEY_RIGHT && (Elmt(gameRoom, Absis(p_pos), Ordinat(p_pos)+1) == ' ')){
		UpDate(&Jam,1);
        updateCustomer(1);
		Ordinat(p_pos)++;
	} else if (key == KEY_LEFT && (Elmt(gameRoom, Absis(p_pos), Ordinat(p_pos)-1) == ' ')){
		UpDate(&Jam,1);
        updateCustomer(1);
		Ordinat(p_pos)--;
	} else if (key == KEY_ESC){
		exit(0);
	}
	
}

void printGame(){
	
	if (g.tp[current_room][Absis(p_pos)][Ordinat(p_pos)].to != -1){
		teleport tmp = g.tp[current_room][Absis(p_pos)][Ordinat(p_pos)];
		current_room = tmp.to;
		p_pos = tmp.pto;
	}
	printf("Life: %d |",life);
	printf(" Money: %d |",money);
	TulisWaktu(Jam);
	displayCustomer();

	CopyMATRIKS(room[current_room], &gameRoom);
	Elmt(gameRoom, Absis(p_pos), Ordinat(p_pos)) = 'P';
	printf("X: %d --- Y: %d\n", Absis(p_pos), Ordinat(p_pos));
	
	TulisMATRIKS(gameRoom);
	printf("\n");

	
}

void printLine(){
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}

void printEmpty(){
    printf("---                                                                                                              ---\n");
}

void printCenter(char *s) {
    printf("---%*s%*s---\n",55+strlen(s)/2,s,55-strlen(s)/2,"");
}

void checkLoad(){
    FILE *file;
    
    char *path = "./savedata/";
    char fname[105];
    strcpy(fname, path);
    strcat(fname, name_load);
    strcat(fname, ".engi");
    
    if (file = fopen(fname, "r")){
        // TODO - Overwrite/load savegame data with file
        fclose(file);
        strcpy(name, name_load);
        state = STATE_MENU;
    } else 
        strcpy(name_load, not_found);
}

void readKey(){
    int key = getKey();
    int len;
    switch(state){
        case STATE_MENU:
            switch(key){
                case KEY_UP:
					option = (option + 4 - 1) % 4;
                    break;
                case KEY_DOWN:
					option = (option + 4 + 1) % 4;
                    break;
                case KEY_ENTER:
                    switch(option){
                        
                        case OPTION_NEW:
                            newSave();
                            emptyString(name);
                            state = STATE_NAME;
                            break;
                        case OPTION_START:
                            if (name[0] == 0){
								newSave();
                                state = STATE_NAME;
							}
                            else
                                state = STATE_GAME;
                            break;
                        case OPTION_LOAD:
                            emptyString(name_load);
                            state = STATE_LOAD;
                            break;
                        case OPTION_EXIT:
                            exit(0);
                        
                    }
            }
            break;
        case STATE_NAME:
            ; len = strlen(name);
            if ((key == KEY_BACKSPACE) && (len > 0))
                name[len-1] = 0;
            else if ((len < 100) && (((key >= 'a') && (key <= 'z')) || ((key >= 'A') && (key <= 'Z')) || (key == KEY_SPACE)))
                name[len] = (char) key;
            else if (key == KEY_ENTER)
                state = STATE_MENU;
            break;
        case STATE_LOAD:
            ; len = strlen(name_load);
            if (strcmp(name_load, not_found) == 0){
                state = STATE_MENU;
                emptyString(name_load);
            } else {
                if ((key == KEY_BACKSPACE) && (len > 0))
                    name_load[len-1] = 0;
                else if ((len < 100) && (((key >= 'a') && (key <= 'z')) || ((key >= 'A') && (key <= 'Z')) || (key == KEY_SPACE)))
                    name_load[len] = (char) key;
                else if (key == KEY_ENTER)
                    checkLoad();
            }
            break;
		case STATE_GAME:
			keyGame(key);
			break;
    }
}

void printOption(){
    char input[100];
    switch(state){
        case STATE_MENU:
            for (int i = OPTION_NEW; i <= OPTION_EXIT; i++){
                emptyString(input);
                if (option == i)
                    strcat(input, ">");
                strcat(input, opt[i]);
                printCenter(input);
            }
            break;
        case STATE_NAME:
            printCenter("Tell me your name:");
            strcpy(input, name);
            strcat(input, "_");
            printCenter(input);
            break;
        case STATE_LOAD:
            printCenter("Input player name to load:");
            strcpy(input, name_load);
            strcat(input, "_");
            printCenter(input);
            break;
		case STATE_GAME:
			printf("\n");
			printGame();
			printf("\n");
			break;
    }
}

void showUI() {
	system("cls");
    printLine();
    printLine();
    printCenter(" _____            _ _       _   ___ _       _                ");
    printCenter("|  ___|          (_| )     | | / (_) |     | |               ");
    printCenter("| |__ _ __   __ _ _|/ ___  | |/ / _| |_ ___| |__   ___ _ __  ");
    printCenter("|  __| '_ \\ / _` | | / __| |    \\| | __/ __| '_ \\ / _ \\ '_ \\ ");
    printCenter("| |__| | | | (_| | | \\__ \\ | |\\  \\ | || (__| | | |  __/ | | |");
    printCenter("\\____/_| |_|\\__, |_| |___/ \\_| \\_/_|\\__\\___|_| |_|\\___|_| |_|");
    printCenter("             __/ |                                           ");
    printCenter("            |___/          Extended version!                 ");
    printLine();
    printLine();
    printEmpty();
    printEmpty();
    char greet[100] = "Hello, ";
    if (name[0] == 0)
        strcat(greet, "stranger");
    else
        strcat(greet, name);
    strcat(greet, "!");
    printCenter(greet);
    printOption();
    printEmpty();
    printEmpty();
    printCenter("Arrow keys to navigate, enter to select option");
    printEmpty();
    printLine();
    printLine();
    readKey();
    showUI();
}

int main() {
    firstSetup();
    showUI();
    return 0;
}

