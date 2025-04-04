#include <stdio.h>

int main(){

    double ValConta, multa, juros, diasAtraso, Total;

    printf("Digite o valor de sua conta atrasada: \n");
    scanf("%lf", &ValConta);
    printf("\nDigite a quantidade de dias de atraso de sua conta: \n");
    scanf("%lf", &diasAtraso);

    multa = ValConta * 0.2;

    if (diasAtraso <= 30){
        juros = ValConta * (0.01 * 0.3) * diasAtraso;
        Total = ValConta + multa + juros;
        printf("A sua conta está com um atraso de: %.0lf dias\nOs juros acumulados foram de: R$%.2lf\nA multa do atrasado foi de: R$%.2lf\nO valor final da sua conta é: R$%.2lf\n ", diasAtraso, juros, multa, Total);
    }   else if (diasAtraso <= 44){
            juros = ValConta * (0.01 * 0.3) * diasAtraso; 
            Total = ValConta + multa + juros;
            printf("A sua conta está com um atraso de: %.0lf dias\nOs juros acumulados foram de: R$%.2lf\nA multa do atrasado foi de: R$%.2lf\nO valor final da sua conta é: R$%.2lf\n ", diasAtraso, juros, multa, Total);
    }   else{
        printf("Sua conta ultrapassa o limite de 44 dias de atraso!\n");
        return -1;
    }
    return 0;
}