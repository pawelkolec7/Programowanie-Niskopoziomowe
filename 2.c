#include <stdio.h>

int main() {
    int n, m, i, j;
    double R = 0.0;
    
    printf("Podaj wartość n: ");
    scanf("%d", &n);
    
    printf("Podaj wartość m: ");
    scanf("%d", &m);
    
    for (i = 1; i <= n; i++) {
        double product = 1.0;
        for (j = 1; j <= m; j++) {
            product *= (i*i + j*j - 1) / (2.0*i + 3.0*j + 4.0);
        }
        R += product;
    }
    
    printf("Wartość sumy iloczynów wynosi: %lf\n", R);
    
    return 0;
}
