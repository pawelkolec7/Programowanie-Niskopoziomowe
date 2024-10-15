#include <stdio.h>

int automorficzne(int n) {
    int square = n * n;
    while (n > 0) {
        if (n % 10 != square % 10) {
            return 0;
        }
        n /= 10;
        square /= 10;
    }
    return 1;
}

int main() {
    int a, b, i, sum=0;
    printf("Potrzebny nam jest przedział <a, b>.\n");
    printf("Podaj liczbę a: ");
    scanf("%d", &a);
    printf("Podaj liczbę b: ");
    scanf("%d", &b);
    printf("Liczby automorficzne w przedziale <%d, %d> to:\n", a, b);
    for (i = a; i <= b; i++) {
        if (automorficzne(i)) {
            printf("Liczba automorficzna: %d\n", i);
            sum += 1;
        }
    }
    if (sum==0) {
        printf("Brak liczb automorficznych w przedziale <%d, %d>.\n", a, b);
    }
    return 0;
}
