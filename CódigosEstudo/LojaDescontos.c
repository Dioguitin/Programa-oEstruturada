#include <stdio.h>




int main(){

    int categoria, quantia;
    double preco, descontoCategoria, Total;

    printf("Digite a categoria do seu produto\n");
    scanf("%d", &categoria);
    if (categoria >= 1 && categoria <= 3){
        printf("Digite o valor do produto e a quantidade comprada\n");
        scanf("%lf %d", &preco, &quantia);
        if (categoria == 1){
            descontoCategoria = preco - (preco * 0.1);
        }   else if (categoria == 2){
            descontoCategoria = preco - (preco * 0.15);
            }   else{
                descontoCategoria = preco - (preco * 0.08);
            }
        else{
            printf("Categoria inválida!\n");
            return -1;
        }
    return descontoCategoria;
    }
    if (quantia <= 2){
        Total = descontoCategoria - (descontoCategoria * 0.02);
        printf("O valor final da sua compra foi: %lf\n", Total);
    } else if (quantia > 2 && <= 10){
        Total = descontoCategoria - (descontoCategoria * 0.05);
        printf("O valor final da sua compra foi: %lf\n", Total);
        } else if (quantia > 10){
            Total = descontoCategoria - (descontoCategoria * 0.1);
            printf("O valor final da sua compra foi: %lf\n", Total);
            }   else    {
                printf("Quantia incorreta\n");
             return -1;
            }




return 0;
}