#include <stdlib.h>
#include <stdio.h>

int main()
{
    //tabuleiro 8x8 + \n e \0
    char mesa[8][10];
    //diz qual linha deve ser digitada
    int line;
    //diz o número do jogo ao final
    int jogo;
    //termina com a partida quando o tabuleiro estiver vazio
    int end;
    //verifica se/qual rei está em cheque 
    int win;
    //posição rei preto e rei branco
    int Bi;
    int Bj;
    int Wi;
    int Wj;
    int i;
    int j;
    
    jogo = 1;
    
    while(1)
    {
    
        line = 1;
        end = 0;
        win = 0;
        
        for(i = 0; i < 8; i++)
        {
            printf("digite a linha %d\n", line);
            fgets(mesa[i], 10, stdin);
            line = line + 1;
        }
        
        for (i = 0; i < 8; i++)
                for (j = 0; j < 8; j++)
                    if (mesa[i][j]=='.')
                        end = end + 1;
        
        if (end == 64)
            break;
        
        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
            {
                if (mesa[i][j] == 'k')
                {
                    Bi = i;
                    Bj = j;
                }   
                if (mesa[i][j] == 'K')
                {
                    Wi = i;
                    Wj = j;
                }
            }
        
        //cheques de cavalo
        for (i = -2; i < 3; i++)
            for (j = -2; j < 3; j++)
            {
                if (((abs(i)==1 && abs(j)==2)||(abs(i)==2 && abs(j)==1))&&mesa[Bi-i][Bj-j]=='N')
                    win = 1;
                 if (((abs(i)==1 && abs(j)==2)||(abs(i)==2 && abs(j)==1))&&mesa[Wi-i][Wj-j]=='n')
                    win = -1;
            }
        
        //cheque da diagonal inferior direita
        for (i = 1; Bi+i < 8 && Bj+i < 8; i++)
        {
            if (mesa[Bi+i][Bj+i]!='B'&&mesa[Bi+i][Bj+i]!='Q'&&mesa[Bi+i][Bj+i]!='.')
                break;
            if (mesa[Bi+i][Bj+i]=='B'||mesa[Bi+i][Bj+i]=='Q')
                win = 1;
        }
                
        for (i = 1; Wi+i < 8 && Wj+i < 8; i++)
        {
            if (mesa[Wi+i][Wj+i]!='b'&&mesa[Wi+i][Wj+i]!='q'&&mesa[Bi+i][Bj+i]!='.')
                break;
            if (mesa[Wi+i][Wj+i]=='b'||mesa[Wi+i][Wj+i]=='q')
                win = -1;
        }
        
        //cheque da diagonal inferior esqurda
        for (i = 1; Bi+i < 8 && Bj-i > -1; i++)
        {
            if (mesa[Bi+i][Bj-i]!='B'&&mesa[Bi+i][Bj-i]!='Q'&&mesa[Bi+i][Bj-i]!='.')
                break;
            if (mesa[Bi+i][Bj-i]=='B'||mesa[Bi+i][Bj-i]=='Q')
                win = 1;
        }
        
        for (i = 1; Wi+i < 8 && Wj-i > -1; i++)
        {
            if (mesa[Wi+i][Wj-i]!='b'&&mesa[Wi+i][Wj+i]!='q'&&mesa[Wi+i][Wj-i]!='.')
                break;
            if (mesa[Wi+i][Wj-i]=='b'||mesa[Wi+i][Wj-i]=='q')
                win = -1;
        }
        
        //cheque da diagonal superior direita
        for (i = 1; Bi-i > -1 && Bj+i < 8; i++)
        {
            if (mesa[Bi-i][Bj+i]!='B'&&mesa[Bi-i][Bj+i]!='Q'&&mesa[Wi-i][Wj+i]!='.')
                break;
            if (mesa[Bi-i][Bj+i]=='B'||mesa[Bi-i][Bj+i]=='Q')
                win = 1;
        }
           
        for (i = 1; Wi-i > -1 && Wj+i < 8; i++)
        {
            if (mesa[Wi-i][Wj+i]!='b'&&mesa[Wi-i][Wj+i]!='q'&&mesa[Wi-i][Wj+i]!='.')
                break;
            if (mesa[Wi-i][Wj+i]=='b'||mesa[Wi-i][Wj+i]=='q')
                win = -1;
        }
        
        //cheque da diagonal superior esquerda
        for (i = 1; Bi-i > -1 && Bj+i > -1; i++)
        {
            if (mesa[Bi-i][Bj-i]!='B'&&mesa[Bi-i][Bj-i]!='Q'&&mesa[Bi-i][Bj-i]!='.')
                break;
            if (mesa[Bi-i][Bj-i]=='B'||mesa[Bi-i][Bj-i]=='Q')
                win = 1;
        }
         
        for (i = 1; Wi-i > -1 && Wj+i > -1; i++)
        {
            if (mesa[Wi-i][Wj+i]!='b'&&mesa[Wi-i][Wj-i]!='q'&&mesa[Wi-i][Wj-i]!='.')
                break;
            if (mesa[Wi-i][Wj+i]=='b'||mesa[Wi-i][Wj-i]=='q')
                win = -1;
        }
        
        //cheque inferior
        for (i = 1; Bi+i < 8; i++)
        {
            if (mesa[Bi+i][Bj]!='R'&&mesa[Bi+i][Bj]!='Q'&&mesa[Bi+i][Bj]!='.')
                break;
            if (mesa[Bi+i][Bj]=='R'||mesa[Bi+i][Bj]=='Q')
                win = 1;
        }
         
        for (i = 1; Wi+i < 8; i++)
        {
            if (mesa[Wi+i][Wj]!='r'&&mesa[Wi+i][Wj]!='q'&&mesa[Wi+i][Wj]!='.')
                break;
            if (mesa[Wi+i][Wj]=='r'||mesa[Wi-i][Wj]=='q')
                win = -1;
        }
        
        //cheque superior
        for (i = 1; Bi-i > -1; i++)
        {
            if (mesa[Bi-i][Bj]!='R'&&mesa[Bi-i][Bj]!='Q'&&mesa[Bi-i][Bj]!='.')
                break;
            if (mesa[Bi-i][Bj]=='R'||mesa[Bi-i][Bj]=='Q')
                win = 1;
        }
          
        for (i = 1; Wi-i > -1; i++)
        {
            if (mesa[Wi-i][Wj]!='r'&&mesa[Wi-i][Wj]!='q'&&mesa[Wi-i][Wj]!='.')
                break;
            if (mesa[Wi-i][Wj]=='r'||mesa[Wi-i][Wj]=='q')
                win = -1;
        }
        
        //cheque direito
        for (i = 1; Bj+i < 8; i++)
        {
            if (mesa[Bi][Bj+i]!='R'&&mesa[Bi][Bj+i]!='Q'&&mesa[Bi][Bj+i]!='.')
                break;
            if (mesa[Bi][Bj+i]=='R'||mesa[Bi][Bj+i]=='Q')
                win = 1;
        }
        
        for (i = 1; Wj+i < 8; i++)
        {
            if (mesa[Wi][Wj+i]!='r'&&mesa[Wi][Wj+i]!='q'&&mesa[Wi][Wj+i]!='.')
                break;
            if (mesa[Wi][Wj+i]=='r'||mesa[Wi][Wj+i]=='q')
                win = -1;
        }
        
        //cheque esquerdo
        for (i = 1; Bj-i > -1; i++)
        {
            if (mesa[Bi][Bj-i]!='R'&&mesa[Bi][Bj-i]!='Q'&&mesa[Bi][Bj-i]!='.')
                break;
            if (mesa[Bi][Bj-i]=='R'||mesa[Bi][Bj-i]=='Q')
                win = 1;
        }
          
        for (i = 1; Wj-i > -1; i++)
        {
            if (mesa[Wi][Wj-i]!='r'&&mesa[Wi][Wj-i]!='q'&&mesa[Wi][Wj-i]!='.')
                break;
            if (mesa[Wi][Wj-i]=='r'||mesa[Wi][Wj-i]=='q')
                win = -1;
        }
        
        //cheque peão
        if (mesa[Bi+1][Bj+1]=='P'||mesa[Bi+1][Bj-1]=='P')
            win = 1;
        if (mesa[Wi-1][Wj+1]=='p'||mesa[Wi-1][Wj-1]=='p')
            win = -1;
      
        //tabuleiro
        printf("\n");
        
        for(i = 0; i < 8; i++)
            printf("%s", mesa[i]);
        
        printf("\n");
        
        //resultado
        if (win==-1)
            printf("Jogo #%d: rei branco esta em cheque.", jogo);
        if (win==1)
            printf("Jogo #%d: rei preto esta em cheque.", jogo);
        if (win==0)
            printf("Jogo #%d: nenhum rei esta em cheque.", jogo);
      
        printf("\n\n");
        
        jogo = jogo + 1;
        
    }
}