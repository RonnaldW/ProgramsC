#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Digite as dimensões da matriz:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int *matriz = (int *)malloc((n - i) * sizeof(int));
        free(matriz);
    }

    return 0;
}
