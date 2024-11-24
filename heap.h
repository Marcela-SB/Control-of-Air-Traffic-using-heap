#ifndef HEAP_H
#define HEAP_H

#include "aeronave.c"

void trocar(Aero* v, int i, int j);

void heapify(Aero *v, int n, int i);

void organizar_maxHeap(Aero *v, int n);
        
    
    Aero* adicionar_aeronave(Aero **v);

#endif