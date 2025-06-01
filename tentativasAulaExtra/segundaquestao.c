#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

typedef struct {
    char titulo[100];
    char autor[100];
    char editora[100];
    int anoPublicacao;
    int qtdPaginas;
} Livro;


void preencherVetor(Livro vetor[], int *n);
void imprimirVetor(Livro vetor[], int n);
int buscarPorTitulo(Livro vetor[], int n, char tituloBusca[]);
void ordenarPorTitulo(Livro vetor[], int n)
int buscaBinariaPorTitulo(Livro vetor[], int n, char tituloBusca[]);


int main() {
    Livro livros[MAX_LIVROS];
    int n;

    preencherVetor(livros, &n);

    printf("\nAntes da ordenação:\n");
    imprimirVetor(livros, n);

    ordenarPorTitulo(livros, n);

    printf("\nApós ordenação por título:\n");
    imprimirVetor(livros, n);

    char tituloBusca[100];
    printf("\nDigite o título do livro para buscar: ");
    fgets(tituloBusca, 100, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    int pos = buscaBinariaPorTitulo(livros, n, tituloBusca);
    if (pos != -1) {
        printf("Livro encontrado na posição %d: %s\n", pos, livros[pos].titulo);
    } else {
        printf("Livro não encontrado.\n");
    }

    return 0;
}

void preencherVetor(Livro vetor[], int *n) {
    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", n);
    getchar(); 

    for (int i = 0; i < *n; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Título: ");
        fgets(vetor[i].titulo, 100, stdin);
        vetor[i].titulo[strcspn(vetor[i].titulo, "\n")] = '\0';

        printf("Autor: ");
        fgets(vetor[i].autor, 100, stdin);
        vetor[i].autor[strcspn(vetor[i].autor, "\n")] = '\0';

        printf("Editora: ");
        fgets(vetor[i].editora, 100, stdin);
        vetor[i].editora[strcspn(vetor[i].editora, "\n")] = '\0';

        printf("Ano de Publicação: ");
        scanf("%d", &vetor[i].anoPublicacao);

        printf("Quantidade de Páginas: ");
        scanf("%d", &vetor[i].qtdPaginas);
        getchar(); 
    }
}

void imprimirVetor(Livro vetor[], int n) {
    printf("\n--- Lista de Livros ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | %s | %s | %d | %d páginas\n", 
            i, vetor[i].titulo, vetor[i].autor, vetor[i].editora, 
            vetor[i].anoPublicacao, vetor[i].qtdPaginas);
    }
}

int buscarPorTitulo(Livro vetor[], int n, char tituloBusca[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(vetor[i].titulo, tituloBusca) == 0) {
            return i;
        }
    }
    return -1;
}

void ordenarPorTitulo(Livro vetor[], int n) {
    Livro temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (strcmp(vetor[j].titulo, vetor[j+1].titulo) > 0) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int buscaBinariaPorTitulo(Livro vetor[], int n, char tituloBusca[]) {
    int esq = 0, dir = n - 1;

    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        int cmp = strcmp(vetor[meio].titulo, tituloBusca);

        if (cmp == 0) return meio;
        else if (cmp < 0) esq = meio + 1;
        else dir = meio - 1;
    }

    return -1;
}
