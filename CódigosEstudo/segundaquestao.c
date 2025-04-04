#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000

int main() {
    int contadores[10] = {0}; 
    int num, i;
    srand(3);
    
    printf("Números gerados:\n");
    for (i = 0; i < TAM; i++) {
        num = rand() % 1000 + 1; 
        printf("%d ", num);
        contadores[num % 10]++;
    }
    
    printf("Contagem de números terminados em:\n");
    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, contadores[i]);
    }
    
    return 0;
}

/*Código referente à segunda questão da atividade de vetores*/