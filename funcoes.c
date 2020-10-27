#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "interfaces/funcoes.h"

int tela_inicial(){
    int opcao;
    
    limpa_tela();    
    titulo();    /*Escreve Batalha Naval*/

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

void instrucoes(){
    char opcao;

    limpa_tela();
    limpa_buffer();
    titulo();
    printf("\n\n\n\t\t\t\t   ------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t  |\t\t\t\t    INSTRUÇÕES SOBRE O JOGO\t\t\t\t     |\n");
    printf("\t\t\t\t  |------------------------------------------------------------------------------------------|\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     Batalha Naval consiste em um jogo estratégico de tabuleiro formado por 2 jogadores,  |\n");
    printf("\t\t\t\t  | cujo principal objetivo é acabar com todas a embarcações do adversário. O primeiro\t     |\n");
    printf("\t\t\t\t  | jogador, sorteado aleatoriamente, realiza o primeiro tiro, ou seja, diz qual casa do     |\n");
    printf("\t\t\t\t  | tabuleiro deseja atacar. Caso acerte um barco, ele joga novamente. Caso contrário, a vez |\n");
    printf("\t\t\t\t  | é passada para o outro jogador.\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     O jogo termina quando um jogador perde todas as embarcações ou quando você acerta    |\n");
    printf("\t\t\t\t  | todas as bombas do adversário, e nesse último caso, você é o perdedor.\t\t     |\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t   ------------------------------------------------------------------------------------------\n\n");  
     
    printf("\n\n\t\t\t\t\t\t\t> Digite o s para voltar: ");
    scanf("%c", &opcao);    
    while(opcao != 's'){        
        limpa_buffer();
        printf("\t\t\t\t\t\t\t> Caracter incorreto. Por favor, tente novamente.\n");        
        printf("\t\t\t\t\t\t\t> Digite o s para voltar: ");
        scanf("%c", &opcao);
    }   
    
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