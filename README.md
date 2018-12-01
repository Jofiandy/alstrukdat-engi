# alstrukdat-engi (a.k.a. Engi's Kitchen Expansion)

A command-line strategy and time-management game made with C with game mechanics akin to Diner Dash, where player shall play the role of a waiter who has to receive and serve orders in multiple rooms. Done to fulfill IF2110 Algorithm & Data Structure's Big Mission (or whatever Tugas Besar is called).

## Known Bug(s)
Too lazy to fix, please create a pull request.
* Can't start a new game after post-game ending.
* On Linux, moving south when there is an obstacle treats the down arrow button as "B" (i.e. throw on-hand ingredients).

## Installation and Running
* Make sure that GNU C is already installed on your computer.
* To compile and run from **Windows**, change the include in game.c to "key_windows/key.h" (line 6-7), execute:
``` bash
tubes> compile_win
tubes> "Engi's Kitchen"
```
* To compile and run from **Linux**, change the include in game.c to "key_linux/key.h" (line 6-7), execute:
``` bash
tubes> chmod +x compile_lin.sh
tubes> ./compile_lin
tubes> ./"Engi's Kitchen"
```
