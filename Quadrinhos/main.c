#include <stdio.h>
#include <stdlib.h>

int *unir_colecoes(int *colecao_herois_hq, int *colecao_acao_comics, int tamanho_herois_hq, int tamanho_acao_comics, int *tamanho_final)
{
    *tamanho_final = tamanho_herois_hq + tamanho_acao_comics; //*tamanho final recebe a soma do tamanhoHQ e tamanhoComics

    int *colecao_unificada = (int *)malloc(*tamanho_final * sizeof(int)); // Colecao Unificada tem uma alocação dinâmica, de acordo com o tamanho final. Seu Casting está sendo feito para o tipo Int.

    int i, j, k = 0;

    // Coleção unificada recebe os itens de coleçãoHQ
    for (i = 0; i < tamanho_herois_hq; i++)
    {
        colecao_unificada[k++] = colecao_herois_hq[i];
    }

    // Copia os elementos de colecaoComics para colecaoUnificada caso não tenha o mesmo ID dentro do array
    for (i = 0; i < tamanho_herois_hq; i++)
    {
        for (j = 0; j < tamanho_acao_comics; j++)
        {
            if (colecao_acao_comics[j] != colecao_herois_hq[i])
            {
                colecao_unificada[k + j] = colecao_acao_comics[j];
            }
        }
    }

    return colecao_unificada;

}

int main()
{
    int colecao_herois_hq[] = {101, 102, 103, 104}; // IDs das edições da Heróis HQ
    int colecao_acao_comics[] = {201, 202, 203};    // IDs das edições da Ação Comics
    int tamanho_herois_hq = 4;
    int tamanho_acao_comics = 3;
    int tamanho_final;

    int *colecao_unificada = unir_colecoes(colecao_herois_hq, colecao_acao_comics, tamanho_herois_hq, tamanho_acao_comics, &tamanho_final);

    // Exibe a coleção unificada
    printf("Colecao unificada: %d");
    for (int i = 0; i < tamanho_final; i++)
    {
        printf("%d ", colecao_unificada[i]);
    }
    printf("\n");

    // Exibe o tamanho da coleção unificada
    printf("Tamanho da colecao unificada: %d\n", tamanho_final);

    // Libera a memória alocada para a coleção unificada
    free(colecao_unificada);

    return 0;
}