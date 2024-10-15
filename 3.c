#include <stdio.h>

int main() {
    int a, i, j, suma_1, suma_2;
    
    printf("Podaj górną granicę przedziału: ");
    scanf("%d", &a);
    
    printf("Liczby zaprzyjaźnione w przedziale [1, %d]:\n", a);
    for (i = 1; i <= a; i++) {
        suma_1 = 0;
        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                suma_1 += j;
            }
        }
        suma_2 = 0;
        for (j = 1; j < suma_1; j++) {
            if (suma_1 % j == 0) {
                suma_2 += j;
            }
        }
        
        if (i == suma_2 && i != suma_1) {
            printf("(%d, %d)\n", i, suma_1);
        }
    }
    return 0;
}
