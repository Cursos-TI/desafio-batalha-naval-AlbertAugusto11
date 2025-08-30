#include <stdio.h>

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

int posicionando(int (*matriz)[10], int *posicoes, int length, int esta_dentro, int esta_livre, int *barco)
{
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
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Capturando o Tamanho das linhas e Colunas
    int tamanho_linhas = sizeof(tabuleiro) / sizeof(tabuleiro[0]);
    int tamanho_colunas = sizeof(tabuleiro[0]) / sizeof(tabuleiro[0][0]);

    // Informações do 1º BARCO
    int navio1[3] = {3, 3, 3};
    int posicoes1[6] = {3, 3, 4, 3, 5, 3};
    int x = esta_dentro(tamanho_linhas, tamanho_colunas, posicoes1, (sizeof(posicoes1) / sizeof(posicoes1[0])));
    int y = esta_livre(tabuleiro, posicoes1, (sizeof(posicoes1) / sizeof(posicoes1[0])));
    posicionando(tabuleiro, posicoes1, (sizeof(posicoes1) / sizeof(posicoes1[0])), x, y, navio1);

    // Informações do 2º BARCO
    int navio2[3] = {3, 3, 3};
    int posicoes2[6] = {9, 2, 9, 3, 9, 4};
    int a = esta_dentro(tamanho_linhas, tamanho_colunas, posicoes2, (sizeof(posicoes2) / sizeof(posicoes2[0])));
    int b = esta_livre(tabuleiro, posicoes2, (sizeof(posicoes2) / sizeof(posicoes2[0])));
    posicionando(tabuleiro, posicoes2, (sizeof(posicoes2) / sizeof(posicoes2[0])), a, b, navio2);

    // Imprimindo o Tabuleiro
    imprimirTabuleiro(tabuleiro, tamanho_linhas, tamanho_colunas);

    return 0;
}
