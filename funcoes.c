/*#include <stdio_ext.h>*/
#ifndef __WIN32__
    #include <stdio_ext.h>
#endif
#include <stdio.h>
#include <stdlib.h>
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
    limpa_buffer();
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
    char opcao;

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
     
    printf("\n\n\t\t\t\t\t\t\t\t> Digite qualquer coisa para voltar: ");
    
    scanf("%c",&opcao);
  
}

void iniciar_jogo(){
    char a[10];
    
    printf("\n\n\t\tInsira seu nome: ");
    fgets(jogador.nome,40,stdin);

    inicializa_tabuleiro(jogador.tabuleiro);
    limpa_tela();
    limpa_buffer();
    imprime_tabuleiro(jogador.tabuleiro);

    preenche_tabuleiro(); 
    
    /*preenche tabuleiro cpu*/
    /*jogando*/

    /*Só para não sair direto*/
    printf("\n\n\t\tDigite qualquer coisa pra sair: ");
    limpa_buffer();
    fgets(a, 10, stdin);
}
void preenche_tabuleiro(){
    int linha, i, j, qtd_barco, tamanho, coluna;
    char orientacao, barco[20], c;

    for(i = 1; i <= 5; i++){
        switch (i){
            case(1):
                qtd_barco = 1;
                strcpy(barco, "Porta-Avião");
                tamanho = TAM_PORTA_AVIAO;
                break; 
            
            case(2):
                qtd_barco = 2;
                strcpy(barco,"Cruzado");
                tamanho = TAM_CRUZADO;
                break;
            
            case(3):
                qtd_barco = 3;
                strcpy(barco,"Contratorpedo");
                tamanho = TAM_CONTRATORPEDO;
                break;
            
            case(4):
                qtd_barco = 4;
                strcpy(barco,"Submarino");
                tamanho = TAM_SUBMARINO;
                break;
            
            case(5):
                qtd_barco = 3;
                strcpy(barco,"Bomba");
                tamanho = TAM_BOMBA;
                break;
            
        }
        
        for(j = 1; j <= qtd_barco; j++){

            printf("\n\n\t\tDigite as coordenadas do %d° %s: \n",j, barco );
            
            printf("\t\tLinha: ");
            scanf("%d", &linha);
            limpa_buffer();
            printf("\t\tColuna: ");
            scanf("%c", &c);

            coluna = toupper(c) - 64;

            if(i < 4){
                limpa_buffer(); 
                printf("\t\tOrientação [h/v]: ");
                orientacao = tolower(getchar());
            }

            /*verifica*/
            while(!verifica_coordenadas(linha, coluna, tamanho, jogador.tabuleiro, orientacao)){
                limpa_tela();
                limpa_buffer();
                imprime_tabuleiro(jogador.tabuleiro);
                printf("\n\n\t\t> COORDENADA INVÁLIDA!\n");

                printf("\n\n\t\tDigite as coordenadas do %d° %s: \n", j, barco);
            
                printf("\t\tLinha: ");
                scanf("%d", &linha);
                limpa_buffer();
                printf("\t\tColuna: ");
                scanf("%c", &c);
                coluna = toupper(c) - 64;

                if(i < 4){
                    limpa_buffer();
                    printf("\t\tOrientação [h/v]: ");
                    orientacao = tolower(getchar());
                }
            }

            if(i != 5){

                insere_barco(linha, coluna, tamanho, jogador.tabuleiro, orientacao);
                cria_borda_barco(linha, coluna, tamanho, jogador.tabuleiro, orientacao); /*não pode barcos adjacentes*/
            }
            else{

                insere_bomba(linha, coluna, jogador.tabuleiro);
                cria_borda_barco(linha, coluna, tamanho, jogador.tabuleiro, 'h'); /*orientação nao importa pq o tamanho é 1*/
            }

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
                    printf("%c   ", 'A'+j-1); /*Letras (colunas)*/ 
                else 
                    printf("%2d| ", i);     /*Números (linhas)*/
            }else{
                if(tabuleiro[i][j] == '.')
                    printf(ANSI_COLOR_BLUE "%c   " ANSI_COLOR_RESET, tabuleiro[i][j]);
                else if(tabuleiro[i][j] == '*')
                    printf(ANSI_COLOR_GREY "%c   " ANSI_COLOR_RESET, tabuleiro[i][j]);
                else
                    printf("%c   ", tabuleiro[i][j]);
            }   

            if(j == MAX -1){
                printf("\t\t");
                switch (i){
                case 1: 
                    printf("LEGENDA:");
                    break;
                case 3:
                    printf("1 PORTA-AVIÕES (4 CASAS): 1");
                    break;
                case 5:
                    printf("2 CRUZADOS (3 CASAS): 1");
                    break;
                case 7:
                    printf("3 CONTRATORPEDOS (2 CASAS): 1");
                    break;
                case 9:
                    printf("4 SUBMARINOS (1 CASA): 1");
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
                printf("%c   ", tabuleiro2[i][j]);            
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
            tabuleiro[linha][coluna+i] = '1';
        else
            tabuleiro[linha+i][coluna] = '1';
    }
        
}
void insere_bomba(int linha, int coluna,char tabuleiro[MAX][MAX]){
    
    tabuleiro[linha][coluna] = '@';
    
}
int verifica_coordenadas(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao){
    int i;
    int ori; /* Auxilar para orientação */
    int resp = 1;

    if(orientacao != 'h' && orientacao != 'v')
        resp = 0;
    else{
        ori = (orientacao == 'h')? coluna : linha;
        
        if(linha < 1 || coluna < 1 || linha > MAX - 1 || coluna > MAX - 1)
            resp = 0;
        else if(ori + tam_barco - 1 > MAX - 1)
            resp = 0;
        else{
            if(orientacao == 'h'){
                for(i = 0; i < tam_barco; i++){
                    if(tabuleiro[linha][coluna + i] == '1' || tabuleiro[linha][coluna + i] == '*'){
                        resp = 0;
                        break;
                    }
                }
            }else{
                for(i = 0; i < tam_barco; i++){
                    if(tabuleiro[linha + i][coluna] == '1' || tabuleiro[linha + i][coluna] == '*'){
                        resp = 0;
                        break;
                    }
                }
            }
        }
    }        
    return resp;
}
void cria_borda_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao){
    int i;
    
    if(orientacao =='h'){    
        if(coluna - 1 > 0){
            tabuleiro[linha][coluna - 1] = '*';
            if(linha + 1 < MAX)
                tabuleiro[linha + 1][coluna - 1] = '*';
            if(linha - 1 > 0)
                tabuleiro[linha - 1][coluna - 1] = '*';
        }
        if(coluna + tam_barco < MAX){
            tabuleiro[linha][coluna + tam_barco] = '*';
            if(linha + 1 < MAX)
                tabuleiro[linha + 1][coluna + tam_barco] = '*';
            if(linha - 1 > 0)
                tabuleiro[linha - 1][coluna + tam_barco] = '*';
        }
        for(i = 0; i < tam_barco; i++){
            if((linha - 1 > 0) && (coluna + i < MAX))
                tabuleiro[linha-1][coluna + i] = '*';
            if((linha + 1 < MAX) && (coluna + i < MAX))
                tabuleiro[linha+1][coluna+i] = '*';
        }
    }else{
        if(linha - 1 > 0){
            tabuleiro[linha - 1][coluna] = '*';
            if(coluna - 1 > 0)
                tabuleiro[linha - 1][coluna - 1] = '*';
            if(coluna + 1 < MAX)
                tabuleiro[linha - 1][coluna + 1] = '*';
        }
        if(linha + tam_barco < MAX){
            tabuleiro[linha+tam_barco][coluna] = '*';
            if(coluna - 1 > 0)
                tabuleiro[linha + tam_barco][coluna - 1] = '*';
            if(coluna + 1 < MAX)
                tabuleiro[linha + tam_barco][coluna + 1] = '*';
        }
        for(i = 0; i < tam_barco; i++){
            if((coluna - 1 > 0) && (linha + i < MAX))
                tabuleiro[linha + i][coluna - 1] = '*';
            if((coluna + 1 < MAX) && (linha + i < MAX))
                tabuleiro[linha + i][coluna + 1] = '*';
        }
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
void muda_config_windows(){
    #ifdef __WIN32__
        system("chcp 65001");
    #endif
}