#include <stdio.h>

int main() {
    int categoria, quantia;
    double preco, descontoCategoria, descontoQuantidade, precoFinal, totalCompra;


    printf("Digite a categoria do seu produto (1, 2 ou 3): ");
    scanf("%d", &categoria);

    if (categoria < 1 || categoria > 3) {
        printf("Categoria inválida!\n");
        return -1;
    }

    printf("Digite o valor do produto e a quantidade comprada: ");
    scanf("%lf %d", &preco, &quantia);

    if (preco <= 0 || quantia <= 0) {
        printf("Preço ou quantidade inválidos!\n");
        return -1;
    }

    if (categoria == 1) {
        descontoCategoria = 0.10;
    } else if (categoria == 2) {
        descontoCategoria = 0.15;
    } else {
        descontoCategoria = 0.08;
    }

    if (quantia <= 2) {
        descontoQuantidade = 0.02;
    } else if (quantia <= 10) {
        descontoQuantidade = 0.05;
    } else {
        descontoQuantidade = 0.10;
    }

    double descontoTotal = descontoCategoria + descontoQuantidade;
    precoFinal = preco * (1 - descontoTotal);

    totalCompra = precoFinal * quantia;

    printf("Desconto aplicado: %.2f%%\n", descontoTotal * 100);
    printf("Novo preço unitário: R$ %.2f\n", precoFinal);
    printf("Valor total da compra: R$ %.2f\n", totalCompra);

    return 0;
}
