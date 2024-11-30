#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"arquivos.c"

int tamanho = 0; 

int main(void){
    int opcao;
    char nome_arquivo[50], id_aero[6];

    Aero a; 
    Aero *v = NULL;  
    v = carregar_aeronaves(&v, "voos");
    
    #ifdef _WIN32
        Sleep(1000);
        printf("\n\n.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
    #else
        sleep(1);
        printf("\n\n.");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
    #endif


    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    while (opcao != 0) { 
        printf("\n\n****************************************** \
                \nO que deseja fazer? \
                \n1- Adicionar nova aeronave\
                \n2- Consultar maior prioridade\
                \n3- Remover maior prioridade\
                \n4- Atualizar aeronave\
                \n5- Exibir aeronaves\
                \n6- Carregar arquivo\
                \n0- Sair");

        printf("\n\n>>> ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (opcao) {
            case 1:     // Adicionar nova aeronave
                a = criar_aeronave_manualmente();
                if (validar_id(v, a.identificador)) { 
                    printf("\nOperacao cancelada.\n");
                } else {
                    inserir_aeronave(&v, a);
                }
                break;
                
            case 2:     // Consultar maior prioridade
                printf("\nAeronave de maior prioridade:\
                \nId: %s\
                \nPrioridade: %d", 
                v[0].identificador, v[0].prioridade);
                break;

            case 3:     // Remover maior prioridade
                printf("\nRemovendo aeronave (id: %s)", v[0].identificador);
                remover_maior_prioridade(&v);
                break;

            case 4:     // Atualizar aeronave
                if (v == NULL || tamanho == 0) {
                    printf("\nNao ha aeronaves para atualizar.\n");
                } else {
                    printf("Qual o ID da aeronave que deseja atualizar?\n>>> ");
                    fgets(id_aero, sizeof(id_aero), stdin);
                    id_aero[strcspn(id_aero, "\n")] = '\0'; 
                    atualizar_prioridade(&v, id_aero);
                }
                break;

            case 5:     // Exibir aeronaves
                exibir_aeronaves(v);
                break;

            case 6:     // Carregar arquivo
                printf("Qual o nome do arquivo? (digite sem a extensao dele) \n>>> ");
                fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
                nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
                v = carregar_aeronaves(&v, nome_arquivo);
                break;

            case 0:     // Sair
                printf("Salvando banco de dados");

                #ifdef _WIN32
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                #else
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                #endif

                salvar_arquivo(v, "voos");
                printf("\n\nSaindo...\n");
                free(v);
                break;
            
            default:
                printf("\n\nEntrada invalida!");
                break;
        }
        
    }

    
    return 0;
}