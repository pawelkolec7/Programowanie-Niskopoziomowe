#include <stdio.h>
#include <stdlib.h>

void wylicz_R(int n, int m, int A[][m], int B[][m], int R[][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == B[i][j]) {
                R[i][j] = 1;
            } else {
                R[i][j] = 0;
            }
        }
    }
}

void wylicz_P(int n, int m, int A[][m], int B[][m], int P[][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] > B[i][j]) {
                P[i][j] = 1;
            } else {
                P[i][j] = 0;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Podaj wymiary macierzy (n, m < 15): ");
    scanf("%d %d", &n, &m);
    if (n > 15 || m > 15) {
        printf("Błąd: wymiary macierzy muszą być mniejsze niż 15.\n");
        return 1;
    }
    int A[n][m], B[n][m], R[n][m], P[n][m];
    
    printf("Wprowadź elementy macierzy A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Podaj element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Wprowadź elementy macierzy B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Podaj element B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    
    wylicz_R(n, m, A, B, R);
    wylicz_P(n, m, A, B, P);
    
    printf("Macierz równości R:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    
    printf("Macierz przewagi P:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
