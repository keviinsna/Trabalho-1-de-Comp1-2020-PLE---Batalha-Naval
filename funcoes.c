#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#ifdef __WIN32__
    #include <windows.h>    
#else
    #include <stdio_ext.h>
    #include <unistd.h>
#endif

#include "interfaces/defs.h"
#include "interfaces/funcoes.h"

JOGADOR jogador, cpu;

int tela_inicial(){
    int opcao;
    
    limpa_tela();    
    titulo();
    menu_inicial();   
    
    do{
        printf("\n\n\t\t\t\t\t\t\t     > DIGITE O NÚMERO DA OPÇÃO: ");    
        limpa_buffer();
        scanf("%d", &opcao);        
        if(!(0 <= opcao && opcao <= 2)){
            limpa_tela();
            titulo();
            menu_inicial();  
            printf("\t\t\t\t\t\t\t> OPÇÃO INEXISTENTE. POR FAVOR, TENTE NOVAMENTE.\n");        
        }
    }while(!(0 <= opcao && opcao <= 2));

    limpa_tela();
    titulo();
    menu_inicial();
    
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

void menu_inicial(){
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tFEITO POR: ELLEN, IGOR e KEVIN\n\n\n");

    printf("\t\t\t\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t\t\t\t   |               MENU INICIAL             |\n");
    printf("\t\t\t\t\t\t\t   |----------------------------------------|\n");
    printf("\t\t\t\t\t\t\t   |                                        |\n");
    printf("\t\t\t\t\t\t\t   |     > [1] INICIAR                      |\n");
    printf("\t\t\t\t\t\t\t   |     > [2] INSTRUÇÕES                   |\n");
    printf("\t\t\t\t\t\t\t   |     > [0] SAIR                         |\n");
    printf("\t\t\t\t\t\t\t   |                                        |\n");
    printf("\t\t\t\t\t\t\t    ---------------------------------------\n\n");    
}

void instrucoes(){
    char opcao;

    limpa_tela();
    limpa_buffer();
    titulo();
    printf("\n\n\n");
    printf("\t\t\t\t   --------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t  |                                      INSTRUÇÕES SOBRE O JOGO                                     |\n");
    printf("\t\t\t\t  |--------------------------------------------------------------------------------------------------|\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Batalha Naval consiste em um jogo estratégico de tabuleiro 10x10 formado por 2 jogadores,    |\n");
    printf("\t\t\t\t  | cujo principal objetivo é acabar com todas a embarcações do adversário.                          |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Antes de iniciar a partida, os jogadores devem posicionar, vertical ou horizontalmente, suas |\n");
    printf("\t\t\t\t  | embarcações da maneira que achar melhor, respeitando a regra não de haver embarcações adjacentes,|\n");
    printf("\t\t\t\t  | exceto para as bombas. Há também a possibilidade de gerar o tabuleiro aleatoriamente.            |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Depois disso, o primeiro jogador realiza o primeiro tiro, ou seja, diz qual casa do tabuleiro|\n");
    printf("\t\t\t\t  | adversário deseja atacar, inserindo as coordenadas da posição.                                   |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Caso acerte uma embarcação, ele joga novamente. Caso contrário, a vez é passada para o outro |\n");
    printf("\t\t\t\t  | jogador.                                                                                         |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     O jogo termina quando um jogador perde todas as embarcações ou quando você acerte todas as   |\n");
    printf("\t\t\t\t  | bombas do adversário, e nesse último caso, você é o perdedor.                                    |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t   --------------------------------------------------------------------------------------------------\n\n");  
     
    printf("\n\n\t\t\t\t\t\t\t\t> DIGITE QUALQUER COISA PARA VOLTAR: ");    
    scanf("%c",&opcao);
    limpa_buffer();  
}

void posicionar_embarcacao(){
    char c, gera_tab_auto;
    int i = 0;

    limpa_buffer();
    printf("\n\n\t\t\t\t\t\t\t     > INSIRA SEU NOME: ");
    while(c != '\n'){
        scanf("%c", &c);
        c = toupper(c);
        jogador.nome[i++] = c;     
    }
    jogador.nome[i-1] = '\0';
    
    inicializa_tabuleiro(jogador.tabuleiro);
    inicializa_tabuleiro(cpu.tabuleiro);

    limpa_tela();        
    imprime_tabuleiro(jogador.tabuleiro);

    do{
        printf("\n\t\t> DESEJA GERAR TABULEIRO AUTOMATICAMENTE? [s,n]: ");
        scanf("%c", &gera_tab_auto);
        limpa_buffer();

        if(tolower(gera_tab_auto) != 's' && tolower(gera_tab_auto) != 'n'){            
            limpa_tela();        
            imprime_tabuleiro(jogador.tabuleiro);
            printf("\t\t> OPÇÃO INEXISTENTE. POR FAVOR, TENTE NOVAMENTE.\n");
        }else
            break;       

    }while(1);
    
    if(tolower(gera_tab_auto) == 's'){
        preenche_tabuleiro_auto(jogador.tabuleiro, jogador.barco); /*adicionei jogador.barco para tentar fazer a embarcação afundada*/
        limpa_tela();
        imprime_tabuleiro(jogador.tabuleiro);
    }else{
        limpa_tela();
        imprime_tabuleiro(jogador.tabuleiro);
        preenche_tabuleiro();
    }

    printf("\n\t\tTABULEIRO PRONTO!");

    preenche_tabuleiro_auto(cpu.tabuleiro, cpu.barco); /*adicionei cpu.barco para tentar fazer a embarcação afundada*/
   
    printf("\n\n\t\t> DIGITE QUALQUER COISA PARA AVANÇAR: ");    
    scanf("%c", &c);
    limpa_buffer();
}

void preenche_tabuleiro(){
    int linha, i, j, /*k=0*/ qtd_barco, tamanho, coluna;
    char orientacao, barco[20], c;

    for(i = 1; i <= 5; i++){
        switch (i){
            case 1:
                qtd_barco = 1;
                strcpy(barco, "PORTA-AVIÃO");
                tamanho = TAM_PORTA_AVIAO;
                break; 
            
            case 2:
                qtd_barco = 2;
                strcpy(barco,"CRUZADO");
                tamanho = TAM_CRUZADO;
                break;
            
            case 3:
                qtd_barco = 3;
                strcpy(barco,"CONTRATORPEDO");
                tamanho = TAM_CONTRATORPEDO;
                break;
            
            case 4:
                qtd_barco = 4;
                strcpy(barco,"SUBMARINO");
                tamanho = TAM_SUBMARINO;
                break;
            
            case 5:
                qtd_barco = 3;
                strcpy(barco,"BOMBA");
                tamanho = TAM_BOMBA;
                break;            
        }
        
        for(j = 1; j <= qtd_barco; j++){

            printf("\n\t\t> DIGITE AS COORDENADAS DO(A) %d° %s: \n\n", j, barco);
            
            printf("\t\t> LINHA: ");
            scanf("%d", &linha);
            limpa_buffer();
            
            printf("\t\t> COLUNA: ");
            scanf("%c", &c);

            coluna = toupper(c) - 64;

            if(i < 4){
                limpa_buffer(); 
                printf("\t\t> ORIENTAÇÃO [h/v]: ");
                orientacao = tolower(getchar());
            }

            if(i < 5){
                while(!verifica_coordenadas(linha, coluna, tamanho, jogador.tabuleiro, orientacao)){
                    limpa_tela();
                    limpa_buffer();
                    imprime_tabuleiro(jogador.tabuleiro);
                    printf("\n\n\t\t> COORDENADA INVÁLIDA!\n");

                    printf("\n\t\t> DIGITE AS COORDENADAS DO(A) %d° %s: \n\n", j, barco);
                
                    printf("\t\t> LINHA: ");
                    scanf("%d", &linha);
                    limpa_buffer();
                    printf("\t\t> COLUNA: ");
                    scanf("%c", &c);
                    coluna = toupper(c) - 64;

                    if(i < 4){
                        limpa_buffer();
                        printf("\t\t> ORIENTAÇÃO [h/v]: ");
                        orientacao = tolower(getchar());
                    }
                }
            }else{
                while(!verifica_coordenadas_bomba(linha, coluna,jogador.tabuleiro)){
                    limpa_tela();
                    limpa_buffer();
                    imprime_tabuleiro(jogador.tabuleiro);
                    printf("\n\n\t\t> COORDENADA INVÁLIDA!\n");

                    printf("\n\t\t> DIGITE AS COORDENADAS DO(A) %d° %s: \n\n", j, barco);
                
                    printf("\t\t> LINHA: ");
                    scanf("%d", &linha);
                    limpa_buffer();
                    printf("\t\t> COLUNA: ");
                    scanf("%c", &c);
                    coluna = toupper(c) - 64;
                }
            }

            if(i != 5){
                /*jogador.barco[k].linha = linha;
                jogador.barco[k].coluna = coluna;
                jogador.barco[k].tamanho = tamanho;
                jogador.barco[k].qtdd_atingida = 0;
                jogador.barco[k].orientacao = orientacao;
                k++;*/
                insere_barco(linha, coluna, tamanho, jogador.tabuleiro, orientacao);
                cria_borda_barco(linha, coluna, tamanho, jogador.tabuleiro, orientacao); /*não pode barcos adjacentes*/               
            }
            else{
                insere_bomba(linha, coluna, jogador.tabuleiro);
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
    printf("\n\n\n\t\t   POSICIONE SUAS EMBARACAÇÕES:\n\t\t ------------------------------------------\n");
    for(i = 0; i < MAX; i++){
        printf("\t\t");

        /* Tabuleiro 1 */        
        for(j = 0; j < MAX; j++){            
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i){
                    printf("%c   ", 'A'+j-1); /*Letras (colunas)*/ 
                    if(j == MAX - 1)
                        printf("\n\t\t ------------------------------------------");                    
                }else 
                    printf("%2d| ", i);     /*Números (linhas)*/
            }else{
                if(tabuleiro[i][j] == '.')
                    printf(HBLU "%c   " COLOR_RESET, tabuleiro[i][j]);
                else if(tabuleiro[i][j] == '*')
                    printf(COLOR_GREY "%c   " COLOR_RESET, tabuleiro[i][j]);
                else if(tabuleiro[i][j] == '1')
                    printf(COLOR_GREEN"%c   "COLOR_RESET, tabuleiro[i][j]);
                else
                    printf(COLOR_YELLOW "%c   "COLOR_RESET, tabuleiro[i][j]);
            }   
 
            if(j == MAX -1){
                printf("\t\t");
                switch (i){
                case 0: 
                    printf("SÍMBOLOS:\t\t\t\t   EMBARCAÇÕES: ");
                    break;
                case 2:
                    printf(COLOR_GREEN"1"COLOR_RESET" - BARCOS");
                    printf("\t\t\t   1 PORTA-AVIÕES (4 CASAS): 1");
                    break;
                case 4:
                    printf(COLOR_YELLOW"@"COLOR_RESET" - BOMBAS");
                    printf("\t\t\t   2 CRUZADOS (3 CASAS, CADA): 1");
                    break;
                case 6:
                    printf(COLOR_BLUE"."COLOR_RESET" - ÁGUA");
                    printf("\t\t\t   3 CONTRATORPEDOS (2 CASAS, CADA): 1");
                    break;
                case 8:
                    printf("* - POSIÇÃO INVÁLIDA");
                    printf("\t\t   4 SUBMARINOS (1 CASA, CADA): 1");
                    break;
                case 10: 
                    printf("\t\t\t\t   3 BOMBAS (1 CASA, CADA): @");
                    break;
                default:
                    break;
                }
            }                
        }
        printf("\n");        
    }
    printf("\t\t ------------------------------------------\n");
}

void imprime_ambos_tabuleiros(char tabuleiro[MAX][MAX], char tabuleiro2[MAX][MAX]){
    int i, j;
    printf("\n\n\n\t\t  TABULEIRO DO OPONENTE\t\t\t\t\t TABULEIRO DE %s\n", jogador.nome);
    printf("\t\t ------------------------------------------\t\t");
    printf(" ------------------------------------------\n");
    
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
                    printf("%2d| ", i);
            }else{
            	if(tabuleiro[i][j] == '!')
                	printf(COLOR_YELLOW"@   "COLOR_RESET);
                else if (tabuleiro[i][j] == '#')
                	printf(COLOR_GREEN"1   "COLOR_RESET);
                else if(tabuleiro[i][j] == 'X')
                    printf(COLOR_RED "X   " COLOR_RESET);
                else if ((tabuleiro[i][j] == '1') || (tabuleiro[i][j] == '@') || (tabuleiro[i][j] == '*') || (tabuleiro[i][j] == '.')){
                	printf(COLOR_BLUE ".   " COLOR_RESET);
                }                
            }    
        }
        
        printf("\t\t");

        /* Tabuleiro 2 */
        for(j = 0; j < MAX; j++){
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i)
                    printf("%c   ", 'A'+j-1); /*Letras (colunas)*/ 
                else 
                    printf("%2d| ", i);
            }else{
            	if(tabuleiro2[i][j] == '!')
                	printf(COLOR_YELLOW"@   "COLOR_RESET);
                else if (tabuleiro2[i][j] == '#')                	
                	printf(COLOR_GREEN"1   "COLOR_RESET);
                else if(tabuleiro2[i][j] == 'X')
                    printf(COLOR_RED "X   " COLOR_RESET);
                else if ((tabuleiro2[i][j] == '1') || (tabuleiro2[i][j] == '@') ||(tabuleiro2[i][j] == '*') || tabuleiro2[i][j] == '.'){
                	printf(COLOR_BLUE ".   " COLOR_RESET);
                }
            }
        }
        if(!i){
            printf("\n\t\t ------------------------------------------\t\t");
            printf(" ------------------------------------------");
        }            
        printf("\n");
    }
    printf("\t\t ------------------------------------------\t\t");
    printf(" ------------------------------------------\n");
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

