#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    //...
    struct no *esq;
    struct no *dir;
}NO;

NO* raiz = NULL;

void in_ordem(NO* pt){
    if(pt->esq != NULL){
        in_ordem(pt->esq);
    }
    printf("\n%d ", pt->chave);
    //qualquer processamento! Ex: imprimindo
    if(pt->dir != NULL){
        in_ordem(pt->dir);
    }
}


NO* busca_arvore (int x, NO* pt){
    if(pt == NULL){
        return NULL; //vazia :D
    }else if(x == pt->chave){
        return pt; // encontrei :D
    }else if(x < pt->chave){ //lado esq
        if(pt->esq == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->esq);
        }
    }else { //lado dir
        if(pt->dir == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->dir);
        }
    }
}

void insercao_arvore(int x){
    NO* pt = busca_arvore(x, raiz); // usa a busca para encontrar
                                // a posicao do no novo
    if(pt == NULL || pt->chave != x){
        NO* novo = (NO*) malloc (sizeof(NO));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(pt == NULL){ //vazia - raiz
            raiz = novo;
        }else if(x < pt->chave){ //elemento x <pt-> chave - esq
            pt->esq = novo;
        }else{                  //elemento x >pt-> chave - dir
            pt->dir = novo;
        }
    }else{
        printf("insercao invalida! :/");
    }
}

//REMOCAO...


int main(){

    insercao_arvore(10);
    insercao_arvore(3);
    insercao_arvore(20);
    insercao_arvore(15);
    insercao_arvore(25);
    insercao_arvore(18);
    in_ordem(raiz);
    return 0;
}
