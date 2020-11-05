#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "interfaces/defs.h"
#include "interfaces/funcoes.h"

int main(void){  
    
    muda_config_windows();
    while(1){        
        switch(tela_inicial()){
        case 1:
            posicionar_embarcacao();
            iniciar_jogo();
            break;
        case 2:            
            instrucoes();
            break;
        case 0:
            printf("\n\n\t\t\t\t\t\t\t\t     FIM DE JOGO\n");
            delay(2);
            limpa_tela();
            return 0;
            break;
        }
    }

    
    return 0;
}