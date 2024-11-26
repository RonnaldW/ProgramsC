/* 4. A prefeitura da Serra abriu uma linha de crédito para os funcionários estatutários. O valor
máximo da prestação não poderá ultrapassar 30% do salário bruto (salário mais benefícios sem
desconto de impostos). Faça um programa que leia o salário bruto de uma pessoa e imprima na
tela o valor máximo possível de prestação para este funcionário. */

#include <stdio.h>

void max_prestacao(float *salario)
{

    float vmax_prestacao = (*salario) * 0.3;

    printf("O valor máximo de prestação é: %.2f\n", vmax_prestacao);
}

int main()
{

    float salario = 0;

    printf("Digite o seu salário bruto (salário mais benefícios sem desconto de impostos) \n");
    scanf("%f", &salario);

    max_prestacao(&salario);

    return 0;
}