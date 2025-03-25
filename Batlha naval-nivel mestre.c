#include <stdio.h>

int main(){
    //Definindo o tamanho do tabuleiro
    int tamanhoTabuleiro = 10;

    //Inicializando o tabuleiro com 0s (representando água)
    int tabuleiro[10][10] = {0};

    // Definindo as matrizes de habilidade para cone, cruz e octaedro (todas 5x5)
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {3, 3, 3, 3, 3},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 2, 0, 0},
        {0, 2, 2, 2, 0},
        {2, 2, 2, 2, 2},
        {0, 2, 2, 2, 0},
        {0, 0, 2, 0, 0}
    };

// Aplicando a habilidade Cone no centro (3,3)
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (cone[i][j] == 1) {
            int novaLinha = 3 + i - 2;
            int novaColuna = 3 + j - 2;
            if (novaLinha >= 0 && novaLinha < tamanhoTabuleiro && novaColuna >= 0 && novaColuna < tamanhoTabuleiro) {
                tabuleiro[novaLinha][novaColuna] = 1;
            }
        }
    }
}

// Aplicando a habilidade Cruz no centro (5,5)
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (cruz[i][j] == 3) {
            int novaLinha = 5 + i - 2;
            int novaColuna = 5 + j - 2;
            if (novaLinha >= 0 && novaLinha < tamanhoTabuleiro && novaColuna >= 0 && novaColuna < tamanhoTabuleiro) {
                tabuleiro[novaLinha][novaColuna] = 3;
            }
        }
    }
}

// Aplicando a habilidade Octaedro no centro (7,7)
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (octaedro[i][j] == 2) {
            int novaLinha = 7 + i - 2;
            int novaColuna = 7 + j - 2;
            if (novaLinha >= 0 && novaLinha < tamanhoTabuleiro && novaColuna >= 0 && novaColuna < tamanhoTabuleiro) {
                tabuleiro[novaLinha][novaColuna] = 2;
            }
        }
    }
}


    // Exibindo o título do tabuleiro
    printf("\nTabuleiro de Batalha Naval com Habilidades:\n");

    // Imprimindo os números de 1 a 10 na vertical (linhas)
    printf("   ");
    for (int j = 0; j < tamanhoTabuleiro; j++) {
        printf("%c  ", 'A' + j); // Letras de A a J na horizontal
    }
    printf("\n");

    // Exibindo o tabuleiro com os números de 1 a 10 nas linhas
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        // Imprimir os números das linhas (1 a 10)
        printf("%2d ", i + 1);
        
        // Imprimir o tabuleiro
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0  ");  // Representando água
            } else if (tabuleiro[i][j] == 1) {
                printf("1  ");  // Representando a área de efeito do cone
            } else if (tabuleiro[i][j] == 2) {
                printf("2  ");  // Representando a área de efeito do octaedro
            } else if (tabuleiro[i][j] == 3) {
                printf("3  ");  // Representando a área de efeito da cruz
            }
        }
        printf("\n");
    }

    return 0;
}