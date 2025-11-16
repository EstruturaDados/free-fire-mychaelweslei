#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Struct Item:
    Representa qualquer objeto coletado pelo jogador no inventário.
    Campos:
    - nome: nome do item
    - tipo: categoria (arma, munição, cura...)
    - quantidade: quantidade do item coletado
*/
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Capacidade máxima da mochila
#define MAX_ITENS 10

// Vetor que armazena os itens da mochila
Item mochila[MAX_ITENS];
int totalItens = 0;

/*  
    Função inserirItem:
    Adiciona um novo item na mochila,
    desde que haja espaço disponível.
*/
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("Digite o nome do item: ");
    scanf("%s", novo.nome);

    printf("Digite o tipo do item: ");
    scanf("%s", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("Item adicionado com sucesso!\n\n");
}

/*
    Remover item:
    Remove um item da mochila com base no nome.
    Se encontrado, ele é substituído pelo último item da lista.
*/
void removerItem() {
    if (totalItens == 0) {
        printf("A mochila está vazia! Nada para remover.\n");
        return;
    }

    char nomeBusca[30];
    printf("Digite o nome do item que deseja remover: ");
    scanf("%s", nomeBusca);

    int encontrado = -1;

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item não encontrado.\n");
        return;
    }

    // Substitui o item removido pelo último da lista
    mochila[encontrado] = mochila[totalItens - 1];
    totalItens--;

    printf("Item removido com sucesso!\n\n");
}

/*
    Listar itens:
    Mostra todos os itens presentes na mochila.
*/
void listarItens() {
    if (totalItens == 0) {
        printf("A mochila está vazia!\n");
        return;
    }

    printf("\n===== Itens na mochila =====\n");

    for (int i = 0; i < totalItens; i++) {
        printf("Item %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
        printf("---------------------------\n");
    }
}

/*
    Buscar item:
    Busca sequencial pelo nome do item e exibe seus dados.
*/
void buscarItem() {
    char nomeBusca[30];
    printf("Digite o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("---------------------------\n");
            return;
        }
    }

    printf("Item não encontrado.\n");
}

int main() {
    int opcao;

    do {
        printf("\n===== Sistema de Inventário =====\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
