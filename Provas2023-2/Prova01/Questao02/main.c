#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, soma = 0;

    printf("Digite as dimensões da matriz:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int *matriz = (int *)malloc((n - i) * sizeof(int));
        soma += ((n - i) * sizeof(int));
        printf("Espaço alocado na memória: %d\n", soma);
        free(matriz);
    }

    return 0;
}
