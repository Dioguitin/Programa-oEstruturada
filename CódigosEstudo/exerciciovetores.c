#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 100

// Função para gerar o vetor com números aleatórios
void gerarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100 + 1; // Gera números aleatórios entre 1 e 100
    }
}

// Função para calcular o somatório dos números pares
int somarPares(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            soma += vetor[i];
        }
    }
    return soma;
}

// Função para calcular o produto dos números ímpares
int produtoImpares(int vetor[], int tamanho) {
    int produto = 1;
    int encontrouImpar = 0; // Flag para verificar se encontrou algum número ímpar
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 != 0) {
            produto *= vetor[i];
            encontrouImpar = 1;
        }
    }
    // Se não encontrou nenhum ímpar, retorna 0 (porque o produto de nenhum número é 0)
    if (!encontrouImpar) {
        return 0;
    }
    return produto;
}

// Função para encontrar o menor valor do vetor
int encontrarMenorValor(int vetor[], int tamanho) {
    int menor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

int main() {
    // Semente para geração de números aleatórios
    srand(time(NULL));

    int vetor[TAMANHO_VETOR];

    // Gerar o vetor de números aleatórios
    gerarVetor(vetor, TAMANHO_VETOR);

    // Calcular o somatório dos números pares
    int somaPares = somarPares(vetor, TAMANHO_VETOR);
    printf("Somatório dos valores pares: %d\n", somaPares);

    // Calcular o produto dos números ímpares
    int produtoPares = produtoImpares(vetor, TAMANHO_VETOR);
    printf("Produto dos valores ímpares: %d\n", produtoPares);

    // Encontrar o menor valor do vetor
    int menorValor = encontrarMenorValor(vetor, TAMANHO_VETOR);
    printf("Menor valor do vetor: %d\n", menorValor);

    return 0;
}
