#ifndef FUNCOES_H
#define FUNCOES_H
    
    void limpa_tela();
    void limpa_buffer();
    void muda_config_windows();
    void delay(int i);

    int  tela_inicial();
    void menu_inicial();
    void titulo();
    void instrucoes();

    void posicionar_embarcacao();
    void inicializa_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_ambos_tabuleiros(char tabuleiro1[MAX][MAX], char tabuleiro2[MAX][MAX]);

    void insere_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);
    void insere_bomba(int linha, int coluna,char tabuleiro[MAX][MAX]);
    void preenche_tabuleiro();
    void preenche_tabuleiro_auto(char tabuleiro[MAX][MAX]);
    
    int  verifica_coordenadas(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);
    int verifica_coordenadas_bomba(int linha, int coluna, char tabuleiro[MAX][MAX]);
    void cria_borda_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);

    void iniciar_jogo();    
    int  atira(int linha, int coluna, char tab_atacado[MAX][MAX]);
    int  verifica_tiro(int linha, int coluna, char tab_atacado[MAX][MAX]);

    void fim_jogo(char vencedor[40]);

#endif