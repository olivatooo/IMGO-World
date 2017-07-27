#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostraOMundao(int mundo[40][100])
{
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(mundo[i][j]==0)
                cout << "#";
            else
                cout << "*";
        }
        cout << endl;
    }
}

void mataASede(int mundo[40][100])
{
    for(int i=0;i<40;i++)
        for(int j=0;j<100;j++)
            mundo[i][j]=0;
}

void socaIlhaNoMar(int mundo[40][100])
{
    int linha, coluna, quantidade, i, j;
    linha=rand()%30+1;
    coluna=rand()%100+1;
    int ilhazinha[linha][coluna];
    for(i=0;i<linha;i++)
        for(j=0;j<coluna;j++)
            ilhazinha[i][j]=0;
    quantidade=(linha*coluna)*((rand()%100+1)/100.0);
    while(quantidade)
    {
        do{
            i=rand()%linha;
            j=rand()%coluna;
        }while(ilhazinha[i][j]==1);
        ilhazinha[i][j]=1;
        quantidade--;
    }
    i=rand()%40;
    j=rand()%100;
    while(i+linha>=40)i--;
    while(j+coluna>=100)j--;
    for(int k=0;k<linha;k++)
        for(int l=0;l<coluna;l++)
            mundo[i+k][l+j]=ilhazinha[k][l];
}

int checaVizinhos(int mundo[40][100], int i, int j)
{
    int k, l, m=0;
    for(k=i-1;k<=i+1;k++)
        for(l=j-1;l<=j+1;l++)
            if(k!=i || l!=j)
                if(mundo[k][l]==1)
                    m++;
    if(m==3)
        return 1;
    else
        return 0;
}

void arredonda(int mundo[40][100])
{
    int i, j;
    for(i=0;i<40;i++)
        for(j=0;j<100;j++)
        {
            if(mundo[i][j]==1 && checaVizinhos(mundo,i,j))
                mundo[i][j]=0;
        }
}

int main()
{
    srand(time(NULL));
    int mundo[40][100];
    mataASede(mundo);
    for(int i=0;i<50;i++)
        socaIlhaNoMar(mundo);
    arredonda(mundo);
    mostraOMundao(mundo);
    return 0;
}
