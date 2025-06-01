#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 40

typedef struct {
    int codigo;
    char descricao[100];
    float valor_unitario;
    int quantidade;
} Produto;

// (a) Procedimento para cadastrar novos produtos
void cadastrarProdutos(Produto estoque[], int *total) {
    int qtd;
    printf("Quantos produtos deseja cadastrar? (máximo %d): ", MAX_PRODUTOS - *total);
    scanf("%d", &qtd);
    getchar(); // limpa o \n

    if (*total + qtd > MAX_PRODUTOS) {
        printf("Erro: isso excederia o limite de produtos (%d).\n", MAX_PRODUTOS);
        return;
    }

    for (int i = 0; i < qtd; i++) {
        Produto p;
        printf("\nProduto %d:\n", *total + 1);
        printf("Código: ");
        scanf("%d", &p.codigo);
        getchar();

        printf("Descrição: ");
        fgets(p.descricao, sizeof(p.descricao), stdin);
        p.descricao[strcspn(p.descricao, "\n")] = '\0';

        printf("Valor unitário: ");
        scanf("%f", &p.valor_unitario);

        printf("Quantidade em estoque: ");
        scanf("%d", &p.quantidade);
        getchar();

        estoque[*total] = p;
        (*total)++;
    }
}

// Busca produto por código (retorna índice ou -1)
int buscarProduto(Produto estoque[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (estoque[i].codigo == codigo)
            return i;
    }
    return -1;
}

// (b) Procedimento para alterar valor unitário
void alterarValor(Produto estoque[], int total) {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    int i = buscarProduto(estoque, total, codigo);
    if (i != -1) {
        printf("Valor atual: %.2f\n", estoque[i].valor_unitario);
        printf("Novo valor: ");
        scanf("%f", &estoque[i].valor_unitario);
        printf("Valor atualizado com sucesso.\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

// (c) Função que retorna o valor unitário
float consultarValor(Produto estoque[], int total, int codigo) {
    int i = buscarProduto(estoque, total, codigo);
    if (i != -1)
        return estoque[i].valor_unitario;
    else
        return -1;
}

// (d) Função que retorna a quantidade em estoque
int consultarQuantidade(Produto estoque[], int total, int codigo) {
    int i = buscarProduto(estoque, total, codigo);
    if (i != -1)
        return estoque[i].quantidade;
    else
        return -1;
}

// (e) Procedimento de venda
void venderProduto(Produto estoque[], int total) {
    int codigo, quantidade;
    printf("Código do produto: ");
    scanf("%d", &codigo);

    int i = buscarProduto(estoque, total, codigo);
    if (i == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    if (estoque[i].quantidade == 0) {
        printf("Produto sem estoque.\n");
        return;
    }

    printf("Quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade <= estoque[i].quantidade) {
        estoque[i].quantidade -= quantidade;
        float total = quantidade * estoque[i].valor_unitario;
        printf("Venda realizada. Total a pagar: R$ %.2f\n", total);
    } else {
        printf("Estoque insuficiente. Apenas %d disponíveis.\n", estoque[i].quantidade);
        char opcao;
        printf("Deseja comprar a quantidade disponível? (s/n): ");
        scanf(" %c", &opcao);
        if (opcao == 's' || opcao == 'S') {
            float total = estoque[i].quantidade * estoque[i].valor_unitario;
            estoque[i].quantidade = 0;
            printf("Venda realizada. Total a pagar: R$ %.2f\n", total);
        } else {
            printf("Venda cancelada.\n");
        }
    }
}

// (f) Atualizar quantidade do produto
void atualizarEstoque(Produto estoque[], int total) {
    int codigo, nova_quantidade;
    printf("Código do produto: ");
    scanf("%d", &codigo);

    int i = buscarProduto(estoque, total, codigo);
    if (i != -1) {
        printf("Quantidade atual: %d\n", estoque[i].quantidade);
        printf("Nova quantidade: ");
        scanf("%d", &nova_quantidade);
        estoque[i].quantidade = nova_quantidade;
        printf("Estoque atualizado.\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

// (g) Exibir código e descrição de todos os produtos
void listarProdutos(Produto estoque[], int total) {
    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < total; i++) {
        printf("Código: %d | Descrição: %s\n", estoque[i].codigo, estoque[i].descricao);
    }
    printf("==========================\n");
}

// (h) Exibir produtos com estoque zero
void listarZerados(Produto estoque[], int total) {
    printf("\n=== Produtos com Estoque Zerado ===\n");
    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (estoque[i].quantidade == 0) {
            printf("Código: %d | Descrição: %s\n", estoque[i].codigo, estoque[i].descricao);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto com estoque zerado.\n");
    }
    printf("====================================\n");
}

// Menu principal
int main() {
    Produto estoque[MAX_PRODUTOS];
    int total_produtos = 0;
    int opcao;

    do {
        printf("\n==== MENU ====\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Alterar valor unitário\n");
        printf("3 - Consultar valor unitário\n");
        printf("4 - Consultar quantidade em estoque\n");
        printf("5 - Realizar venda\n");
        printf("6 - Atualizar quantidade em estoque\n");
        printf("7 - Listar todos os produtos\n");
        printf("8 - Listar produtos com estoque zero\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        int codigo;

        switch (opcao) {
            case 1:
                cadastrarProdutos(estoque, &total_produtos);
                break;
            case 2:
                alterarValor(estoque, total_produtos);
                break;
            case 3:
                printf("Código do produto: ");
                scanf("%d", &codigo);
                float valor;
                valor = consultarValor(estoque, total_produtos, codigo);
                if (valor != -1)
                    printf("Valor unitário: R$ %.2f\n", valor);
                else
                    printf("Produto não encontrado.\n");
                break;
            case 4:
                printf("Código do produto: ");
                scanf("%d", &codigo);
                int qtd;
                qtd = consultarQuantidade(estoque, total_produtos, codigo);
                if (qtd != -1)
                    printf("Quantidade em estoque: %d\n", qtd);
                else
                    printf("Produto não encontrado.\n");
                break;
            case 5:
                venderProduto(estoque, total_produtos);
                break;
            case 6:
                atualizarEstoque(estoque, total_produtos);
                break;
            case 7:
                listarProdutos(estoque, total_produtos);
                break;
            case 8:
                listarZerados(estoque, total_produtos);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
