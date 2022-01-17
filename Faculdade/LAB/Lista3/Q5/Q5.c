#include <stdio.h>

void q4(int *v, int n);
int q5(int *x, int *y, int n);

int main(){
    int x[] = {1, 2, 3};
    int y[] = {1, 2, 3};
    printf("prod = %d\n", q5(x, y, 3));
    return 0;
}

void q4(int *v, int n){
    int max = v[0], min = v[0];

    for(int i = 0; i < n; i++){
        if(v[i] > max)
            max = v[i];
        if(v[i] < min)
            min = v[i];
    }
    printf("max = %d\n", max);
    printf("min = %d", min);
}

int q5(int *x, int *y, int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s = s + x[i] * y[i];
    }
    return s;
}