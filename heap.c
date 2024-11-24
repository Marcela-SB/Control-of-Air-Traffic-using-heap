#include "heap.h"

extern int tamanho;

void trocar(Aero* v, int i, int j) {
    Aero temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void heapify(Aero *v, int n, int i){
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
        trocar(v, i, maior);
        heapify(v, n, maior);
    }
}


void organizar_maxHeap(Aero *v, int n) {
    int i;
    for (i=n/2 -1; i >= 0; i--) {
        heapify(v, n, i);
    }
}


Aero* adicionar_aeronave(Aero **v) {
    tamanho += 1;
    *v = (Aero*)realloc(*v, (tamanho) * sizeof(Aero));
    if (*v == NULL) {
        printf("\nErro de alocação de memória!");
        exit(1);  
    }

    (*v)[tamanho-1] = criar_aeronave("YZ987", 200, 60, 1, 0);
    //(*v)[tamanho-1] = criar_aeronave_manualmente();

    organizar_maxHeap(*v, tamanho);

    return *v;
}