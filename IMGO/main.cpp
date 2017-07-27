/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: olivato
 *
 * Created on 27 de Julho de 2017, 00:18
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <curses.h>
#define tam 50
#define agua '0'
#define terra 'X'
using namespace std;

/*
 * 
 */
char m[tam][tam];
int random(int rng)
{
    return (rand()%rng)+1;
}
void fillIsland()
{
    for(int i =0;i<tam;i++)
    {
        for(int j =0;j<tam;j++)
        {
            m[i][j]=agua;
        }
    }
}
int checaVizinhos(int x,int y,char tipoDeVizinho)
{
    int qntVizinhos=0;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            try
            {
                if(m[i+x][j+y]==tipoDeVizinho)
                    qntVizinhos++;
            }catch(int e){};
        }
    }
    return qntVizinhos-1;
}
void aquelaRebolada(char morena,int chance)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(m[i][j]==morena && checaVizinhos(i,j,morena)<=7)
            {
                if(random(100)<chance)
                {
                    m[i][j]=agua;
                }
            }
        }
    }
}
void createIsland(int x,int y,int tamX,int tamY)
{
        for(int i =0;i<tamX;i++)
        {
            for(int j =0;j<tamY;j++)
            {
                try
                {
                    m[i+x][j+y]=terra;
                }catch(int e){}
            }
        }
}
void printIsland()
{
    for(int i =0;i<tam;i++)
    {
        for(int j =0;j<tam;j++)
        {
            if(m[i][j]==terra)
            {
                printf("%c[%dm", 0x1B,41);
            }
            if(m[i][j]==agua)
            {
                printf("%c[%dm", 0x1B,44);
            }
            cout << "  ";
        }
        cout << "\n";
    }  
}

int main(int argc, char** argv) 
{
    srand(time(NULL));
    fillIsland();
    for(int i=0;i<random(10);i++)
    {
        try
        {
            createIsland(random(tam),random(tam),random(tam),random(tam));
            aquelaRebolada(terra,80);
        }catch(int e){}
    }
    printIsland();
    return 0;
}

