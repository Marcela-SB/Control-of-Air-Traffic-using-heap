    #ifndef AERONAVE_H
    #define AERONAVE_H

        #include <stdio.h>
        #include <stdlib.h>
        #include <stdbool.h>

        typedef struct aeronave Aero;

        struct aeronave
        {
            char identificador[6];
            float combustivel;
            int horario;
            int operacao;
            int emergencia;
            int prioridade;
        };

        int calcular_prioridade(Aero a);

        Aero criar_aeronave(const char id[6], float c, int h, int o, int e);
        Aero criar_aeronave_manualmente();
        
        void exibir_aeronaves(Aero *v);
    #endif