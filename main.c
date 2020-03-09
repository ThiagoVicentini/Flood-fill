#include <stdio.h>
#include <stdlib.h>

void lerMatriz(FILE *file,int i, int j){
    allocMatriz(i,j);
    int value;
    for(int x =0; x<j;x++){
        for(int x =0; x<i;x++){
            fscanf(file,"%d",&value);
            printf("%d ",value);
        }
    }
}

void allocMatriz(int i, int j){
    
}


int main(){
    char arquivo[100];//        printf("\n"); vetor que armazena o nome do arquivo
    int i,j;//dimensoes da matriz
    FILE *file;// arquivo a ser lido
    scanf("%s",arquivo);//lê o nome do arquivo
    file = fopen(arquivo,"r");//abre o arquivo
    fscanf(file,"%d %d",&i,&j);//lê as dimensões da matriz
    lerMatriz(file,i,j);//lê a matriz
    fscanf(file,"%d %d",&i,&j);//lê a posição inicial do algoritimo
}