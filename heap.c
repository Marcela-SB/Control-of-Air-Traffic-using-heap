#include "heap.h"
#include <math.h>

extern int tamanho;

void trocar(Aero *v, int i, int j) {
    Aero temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void heapify(Aero *v, int t, int i) {
    int maior = i; 
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2; 
   
    if (esquerda < t && v[esquerda].prioridade < v[maior].prioridade) {
        maior = esquerda;
    }

    if (direita < t && v[direita].prioridade < v[maior].prioridade) {
        maior = direita;
    }

    if (maior != i) {
        trocar(v, i, maior);
        heapify(v, t, maior);
    }
}

void organizar_maxHeap(Aero *v, int t) {
    int i;
    for (i = t / 2 - 1; i >= 0; i--) {
        heapify(v, t, i);
    }
}

void heapsort(Aero *v, int t) {
    organizar_maxHeap(v, t); 
    int i;
    for (i = t - 1; i > 0; i--) {
        trocar(v, 0, i);
        heapify(v, i, 0);   
    }
}


int validar_id(Aero *v, char id[]){
    int i;
    for (i = 0; i < tamanho; i++) {
        if (strcmp(v[i].identificador, id) == 0) {
            printf("\nNao e possivel inserir aeronave %s. Id ja existe!", id);
            return 1;
        }
        
    }
    return 0;
}

void inserir_aeronave(Aero **v, Aero a) {
    tamanho += 1;
    *v = (Aero*)realloc(*v, (tamanho) * sizeof(Aero));
    if (*v == NULL) {
        printf("\nErro de alocação de memória!");
        exit(1);  
    }
    
    (*v)[tamanho-1] = a;

    heapsort(*v, tamanho);
}

void remover_maior_prioridade(Aero **v){
    if (tamanho == 0) {
        printf("\nNenhuma aeronave para remover!");
    }

    trocar(*v, 0, tamanho-1);

    tamanho -= 1;
    *v = (Aero*)realloc(*v, (tamanho) * sizeof(Aero));
    if (*v == NULL) {
        printf("\nErro de alocação de memória!");
        exit(1);  
    }
    heapsort(*v, tamanho);
}

void atualizar_prioridade(Aero **v, char id[]) {
    int i, valor;
    int opcao_atualizar = -1;

    // Percorrendo o vetor de aeronaves
    for (i = 0; i < tamanho; i++) {
        if (strncmp((*v)[i].identificador, id, 6) == 0) {
            while (opcao_atualizar != 0) {
                printf("\n\nO que deseja atualizar? \
                \n1- Combustivel\
                \n2- Horaio de chegada/saida\
                \n3- Operacao de pouso/decolagem\
                \n4- Situacao de emergencia\
                \n0- Sair\
                \n\n>>> ");
                scanf("%d", &opcao_atualizar);

                switch (opcao_atualizar) {
                    case 1: // Atualizar combustível
                        printf("\nQual a nova quantidade de combustivel?\n>>> ");
                        scanf("%d", &valor); 
                        (*v)[i].combustivel = valor; 
                        break;
                    case 2: // Atualizar horário
                        printf("\nQual o novo horario de chegada/saida? (em minutos do dia)\n>>> ");
                        scanf("%d", &valor);
                        (*v)[i].horario = valor; 
                        break;
                    case 3: // Atualizar operação (pouso/decolagem)
                        printf("\nQual a operacao? (0-decolagem / 1-pouso)\n>>> ");
                        scanf("%d", &valor); 
                        (*v)[i].operacao = valor;  
                        break;
                    case 4: // Atualizar situação de emergência
                        printf("\nEsta em situacao de emergencia? (0-Nao / 1-Sim)\n>>> ");
                        scanf("%d", &valor);
                        (*v)[i].emergencia = valor; 
                        break;
                    case 0: // Sair 
                        printf("Sair da operacao...");
                        break;
                    default:
                        printf("\nValor invalido!"); 
                        break;
                }
            }
            
            // Recalcular a prioridade após a atualização dos dados
            (*v)[i].prioridade = calcular_prioridade((*v)[i]); 

            printf("\nAeronave com id = %s foi atualizada com sucesso!\n", id);
            heapsort(*v, tamanho);
            return; 
        }
    }

    printf("\nAeronave com id = %s nao encontrada.\n", id);
}
