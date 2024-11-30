#ifndef HEAP_H
#define HEAP_H

#include "aeronave.c"

void trocar(Aero* v, int i, int j);

void heapify(Aero *v, int t, int i);

void organizar_maxHeap(Aero *v, int t);

void heapsort(Aero *v, int t);
        
    int validar_id(Aero *v, char id[]);
    void inserir_aeronave(Aero **v, Aero a);
    void remover_maior_prioridade(Aero **v);
    void atualizar_prioridade(Aero **v, char id[]);
#endif