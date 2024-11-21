#include <stdio.h>
#include <stdlib.h>
#include"heap.c"

int main(void){
    Aero v[];

    v[0] = criar_aeronave(FL123, 200, 600, 1, 0);
    v[1] = criar_aeronave(AB456, 50, 800, 2, 1);
    v[2] = criar_aeronave(CD789, 300, 500, 1, 0);


    return 0;
}