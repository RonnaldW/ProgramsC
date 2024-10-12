#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definindo uma constante
#define N_MAX_ROUNDS 3

//Fun��o VOID, sem retorno. Os valores s�o alterados direto no ponteiro recebido (int *x)
void triple7(int *x){

  //Pegando um n�mero pseudo aleat�rio
  srand(time(NULL));

  //Pegando o resto do (pseudo n�mero / 100)
  int p = rand() % 100;

  //Alterando as m�tricas do programa de forma tendenciosa
  if(p <= 50){
    *x = 0; //Pedra
  }
  else if(x <= 75){
    *x = 1; //Papel
  }
  else{
    *x = 2; //Tesoura
  }
}

//Fun��o VOID que recebe as entradas do humano, a "escolha do computador"
void jokenpo(int number, int *human, int *computer, int *empate){

  int x;

    triple7(&x); //Mandando o endere�o de 'x' para a fun��o que vai definir o seu valor via ponteiro

    if(number == x){
      printf("Empate!!! \n Human: %d X Computer: %d\n", number, x);
      (*empate)++; //Somando '+1' no atual valor do ponteiro
    }
    else if(number == 0 && x == 2){
      printf("Humano ganhou!\n Human: %d X Computer: %d\n", number, x);
      (*human)++;
    }
    else if(number == 1 && x == 0){
      printf("Humano ganhou!\n Human: %d X Computer: %d\n", number, x);
      (*human)++;
    }
    else if(number == 2 && x == 1){
      printf("Humano Ganhou!\n Human: %d X Computer: %d\n", number, x);
      (*human)++;
    }
    else{
      printf("PC Ganhou!!\n Human: %d X Computer: %d\n", number, x);
      (*computer)++;
    }
}

int main(){

  //Definindo e inicializando as VARs
  int number, human = 0, computer = 0, empate = 0, i = 0;

    while(i < N_MAX_ROUNDS){
      printf("\nEscolha entre \n 0 - Pedra \n 1 - Papel \n 2 - Tesoura \n");
      scanf("%d", &number);

      //Definindo qual vai ser a a��o do programa de acordo com o valor da Var 'number'
      switch(number){
        case 0:
        case 1:
        case 2:
          jokenpo(number, &human, &computer, &empate); //caso seja 0, 1 ou 2, ele vai para a fun��o JoKenPo
          i++; //incrementa +1 no While
          break;
        default: //Caso nada acima seja verdade, a resposta � inv�lida, e o usu�rio deve enviar a resposta novamente
          printf("Resposta inv�lida. \n");
          break;
      }
    }

    //Printando o resultado final
    printf("\n###############################");
    printf("Resultado Geral:");
    printf("###############################\n");
    printf("Vit�rias do Humano: %d \n Vit�rias do computador: %d \n Empates: %d\n", human, computer, empate);
  return 0;
}
