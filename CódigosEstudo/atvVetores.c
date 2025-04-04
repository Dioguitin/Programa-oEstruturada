#include <stdio.h>

#define TAM 50

void imprimirVetor(int vetor[], int tamanho){
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);

    }
    printf("\n");
}

void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= TAM) {
        printf("Erro: vetor cheio!\n");
        return;
    }

    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

void removerValor(int vetor[], int *tamanho, int valor) {
    int pos = buscaBinaria(vetor, *tamanho, valor);
    if (pos == -1) {
        printf("Valor não encontrado. Nada foi removido.\n");
        return;
    }
    for (int i = pos; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("O valor escolhido foi removido.\n");
}


int main() {
    int vetor[TAM];
    int tamanho = 0;
    int capacidade;

    do {
        printf("Digite a capacidade do vetor (entre 3 e 50): ");
        scanf("%d", &capacidade);
    } while (capacidade < 3 || capacidade > 50);

    int qtd;
    do {
        printf("Digite a quantidade de elementos a inserir inicialmente (até %d): ", capacidade);
        scanf("%d", &qtd);
    } while (qtd < 0 || qtd > capacidade);

    printf("Digite os valores inteiros:\n");
    for (int i = 0; i < qtd; i++) {
        int valor;
        scanf("%d", &valor);
        inserirOrdenado(vetor, &tamanho, valor);
    }

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Checar elemento no vetor\n");
        printf("3 - Retirar elemento\n");
        printf("4 - Inserir novo elemento\n");
        printf("0 - Encerrar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int valor;
        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;
            case 2:
                printf("Digite o valor a consultar: ");
                scanf("%d", &valor);
                int pos = buscaBinaria(vetor, tamanho, valor);
                if (pos != -1)
                    printf("Elemento encontrado na posição %d\n", pos);
                else
                    printf("Elemento não encontrado\n");
                break;
            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                removerValor(vetor, &tamanho, valor);
                break;
            case 4:
                if (tamanho >= capacidade) {
                    printf("Erro: vetor está na capacidade máxima definida (%d).\n", capacidade);
                } else {
                    printf("Digite o valor a inserir: ");
                    scanf("%d", &valor);
                    inserirOrdenado(vetor, &tamanho, valor);
                }
                break;
            case 0:
                printf("Encerrando programa...\n");
                default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != 0);
    return 0;
}
