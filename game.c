#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "key.h"

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

void emptyString(char* s){
    for (int i = 0; i < 100; i++)
        s[i] = 0;
}

void firstSetup(){
    emptyString(name);
    state = STATE_MENU;
    option = OPTION_NEW;
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
                    if (option == OPTION_NEW)
                        option = OPTION_EXIT;
                    else
                        option--;
                    break;
                case KEY_DOWN:
                    if (option == OPTION_EXIT)
                        option = OPTION_NEW;
                    else
                        option++;
                    break;
                case KEY_ENTER:
                    switch(option){
                        
                        case OPTION_NEW:
                            // TODO - Overwrite savegame data with new savegame
                            emptyString(name);
                            state = STATE_NAME;
                            break;
                        case OPTION_START:
                            if (name == "")
                                state = STATE_NAME;
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
            ;
            len = strlen(name_load);
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
    printCenter("Up/down to navigate, enter to select option");
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

