#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "heap.c"

Aero* carregar_aeronaves(Aero **v, char nomeArquivo[]);

void salvar_arquivo(Aero *v, char nomeArquivo[]);

#endif