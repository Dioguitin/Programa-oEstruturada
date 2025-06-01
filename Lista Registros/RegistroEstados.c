#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 26
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int num_veiculos;
    int num_acidentes;
} Estado;

void coletarDados(Estado estados[]);
void encontrarExtremos(Estado estados[], int *indice_maior, int *indice_menor);
float calcularPercentual(Estado estado);
float calcularMedia(Estado estados[]);
void exibirEstadosAcimaDaMedia(Estado estados[], float media);


int main() {
    Estado estados[NUM_ESTADOS];
    int indice_maior, indice_menor;

    
    coletarDados(estados);

   
    encontrarExtremos(estados, &indice_maior, &indice_menor);

    printf("\nEstado com MAIOR numero de acidentes: %s (%d acidentes)\n",
           estados[indice_maior].nome, estados[indice_maior].num_acidentes);
    printf("Estado com MENOR numero de acidentes: %s (%d acidentes)\n",
           estados[indice_menor].nome, estados[indice_menor].num_acidentes);

    
    printf("\nPercentual de veiculos envolvidos em acidentes por estado:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        float percentual = calcularPercentual(estados[i]);
        printf("%s: %.2f%%\n", estados[i].nome, percentual);
    }

    
    float media = calcularMedia(estados);
    printf("\nMedia de acidentes no pais: %.2f\n", media);

    
    exibirEstadosAcimaDaMedia(estados, media);

    return 0;
}

void coletarDados(Estado estados[]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("\nEstado %d:\n", i + 1);
        printf("Nome do estado: ");
        scanf(" %[^\n]", estados[i].nome);
        printf("Numero de veiculos (2007): ");
        scanf("%d", &estados[i].num_veiculos);
        printf("Numero de acidentes (2007): ");
        scanf("%d", &estados[i].num_acidentes);
    }
}

void encontrarExtremos(Estado estados[], int *indice_maior, int *indice_menor) {
    *indice_maior = 0;
    *indice_menor = 0;
    for (int i = 1; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > estados[*indice_maior].num_acidentes) {
            *indice_maior = i;
        }
        if (estados[i].num_acidentes < estados[*indice_menor].num_acidentes) {
            *indice_menor = i;
        }
    }
}

float calcularPercentual(Estado estado) {
    if (estado.num_veiculos == 0) return 0.0;
    return ((float)estado.num_acidentes / estado.num_veiculos) * 100;
}

float calcularMedia(Estado estados[]) {
    int soma = 0;
    for (int i = 0; i < NUM_ESTADOS; i++) {
        soma += estados[i].num_acidentes;
    }
    return (float)soma / NUM_ESTADOS;
}

void exibirEstadosAcimaDaMedia(Estado estados[], float media) {
    printf("\nEstados com numero de acidentes acima da media nacional (%.2f):\n", media);
    for (int i = 0; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > media) {
            printf("%s - %d acidentes\n", estados[i].nome, estados[i].num_acidentes);
        }
    }
}