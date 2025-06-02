#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3

// Função para verificar se as posições estão livres para posicionar o navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0; // Fora dos limites
        if (tabuleiro[linha[i]][coluna[i]] != MAR)
            return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// Função para imprimir o tabuleiro com cabeçalho
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // === Navio Horizontal ===
    int hLinha[] = {2, 2, 2};
    int hColuna[] = {4, 5, 6};

    // === Navio Vertical ===
    int vLinha[] = {5, 6, 7};
    int vColuna[] = {7, 7, 7};

    // === Navio Diagonal (principal) ===
    int d1Linha[] = {0, 1, 2};
    int d1Coluna[] = {0, 1, 2};

    // === Navio Diagonal (secundária) ===
    int d2Linha[] = {7, 8, 9};
    int d2Coluna[] = {2, 1, 0};

    // Posiciona os navios se possível
    if (podePosicionar(tabuleiro, hLinha, hColuna))
        posicionarNavio(tabuleiro, hLinha, hColuna);

    if (podePosicionar(tabuleiro, vLinha, vColuna))
        posicionarNavio(tabuleiro, vLinha, vColuna);

    if (podePosicionar(tabuleiro, d1Linha, d1Coluna))
        posicionarNavio(tabuleiro, d1Linha, d1Coluna);

    if (podePosicionar(tabuleiro, d2Linha, d2Coluna))
        posicionarNavio(tabuleiro, d2Linha, d2Coluna);

    // Imprime o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
