#include <stdio.h>

int main(){
    //Definindo o tamanho do tabuleiro e o tamanho dos navios
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    //Inicializando o tabuleiro com 0s (representando água)
    int tabuleiro[10][10] = {0};

    //Definindo as coordenadas e orientações dos navios
    int linhaNavioHozintal = 2, colunaNavioHorizontal = 3; //Navio Horizontal começa em (2,3)
    int linhaNavioVertical = 5, colunaNavioVertical = 6;   //Navio Vertical começa em (5,6)

    //Posicionando o navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioHozintal][colunaNavioHorizontal + i] = 3; //Representando o navio com o valor 3
    }

    //Posicionando o navio vertical
    for(int i = 0; i < tamanhoNavio; i ++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3; //Representando o navio com o valor 3
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