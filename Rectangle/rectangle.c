#include <stdio.h>
#include <math.h> //Library to use a function that calculates the square root

//Function with no return type, to calculate the area, perimeter, and diagonal using pointers.
void calc_info_retangulo(float a, float b, float *area, float *perim, float *diag){

    *area = (a * b);
    *perim = (2 * a) + (2 * b);
    *diag = sqrt((a * a) + (b * b));

}

int main(){
    float comp, larg, area, perim, diag;

    printf("Enter the length\n");
    scanf("%f", &comp);

    printf("Enter the width\n");
    scanf("%f", &larg);

    calc_info_retangulo(comp, larg, &area, &perim, &diag); //Passing the values of the variables (comp and larg), and passing the address of the vars (area, perim and diag)

    printf("Area = %.2f \n", area);
    printf("Perimeter = %.2f\n", perim);
    printf("Diagonal = %.2f\n", diag);

    return 0;
}
