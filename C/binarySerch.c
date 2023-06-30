#include <stdio.h>

void preencheLista(int *lista, int sizeLista){ 
    for(int i = 0; i < sizeLista; i++){       
        lista[i] = i + 1;
    }
}

int search(int *lista, int numero, int baixo, int alto){
    int meio = (baixo + alto) / 2;
    while(baixo <= alto){
        meio = (baixo + alto) / 2;
        if(lista[meio] == numero){
            return meio;
        }
        if(lista[meio] < numero){
            baixo = meio + 1;
        }else{
            alto = meio - 1;
        }
    }
    return -1;
}

int main(){
    int lista[100];

    preencheLista(lista, 100);

    int tamArray = sizeof(lista)/sizeof(lista[0]);
    int baixo = 0;
    int alto = tamArray -1;

    printf("%d\n", search(lista, 73, baixo, alto));
}