#include <stdio.h>
#include <string.h>

// Definição da struct aluno
typedef struct
{
    char nome[100]; // var nome da struct
    int idade;      // var nome da struct
    float nota;     // var nome da struct
} aluno;            // nome da struct

/*
Inicializa os dados de um aluno com o nome, idade e nota fornecidos.
Parâmetros:
- a: Ponteiro para a estrutura aluno que será inicializada.
- nome: String contendo o nome do aluno.
- idade: Idade do aluno.
- nota: Nota do aluno.
*/

void inicializar_aluno(aluno *a, const char *nome, int idade, float nota)
{
    strcpy(a->nome, nome); // Parametro `nome` da estrutura `a` recebe o valor da VAR `nome`
    a->idade = idade;      // Parametro `idade` da estrutura `a` recebe o valor da VAR `idade`
    a->nota = nota;        // Parametro `nome` da estrutura `a` recebe o valor da VAR `nome`
}
/*
Imprime na saída padrão os dados de um aluno (nome, idade e nota).
Parâmetros:
- a: Ponteiro constante para a estrutura aluno cujos dados serão impressos.
*/
void imprimir_aluno(const aluno *a)
{
    printf("Nome: %s\n", a->nome);
    printf("Idade: %d\n", a->idade);
    printf("Nota: %.1f\n", a->nota);
}
int main()
{
    aluno a; // VAR `a` é definida pela struct aluno

    // Inicializa o aluno com os dados fornecidos
    inicializar_aluno(&a, "João Silva", 20, 8.5);
    // Imprime os dados do aluno
    imprimir_aluno(&a);
    return 0;
}