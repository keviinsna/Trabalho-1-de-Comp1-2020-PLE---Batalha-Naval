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

/*Quantidade de barcos*/
#define QTD_PORTA_AVIAO 1
#define QTD_CRUZADO 2
#define QTD_CONTRATORPEDO 3
#define QTD_SUBMARINO 4
#define QTD_BOMBA 3

/*Cores*/
#define COLOR_RED      "\x1b[31m"
#define COLOR_BLUE     "\x1b[94m"
#define COLOR_SKY_BLUE "\x1b[96m"
#define COLOR_GREEN    "\x1b[32m"
#define COLOR_GREY     "\x1b[37m"
#define COLOR_YELLOW   "\x1b[93m"
#define COLOR_RESET    "\x1b[0m"

/*High intensty text*/
#define HBLK "\x1b[0;90m"
#define HRED "\x1b[0;91m"
#define HGRN "\x1b[0;92m"
#define HYEL "\x1b[0;93m"
#define HBLU "\x1b[0;94m"
#define HMAG "\x1b[0;95m"
#define HCYN "\x1b[0;96m"
#define HWHT "\x1b[0;97m"
 

typedef struct {
    char nome[40];
    char tabuleiro[MAX][MAX];
    int  qtd_barcos, qtd_bombas;
}JOGADOR;

#endif