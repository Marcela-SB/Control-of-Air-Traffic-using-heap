#ifndef ARVORE_H
#define ARVORE_H

    #include "aeronave.h"

    typedef struct arvore Arv;
    struct arvore {
        Aero a;
        int *esquerda;
        int *direita;
    };

    Arv *criar_arvore(Aero a, int *e, int *d);
    void liberar_arvore(Arv *raiz);

#endif