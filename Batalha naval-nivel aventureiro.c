#include <stdio.h>

int main(){
    //Definindo o tamanho do tabuleiro e o tamanho dos navios
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    //Inicializando o tabuleiro com 0s (representando água)
    int tabuleiro[10][10] = {0};

    //Variaveis para coordenadas e orientações dos navios
    int linha, coluna, i;

    //Posicionando o navio horizontal
    linha = 2; coluna = 3;
    if(coluna + tamanhoNavio <= tamanhoTabuleiro){
        int podePosicionar = 1;
        for( i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if(podePosicionar) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro [linha] [coluna + i]= 3;
            }
        }
    }

    //Posicionando o navio vertical
    linha = 5; coluna= 6;
    if(linha + tamanhoNavio <= tamanhoTabuleiro) {
        int podePosicionar = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha + i] [coluna] != 0){
                podePosicionar = 0;
                break;
            }
        }
        if(podePosicionar) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro [linha + i] [coluna] = 3;
            }
        }
    }

    //Posicionando o navio diagonal crescente
    linha = 1; coluna = 1;
    if( linha + tamanhoNavio <= tamanhoTabuleiro && coluna + tamanhoNavio <= tamanhoTabuleiro) {
        int podePosicionar = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if(tabuleiro[linha + i] [coluna + i] != 0){
                podePosicionar = 0;
                break;
            }
        }
        if(podePosicionar){
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linha + i][coluna] = 3;
            }
        }    
    }
    //Posicionando o navio diagonal decrescente
    linha = 6; coluna = 8;
    if( linha + tamanhoNavio <= tamanhoTabuleiro && coluna - tamanhoNavio + 1 >= 0) {
        int podePosicionar = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0){
                podePosicionar = 0;
                break;
            }
        }
        if(podePosicionar){
            for (i = 0; i < tamanhoNavio; i++){
                tabuleiro[linha + i][coluna - i] = 3;
            }
        }
    }
    //Exibindo o título do tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n");

    //Imprimindo os números de 1 a 10 na vertical (linhas)
    printf("  ");
    for (int j = 0; j < tamanhoTabuleiro; j++) {
        printf("%c  ", 'A' + j); //Letras de A a J na horizontal
    }
    printf("\n");

    //Exibindo o tabuleiro com os números de 1 a 10 nas linhas
    for (int i = 0; i < tamanhoTabuleiro; i++) {
      //Imprimir os números das linhas (1 a 10)
      printf("%2d ", i + 1);

      //Imprimir o tabuleiro
      for (int j = 0; j < tamanhoTabuleiro; j++){
        printf("%d  ", tabuleiro[i][j]);
      }
      printf("\n");
    }

    return 0;
}