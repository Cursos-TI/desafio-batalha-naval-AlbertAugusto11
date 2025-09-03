#include <stdio.h>

int posicao_e_valida(int *posicoes, int length)
{
    for (int i = 0; i < length - 3; i += 2)
    {
        int p1_linha = posicoes[i];
        int p2_coluna = posicoes[i + 1];
        int p3_linha = posicoes[i + 2];
        int p4_coluna = posicoes[i + 3];

        int linha_valida = (p3_linha == p1_linha) ||
                           (p3_linha == p1_linha + 1) ||
                           (p3_linha == p1_linha - 1);

        int coluna_valida = (p4_coluna == p2_coluna) ||
                            (p4_coluna == p2_coluna + 1) ||
                            (p4_coluna == p2_coluna - 1);

        if (!(linha_valida && coluna_valida))
        {
            return 0;
        }
    }
    return 1;
}

int esta_dentro(int tamanhoLinha, int tamanhoColuna, int *posicoes, int length)
{
    if (length % 2 != 0)
        return 0;

    for (int i = 0; i < length; i += 2)
    {
        int linha = posicoes[i];
        int coluna = posicoes[i + 1];

        if (linha < 0 || linha >= tamanhoLinha || coluna < 0 || coluna >= tamanhoColuna)
            return 0;
    }
    return 1;
}

int esta_livre(int (*matriz)[10], int *posicoes, int length)
{
    if (length % 2 != 0)
        return 0; // Garante que há pares completos

    for (int i = 0; i < length; i += 2)
    {
        int linha = posicoes[i];
        int coluna = posicoes[i + 1];

        if (matriz[linha][coluna] != 0)
            return 0;
    }
    return 1;
}

int posicionando(int (*matriz)[10], int *posicoes, int length, int posicao_valida, int esta_dentro, int esta_livre, int *barco)
{
    if (!posicao_valida)
    {
        printf("Erro: Coordenadas passadas não são validas.\n");
        return 0;
    }

    if (!esta_dentro)
    {
        printf("Erro: Coordenadas fora dos limites do tabuleiro.\n");
        return 0;
    }

    if (!esta_livre)
    {
        printf("Erro: Coordenadas já estão ocupadas.\n");
        return 0;
    }

    for (int i = 0, j = 0; i < length; i += 2, j++)
    {
        int linha = posicoes[i];
        int coluna = posicoes[i + 1];
        matriz[linha][coluna] = barco[j];
    }

    printf("Barco posicionado com sucesso!\n");
    return 1;
}

void imprimirTabuleiro(int (*matriz)[10], int tamanhoLinha, int tamanhoColuna)
{
    for (int i = 0; i < tamanhoLinha; i++)
    {
        for (int j = 0; j < tamanhoColuna; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Tabuleiro 10x10
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Capturando o Tamanho das linhas e Colunas
    int tamanho_linhas = sizeof(tabuleiro) / sizeof(tabuleiro[0]);
    int tamanho_colunas = sizeof(tabuleiro[0]) / sizeof(tabuleiro[0][0]);

    // Informações do 1º BARCO
    int navio1[3] = {3, 3, 3};
    int posicoes1[6] = {3, 3, 4, 3, 5, 3};
    int x1 = posicao_e_valida(posicoes1, (sizeof(posicoes1) / sizeof(posicoes1[0])));
    int y1 = esta_dentro(tamanho_linhas, tamanho_colunas, posicoes1, (sizeof(posicoes1) / sizeof(posicoes1[0])));
    int z1 = esta_livre(tabuleiro, posicoes1, (sizeof(posicoes1) / sizeof(posicoes1[0])));
    posicionando(tabuleiro, posicoes1, (sizeof(posicoes1) / sizeof(posicoes1[0])), x1, y1, z1, navio1);

    // Informações do 2º BARCO
    int navio2[3] = {3, 3, 3};
    int posicoes2[6] = {9, 7, 9, 8, 9, 9};
    int x2 = posicao_e_valida(posicoes2, (sizeof(posicoes2) / sizeof(posicoes2[0])));
    int y2 = esta_dentro(tamanho_linhas, tamanho_colunas, posicoes2, (sizeof(posicoes2) / sizeof(posicoes2[0])));
    int z2 = esta_livre(tabuleiro, posicoes2, (sizeof(posicoes2) / sizeof(posicoes2[0])));
    posicionando(tabuleiro, posicoes2, (sizeof(posicoes2) / sizeof(posicoes2[0])), x2, y2, z2, navio2);

    // Informações do 3º BARCO
    int navio3[3] = {3, 3, 3};
    int posicoes3[6] = {0, 0, 1, 1, 2, 2};
    int x3 = posicao_e_valida(posicoes3, (sizeof(posicoes3) / sizeof(posicoes3[0])));
    int y3 = esta_dentro(tamanho_linhas, tamanho_colunas, posicoes3, (sizeof(posicoes3) / sizeof(posicoes3[0])));
    int z3 = esta_livre(tabuleiro, posicoes3, (sizeof(posicoes3) / sizeof(posicoes3[0])));
    posicionando(tabuleiro, posicoes3, (sizeof(posicoes3) / sizeof(posicoes3[0])), x3, y3, z3, navio3);

    // Informações do 4º BARCO
    int navio4[3] = {3, 3, 3};
    int posicoes4[6] = {9, 0, 8, 1, 7, 2};
    int x4 = posicao_e_valida(posicoes4, (sizeof(posicoes4) / sizeof(posicoes4[0])));
    int y4 = esta_dentro(tamanho_linhas, tamanho_colunas, posicoes4, (sizeof(posicoes4) / sizeof(posicoes4[0])));
    int z4 = esta_livre(tabuleiro, posicoes4, (sizeof(posicoes4) / sizeof(posicoes4[0])));
    posicionando(tabuleiro, posicoes4, (sizeof(posicoes4) / sizeof(posicoes4[0])), x4, y4, z4, navio4);

    // Imprimindo o Tabuleiro
    imprimirTabuleiro(tabuleiro, tamanho_linhas, tamanho_colunas);

    return 0;
}
