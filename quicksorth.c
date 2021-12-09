#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particiona(int *V, int inicio, int final ){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        while(esq <= final && V[esq] <= pivo)
            esq++;

        while(dir >= 0 && V[dir] > pivo)
            dir--;

        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}



int main(){
    int i;
    int vetorai[1000];

    printf("------------------\n");
    printf(">>>>>Quick Sort<<<<<\n");
    printf("------------------\n");

    srand(time(NULL));
    for(i = 0; i < 1000; i++)
        vetorai[i] = rand();

    printf("\n\n ");

    quickSort(vetorai,0,999);

    for(i = 0; i < 1000; i++){
       printf("%d/", vetorai[i]);
    }

    printf("\n\n\n");
    
    return 0;
}
