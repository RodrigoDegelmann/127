#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//O valor do meio será o vértice
float angulo(int a[2], int b[2], int c[2])
{
    float V[2];
    float U[2];
    float ang;
    int i;
    
    for (i = 0; i < 2; i++)
    {
        V[i] = a[i] - b[i];
        U[i] = c[i] - b[i];
    }
    
    //aplicando (VxU/|V|x|U|)
    ang = (V[0]*U[0]+V[1]*U[1])/(sqrt(pow(V[0], 2)+pow(V[1], 2))*sqrt(pow(U[0], 2)+pow(U[1], 2)));
    //aplicando o arco e transformando em graus
    ang = acos(ang)*180/M_PI;
    
    return ang;
}

//CODE⬆️ TEST⬇️

int main (void)
{
    int a[2];
    int b[2];
    int c[2];
    int i;
    
    for (i = 0; i < 2; i++)
        scanf("%d", &a[i]);
    
    for (i = 0; i < 2; i++)
        scanf("%d", &b[i]);
    
    for (i = 0; i < 2; i++)
        scanf("%d", &c[i]);
    
    printf("%.2f", angulo(a, b, c));
}