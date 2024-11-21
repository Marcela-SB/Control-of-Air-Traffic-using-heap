#include "aeronave.h"


int calcular_prioridade(Aero a){
    int prioridade = (1000−a.combustivel)+ (1440−a.horario) (500×a.operacao) + (5000×a.emergencia);

    return prioridade;
}

Aero criar_aeronave(char id, int comb, int h, bool op, bool e, int p){
    Aero a;

    a.identificador = (char *) malloc(strlen(id));
    strcpy(a.identificador, id);

    a.combustivel = comb;
    a.horario = h;
    a.operacao = op;
    a.emergencia = e;
    a.prioridade = calcular_prioridade(a);

    return a;
}

