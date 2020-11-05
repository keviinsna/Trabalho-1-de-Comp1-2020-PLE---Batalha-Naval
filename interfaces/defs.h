#ifndef DEFS_H
#define DEFS_H

/*Tamnhos*/
#define MAX 11
#define TAM_PORTA_AVIAO 4
#define TAM_CRUZADO 3
#define TAM_CONTRATORPEDO 2
#define TAM_SUBMARINO 1
#define TAM_BOMBA 1
#define TOTAL_BARCO 10

/*Cores*/
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_SKY_BLUE "\x1b[96m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_GREY     "\x1b[37m"
#define ANSI_COLOR_RESET    "\x1b[0m"
/*High intensty text*/
#define HBLK "\x1b[0;90m"
#define HRED "\x1b[0;91m"
#define HGRN "\x1b[0;92m"
#define HYEL "\x1b[0;93m"
#define HBLU "\x1b[0;94m"
#define HMAG "\x1b[0;95m"
#define HCYN "\x1b[0;96m"
#define HWHT "\x1b[0;97m"

typedef struct{
    int tamanho;
    int linha, coluna;
    int qtdd_atingida;
    char orientacao;
}BARCO; /*  */

typedef struct {
    char nome[40];
    char tabuleiro[MAX][MAX];
    int  qtd_barcos, qtd_bombas;
    BARCO barco[10];
}JOGADOR;



#endif