#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>

#include "interfaces/funcoes.h"

int tela_inicial(){
    int opcao;
    
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tFeito por: Ellen, Igor e Kevin\n\n\n");

    printf("\t\t\t\t\t\t\t ----------------------------------------\n");
    printf("\t\t\t\t\t\t\t|\t\tMENU INICIAL\t\t |\n");
    printf("\t\t\t\t\t\t\t|----------------------------------------|\n");
    printf("\t\t\t\t\t\t\t|\t\t\t\t\t |\n");
    printf("\t\t\t\t\t\t\t|\t> [1] INICIAR\t\t\t |\n");
    printf("\t\t\t\t\t\t\t|\t> [2] INSTRUÇÕES\t\t |\n");
    printf("\t\t\t\t\t\t\t|\t> [3] RANKING\t\t\t |\n");
    printf("\t\t\t\t\t\t\t|\t> [4] SAIR\t\t\t |\n");
    printf("\t\t\t\t\t\t\t|\t\t\t\t\t |\n");
    printf("\t\t\t\t\t\t\t ---------------------------------------\n\n");    

    printf("\n\n\t\t\t\t\t\t\t> Digite o número da opção: ");
    scanf("%d", &opcao);
    while(!((opcao == 1) || (opcao == 2) || (opcao == 3) || (opcao == 4))){
        printf("\t\t\t\t\t\t\t> Opção inexistente. Por favor, tente novamente.\n");
        printf("\t\t\t\t\t\t\t> Digite o número da opção: ");
        scanf("%d", &opcao);
    }
    return opcao;
}
void titulo(){
    printf("\n\n\n");
    printf("\t\t\t\t\t╔══╗ ╔═══╗╔════╗╔═══╗╔╗   ╔╗ ╔╗╔═══╗     ╔═╗ ╔╗╔═══╗╔╗  ╔╗╔═══╗╔╗   \t       ▓▓╬▓\n");
    printf("\t\t\t\t\t║╔╗║ ║╔═╗║║╔╗╔╗║║╔═╗║║║   ║║ ║║║╔═╗║     ║║╚╗║║║╔═╗║║╚╗╔╝║║╔═╗║║║   \t      ▓▓▓║▓▓\n");
    printf("\t\t\t\t\t║╚╝╚╗║║ ║║╚╝║║╚╝║║ ║║║║   ║╚═╝║║║ ║║     ║╔╗╚╝║║║ ║║╚╗║║╔╝║║ ║║║║   \t     ▓▓▓▓╬▓▓▓▓\n");
    printf("\t\t\t\t\t║╔═╗║║╚═╝║  ║║  ║╚═╝║║║ ╔╗║╔═╗║║╚═╝║     ║║╚╗║║║╚═╝║ ║╚╝║ ║╚═╝║║║ ╔╗\t  ▄ ▓▓▓▓▓║▓▓▓▓▓     \n");
    printf("\t\t\t\t\t║╚═╝║║╔═╗║  ║║  ║╔═╗║║╚═╝║║║ ║║║╔═╗║     ║║ ║║║║╔═╗║ ╚╗╔╝ ║╔═╗║║╚═╝║\t ▀████████████████▀  \n");
    printf("\t\t\t\t\t╚═══╝╚╝ ╚╝  ╚╝  ╚╝ ╚╝╚═══╝╚╝ ╚╝╚╝ ╚╝     ╚╝ ╚═╝╚╝ ╚╝  ╚╝  ╚╝ ╚╝╚═══╝\n");
}

void limpa_tela(){
    #ifdef __WIN32__
        system("cls");
    #else
        system("clear");
    #endif
}

void limpa_buffer(){
    #ifdef __WIN32__
        fflush(stdin);
    #else
        __fpurge(stdin);
    #endif
}