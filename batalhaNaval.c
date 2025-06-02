#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAM_HABILIDADE 5  // 5x5

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf(". ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("* ");
            else printf("? ");
        }
        printf("\n");
    }
}

// Marca a área de efeito no tabuleiro com base na matriz da habilidade
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HABILIDADE][TAM_HABILIDADE], int origem_l, int origem_c) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matriz[i][j] == 1) {
                int l = origem_l - offset + i;
                int c = origem_c - offset + j;
                if (l >= 0 && l < TAM && c >= 0 && c < TAM && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }
}

// Cria uma matriz de habilidade em forma de cone
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) ? 1 : 0;
        }
    }
}

// Cria uma matriz de habilidade em forma de cruz
void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Cria uma matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (abs(i - centro) + abs(j - centro) <= centro) ? 1 : 0;
        }
    }
}

// Posiciona um navio horizontal simples
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int l, int c) {
    for (int i = 0; i < 3 && c + i < TAM; i++) {
        tabuleiro[l][c + i] = NAVIO;
    }
}

// Posiciona um navio diagonal simples
void posicionarNavioDiagonal(int tabuleiro[TAM][TAM], int l, int c) {
    for (int i = 0; i < 3 && l + i < TAM && c + i < TAM; i++) {
        tabuleiro[l + i][c + i] = NAVIO;
    }
}


int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona alguns navios fixos
    posicionarNavioHorizontal(tabuleiro, 2, 4); // navio horizontal
    posicionarNavioDiagonal(tabuleiro, 5, 5);   // navio diagonal

    // Matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Cria as matrizes
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define origem de cada habilidade (posição central)
    aplicarHabilidade(tabuleiro, cone, 1, 1);        // Cone no canto superior
    aplicarHabilidade(tabuleiro, cruz, 4, 2);        // Cruz no meio-esquerda
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);    // Octaedro no meio-inferior-direita

    // Exibe tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
