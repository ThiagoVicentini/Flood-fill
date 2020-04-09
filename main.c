#include <stdio.h>
#include <stdlib.h>
#define DEBUG

int** allocMatriz(int i, int j){//aloca dinamicamente uma matriz de dimensoes i,j
    int** matriz;
    matriz = (int**)malloc (i * sizeof(int *));
    for (int x = 0; x < i; x++){
        matriz[x] = (int*)malloc (j * sizeof (int));
    }
    return matriz;
}

int** lerMatriz(FILE *file,int i, int j){
    int** matriz = allocMatriz(i,j);//recebe a matriz
    for(int x = 0; x<i;x++){//le a linha
        for(int  y=0; y<j;y++){//le a coluna
            fscanf(file,"%d",&matriz[x][y]);//le cada valor e salva na matriz
        }
    }
    return matriz;//retorna matriz completa
}

int floodfill(int** matriz,int i,int j,int i_inicial,int j_inicial,int busca, int substituicao){
    int cont = 0;
    if(matriz[i_inicial][j_inicial] == busca) {
        matriz[i_inicial][j_inicial] = substituicao;
        cont++;
        if(i_inicial-1 >= 0) {
            cont +=floodfill(matriz,i,j,i_inicial-1,j_inicial,busca,substituicao);
        }
        if(i_inicial-1 >= 0 && j_inicial-1 >= 0) {
            cont +=floodfill(matriz,i,j,i_inicial-1,j_inicial-1,busca,substituicao);
        }
        if(j_inicial-1 >= 0){
            cont +=floodfill(matriz,i,j,i_inicial,j_inicial-1,busca,substituicao);
        }
        if(i_inicial+1 < i && j_inicial-1 >= 0) {
            cont +=floodfill(matriz,i,j,i_inicial+1,j_inicial-1,busca,substituicao);
        }
        if(i_inicial+1 < i){
            cont +=floodfill(matriz,i,j,i_inicial+1,j_inicial,busca,substituicao);
        }
        if(i_inicial+1 < i && j_inicial+1 < j) {
            cont +=floodfill(matriz,i,j,i_inicial+1,j_inicial+1,busca,substituicao);
        }
        if(j_inicial+1 < j){
            cont +=floodfill(matriz,i,j,i_inicial,j_inicial+1,busca,substituicao);
        }
        if(i_inicial-1 >= 0 && j_inicial+1 < j) {
            cont +=floodfill(matriz,i,j,i_inicial-1,j_inicial+1,busca,substituicao);
        }
    }
    return cont;
}

void mostra_indices(int** matriz, int i, int j, int i_inicial, int j_inicial, int sub){
    for(int x = i_inicial; x < i-1; x++)
        for(int y = j_inicial; y < j-1; y++) //percorre a matriz procurando pelos nodos alterados
            if(matriz[x][y] == sub)
                printf("%d %d\n", x, y);
}

void freeMatriz(int **matriz, int i){//percorre todos os espaços alocados liberando-os
  for(int x = 0; x < i; x++){
    free(matriz[x]);
  }
  free(matriz);
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
        int cont = floodfill(matriz,i,j,posInitI,posInitJ,matriz[posInitI][posInitJ],2);//aplica o algoritmo e altera os valores de borda para 2
        printf("Total: %d\n",cont);
        mostra_indices(matriz,i,j,posInitI,posInitJ, 2);//procura pelos nodos alterados e printa-os na tela com complexidade O(n²)
    //=========================
    //Finalização
        fclose(file);
        freeMatriz(matriz,i);
    //=========================
}
