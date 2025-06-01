#include <stdio.h>
#include <string.h>
#include <ctype.h>


int contarVogais(char frase[]);
void capitalizar(char frase[]);

int main() {
    char frase[201];

    printf("Digite uma frase: ");
    fgets(frase, 201, stdin);
    frase[strcspn(frase, "\n")] = '\0'; 

    printf("Frase digitada: %s\n", frase);

    int totalVogais = contarVogais(frase);
    printf("Total de vogais: %d\n", totalVogais);

    capitalizar(frase);
    printf("Frase com cada palavra iniciando em maiúscula: %s\n", frase);

    return 0;
}

int contarVogais(char frase[]) {
    int contador = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = tolower(frase[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}

void capitalizar(char frase[]) {
    int novoInicio = 1; 

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == ' ') {
            novoInicio = 1;
        } else if (novoInicio && frase[i] >= 'a' && frase[i] <= 'z') {
            frase[i] = frase[i] - 32; 
            novoInicio = 0;
        } else {
            novoInicio = 0;
        }
    }
}
