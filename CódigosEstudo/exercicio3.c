#include <stdio.h>

int main() {
    char sexo;
    int idade, idade_mais_pesada = 0, total_homens_menos30 = 0, total_mulheres = 0, total_mulheres_menos50 = 0;
    float peso, maior_peso = 0, soma_peso_homens_menos30 = 0;
    int continuar;
    
    do {
        printf("Digite o sexo (M para masculino, F para feminino): ");
        scanf(" %c", &sexo);
        
        printf("Digite a idade: ");
        scanf("%d", &idade);
        
        printf("Digite o peso: ");
        scanf("%f", &peso);
        
        if (peso >= maior_peso) {
            maior_peso = peso;
            idade_mais_pesada = idade;
        }
        
        if (sexo == 'M' || sexo == 'm') {
            if (idade < 30) {
                soma_peso_homens_menos30 += peso;
                total_homens_menos30++;
            }
        }
        
        if (sexo == 'F' || sexo == 'f') {
            total_mulheres++;
            if (peso < 50) {
                total_mulheres_menos50++;
            }
        }
        
        printf("Deseja continuar? (1 para Sim, 0 para Não): ");
        scanf("%d", &continuar);
        
    } while (continuar == 1);
    
    float media_peso_homens_menos30 = 0;
    if (total_homens_menos30 > 0) {
        media_peso_homens_menos30 = soma_peso_homens_menos30 / total_homens_menos30;
    }
    
    float percentual_mulheres_menos50 = 0;
    if (total_mulheres > 0) {
        percentual_mulheres_menos50 = ((float)total_mulheres_menos50 / total_mulheres) * 100;
    }
    
    printf("\nResultados:\n");
    printf("Idade da pessoa mais pesada: %d anos\n", idade_mais_pesada);
    printf("Média de peso dos homens com menos de 30 anos: %.2f kg\n", media_peso_homens_menos30);
    printf("Percentual de mulheres com menos de 50 kg: %.2f%%\n", percentual_mulheres_menos50);
    
    return 0;
}
