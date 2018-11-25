#include <stdio.h>
#include "jam.h"

Waktu Time;

int main(){
    CreateStart(&Time);
    Time = CreateWaktu(12, 0, 1, 0);
    UpDate(&Time, 40);
    UpDate(&Time, 21);
    TulisWaktu(Time);
    TulisWaktuKesabaran(Time);
    return 0;
}