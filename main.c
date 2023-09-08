//
//  main.c
//  EDII_Tarea3
//
//  Created by Leo Vedovatti on 07/09/23.
//  Copyright © 2023 Leo Vedovatti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

char **CreaMatriz(int col,int ren);
void ImprimirPuntos(char **matriz, int col, int ren);
void ImprimirNum(char **matriz, int col, int ren);
void LlenadoDeMinas(char **matriz, int col, int fil, int bombas);
int CuentaBombas(char **matriz, int x, int y);



int main(int argc, const char * argv[]) {
    int col, ren, bombas;
    srand(time(0));

    printf("Numero de columnas: ");
    scanf("%d",&col);
    printf("Numero de filas: ");
    scanf("%d",&ren);
    
    char **matriz = CreaMatriz(col, ren);
    
    printf("Numero de bombas: ");
    scanf("%d",&bombas);
    LlenadoDeMinas(matriz, col, ren, bombas);
    ImprimirPuntos(matriz,col,ren);
    ImprimirNum(matriz, col, ren);
    
    return 0;
}

char **CreaMatriz(int col, int ren)
{
    char **matriz = (char**)malloc(col*sizeof(char));
    assert(matriz!=NULL);
    
    for(int i=0; i<col; i++)
    {
        matriz[i]=(char*)malloc(ren*sizeof(char));
        assert(matriz[i]!=NULL);
    }
    
    return matriz;
}

void LlenadoDeMinas(char **matriz,int col, int ren, int bombas)
{
    int bombX, bombY;
    
    for(int i=0; i<col; i++){
        for(int x=0; x<ren; x++)
        {
            matriz[i][x]='.';
            printf("%c",matriz[i][x]);
        }
        printf("\n");
    }
            
    
    for (int z = 0; z < bombas; z ++)
    {
        /*bombX = rand()%tamT;
        bombY = rand()%tamT;
        matriz[bombX][bombY]='*';*/
        printf("Indique coordenada X de Bomba %d: ",z+1);
        scanf("%d",&bombX);
        printf("Indique coordenada Y de Bomba %d: ",z+1);
        scanf("%d",&bombY);
        matriz[bombX-1][bombY-1]='*';

    }
    
}

void ImprimirPuntos(char **matriz, int col, int ren)
{
    for(int i=0; i<col; i++)
    {
        for(int x=0; x<ren; x++)
        {
            printf("%c",matriz[i][x]);
        }
        printf("\n");
    }
}

void ImprimirNum(char **matriz, int col, int ren)
{
    for(int x=0; x<col; x++)
    {
        for(int y=0; y<ren; y++)
        {
            if(matriz[x][y]!='*')
            {
                matriz[x][y] = CuentaBombas(matriz, x, y)+0;
                if(matriz[x][y]=='0')
                    matriz[x][y]='.';
            }
        }
    }
}

int CuentaBombas(char **matriz, int x, int y)
{
    int bombas=0;
    
    for(int contx=-1; contx<2; contx++)
    {
        for(int conty=-1; conty<2; conty++)
        {
            if(x+contx>=0 && y+conty>=0)
                if( matriz[x+contx][y+conty]=='*')
                    bombas++;
        }
        
    }
    
    return bombas;
}
