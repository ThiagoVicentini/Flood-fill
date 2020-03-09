#include <stdio.h>
#include <stdlib.h>
//#define DEBUG

int** allocMatriz(int i, int j){//aloca dinamicamente uma matriz de dimensoes i,j
    int** matriz;
    matriz = (int**)malloc (i * sizeof(int *));
    for (int m = 0; m < i; m++){
        matriz[m] = (int*)malloc (j * sizeof (int));
    }
    return matriz;
}

int** lerMatriz(FILE *file,int i, int j){
    int** matriz = allocMatriz(i,j);//recebe a matriz
    int value;
    for(int y =0; y<j;y++){//le a coluna
        for(int  x=0; x<i;x++){//le a linha
            fscanf(file,"%d",&value);//le cada valor
            matriz[x][y] = value;//salva em sua respectiva casa
            #ifdef DEBUG
                printf("%d ",matriz[x][y]);
            #endif
        }
        #ifdef DEBUG
            printf("\n");
        #endif
    }
    return matriz;//retorna matriz completa
}

int main(){
    //Declaraçao de variáveis
        char arquivo[100];//vetor que armazena o nome do arquivo
        int i,j;//dimensoes da matriz
        int posInitX, posInitY;// posicoes iniciais
        int** matriz;//matriz onde os valores serão armazenados
        FILE *file;// arquivo a ser lido
    //=========================
    //Execução
        scanf("%s",arquivo);//lê o nome do arquivo
        file = fopen(arquivo,"r");//abre o arquivo
        fscanf(file,"%d %d",&i,&j);//lê as dimensões da matriz
        matriz = lerMatriz(file,i,j);//lê a matriz
        fscanf(file,"%d %d",&posInitX,&posInitY);//lê a posição inicial do algoritimo
        #ifdef DEBUG
            printf("%d %d",posInitX,posInitY);
            printf("\n");
        #endif
    //=========================
}