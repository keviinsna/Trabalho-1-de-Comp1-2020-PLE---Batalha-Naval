#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "interfaces/defs.h"
#include "interfaces/funcoes.h"

JOGADOR jogador;

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
    while(!(1 <= opcao && opcao <= 4)){
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
    char opcao[2];

    limpa_tela();
    limpa_buffer();
    titulo();
    printf("\n\n\n\t\t\t\t   --------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t  |\t\t\t\t         INSTRUÇÕES SOBRE O JOGO\t\t\t\t     |\n");
    printf("\t\t\t\t  |--------------------------------------------------------------------------------------------------|\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     Batalha Naval consiste em um jogo estratégico de tabuleiro 14x14 formado por 2 jogadores,    |\n");
    printf("\t\t\t\t  | cujo principal objetivo é acabar com todas a embarcações do adversário.\t\t\t     |\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     Antes de iniciar a partida, os jogadores devem posicionar, vertical ou horizontalmente, suas |\n");
    printf("\t\t\t\t  | peças da maneira que achar melhor, respeitando a regra não de haver embarcações adjacentes.\t     |\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     Depois disso, o primeiro jogador, sorteado aleatoriamente, realiza o primeiro tiro, ou seja, |\n");
    printf("\t\t\t\t  | diz qual casa do tabuleiro adversário deseja atacar, inserindo as coordenadas da posição.        |\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     Caso acerte uma embarcação, ele joga novamente. Caso contrário, a vez é passada para o outro |\n");
    printf("\t\t\t\t  | jogador.\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     O jogo termina quando um jogador perde todas as embarcações ou quando você acerte todas as   |\n");
    printf("\t\t\t\t  | bombas do adversário, e nesse último caso, você é o perdedor.\t\t\t\t     |\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t   --------------------------------------------------------------------------------------------------\n\n");  
     
    printf("\n\n\t\t\t\t\t\t\t\t> Digite [v] para voltar: ");
    fgets(opcao, 2, stdin);
    while(opcao[0] != 'v'){
        limpa_buffer();
        printf("\t\t\t\t\t\t\t\t> Caracter incorreto. Por favor, tente novamente.\n");        
        printf("\t\t\t\t\t\t\t\t> Digite [v] para voltar: ");
        fgets(opcao, 2, stdin);
    }   
    
}

void iniciar_jogo(){
    char a[10];
    limpa_tela();
    limpa_buffer();

/*
    titulo();
    printf("\n\n\t\t\t\t\t\tANTES DE COMEÇARMOS, DIGITE SEU NOME: ");
    fgets(jogador.nome, 40, stdin);
    limpa_tela();
*/
    printf("\n\n\n");
    inicializa_tabuleiro(jogador.tabuleiro);
    imprime_tabuleiro(jogador.tabuleiro);
    
    printf("\n\n\t\t> Digite qualquer coisa para sair: ");
    fgets(a, 10, stdin);
}

void inicializa_tabuleiro(char tabuleiro[MAX][MAX]){
    int i, j;
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++)
            tabuleiro[i][j] = '.';
    }    
}
void imprime_tabuleiro(char tabuleiro[MAX][MAX]){
    int i, j;
    printf("\t\t   POSICIONE SUAS PEÇAS:\n\t\t ---------------------------------------------------------\n");
    for(i = 0; i < MAX; i++){
        printf("\t\t");
        /* Tabuleiro 1 */        
        for(j = 0; j < MAX; j++){
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i)
                    printf("%c   ", 'A'+j-1);
                else 
                    printf("%2d| ", i);
            }else
                printf("%c   ", tabuleiro[i][j]);

            if(j == MAX -1){
                printf("\t\t");
                switch (i){
                case 1: 
                    printf("LEGENDA:");
                    break;
                case 3:
                    printf("1 PORTA-AVIÕES (4 CASAS): #");
                    break;
                case 5:
                    printf("2 CRUZADOS (3 CASAS): @");
                    break;
                case 7:
                    printf("3 CONTRATORPEDOS (2 CASAS): $");
                    break;
                case 9:
                    printf("4 SUBMARINOS (1 CASA): &");
                    break;
                case 11: 
                    printf("3 BOMBAS (1 CASA): ó");
                    break;
                default:
                    break;
                }
            }
                
        }
        printf("\n");        
    }
    printf("\t\t ---------------------------------------------------------\n");
}
void imprime_ambos_tabuleiros(char tabuleiro[MAX][MAX], char tabuleiro2[MAX][MAX]){
    int i, j;
    printf("\t\t ---------------------------------------------------------\t\t");
    printf(" ---------------------------------------------------------\n");
    for(i = 0; i < MAX; i++){
        printf("\t\t");
        /* Tabuleiro 1 */
        
        for(j = 0; j < MAX; j++){
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i)
                    printf("%c   ", 'A'+j-1);
                else 
                    printf("%2d| ", i);
            }else
                printf("%c   ", tabuleiro[i][j]);
            
        }
        
        printf("\t\t");
        /* Tabuleiro 2 */
        for(j = 0; j < MAX; j++){
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i)
                    printf("%c   ", 'A'+j-1);
                else 
                    printf("%2d| ", i);
            }else
                printf("%c   ", tabuleiro[i][j]);            
        }
            
        printf("\n");
    }
    printf("\t\t ---------------------------------------------------------\t\t");
    printf(" ---------------------------------------------------------\n");
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