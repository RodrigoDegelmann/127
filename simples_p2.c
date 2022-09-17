#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perfeito(int num)
{
    int som;
    int i;
    
    som = 0;
    
    for (i = 1; i <= num/2; i++)
        if (num%i == 0)
            som = som + i;
  
    if (som == num)
        return 1;
    else
        return 0;
}

//CODE⬆️ TEST⬇️

int main (void)
{
    int X;

    scanf("%d", &X);

    if (perfeito(X))
        printf("X eh perfeito");
    else
        printf("X nao eh perfeito");
}