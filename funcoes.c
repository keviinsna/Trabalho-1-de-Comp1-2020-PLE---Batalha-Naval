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
    limpa_buffer();
    while(!(1 <= opcao && opcao <= 4)){        
        printf("\t\t\t\t\t\t\t> Opção inexistente. Por favor, tente novamente.\n");
        printf("\t\t\t\t\t\t\t> Digite o número da opção: ");
        scanf("%d", &opcao);
        limpa_buffer();
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
    titulo();
    printf("\n\n\n\t\t\t\t   --------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t  |\t\t\t\t         INSTRUÇÕES SOBRE O JOGO\t\t\t\t     |\n");
    printf("\t\t\t\t  |--------------------------------------------------------------------------------------------------|\n");
    printf("\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t\t     |\n");
    printf("\t\t\t\t  |     Batalha Naval consiste em um jogo estratégico de tabuleiro 10x10 formado por 2 jogadores,    |\n");
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
     
    printf("\n\n\t\t\t\t\t\t\t\t> DIGITE QUALQUER COISA PARA VOLTAR: ");    
    scanf("%c",&opcao);
    limpa_buffer();  
}

void posicionar_embarcacao(){
    char c, gera_tab_auto;
    int i = 0;
        
    printf("\n\n\t\t\t\t\tInsira seu nome: ");
    limpa_buffer();

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
        printf("\n\t\t> Deseja gerar tabuleiro automaticamente? [s,n]: ");
        scanf("%c", &gera_tab_auto);
        limpa_buffer();

        if(tolower(gera_tab_auto) != 's' && tolower(gera_tab_auto) != 'n'){            
            limpa_tela();        
            imprime_tabuleiro(jogador.tabuleiro);
            printf("\n\t\t> Opção inexistente. Por favor, tente novamente.\n");
        }else
            break;       

    }while(1);
    
    if(tolower(gera_tab_auto) == 's'){
        preenche_tabuleiro_auto(jogador.tabuleiro);
        limpa_tela();
        imprime_tabuleiro(jogador.tabuleiro);
    }else{
        limpa_tela();
        imprime_tabuleiro(jogador.tabuleiro);
        preenche_tabuleiro();
    }

    printf("\n\t\tTABULEIRO PRONTO!");

    preenche_tabuleiro_auto(cpu.tabuleiro);

    /*jogando*/
    
    /*Só para não sair direto*/
    printf("\n\n\t\t> Digite qualquer coisa pra avançar: ");    
    scanf("%c", &c);
    limpa_buffer();
}

