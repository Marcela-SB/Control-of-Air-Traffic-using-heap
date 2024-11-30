#include "arquivos.h"

Aero* carregar_aeronaves(Aero **v, char nome_arquivo[]) {
    char caminho[55];
    sprintf(caminho, "%s.csv", nome_arquivo);

    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return *v;
    }

    char id[6];
    int c, h, o, e;

    while (fscanf(arquivo, "%5[^,],%d,%d,%d,%d\n", id, &c, &h, &o, &e) == 5) {
        if (validar_id(*v, id) == 0) {
            Aero a = criar_aeronave(id, c, h, o, e);
            inserir_aeronave(&(*v), a);
        }
    }

    heapsort(*v, tamanho);
    fclose(arquivo);
    if (tamanho > 0) {
        printf("\n\nAeronaves carregadas com sucesso!");
    } else {
        printf("\n\nNenhuma aeronave carregada.");
    }
    return *v;
}

void salvar_arquivo(Aero *v, char nomeArquivo[]){
    char caminho[55];
    sprintf(caminho, "%s.csv", nomeArquivo);

    FILE *arquivo;
    arquivo = fopen(caminho, "w");

    if(arquivo == NULL) printf("Erro ao abrir arquivo");

    if (tamanho > 0) {
        int i;
        for (i = 0; i < tamanho; i++) {
            fprintf(arquivo, "%s, %d, %d, %d, %d\n", 
                v[i].identificador,
                v[i].combustivel,
                v[i].horario,
                v[i].operacao,
                v[i].emergencia);
        }
    }
    
    fclose(arquivo);
    printf("\n\nArquivo salvo!");
    return;
}