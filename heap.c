#include "heap.h"

void trocar(Aero* a, Aero* b) {
    Aero aux = *a;
    *a = *b;
    *b = aux;
}

void heapify(Aero v[], int n, int i){
    int maior = i;
    int esquerda = (2*i) + 1;
    int direita = (2*i) + 2;

    if (esquerda < n && v[esquerda].prioridade > v[maior].prioridade) {
        maior = esquerda;
    }

    if (direita < n && v[direita].prioridade > v[maior].prioridade) {
        maior = direita;
    }
    
    if (maior != i) {
        trocar(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}