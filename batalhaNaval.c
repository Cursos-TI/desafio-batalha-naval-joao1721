#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro com valor 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha e coluna)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    // Posicionamento horizontal do navio
    // Verificação de limites e preenchimento do tabuleiro
    if (coluna_navio_horizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica se a posição já está ocupada
            if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == MAR) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = NAVIO;
            } else {
                printf("Erro: sobreposição de navio na posição horizontal.\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio horizontal fora dos limites.\n");
        return 1;
    }

    // Posicionamento vertical do navio
    if (linha_navio_vertical + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == MAR) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = NAVIO;
            } else {
                printf("Erro: sobreposição de navio na posição vertical.\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio vertical fora dos limites.\n");
        return 1;
    }

    // Impressão do tabuleiro
    printf("\nTabuleiro (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
