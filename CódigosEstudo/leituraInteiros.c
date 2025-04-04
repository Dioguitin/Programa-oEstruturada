#include <stdio.h>

int main() {
    int valor_inicial, incremento, quantidade;
    
    printf("Digite o valor inicial da progressão aritmética: ");
    scanf("%d", &valor_inicial);
    
    printf("Digite o fator de incremento: ");
    scanf("%d", &incremento);
    
    printf("Digite a quantidade de termos: ");
    scanf("%d", &quantidade);
    
    if (quantidade <= 0) {
        printf("A quantidade de termos deve ser maior que zero.\n");
        return 1;
    }
    
    printf("Série da progressão aritmética:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d", valor_inicial + (i * incremento));
        if (i < quantidade - 1) {
            printf(", ");
        }
    }
    printf("\n");
    
    return 0;
}