int verifica_coordenadas_bomba(int linha, int coluna, char tabuleiro[MAX][MAX]){
    int resp = 1;
        
        if(linha < 1 || coluna < 1 || linha > MAX - 1 || coluna > MAX - 1)
            resp = 0;
        else{
            if(tabuleiro[linha][coluna] == '1'){
                resp = 0;
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

void preenche_tabuleiro_auto(char tabuleiro[MAX][MAX], BARCO barco[10]){    /*adicionei BARCO.barco para tentar fazer a embarcação afundada*/
    int i, j, /*b=0*/ qtd_barco, tamanho, coluna, linha, ori;
    static int k;
    char orientacao;
    
    for(i = 1; i <= 5; i++){
        switch (i){
            case 1:
                qtd_barco = QTD_PORTA_AVIAO;
                tamanho   = TAM_PORTA_AVIAO;
                break; 
            
            case 2:
                qtd_barco = QTD_CRUZADO;
                tamanho   = TAM_CRUZADO;
                break;
            
            case 3:
                qtd_barco = QTD_CONTRATORPEDO;
                tamanho   = TAM_CONTRATORPEDO;
                break;
            
            case 4:
                qtd_barco = QTD_SUBMARINO;
                tamanho   = TAM_SUBMARINO;
                break;
            
            case 5:
                qtd_barco = QTD_BOMBA;
                tamanho   = TAM_BOMBA;
                break;            
        }
        srand(k + time(NULL));
        k++;
        for(j = 1; j <= qtd_barco; j++){
            
            linha =  1 + rand()%10; /*[1,10]*/ 
            coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
                        
            if(i < 4){
                ori = rand()%2; /*[0,1]*/ 
                orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
            }

            /* Verifica */    
            if(i < 5){        
                while(!verifica_coordenadas(linha, coluna, tamanho, tabuleiro, orientacao)){

                    linha =  1 + rand()%10; /*[1,10]*/ 
                    coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
                
                    if(i < 4){
                        ori = rand()%2; /*[0,1]*/ 
                        orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
                    }
                }
            }else{
                while(!verifica_coordenadas_bomba(linha, coluna, tabuleiro)){
    
                    linha =  1 + rand()%10; /*[1,10]*/ 
                    coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
                
                    if(i < 4){
                        ori = rand()%2; /*[0,1]*/ 
                        orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
                    }
                }
            } 

            if(i != 5){
                /*barco[b].linha = linha;
                barco[b].coluna = coluna;
                barco[b].tamanho = tamanho;
                barco[b].qtdd_atingida = 0;
                barco[b].orientacao = orientacao;
                b++;*/
                insere_barco(linha, coluna, tamanho, tabuleiro, orientacao);
                cria_borda_barco(linha, coluna, tamanho, tabuleiro, orientacao); /*não pode barcos adjacentes*/         
            }
            else{
                insere_bomba(linha, coluna, tabuleiro);
            }            
        }
    }
}

void iniciar_jogo(){
	int linha, coluna;
    /*int orientacao, num_barco, tamanho_barco_CPU, tamanho_barco;*/
    int resp_verificacao, resp_tiro; 
    int tiro_anterior=0, linha_tiro_anterior, coluna_tiro_anterior, primeira_linha, primeira_coluna; 
    int norte_sul, leste_oeste, k, verificou=0, horizontal;
	char c, feedback[60]; 
    int fim = 0;

    jogador.qtd_barcos = cpu.qtd_barcos = 20;
    jogador.qtd_bombas = cpu.qtd_bombas = 3;
    
    limpa_tela();
    imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
	while(1){		
        
		do{ /* Jogador */
			printf("\n\n\t\t> SUA VEZ! \n\t\t> DIGITE AS COORDENADAS DA POSIÇÃO QUE DESEJA ATACAR: \n\n");
		    limpa_buffer();        
		    printf("\t\t> LINHA: ");
		    if(!scanf("%d", &linha))
                linha = 20;
		    limpa_buffer();
		    
            printf("\t\t> COLUNA: ");
		    scanf("%c", &c);            
		    coluna = toupper(c) - 64;
            limpa_buffer();

            resp_verificacao = verifica_tiro(linha, coluna, cpu.tabuleiro);
            if(resp_verificacao == 0){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\tCOORDENADA INVÁLIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else if(resp_verificacao == 1){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\tCOORDENADA JÁ ATINGIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else{
                resp_tiro = atira(linha, coluna, cpu.tabuleiro);
                
                if(resp_tiro == 0){
                    cpu.qtd_barcos--;
                    strcpy(feedback, "\t\tEMBARCAÇÃO ATINGIDA COM SUCESSO.");
                }else if(resp_tiro == 1){
                    cpu.qtd_bombas--; 
                    strcpy(feedback, "\t\t\t\tBOMBA ATINGIDA!");
                }else
                    strcpy(feedback, "\t\t\t\tÁGUA ATINGIDA!");
            }

            limpa_tela();
            imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
            if(resp_tiro == 0){
                printf(COLOR_GREEN"%s"COLOR_RESET, feedback);                 
                if(fim_jogo())
                    break;             
                /*printf("\t\tlinha = %d       coluna = %d", linha, coluna);
                for(b=0;b<10;b++){
                    for(t=0;t < (cpu.barco[b].tamanho);t++){
                        if( (linha == (cpu.barco[b].linha)) && (cpu.barco[b].orientacao != 'h') && (cpu.barco[b].orientacao != 'v') ){
                            (cpu.barco[b].qtdd_atingida)++;
                            num_barco = b;
                            b=10;
                            break;
                        }else{
                            orientacao = (cpu.barco[b].orientacao == 'h')? coluna : linha;
                            if( (orientacao == linha) && (linha == ((cpu.barco[b].linha) + t) ) ){
                                (cpu.barco[b].qtdd_atingida)++;
                                num_barco = b;
                                b=10;
                                break;
                            }else if((orientacao == coluna) && (coluna == ((cpu.barco[b].coluna) + t) )){
                                (cpu.barco[b].qtdd_atingida)++;
                                num_barco = b;
                                b=10;
                                break;
                            }
                        }
                    }
                }
                printf("\n\t\tlinha = %d       coluna = %d", linha, coluna);
                printf("\n\t\torientacao = %c      linha barco[%d] = %d       coluna barco[%d] = %d",cpu.barco[num_barco].orientacao, num_barco, cpu.barco[num_barco].linha, num_barco, cpu.barco[num_barco].coluna);
                printf("\n\t\tqtdd atingida = %d      tamanho barco[%d] = %d",cpu.barco[num_barco].qtdd_atingida, num_barco, cpu.barco[num_barco].tamanho);

                if( (cpu.barco[num_barco].tamanho) == (cpu.barco[num_barco].qtdd_atingida) ){
                    printf(HBLU "\t\tEMBARCAÇÃO AFUNDADA!" ANSI_COLOR_RESET);
                    cpu.barco[b].qtdd_atingida=0;
                }else{
                    printf(ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, feedback);    
                }*/
            }else{
                printf("%s", feedback);                
                break;
            }
           
        }while(1);

        fim = fim_jogo();
        if(fim){
            mensagem_fim_jogo(fim);
            break;
        }            

        srand(time(NULL));
        do{  /* CPU */
            if(tiro_anterior >= 1){       
                verificou = 0;
                if(tiro_anterior == 1){
                    k = rand()%4;
                    do{
                        if(k == 0){
                            linha = linha_tiro_anterior + 1;
                            coluna = coluna_tiro_anterior;
                            k++;
                            verificou++;
                            horizontal = 0;
 
                        }else if(k == 1){
                            linha = linha_tiro_anterior - 1;
                            coluna = coluna_tiro_anterior;
                            k++;
                            verificou++;
                            horizontal = 0;

                        }else if(k == 2){
                            linha = linha_tiro_anterior;
                            coluna = coluna_tiro_anterior + 1;
                            k++;
                            verificou++;
                            horizontal = 1;
 
                        }else if(k==3){
                            linha = linha_tiro_anterior;
                            coluna = coluna_tiro_anterior - 1;
                            k=0;
                            verificou++;
                            horizontal = 1;
                        }
                    
                    resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                    }while((resp_verificacao != 2) && (verificou < 4));

                    if((resp_verificacao != 2) && (verificou == 4)){
                        tiro_anterior = 0;
                    }else{
                        printf("\n\n\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");
                    }
                }else{
                    if(horizontal == 0){
                        norte_sul = rand()%2;
                        do{
                            if(norte_sul == 1){
                                linha = linha_tiro_anterior + 1;
                                coluna = coluna_tiro_anterior;
                                verificou++;
                                norte_sul = 0;
                                horizontal = 0;
    
                            }else if(norte_sul == 0){
                                linha = linha_tiro_anterior - 1;
                                coluna = coluna_tiro_anterior;
                                verificou++;
                                norte_sul = 1;
                                horizontal = 0;
                            }                        
                            resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                        }while((resp_verificacao != 2) && (verificou < 2));

                        if((resp_verificacao != 2) && (verificou == 2)){
                            if( (linha_tiro_anterior - primeira_linha) > 0) {
                                norte_sul = -1; 
                            }else{
                                norte_sul = 1;
                            }  
                            
                            resp_verificacao = verifica_tiro( (primeira_linha + norte_sul), coluna, jogador.tabuleiro);
                            if(resp_verificacao!=2)
                                tiro_anterior = 0;
                            else{
                                linha = primeira_linha + norte_sul;
                                coluna = primeira_coluna;
                            }
                            
                        }else
                            printf("\n\n\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");
                    }else{
                        leste_oeste = rand()%2;
                        do{
                            if((leste_oeste == 1)){
                                linha = linha_tiro_anterior;
                                coluna = coluna_tiro_anterior + 1;
                                verificou++;
                                leste_oeste = 0;
                                horizontal = 1;    
                            }else if( (leste_oeste == 0) ){
                                linha = linha_tiro_anterior;
                                coluna = coluna_tiro_anterior - 1;
                                verificou++;
                                leste_oeste = 1;
                                horizontal = 1;
                            }
                            resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                        }while((resp_verificacao != 2) && (verificou < 2));

                        if((resp_verificacao != 2) && (verificou == 2)){
                            if((coluna_tiro_anterior - primeira_coluna) > 0) {
                                leste_oeste = -1; 
                            }else{
                                leste_oeste = 1;
                            }  
                            
                            resp_verificacao = verifica_tiro( linha, (primeira_coluna + leste_oeste), jogador.tabuleiro);
                            if(resp_verificacao != 2){
                                tiro_anterior = 0;
                            }else{
                                linha = primeira_linha;
                                coluna = primeira_coluna + leste_oeste;
                            }
                        }else
                            printf("\n\n\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");                        
                    }
                }
            }
            if(tiro_anterior == 0){
                printf("\n\n\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");

                do{
                    linha = 1 + rand()%10;
                    coluna = 1 + rand()%10;

                    resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                }while(resp_verificacao != 2);
            }
            delay(2);
            if(resp_verificacao == 2){
                resp_tiro = atira(linha, coluna, jogador.tabuleiro);
                
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                
                if(resp_tiro == 0){
                    jogador.qtd_barcos--;
                    printf(COLOR_GREEN "\t\t\t\t\t\t\t\t\t\t\tEMBARCAÇÃO ATINGIDA!" COLOR_RESET);
                    tiro_anterior++;
                    if(tiro_anterior == 1){
                        primeira_linha = linha;
                        primeira_coluna = coluna;
                    }
                    linha_tiro_anterior = linha;
                    coluna_tiro_anterior = coluna;
                    verificou = 0;                    
                    
                    /*tiro_anterior++;
                    if(tiro_anterior==1){
                        primeira_linha = linha;
                        primeira_coluna = coluna;
                        for(b=0;b<10;b++){
                            for(t=0;t < (jogador.barco[b].tamanho);t++){
                                if(primeira_linha == ((jogador.barco[b].linha) + t) ){
                                    tamanho_barco = jogador.barco[b].tamanho;
                                    b=10;
                                    break;
                                }
                            }
                        }
                    }
                    if(tamanho_barco==tiro_anterior){
                        printf(HBLU "\t\t\t\t\t\t\t\t\t\t\tEMBARCAÇÃO AFUNDADA!" ANSI_COLOR_RESET);
                        tiro_anterior=0;
                    }else{
                        printf(ANSI_COLOR_GREEN "\t\t\t\t\t\t\t\t\t\t\tEMBARCAÇÃO ATINGIDA!" ANSI_COLOR_RESET);
                    }
                    linha_tiro_anterior = linha;
                    coluna_tiro_anterior = coluna;
                    verificou=0;*/

                    if(fim_jogo())
                        break;
                }else if(resp_tiro == 1){
                    jogador.qtd_bombas--;
                    printf( "\t\t\t\t\t\t\t\t\t\t\tBOMBA ATINGIDA!");
                    if((verificou >= 4) || ((tiro_anterior > 1) && (verificou >= 2)))
                        tiro_anterior = 0;
                    break;
                }else{
                    printf("\t\t\t\t\t\t\t\t\t\t\tÁGUA ATINGIDA!");
                    if(verificou >= 4)
                        tiro_anterior = 0;
                    break;
                }                
            }                
		}while(1);
        
        /*Mensagem de fim de jogo*/
        fim = fim_jogo();
        if(fim){
            mensagem_fim_jogo(fim);
            break;
        }            
	}

    printf("\n\t\t> DIGITE QUALQUER COISA PARA VOLTAR AO MENU INICIAL: ");    
    scanf("%c", &c);
}

int verifica_tiro(int linha, int coluna, char tab_atacado[MAX][MAX]){
    int resp = 2;
   
    /*
        0 = coordenada inválida
        1 = coordenada já atingida
        2 = coordenda válida
    */

    if(linha < 1 || coluna < 1 || linha > MAX - 1 || coluna > MAX - 1)  
        resp = 0;
    else if(tab_atacado[linha][coluna] == '#' || tab_atacado[linha][coluna] == '!' || tab_atacado[linha][coluna] == 'X')
        resp = 1;
            
    return resp;
}
int atira(int linha, int coluna, char tab_atacado[MAX][MAX]){
    int resp;

    /*
        0 = Barco atingido
        1 = Bomba atingida
        2 = Água  atingida
    */

    if(tab_atacado[linha][coluna] == '1'){
        tab_atacado[linha][coluna] = '#';
        resp = 0;
    }else if(tab_atacado[linha][coluna] == '@'){
        tab_atacado[linha][coluna] = '!';
        resp = 1;
    }else if(tab_atacado[linha][coluna] == '.' || tab_atacado[linha][coluna] == '*'){
        tab_atacado[linha][coluna] = 'X';
        resp = 2;
    }

    return resp;
}

int fim_jogo(){
    int resp = 0;
    /*
        0 = jogo não terminou
        1 = jogador venceu
        2 = jogador perdeu
    */

    if(jogador.qtd_barcos == 0 || cpu.qtd_bombas == 0)
       resp = 2;
    else if(cpu.qtd_barcos == 0 || jogador.qtd_bombas == 0)
       resp = 1;

    return resp;
}

void mensagem_fim_jogo(int venceu){
    if(venceu == 1){
        printf("\n\n\n\t\t\t\tPARABÉNS! VOCÊ VENCEU, %s.\n\n", jogador.nome);
        printf("\t\t\t\t╔═══╗╔═══╗╔═══╗╔═══╗╔══╗ ╔═══╗╔═╗ ╔╗╔═══╗  ╔╗  ╔╗╔═══╗╔═══╗╔═══╗     ╔╗  ╔╗╔═══╗╔═╗ ╔╗╔═══╗╔═══╗╔╗ ╔╗\n");
        printf("\t\t\t\t║╔═╗║║╔═╗║║╔═╗║║╔═╗║║╔╗║ ║╔══╝║║╚╗║║║╔═╗║  ║╚╗╔╝║║╔═╗║║╔═╗║║╔══╝     ║╚╗╔╝║║╔══╝║║╚╗║║║╔═╗║║╔══╝║║ ║║\n");
        printf("\t\t\t\t║╚═╝║║║ ║║║╚═╝║║║ ║║║╚╝╚╗║╚══╗║╔╗╚╝║║╚══╗  ╚╗║║╔╝║║ ║║║║ ╚╝║╚══╗     ╚╗║║╔╝║╚══╗║╔╗╚╝║║║ ╚╝║╚══╗║║ ║║\n");
        printf("\t\t\t\t║╔══╝║╚═╝║║╔╗╔╝║╚═╝║║╔═╗║║╔══╝║║╚╗║║╚══╗║   ║╚╝║ ║║ ║║║║ ╔╗║╔══╝      ║╚╝║ ║╔══╝║║╚╗║║║║ ╔╗║╔══╝║║ ║║\n");
        printf("\t\t\t\t║║   ║╔═╗║║║║╚╗║╔═╗║║╚═╝║║╚══╗║║ ║║║║╚═╝║   ╚╗╔╝ ║╚═╝║║╚═╝║║╚══╗      ╚╗╔╝ ║╚══╗║║ ║║║║╚═╝║║╚══╗║╚═╝║\n");
        printf("\t\t\t\t╚╝   ╚╝ ╚╝╚╝╚═╝╚╝ ╚╝╚═══╝╚═══╝╚╝ ╚═╝╚═══╝    ╚╝  ╚═══╝╚═══╝╚═══╝       ╚╝  ╚═══╝╚╝ ╚═╝╚═══╝╚═══╝╚═══╝\n");
    }else{
        printf("\n\n\n\t\t\t\tVOCÊ PERDEU, %s!\n\n", jogador.nome);
        printf("\t\t\t\t╔╗  ╔╗╔═══╗╔═══╗╔═══╗     ╔═══╗╔═══╗╔═══╗╔═══╗╔═══╗╔╗ ╔╗  ╔═══╗╔══╗╔═╗╔═╗     ╔═══╗╔═══╗       ╔╗╔═══╗╔═══╗╔═══╗\n");
        printf("\t\t\t\t║╚╗╔╝║║╔═╗║║╔═╗║║╔══╝     ║╔═╗║║╔══╝║╔═╗║╚╗╔╗║║╔══╝║║ ║║  ║╔══╝╚╣─╝║║╚╝║║     ╚╗╔╗║║╔══╝       ║║║╔═╗║║╔═╗║║╔═╗║\n");
        printf("\t\t\t\t╚╗║║╔╝║║ ║║║║ ╚╝║╚══╗     ║╚═╝║║╚══╗║╚═╝║ ║║║║║╚══╗║║ ║║  ║╚══╗ ║║ ║╔╗╔╗║      ║║║║║╚══╗       ║║║║ ║║║║ ╚╝║║ ║║\n");
        printf("\t\t\t\t ║╚╝║ ║║ ║║║║ ╔╗║╔══╝     ║╔══╝║╔══╝║╔╗╔╝ ║║║║║╔══╝║║ ║║  ║╔══╝ ║║ ║║║║║║      ║║║║║╔══╝     ╔╗║║║║ ║║║║╔═╗║║ ║║\n");
        printf("\t\t\t\t ╚╗╔╝ ║╚═╝║║╚═╝║║╚══╗     ║║   ║╚══╗║║║╚╗╔╝╚╝║║╚══╗║╚═╝║  ║║   ╔╣─╗║║║║║║     ╔╝╚╝║║╚══╗     ║╚╝║║╚═╝║║╚╩═║║╚═╝║\n");
        printf("\t\t\t\t  ╚╝  ╚═══╝╚═══╝╚═══╝     ╚╝   ╚═══╝╚╝╚═╝╚═══╝╚═══╝╚═══╝  ╚╝   ╚══╝╚╝╚╝╚╝     ╚═══╝╚═══╝     ╚══╝╚═══╝╚═══╝╚═══╝\n");
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

void delay(int i){
    #ifdef __WIN32__
        Sleep(i*1000);
    #else 
        sleep(i);
    #endif
}