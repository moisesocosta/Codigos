#include <stdio.h>

int itemA(int n){
    int cont = 0;

    if(n == 0){
        return 1;
    }

    while(n != 0){
        n = n / 10;
        cont = cont + 1;
    }
    return cont;
}

int itemB(int n, int d){
    int cont = 0;

    if(n == 0 && d == 0)
        return 1;
    
    while(n != 0){
        if(n % 10 == d)
            cont++;
        n = n / 10;
    }
    return cont;
}

int itemC(int x, int y){
    for(int i = 0; i <= 9; i++){
        if(itemB(x, i) != itemC){
            return 0;
        }
    }

    return 1;
}

int itemD(int x, int y){
    if(x > y){
        return 0;
    }

    while(x != 0){
        if(x % 10 != y % 10)
            return 0;
        x = x / 10;
        y = y / 10;
    }
    return 1;
}

int main(){
    printf("%d \n", itemD(0, 121));
    return 0;
}