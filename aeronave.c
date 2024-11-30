#include "aeronave.h"
#include <string.h>

extern int tamanho;

int calcular_prioridade(Aero a) {
    int prioridade = (1000 - a.combustivel) + (1440 - a.horario) + (500 * a.operacao) + (5000 * a.emergencia);

    return prioridade;
}

Aero criar_aeronave(const char id[6], int c, int h, int o, int e){
    Aero a;

    strncpy(a.identificador, id, sizeof(a.identificador) - 1);
    a.identificador[sizeof(a.identificador) - 1] = '\0';

    a.combustivel = c;
    a.horario = h;
    a.operacao = o;
    a.emergencia = e;
    a.prioridade = calcular_prioridade(a);

    printf("\nAeronave %s criada com sucesso!", a.identificador);
    return a;
}

Aero criar_aeronave_manualmente() {
    char id[6];
    int c, h, o, e;

    printf("\n\nCriando Aeronave...");
    printf("\nQual o identificador? (ate 5 digitos) ");
    fgets(id, sizeof(id), stdin);  
    id[strcspn(id, "\n")] = 0;
    
    printf("Quanto combustivel (em litros) resta? ");
    scanf("%d", &c);
    
    printf("Qual o horario previsto de chegada ou partida (em minutos do dia)? ");
    scanf("%d", &h);
    
    printf("Qual operacao sera realizada? (0 para decolagem, 1 para pouso) ");
    scanf("%d", &o);
    
    printf("Esta em situacao de emergencia? (1-Sim / 0-Nao) ");
    scanf("%d", &e);
    
    return criar_aeronave(id, c, h, o, e);
}



void exibir_aeronaves(Aero *v) {
    if (tamanho > 0) {
        printf("\nAeronaves por ordem de prioridade:");
        int i;
        for (i = 0; i < tamanho; i++) {
            printf("\nID: %s, Prioridade: %d", v[i].identificador, v[i].prioridade);
        }
        printf("\n");
    }
    else{
        printf("\nNao ha aeronaves cadastradas!");
    }
}