#include <stdio.h>

int main(){

    float temp;
    float celsius;

    printf("Digite a temperatura em Farenheit: ");
    scanf("%f", &temp);

    celsius = ((5 * (temp - 32))/9);

    printf("Essa temperatura (%.2f) em Celsius é igual a: %.2f\n", temp, celsius);
    return 0;

}
