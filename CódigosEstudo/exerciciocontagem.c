#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000

int main() {
    int contadores[10] = {0}; // Apenas 1 variável para armazenar os contadores
    int num, i;

    srand(3); // Inicializa a semente do gerador de números aleatórios
    
    printf("Números gerados:\n");
    for (i = 0; i < TAM; i++) {
        num = rand() % 1000 + 1; // Gera números aleatórios de 0 a 1000
        printf("%d ", num); // Imprime o número gerado
        contadores[num % 10]++; // Incrementa a contagem do último dígito
    }
    
    printf("\n\nQuantidade de números terminados em:\n");
    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, contadores[i]);
    }
    
    return 0;
}