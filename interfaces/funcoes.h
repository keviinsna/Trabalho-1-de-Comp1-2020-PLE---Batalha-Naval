#ifndef FUNCOES_H
#define FUNCOES_H

    void muda_config_windows();
    void limpa_tela();
    void limpa_buffer();


    int  tela_inicial();
    void titulo();
    void instrucoes();

    void iniciar_jogo();
    void inicializa_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_ambos_tabuleiros(char tabuleiro1[MAX][MAX], char tabuleiro2[MAX][MAX]);

    void insere_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);
    void insere_bomba(int linha, int coluna,char tabuleiro[MAX][MAX]);
    void preenche_tabuleiro();
    
    int verifica_coordenadas(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);
    void cria_borda_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);

#endif