#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

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
        limpa_buffer();
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
    while(tolower(opcao[0]) != 'v'){
        limpa_buffer();
        printf("\t\t\t\t\t\t\t\t> Caracter incorreto. Por favor, tente novamente.\n");        
        printf("\t\t\t\t\t\t\t\t> Digite [v] para voltar: ");
        fgets(opcao, 2, stdin);
    }   
    
}

void iniciar_jogo(){
    char a[10];
    

    inicializa_tabuleiro(jogador.tabuleiro);
    limpa_tela();
    limpa_buffer();
    imprime_tabuleiro(jogador.tabuleiro);

    preenche_tabuleiro(); 
    


    /*Só para não sair direto*/
    printf("\n\n\t\tDigite qualquer coisa pra sair: ");
    limpa_buffer();
    fgets(a, 10, stdin);
}
void preenche_tabuleiro(){
    int linha, coluna,i,j,k,tamanho;
    char orientacao, barco[20];

    for(i=1;i<=5;i++){
        switch (i){
            case(1):
                j=1;
                strcpy(barco,"Porta-Avião");
                tamanho=TAM_PORTA_AVIAO;
                break; 
            
            case(2):
                j=2;
                strcpy(barco,"Cruzado");
                tamanho=TAM_CRUZADO;
                break;
            
            case(3):
                j=3;
                strcpy(barco,"Contratorpedo");
                tamanho=TAM_CONTRATORPEDO;
                break;
            
            case(4):
                j=4;
                strcpy(barco,"Submarino");
                tamanho=TAM_SUBMARINO;
                break;
            
            case(5):
                j=3;
                strcpy(barco,"Bomba");
                tamanho=TAM_BOMBA;
                break;
            
        }
        for(k=1;k<=j;k++){

            printf("\n\n\t\tDigite as coordenadas do %d %s: \n",k,barco );
            
            printf("\t\tLinha: ");
            scanf("%d", &linha);
            
            printf("\t\tColuna: ");
            scanf("%d", &coluna);

            if(i<4){
                limpa_buffer();
                printf("\t\tOrientação [h/v]: ");
                orientacao = getchar();

            }

            /*verifica*/
            if(i!=5)
                insere_barco(linha,coluna,tamanho,jogador.tabuleiro,orientacao);
            else 
                insere_bomba(linha,coluna,jogador.tabuleiro);

            limpa_tela();
            limpa_buffer();
            imprime_tabuleiro(jogador.tabuleiro);
        }
    }
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
    printf("\n\n\n\t\t   POSICIONE SUAS PEÇAS:\n\t\t ---------------------------------------------------------\n");
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
                    printf("1 PORTA-AVIÕES (4 CASAS): $");
                    break;
                case 5:
                    printf("2 CRUZADOS (3 CASAS): $");
                    break;
                case 7:
                    printf("3 CONTRATORPEDOS (2 CASAS): $");
                    break;
                case 9:
                    printf("4 SUBMARINOS (1 CASA): $");
                    break;
                case 11: 
                    printf("3 BOMBAS (1 CASA): @");
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

void insere_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao){
    int i; 
    for(i = 0; i < tam_barco; i++){
        if(orientacao == 'h')
            tabuleiro[linha][coluna+i] = '$';
        else
            tabuleiro[linha+i][coluna] = '$';
    }
        
}
void insere_bomba(int linha, int coluna,char tabuleiro[MAX][MAX]){
    
    tabuleiro[linha][coluna] = '@';
    
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