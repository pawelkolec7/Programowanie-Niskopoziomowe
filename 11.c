#include <stdio.h>
#include <math.h>

void wyliczB_ij(double A_ij, double *B_ij) {
    if (A_ij > -1.0) {
        *B_ij = (pow(sin(A_ij), 2) - 3) / sqrt(A_ij + 1);
    } else {
        *B_ij = 3.31;
    }
}

int main() {
    int n, m, i, j;
    double A[50][50], B[50][50];
    
    printf("Podaj liczbe wierszy macierzy A: ");
    scanf("%d", &n);
    printf("Podaj liczbe kolumn macierzy A: ");
    scanf("%d", &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Podaj element A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            wyliczB_ij(A[i][j], &B[i][j]);
        }
    }
    
    printf("Macierz B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%lf ", B[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


