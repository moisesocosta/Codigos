#include<stdlib.h>
#include<stdio.h>


typedef struct no{

    int valor;
    struct no *prox;
}NO;

NO* inicio = NULL;
int cont = 0;

void add(int valor, int pos){
    if( pos <=cont){ 
        NO* novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;
        if(pos == 0 && cont == 0){ //INICIO! CONSTANTE
            inicio = novo;
            cont++;
        }else if(pos == 0){
            novo->prox = inicio;
            inicio = novo;
            cont++;
        }else if(pos == cont){
            NO* aux = inicio;
            int i;
            for(i = 0; i< cont -1; i++){
                aux = aux->prox;
            }
            aux->prox = novo;
            cont++;
            
        } // FIM!!!!!
    }
}

void imprimir(){
    NO* aux = inicio;
    int i;
    printf("LISTA 1 2 3... :D\n");
    for(i = 0; i< cont; i++){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("FIM DA LISTA  :(\n");
}


int main(){
    
    add(10,0);
    add(20,0);
    add(30,2);
    imprimir();
    return 0;
}






