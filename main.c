#include <stdio.h>
#include <stdlib.h>
#include"heap.c"

int tamanho = 4; 

int main(void){
     
    Aero *v = malloc(tamanho * sizeof(Aero));// Aloca memória para 3 aeronaves

    v[0] = criar_aeronave("FL123", 200, 600, 1, 0);
    v[1] = criar_aeronave("AB456", 50, 800, 2, 1);
    v[2] = criar_aeronave("CD789", 300, 500, 1, 0);
    v[3] = criar_aeronave("TM459", 500, 360, 0, 1);

    exibir_aeronaves(v);

    printf("\nTamanho inicial: %d\n", tamanho);
    
    v = adicionar_aeronave(&v);
    
    printf("\nTamanho final: %d\n", tamanho);

    exibir_aeronaves(v);

    free(v);
    return 0;
}