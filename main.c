#include <stdio.h>
#include <stdlib.h>
#define DEBUG

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
    for(int x = 0; x<i;x++){//le a coluna
        for(int  y=0; y<j;y++){//le a linha
            fscanf(file,"%d",&matriz[x][y]);//le cada valor e salva na matriz
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

void floodfill(int** matriz,int i,int j,int i_inicial,int j_inicial,int busca, int substituicao){
    matriz[i_inicial][j_inicial] = substituicao;
    if(i_inicial-1 >= 0 && matriz[i_inicial-1][j_inicial] == busca){
        floodfill(matriz,i,j,i_inicial-1,j_inicial,busca,substituicao);
    }
    if(i_inicial-1 >= 0 && j_inicial-1 >= 0 && matriz[i_inicial-1][j_inicial-1] == busca) {
        floodfill(matriz,i,j,i_inicial-1,j_inicial-1,busca,substituicao);
    }
    if(j_inicial-1 >= 0 && matriz[i_inicial][j_inicial-1] == busca){
        floodfill(matriz,i,j,i_inicial,j_inicial-1,busca,substituicao);
    }
    if(i_inicial+1 < i && j_inicial-1 >= 0 && matriz[i_inicial+1][j_inicial-1] == busca) {
        floodfill(matriz,i,j,i_inicial+1,j_inicial-1,busca,substituicao);
    }
    if(i_inicial+1 < i && matriz[i_inicial+1][j_inicial] == busca){
        floodfill(matriz,i,j,i_inicial+1,j_inicial,busca,substituicao);
    }
    if(i_inicial+1 < i && j_inicial+1 < j && matriz[i_inicial+1][j_inicial+1] == busca) {
        floodfill(matriz,i,j,i_inicial+1,j_inicial+1,busca,substituicao);
    }
    if(j_inicial+1 < j && matriz[i_inicial][j_inicial+1] == busca){
        floodfill(matriz,i,j,i_inicial,j_inicial+1,busca,substituicao);
    }
    if(i_inicial-1 >= 0 && j_inicial+1 < j && matriz[i_inicial-1][j_inicial+1] == busca) {
        floodfill(matriz,i,j,i_inicial-1,j_inicial+1,busca,substituicao);
    }
}

int main(){
    //Declaraçao de variáveis
        char arquivo[100];//vetor que armazena o nome do arquivo
        int i,j;//dimensoes da matriz
        int posInitI, posInitJ;// posicoes iniciais
        int** matriz;//matriz onde os valores serão armazenados
        FILE *file;// arquivo a ser lido
    //=========================
    //Execução
        scanf("%s",arquivo);//lê o nome do arquivo
        file = fopen(arquivo,"r");//abre o arquivo
        fscanf(file,"%d %d",&i,&j);//lê as dimensões da matriz
        matriz = lerMatriz(file,i,j);//lê a matriz
        fscanf(file,"%d %d",&posInitI,&posInitJ);//lê a posição inicial do algoritimo
        #ifdef DEBUG
            printf("%d %d",posInitI,posInitJ);
            printf("\n");
        #endif
        floodfill(matriz,i,j,posInitI,posInitJ,1,2);
        #ifdef DEBUG
            for(int x = 0; x<i; x++){
                for(int y = 0; y<j; y++){
                    printf("%d ",matriz[x][y]);
                }
                printf("\n");
            }
        #endif
    //=========================
}