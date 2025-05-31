#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 10
#define MAX_STR 100

typedef struct {
    int id;
    char descricao[MAX_STR];
    float preco;
    int estoque;
} Produto;

typedef struct {
    int id;
    int produtos[MAX_PRODUTOS];
    int num_produtos;
} Venda;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funções de escrita
void salvarProduto(Produto p) {
    FILE *f = fopen("produtos.dat", "ab");
    fwrite(&p, sizeof(Produto), 1, f);
    fclose(f);
}

void salvarVenda(Venda v) {
    FILE *f = fopen("vendas.dat", "ab");
    fwrite(&v, sizeof(Venda), 1, f);
    fclose(f);
}

// Cadastro
void cadastrarProduto() {
    Produto p;
    printf("ID do produto: ");
    scanf("%d", &p.id);
    limparBuffer();
    printf("Descrição: ");
    fgets(p.descricao, MAX_STR, stdin);
    p.descricao[strcspn(p.descricao, "\n")] = '\0';
    printf("Preço: ");
    scanf("%f", &p.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &p.estoque);

    salvarProduto(p);
    printf("Produto cadastrado com sucesso!\n");
}

void cadastrarVenda() {
    Venda v;
    printf("ID da venda: ");
    scanf("%d", &v.id);
    printf("Número de produtos vendidos: ");
    scanf("%d", &v.num_produtos);
    if (v.num_produtos > MAX_PRODUTOS) v.num_produtos = MAX_PRODUTOS;

    for (int i = 0; i < v.num_produtos; i++) {
        printf("ID do produto %d: ", i + 1);
        scanf("%d", &v.produtos[i]);
    }

    salvarVenda(v);
    printf("Venda registrada com sucesso!\n");
}

// Listagens
void listarProdutos() {
    FILE *f = fopen("produtos.dat", "rb");
    if (!f) {
        printf("Nenhum produto encontrado.\n");
        return;
    }
    Produto p;
    printf("==== LISTA DE PRODUTOS ====\n");
    while (fread(&p, sizeof(Produto), 1, f)) {
        printf("ID: %d | %s | R$%.2f | Estoque: %d\n", p.id, p.descricao, p.preco, p.estoque);
    }
    fclose(f);
}

void listarVendasComProdutos() {
    FILE *fvenda = fopen("vendas.dat", "rb");
    if (!fvenda) {
        printf("Nenhuma venda registrada.\n");
        return;
    }

    Venda v;
    Produto p;
    FILE *fprod;

    printf("==== RELATÓRIO DE VENDAS ====\n");
    while (fread(&v, sizeof(Venda), 1, fvenda)) {
        printf("Venda ID: %d\n", v.id);
        printf("Produtos vendidos:\n");
        for (int i = 0; i < v.num_produtos; i++) {
            fprod = fopen("produtos.dat", "rb");
            int achou = 0;
            while (fread(&p, sizeof(Produto), 1, fprod)) {
                if (p.id == v.produtos[i]) {
                    printf("  - %s (R$%.2f)\n", p.descricao, p.preco);
                    achou = 1;
                    break;
                }
            }
            if (!achou) {
                printf("  - Produto ID %d (não encontrado)\n", v.produtos[i]);
            }
            fclose(fprod);
        }
        printf("---------------------------\n");
    }

    fclose(fvenda);
}

// Atualização de produto
void atualizarProduto(int id_alvo) {
    FILE *f = fopen("produtos.dat", "r+b");
    Produto p;
    while (fread(&p, sizeof(Produto), 1, f)) {
        if (p.id == id_alvo) {
            printf("Atualizando produto: %s\n", p.descricao);
            limparBuffer();
            printf("Nova descrição: ");
            fgets(p.descricao, MAX_STR, stdin);
            p.descricao[strcspn(p.descricao, "\n")] = '\0';
            printf("Novo preço: ");
            scanf("%f", &p.preco);
            printf("Nova quantidade em estoque: ");
            scanf("%d", &p.estoque);

            fseek(f, -sizeof(Produto), SEEK_CUR);
            fwrite(&p, sizeof(Produto), 1, f);
            fclose(f);
            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }
    fclose(f);
    printf("Produto não encontrado.\n");
}

// Remoção de venda
void removerVenda(int id_remover) {
    FILE *fin = fopen("vendas.dat", "rb");
    FILE *fout = fopen("vendas_temp.dat", "wb");
    Venda v;
    int achou = 0;

    while (fread(&v, sizeof(Venda), 1, fin)) {
        if (v.id != id_remover) {
            fwrite(&v, sizeof(Venda), 1, fout);
        } else {
            achou = 1;
        }
    }

    fclose(fin);
    fclose(fout);

    if (achou) {
        remove("vendas.dat");
        rename("vendas_temp.dat", "vendas.dat");
        printf("Venda removida com sucesso.\n");
    } else {
        remove("vendas_temp.dat");
        printf("Venda não encontrada.\n");
    }
}

// Menu principal
int main() {
    int opcao, id;

    do {
        printf("\n==== MENU DE ESTOQUE E VENDAS ====\n");
        printf("1. Cadastrar item\n");
        printf("2. Cadastrar venda\n");
        printf("3. Listar items cadastrados\n");
        printf("4. Listar items vendidos\n");
        printf("5. Atualizar item\n");
        printf("6. Remover venda\n");
        printf("0. Finalizar programa\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: cadastrarVenda(); break;
            case 3: listarProdutos(); break;
            case 4: listarVendasComProdutos(); break;
            case 5:
                printf("ID do produto que deseja atualizar: ");
                scanf("%d", &id);
                atualizarProduto(id);
                break;
            case 6:
                printf("ID da venda que deseja remover: ");
                scanf("%d", &id);
                removerVenda(id);
                break;
            case 0: printf("Finalizando...\n");
             break;
            default: printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
