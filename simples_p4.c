#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int encontra_letra(char a, char b[100])
{
    //número de vezes que a letra foi vista
    int total;
    int i;
    
    total = 0;
    
    for (i = 0; b[i] != '\0'; i++)
        if (b[i] == a)
            total = total + 1;

    return total;
}

//CODE⬆️ TEST⬇️

int main (void)
{
    char s[100];
    char letra;
    int i;
 

    scanf("%100[^\n]", s);
    scanf(" %c", &letra);

    
    printf("%d", encontra_letra(letra, s));
}