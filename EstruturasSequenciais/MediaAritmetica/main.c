//3. Faça um programa que leia três notas e imprima na tela a média aritmética delas.

#include <stdio.h>

int main(){
    int nota, total = 0;

    for(int i = 0; i < 3; i++){
        printf("Digite a nota do aluno \n");
        scanf("%d", &nota);
        total += nota;
    }

    printf("A média aritmetica das notas foi: \n %d", (total / 3));

    return 0;
}