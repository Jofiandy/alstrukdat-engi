#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// [!] comment out one of these depending on your OS
#include "linux/key.h"
//#include "windows/key.h"

#include "matriks.h"
#include "point.h"
#include "jam.h"
#include "queue.h"
#include "graph.h"

#define STATE_MENU 0
#define STATE_NAME 1
#define STATE_LOAD 2
#define STATE_GAME 3

#define OPTION_NEW 0
#define OPTION_START 1
#define OPTION_LOAD 2
#define OPTION_EXIT 3

const char *not_found = "Player name not found, press any key to go back";
const char *opt[] = {" New Game"," Start   "," Load    "," Exit    "};

int state, option;
char name[100], name_load[100];

int current_room;
MATRIKS room[5], gameRoom;
POINT p_pos;
Waktu Jam;
Queue Customer;
graph g;
int life = 3;
int money = 0;

void emptyString(char* s){
    for (int i = 0; i < 100; i++)
        s[i] = 0;
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

void displayCustomer(){
    printf("List Customer yang Menunggu\n");
    printLine();    
    printf("Jumlah Antrian: %d \n", NBElmtQue(Customer));
    PrintQue(Customer);
}

void updateCustomer(int number)
{
    infotypeQue orang;
    int jumlah;
    Waktu WaktuKesabaran;
    CreateStart(&WaktuKesabaran);
    if (Sec(Jam) % 37 == 0 || (Hour(Jam) == 0 && Min(Jam) == 0 && Sec(Jam) == 1) || Sec(Jam) % 23 == 0)
    {
        orang.id = (rand()%(number+1) +1)*2;
        printf("%d\n", orang.id);
        WaktuKesabaran = Jam;
        int temp = (rand()%(1) +1);
        if (temp == 1)
        {
            UpDate(&WaktuKesabaran, (rand()%20)+30);
        }
        else
        {
            UpDate(&WaktuKesabaran, (rand()%15)+30);
        }
        orang.Jam = CreateWaktu(Hour(WaktuKesabaran), Min(WaktuKesabaran), Sec(WaktuKesabaran), Day(WaktuKesabaran));
        AddQue(&Customer, orang);
    }
}

void newSave(){
	CreateStart(&Jam);
    CreateEmptyQue(&Customer, 20);
	p_pos = MakePOINT(7, 7);
	current_room = 1;
	for (char c = '1'; c <= '4'; c++){
		char src[] = "./src/1.txt";
		src[6] = c;
		BacaMATRIKS(&room[c - '0'], src);
	}
	initTp(&g, "./src/g.txt"); // temporary
}

void firstSetup(){
	
    emptyString(name);
    state = STATE_MENU;
    option = OPTION_NEW;

}

void printGameOver(){
  printf("\t\t\t  -------                                  --------\n");
  printf("\t\t\t |       |                                |        |\n");
  printf("\t\t\t|         |                              |          |\n" );
  printf("\t\t\t|                                        |          |\n");  
  printf("\t\t\t|     ------ ----- ---- ----  ----|      |          ||     ||----||----\n");
  printf("\t\t\t|          |----  |    |    |  ___.      |          | |   | |____.|    |\n");
  printf("\t\t\t |        |       |    |    |     `       |        |   | |  |    `|---|\n");
  printf("\t\t\t  -------- -------|    |    |-----|        --------     |   |----||    -|\n\n\n");
}

void printCreditCreator(int money){
    printf("\t\t\t\t\t\tThanks for playing with us!\n");
    printf("\t\t\t\t\t\tYour Score is %d. Not bad!\n",money);
    printf("\t\t\t\t\t\tHope you enjoy the game!\n\n");
    printThank();
    printf("\n\t\t\t\t\t\tThis game is presented by:\n");
    printf("\t\t\t\t\t\t     Asif Hummam Rais\n");
    printf("\t\t\t\t\t\t  Faiz Muhammad Muflich\n");
    printf("\t\t\t\t\t\t   Irfan Sofyana Putra\n");
    printf("\t\t\t\t\t\t     Jofiandy Leonata\n");
    printf("\t\t\t\t\t\t  Muhammad Hanif Adzkiya\n");
    printf("\t\t\t\t\t\t      Winston Wijaya\n\n");
}

printThank(){
    printf("\n\t\t\t\t----- .    .  ----  |   | |  |     |   |  ----  |   |\n");
    printf("\t\t\t\t  |   |----| |----| | | | |||        |   |    | |   |\n");
    printf("\t\t\t\t  |   |    | |    | |  || |  |       |    ----   ---\n");
}

void printCredit(int money){
    clrscr();
    printGameOver();   
    printCreditCreator(money);    
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
    } else if (key == KEY_SPACE) {
        // taruh makan, customer, ngambil makanan dari dapur, buang sampah.
	} else if (key == 'q'){
        printCredit(money);
		exit(0);
	}
	
}

void printGame(){
	
    infotypeQue buang;
	if (g.tp[current_room][Absis(p_pos)][Ordinat(p_pos)].to != -1){
		teleport tmp = g.tp[current_room][Absis(p_pos)][Ordinat(p_pos)];
		current_room = tmp.to;
		p_pos = tmp.pto;
	}
	printf("Life: %d |",life);
	printf(" Money: %d |",money);
	TulisWaktu(Jam);

	CopyMATRIKS(room[current_room], &gameRoom);
	Elmt(gameRoom, Absis(p_pos), Ordinat(p_pos)) = 'P';
	printf("X: %d --- Y: %d\n", Absis(p_pos), Ordinat(p_pos));
	
	TulisMATRIKS(gameRoom);
    printf("\n");
	displayCustomer();
    if (InfoHeadQue(Customer).Jam.H == Jam.H && InfoHeadQue(Customer).Jam.M == Jam.M 
    && InfoHeadQue(Customer).Jam.S == Jam.S)
    {
        DelQue(&Customer, &buang);
        life--;
    }

    /* Life Habis */
    if(life == 0)
    {
        printCredit(money);
        exit(0);
    }
	printf("\n");
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
                        case OPTION_EXIT:{
                            printCredit(money);
                            exit(0);
                        }
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
	clrscr();
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

