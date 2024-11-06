#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50 // Tamanho máximo de string

char *my_strcpy(char *dest, const char *src)
{

    int i = 0;
    int tamanho = strlen(src); // Tamanho recebe o len de src
    for (i = 0; i < tamanho; i++)
    {
        dest[i] = src[i]; // Destino recebe as letras de src
    }

    return dest; // retornando destino
}

int main()
{
    char string[MAX], destino[MAX];

    printf("Digite um texto: \n");
    fgets(string, sizeof(string), stdin); // string, tamanho máximo da string, tipo de leitura

    my_strcpy(destino, string);
    printf("String de destino é: %s \n", destino);

    return 0;
}
