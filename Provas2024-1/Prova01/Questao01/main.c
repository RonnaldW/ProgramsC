#include <stdio.h>
#define MAX 4

int busca(float M[MAX][MAX], int n_lin, int n_col, float v, int *lin, int *col)
{
    int i, j;

    for (i = 0; i < n_lin; i++) // Lendo as linhas
    {
        for (j = 0; j < n_col; j++) // Lendo as colunas
        {
            if (M[i][j] == v)
            {
                *lin = i; // Linha onde está o número
                *col = j; // Coluna onde está o númerro
                return 1; // Valor encontrado
            }
        }
    }

    return 0; // Valor não encontrado
}

int main()
{
    float v;
    int lin, col;
    float matriz[3][4] = {{1, 2, 1, 4}, {5, 15, 23, 23}, {9, -1, 4, 10}}; // Definindo matriz

    printf("Digite o número que você deseja encontrar\n");
    scanf("%f", &v);

    if (busca(matriz, 3, 4, v, &lin, &col))
    {
        printf("Número encontrado na Linha %d, Coluna %d\n", lin, col);
    }
    else
    {
        printf("Número não encontrado na matriz.\n");
    }

    return 0;
}
