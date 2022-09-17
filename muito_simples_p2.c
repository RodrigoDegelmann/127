#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float converte_temperatura(float a)
{
    float C;
    
    C = (a - 32)/9 * 5;
    
    return C;
}

//CODE⬆️ TEST⬇️

int main (void)
{
    float F;

    scanf("%f", &F);

    printf("%.2f", converte_temperatura(F));
}