/*
A - Alocação dinâmica: A alocação dinâmica permite que a quantidade de memória reservada para uma variável ou estrutura seja determinada durante a execução do programa, conforme a necessidade.
Com isso, o programa pode alocar apenas a quantidade exata de espaço necessário para armazenar determinado dado.

Na alocação estática, por outro lado, o tamanho da memória para uma variável é definido no momento da compilação, e o espaço em memória ocupado pelo objeto será sempre o mesmo,
independentemente de quanto dessa memória é realmente usada.

* Alocação Dinâmica:
  Vantagens:
    - Flexibilidade: Permite usar apenas a quantidade de memória necessária em tempo de execução, economizando recursos.
    - Eficiência: Ideal para situações em que o tamanho dos dados é variável e não pode ser determinado antes da execução.
  Desvantagens:
    - Mais complexidade: O programador precisa gerenciar manualmente a memória, liberando-a quando não for mais necessária.
    - Risco de vazamento de memória: Caso a memória não seja liberada corretamente, pode ocorrer um "memory leak", que compromete o desempenho do sistema.

* Alocação Estática:
  Vantagens:
    - Simplicidade: A memória é alocada automaticamente e liberada quando o programa termina, sem necessidade de gerenciamento manual.
    - Desempenho: Como o espaço é pré-alocado, o programa pode ter um desempenho mais previsível e eficiente em relação ao uso da memória.
  Desvantagens:
    - Falta de flexibilidade: O espaço em memória é fixo, o que pode levar a desperdício de memória se o tamanho definido for maior que o necessário ou a limitações se for menor.
    - Impossibilidade de redimensionamento: Não é possível aumentar ou diminuir o espaço de memória alocado após a compilação, limitando a capacidade de adaptação do programa.

*/

#include <stdio.h>
#include <stdlib.h>

int *aloca_vetor(int n)
{
  int *vetor = (int *)malloc(n * sizeof(int)); //Alocando memória do vetor

  if (vetor == NULL) // Verifica se a alocação foi bem-sucedida
  {
    printf("Erro de alocação de memória.\n");
    return NULL;
  }

  return vetor; // Retorna o ponteiro para o vetor alocado
}

int main()
{
  int n;

  printf("Digite um número inteiro: \n");
  scanf("%d", &n);

  int *vetor = aloca_vetor(n);
  printf("Tamanho do vetor: %d bytes\n", n * (int)sizeof(int));

  if (vetor != NULL)
  {
    free(vetor); // Libera a memória depois de usar o vetor
  }

  return 0;
}