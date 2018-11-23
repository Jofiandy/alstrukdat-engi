# tubes (a.k.a. Engi's Kitchen Expansion)

A command-line strategy and time-management game made with C with game mechanics akin to Diner Dash, where player shall play the role of a waiter who has to receive and serve orders in multiple rooms. Done to fulfill IF2110 Algorithm & Data Structure's Big Mission (or whatever Tugas Besar is called).

## Current To-Do's
Always mark what's currently missing on the source code by putting in a comment, "// TODO - Thing(s) to do".
* ~~Main menu~~ DONE!
* New game and save game handler
* The game itself

## Installation and Running
* Make sure that GNU C is already installed on your computer.
* To compile and run from **Windows**, change the include in game.c to "windows/key.h" (line 6-7), execute:
``` bash
tubes> compile_win
tubes> "Engi's Kitchen"
```
* To compile and run from **Linux**, change the include in game.c to "linux/key.h" (line 6-7), execute:
* *Once*
``` bash
tubes> chmod +x compile_lin.sh
```
* *Later on*
``` bash
tubes> ./compile_lin
tubes> ./"Engi's Kitchen"
```
