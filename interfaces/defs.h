#ifndef DEFS_H
#define DEFS_H

/*Tamnhos*/
#define MAX 15

/*Cores*/
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
    char nome[40];
    char tabuleiro[MAX][MAX];
}JOGADOR;


#endif