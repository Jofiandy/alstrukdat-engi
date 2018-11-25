#include <stdio.h>
#include "../point/point.h"

int main(){
    POINT Titik;
    Titik = MakePOINT(1, 2);
    TulisPOINT(Titik);
    Geser(&Titik, 10, 20);
    Turun(&Titik);
    KeKanan(&Titik);
    KeKiri(&Titik);
    TulisPOINT(Titik);
    BacaPOINT(&Titik);
    TulisPOINT(Titik);
    return 0;
}
