#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float distancia(float a[2], float b[2])
{
    float c[2];
    float dis;
    
    c [0] = a[0] - b[0];
    c [1] = a[1] - b[1];
    
    dis = sqrt(pow(c[0], 2) + pow(c[1], 2));
    
    return dis;
}

//CODE⬆️ TEST⬇️

int main(void)
{
    float a[2];
    float b[2];
    int i;

    for (i = 0; i < 2; i++)
        scanf("%f", &a[i]);
    for (i = 0; i < 2; i++)
        scanf("%f", &b[i]);

    printf("%.5f", distancia(a, b));
}