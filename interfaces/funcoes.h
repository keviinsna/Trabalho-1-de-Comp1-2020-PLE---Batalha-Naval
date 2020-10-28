#ifndef FUNCOES_H
#define FUNCOES_H

    void limpa_tela();
    void limpa_buffer();


    int  tela_inicial();
    void titulo();
    void instrucoes();

    void iniciar_jogo();
    void inicializa_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_ambos_tabuleiros(char tabuleiro1[MAX][MAX], char tabuleiro2[MAX][MAX]);



#endif