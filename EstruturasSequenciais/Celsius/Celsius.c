#include <stdio.h>

int main(){

    float celsius, fahrenheit;

    printf("Write the temperature in Celsius:");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 1.8) + 32;

    printf("This is the temperature in Fahrenheit: %f\n ",  fahrenheit);

    return 0;
}
