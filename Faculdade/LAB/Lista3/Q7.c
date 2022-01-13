#include <stdio.h>

void q4(int *v, int n);
int q5(int *x, int *y, int n);
void q6(float *x, int n);
int* q7(int *x, int y, int n);

int main(){
    int x[] = {1, 2, 3};
    int y[] = {1, 2, 3};
    int *z = q7(x, y, 3);
    for(int i = 0; i < 6; i++){
        printf("%d", z[i]);
    }
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

void q6(float *x, int n){
    int cont = 0, j = 0;

    for(int i = 0; i < n; i++){
        j = 0;
        while(j < i && x[j] != x[i]){
            j = j + 1;
        }

        if(j == i){
            cont = 1;
            for(int j = i + 1; j < n; j++){
                if(x[i] == x[j])
                    cont++;
            }
            if(cont == 1)
                printf("%.1f ocorre %d vez", x[i], cont);
            else
                printf("%.1f ocorre %d vezes", x[i], cont);
        }

        
    }
}

int* q7(int *x, int y, int n){
    int i = 0, j = 0;
    int *z = malloc(2 * n * sizeof(int));

    for(int k = 0; k < 2 * n; k++){
        if(i == n){
            z[k] = y[j];
            j++;
        }else if(j == n){
            z[k] = x[i];
            i++;
        }

        if(i < n && j < n){
            if(x[i] < y[i]){
                z[k] = x[i];
                i++;
            }else{
                z[k] = y[j];
                j++;
            }
        }
    }
    return z;
}