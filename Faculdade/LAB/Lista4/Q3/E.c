#include <stdio.h>
#include <stdlib.h>

int q1(int **A, int m, int n);
int q2a(int **M, int n);
void q2b(int n);
void q3a(int **A, int n, int k);
int q3b(int **A, int n);
int q3c(int **A, int n, int k);
int q3d(int **A, int n);
int q3e(int **A, int n);

int main(){
    int **A, i, j;

    A = (int**)malloc(4 * sizeof(int*));
    for(int i = 0; i < 4; i++)
        A[i] = (int*)malloc(4 * sizeof(int));
    
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            A[i][j] = 0;
    
    printf("\n");
    printf("%d \n", q1(A, 4, 4));
    printf("q2a: %d \n", q2a(A, 4));
    q2b(4);
    
    A[0][1] = 1;
    A[1][2] = 1;
    A[2][0] = 1;
    A[3][3] = 1;
    A[2][3] = A[3][2] = 1;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    q3a(A, 4, 2);
    printf("%d\n", q3b(A, 4));
    printf("%d", q3c(A, 4, 1));
    printf("%d\n", q3d(A, 4));
    printf("%d\n", q3e(A, 4));

    return 0;
}

int q1(int **A, int m, int n){
    int  cont0, cont1;

    printf("q1: ");
    for(int i = 0; i < m; i++){
        cont0 = 0;
        cont1 = 0;
        for (int j = 0; j < n; j++){
            if(A[i][j] == 0)
                cont0++;
            if(A[i][j] == 1)
                cont1++;
        }
        if(cont0 != n - 1 || cont1 != 1)
            return 0;
    }

    for(int j = 0; j < m; j++){
        cont0 = 0;
        cont1 = 0;
        for (int i = 0; i < n; i++){
            if(A[i][j] == 0)
                cont0++;
            if(A[i][j] == 1)
                cont1++;
        }
        if(cont0 != m - 1 || cont1 != 1)
            return 0;
    }
}

int q2a(int **M, int n){
    int s = 0, s1 = 0, i, j;

    for(i = 0; i < n; i++)
        s = s + M[i][j];

    for(j = 0; j < n; j++)
        s1 = s1 + M[i][n - j - 1];

    if(s != s1)
        return 0;

    for(i = 0; i < n; i++){
        s1 = 0;
        for(j = 0; j < n; j++){
            s1 = s1 + M[i][j];
        }
        if(s != s1)
            return 0;
    }

    for(j = 0; j < n; j++){
        s1 = 0;
        for(i = 0; i < n; i++){
            s1 = s1 + M[i][j];
        }
        if(s != s1)
            return 0;
    }
    return 1;
}

void q2b(int n){
    int **A, i, j;

    printf("q2b: \n");
    A = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < 4; i++)
        A[i] = (int*)malloc(n * sizeof(int));
    
    do{
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                A[i][j] = rand() % 4;
    }while(q2a(A, n) != 1);
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%d ");
        printf("\n");
    }
}

void q3a(int **A, int n, int k){
    int contl = 0, contc = 0;
    printf("q3a: ");

    for(int i = 0; i < n; i++){
        contl = contl + A[k][i];
        contc = contc + A[i][k];
    }
    printf("%d saem %d e chegam %d", k, contl, contc);
}

int q3b(int **A, int n){
    int i, j, s = 0, s1 = 0, cid = 0;

    printf("\nq3b: ");
    for(i = 0; i < n; i++)
        s = s + A[i][0];
    
    for(j = 1; j < n; j++){
        s1 = 0;
        for(i = 0; i < n; i++)
            s1 = s1 + A[i][j];
        if(s1 > s){
            s = s1;
            cid = j;
        }
    }
    return cid;
}

int q3c(int **A, int n, int k){
    printf("\nq3c: ");
    for(int j = 0; j < n; j++)
        if(A[k][j] != A[j][k])
            return 0;
    return 1;
}

int q3d(int **A, int n){
    int contl = 0, contc = 0, cont = 0;
    printf("q3d: \n");

    for(int k = 0; k < n; k++){
        contl = 0; contc = 0;
        for(int i = 0; i < n; i++){
            contl = contl + A[k][i];
            contc = contc + A[i][k];
        }
        if(contl == 1 && contc == 1)
            cont++;
    }
    return cont;
}

int q3e(int **A, int n){
    int contl = 0, cont = 0;
    printf("q3e: \n");

    for(int k = 0; k < n; k++){
        contl = 0;
        for(int i = 0; i < n; i++){
            contl = contl + A[k][i];
        }
        if(contl == 1)
            cont++;
    }
    return cont;
}