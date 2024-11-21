#include "arvore.h"

Arv *criar_arvore(Aero a, int *e, int *d){
    Arv *no;

    no.a = a;

    no.esquerda = (int*) malloc(int *e);
    no.esquerda = e;

    no.direita = (int*) malloc(int *d);
    no.direita = d;

    return no;
}


void liberar_arvore(Arv *raiz){
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}