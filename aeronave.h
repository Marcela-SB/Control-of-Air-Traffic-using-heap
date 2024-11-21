#ifndef AERONAVE_H
#define AERONAVE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct aeronave Aero;

    struct aeronave
    {
        char identificador[6];
        double combustivel;
        int horario;
        bool operacao;
        bool emergencia;
        int prioridade;
    };

    int calcular_prioridade(Aero a);

    Aero criar_aeronave(char id, int comb, int h, bool op, bool e, int p);
#endif