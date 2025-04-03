#include <stdio.h>
#include <stdlib.h>
#include "agenda.h" 

int main() {
    int opcao;

    printf("Bem-vindo à sua Agenda Pessoal\n");

    while (1) { 
        printf("\n-------------\n");
        printf("    MENU     \n");
        printf("-------------\n");
        printf("1) Adicionar contato\n");
        printf("2) Remover contato\n");
        printf("3) Listar contatos\n");
        printf("4) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                removerContato();
                break;
            case 3:
                listarContatos();
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
