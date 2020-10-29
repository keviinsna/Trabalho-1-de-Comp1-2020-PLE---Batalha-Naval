#ifndef DEFS_H
#define DEFS_H

/*Tamnhos*/
#define MAX 15
#define TAM_PORTA_AVIAO 4
#define TAM_CRUZADO 3
#define TAM_CONTRATORPEDO 2
#define TAM_SUBMARINO 1
#define TAM_BOMBA 1

/*Cores*/
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_SKY_BLUE "\x1b[96m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_GREY     "\x1b[37m"
#define ANSI_COLOR_RESET    "\x1b[0m"

typedef struct {
    char nome[40];
    char tabuleiro[MAX][MAX];
}JOGADOR;



#endif