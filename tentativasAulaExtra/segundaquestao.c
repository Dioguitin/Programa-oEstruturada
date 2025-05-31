#include <stdio.h>
#include <string.h>

#define TAM_NOME 30
#define TAM_TEMP 256

struct Livro {
    char titulo[TAM_NOME];
    char autor[TAM_NOME];
    char editora[TAM_NOME];
    int anoPublicacao, qtdPaginas;
};

void lerStr(char *str, int count);
void lerLivro(struct Livro *livro);
void imprimirLivro(struct Livro livro);

int main(){

struct Livro livro1, livro2;
printf("----- Digitação dos dados do Livro 1 -----\n");
lerLivro(&livro1);
printf("----- Digitação dos dados do Livro 2 -----\n");
lerLivro(&livro2);
printf("----- Impressão dados do Livro 1 -----\n");
imprimirLivro(livro1);
printf("----- Impressão dados do Livro 2 -----\n");
imprimirLivro(livro2);
return 0;
}

void lerStr(char *str, int count) {
  fgets(str, count, stdin);
  int tam = strlen(str);
  if (tam > 0 && str[tam - 1] == '\n') {
    str[tam - 1] = '\0';
  }
}

void lerLivro(struct Livro *livro) {
  char tempStr[TAM_TEMP];
  printf("Digite o nome do livro: \n");
  lerStr(livro->titulo, TAM_NOME);
  printf("Digite o nome do autor: \n");
  lerStr(livro->autor, TAM_NOME);
  printf("Digite o nome da editora: \n");
  lerStr(livro->editora, TAM_NOME);
  printf("Digite o ano de publicação do livro: \n");
  scanf("%d", &livro->anoPublicacao);
  printf("Digite a quantidade de páginas: \n");
  scanf("%d", &livro->qtdPaginas);
}
 
void imprimirLivro(struct Livro livro) {
  printf("(Livro: %s\nAutor: %s\nEditora: %s\nAno: %d,Quantia de paginas:  %d)\n",
    livro.titulo,
    livro.autor,
    livro.editora,
    livro.anoPublicacao,
    livro.qtdPaginas
  );
}








/*
  scanf("%d", &pessoa->idade); // scanf("%d", &(*pessoa).idade);
  printf("Digite o peso: ");
  scanf("%lf", &pessoa->peso); // scanf("%lf", &(*pessoa).peso);
  printf("Digite a altura: ");
  */