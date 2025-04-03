#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

#define MAX_NOME 50
#define MAX_TELEFONE 20
#define MAX_LINHA 100
#define ARQUIVO "agenda.txt"

void adicionarContato() {
    FILE *file = fopen(ARQUIVO, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char nome[MAX_NOME], telefone[MAX_TELEFONE];

    printf("Nome: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0'; 

    printf("Telefone: ");
    fgets(telefone, MAX_TELEFONE, stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    fprintf(file, "%s - %s\n", nome, telefone);
    fclose(file);

    printf("Contato salvo!\n");
}

void listarContatos() {
    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        printf("Nenhum contato salvo ainda.\n");
        return;
    }

    char linha[MAX_LINHA];
    printf("\nLista de Contatos:\n");
    printf("------------------\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }
    fclose(file);
}

void removerContato() {
    char nomeRemover[MAX_NOME];
    printf("Digite o nome do contato que deseja remover: ");
    fgets(nomeRemover, MAX_NOME, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        printf("Nenhum contato salvo ainda.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(file);
        return;
    }

    char linha[MAX_LINHA];
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (strstr(linha, nomeRemover) == NULL) {
            fputs(linha, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (encontrado) {
        remove(ARQUIVO);
        rename("temp.txt", ARQUIVO);
        printf("Contato removido com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("Contato não encontrado.\n");
    }
}