void preenche_tabuleiro(){
    int linha, i, j, qtd_barco, tamanho, coluna;
    char orientacao, barco[20], c;

    for(i = 1; i <= 5; i++){
        switch (i){
            case 1:
                qtd_barco = 1;
                strcpy(barco, "Porta-Avião");
                tamanho = TAM_PORTA_AVIAO;
                break; 
            
            case 2:
                qtd_barco = 2;
                strcpy(barco,"Cruzado");
                tamanho = TAM_CRUZADO;
                break;
            
            case 3:
                qtd_barco = 3;
                strcpy(barco,"Contratorpedo");
                tamanho = TAM_CONTRATORPEDO;
                break;
            
            case 4:
                qtd_barco = 4;
                strcpy(barco,"Submarino");
                tamanho = TAM_SUBMARINO;
                break;
            
            case 5:
                qtd_barco = 3;
                strcpy(barco,"Bomba");
                tamanho = TAM_BOMBA;
                break;
            
        }
        
        for(j = 1; j <= qtd_barco; j++){

            printf("\n\t\t> Digite as coordenadas do %d° %s: \n\n",j, barco);
            
            printf("\t\t> Linha: ");
            scanf("%d", &linha);
            limpa_buffer();
            
            printf("\t\t> Coluna: ");
            scanf("%c", &c);

            coluna = toupper(c) - 64;

            if(i < 4){
                limpa_buffer(); 
                printf("\t\t> Orientação [h/v]: ");
                orientacao = tolower(getchar());
            }

            /*verifica*/
            while(!verifica_coordenadas(linha, coluna, tamanho, jogador.tabuleiro, orientacao)){
                limpa_tela();
                limpa_buffer();
                imprime_tabuleiro(jogador.tabuleiro);
                printf("\n\n\t\t> COORDENADA INVÁLIDA!\n");

                printf("\n\t\t> Digite as coordenadas do %d° %s: \n", j, barco);
            
                printf("\t\t> Linha: ");
                scanf("%d", &linha);
                limpa_buffer();
                printf("\t\t> Coluna: ");
                scanf("%c", &c);
                coluna = toupper(c) - 64;

                if(i < 4){
                    limpa_buffer();
                    printf("\t\t> Orientação [h/v]: ");
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
    printf("\n\n\n\t\t   POSICIONE SUAS PEÇAS:\n\t\t ------------------------------------------\n");
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
                    printf(ANSI_COLOR_BLUE "%c   " ANSI_COLOR_RESET, tabuleiro[i][j]);
                else if(tabuleiro[i][j] == '*')
                    printf(ANSI_COLOR_GREY "%c   " ANSI_COLOR_RESET, tabuleiro[i][j]);
                else
                    printf(ANSI_COLOR_GREEN"%c   "ANSI_COLOR_RESET, tabuleiro[i][j]);
            }   

            if(j == MAX -1){
                printf("\t\t");
                switch (i){
                case 0: 
                    printf("LEGENDA:");
                    break;
                case 2:
                    printf("1 PORTA-AVIÕES (4 CASAS): 1");
                    break;
                case 4:
                    printf("2 CRUZADOS (3 CASAS): 1");
                    break;
                case 6:
                    printf("3 CONTRATORPEDOS (2 CASAS): 1");
                    break;
                case 8:
                    printf("4 SUBMARINOS (1 CASA): 1");
                    break;
                case 10: 
                    printf("3 BOMBAS (1 CASA): @");
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
                	printf("@   ");
                else if (tabuleiro[i][j] == '#')
                	printf("1   " );
                else if(tabuleiro[i][j] == 'X')
                    printf(ANSI_COLOR_RED "X   " ANSI_COLOR_RESET);
                else if ((tabuleiro[i][j] == '1') || (tabuleiro[i][j] == '@') || (tabuleiro[i][j] == '*') || (tabuleiro[i][j] == '.')){
                	printf(ANSI_COLOR_BLUE ".   " ANSI_COLOR_RESET);
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
                	printf("@   ");
                else if (tabuleiro2[i][j] == '#')                	
                	printf("1   " );
                else if(tabuleiro2[i][j] == 'X')
                    printf(ANSI_COLOR_RED "X   " ANSI_COLOR_RESET);
                else if ((tabuleiro2[i][j] == '1') || (tabuleiro2[i][j] == '@') ||(tabuleiro2[i][j] == '*') || tabuleiro2[i][j] == '.'){
                	printf(ANSI_COLOR_BLUE ".   " ANSI_COLOR_RESET);
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

void preenche_tabuleiro_auto(char tabuleiro[MAX][MAX]){    
    int i, j, qtd_barco, tamanho, coluna, linha, ori;
    static int k;
    char orientacao;
    
    for(i = 1; i <= 5; i++){
        switch (i){
            case 1:
                qtd_barco = 1;
                tamanho = TAM_PORTA_AVIAO;
                break; 
            
            case 2:
                qtd_barco = 2;
                tamanho = TAM_CRUZADO;
                break;
            
            case 3:
                qtd_barco = 3;
                tamanho = TAM_CONTRATORPEDO;
                break;
            
            case 4:
                qtd_barco = 4;
                tamanho = TAM_SUBMARINO;
                break;
            
            case 5:
                qtd_barco = 3;
                tamanho = TAM_BOMBA;
                break;            
        }
        srand(k+time(NULL));
        k++;
        for(j = 1; j <= qtd_barco; j++){
            
            /* Gerar linha e coluna */
            linha =  1 + rand()%10; /*[1,10]*/ 
            coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
            
            /* Gerar orientação */ 
            if(i < 4){
                ori = rand()%2; /*[0,1]*/ 
                orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
            }

            /* Verifica */            
            while(!verifica_coordenadas(linha, coluna, tamanho, tabuleiro, orientacao)){
                /* Gerar linha e coluna */
                linha =  1 + rand()%10; /*[1,10]*/ 
                coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
            
                /* Gerar orientação */ 
                if(i < 4){
                    ori = rand()%2; /*[0,1]*/ 
                    orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
                }
            } 

            if(i != 5){
                insere_barco(linha, coluna, tamanho, tabuleiro, orientacao);
                cria_borda_barco(linha, coluna, tamanho, tabuleiro, orientacao); /*não pode barcos adjacentes*/
            }
            else{
                insere_bomba(linha, coluna, tabuleiro);
                cria_borda_barco(linha, coluna, tamanho, tabuleiro, 'h'); /*orientação nao importa pq o tamanho é 1*/
            }            
        }
    }
}

void iniciar_jogo(){
	int linha, coluna;
    int resp_verificacao, resp_tiro;    
	char c, feedback[60]; 
    int fim_jogo = 0;

    jogador.qtd_barcos = cpu.qtd_barcos = 20;
    jogador.qtd_bombas = cpu.qtd_bombas = 3;
    
    limpa_tela();
    imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
	while(1){		
        
		do{ /* Jogador */
			printf("\n\n\t\t> SUA VEZ! \n\t\t> DIGITE AS COORDENADAS DA POSIÇÃO QUE DESEJA ATACAR: \n\n");
		            
		    printf("\t\t> Linha: ");
		    scanf("%d", &linha);
		    limpa_buffer();
		    
            printf("\t\t> Coluna: ");
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
            }else{                
                if(resp_verificacao == 1)
                    strcpy(feedback,"\t\tCOORDENADA JÁ ATINGIDA. TENTE OUTRA.");
                else{
                    resp_tiro = atira(linha, coluna, cpu.tabuleiro);
                    
                    if(resp_tiro == 0){
                        cpu.qtd_barcos--;

                        if(cpu.qtd_barcos == 0){
                            limpa_tela();
                            imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                            printf(ANSI_COLOR_GREEN"\t\tEMBARCAÇÃO ATINGIDA COM SUCESSO!"ANSI_COLOR_RESET);
                            printf("\n\n\t\tPARABÉNS, %s, VOCÊ VENCEU!\n",jogador.nome);
                            fim_jogo = 1;
                            break;
                        }

                        strcpy(feedback, "\t\tEMBARCAÇÃO ATINGIDA COM SUCESSO! JOGUE NOVMENTE.");

                    }else if(resp_tiro == 1){
                        cpu.qtd_bombas--; 
                        strcpy(feedback, "\t\tBOMBA ATINGIDA!");

                        if(cpu.qtd_bombas == 0){
                            limpa_tela();
                            imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                            printf("\n\n\t\tVOCÊ ATINGIU TODAS AS BOMBAS DO ADVERSÁRIO!");
                            printf("\n\n\t\tVOCÊ PERDEU, %s.",jogador.nome);
                            fim_jogo = 1;
                            break;
                        }

                    }else
                        strcpy(feedback, "\t\tÁGUA ATINGIDA!");               
                }
            }
            limpa_tela();
            imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
            if(resp_tiro == 0){
                printf(ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, feedback);
            }else{
                printf("%s", feedback);
                break;
            }
           
            /*if(cpu.qtd_bombas == 0){
                printf("\n\n\t\tVOCÊ ATINGIU TODAS AS BOMBAS DO ADVERSÁRIO!");
                printf("\n\n\t\tVOCÊ PERDEU, %s.",jogador.nome);
                fim_jogo = 1;
                break;
            }else if(cpu.qtd_barcos == 0){
                printf("\n\n\t\tPARABÉNS, %s, VOCÊ VENCEU!\n",jogador.nome);
                fim_jogo = 1;
                break;
            }*/
        }while(1);

        if(fim_jogo)
            break;
     
        srand(time(NULL));
        do{  /* CPU */         
            
            /*limpa_tela();*/
            printf("\n\n\t\t\t\t> VEZ DO OPONENTE!\n");
            
            linha = 1 + rand()%10;
            coluna = 1 + rand()%10;

            resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);

            Sleep(1000);
            if(resp_verificacao == 2){
                resp_tiro = atira(linha, coluna, jogador.tabuleiro);
                
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                
                if(resp_tiro == 0){
                    jogador.qtd_barcos--;
                    printf(ANSI_COLOR_GREEN "\t\t\t\t\t\t\t\t\t\t\tEMBARCAÇÃO ATINGIDA!" ANSI_COLOR_RESET);
                }else if(resp_tiro == 1){
                    jogador.qtd_bombas--;
                    printf( "\t\t\t\t\t\t\t\t\t\t\tBOMBA ATINGIDA!");
                    break;
                }else{
                    printf("\t\t\t\t\t\t\t\t\t\t\tÁGUA ATINGIDA!");
                    break;
                }
            }
            if(jogador.qtd_bombas == 0){
                printf("\n\n\t\tPARABÉNS, %s, VOCÊ VENCEU!\n",jogador.nome);
                Sleep(1000);
                fim_jogo = 1;
                break;
            }else if(jogador.qtd_barcos == 0){
                printf("\n\n\t\tVOCÊ PERDEU, %s.",jogador.nome);
                Sleep(1000);
                fim_jogo = 1;
                break;
            }        
		}while(1);
        
        if(fim_jogo)
            break;        
	}
    printf("\n\t\t> DIGITE QUALQUER COISA PARA VOLTAR: ");    
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
  /*
    
    imprime_ambos_tabuleiros(jogador.tabuleiro,cpu.tabuleiro);
    */