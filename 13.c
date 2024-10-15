#include <stdio.h>

double avg(double* pomiary, int n);
double max(double* pomiary, int n);
double mini(double* pomiary, int n);

int main() {
    FILE* wejscie = fopen("Pomiary.txt", "r");
    if (wejscie == NULL) {
        printf("Nie udało się otworzyć pliku wejściowego.\n");
        return 1;
    }
    FILE* wyjscie = fopen("Wyniki.txt", "w");

    double (*przetwarzaj[3])(double*, int) = {avg, max, mini};

    int numer_serii, kod_przetwarzania;
    double pomiary[4];
    while (fscanf(wejscie, "%d %lf %lf %lf %lf %d", &numer_serii, &pomiary[0], &pomiary[1], &pomiary[2], &pomiary[3], &kod_przetwarzania) == 6) {
        double wynik = przetwarzaj[kod_przetwarzania](pomiary, 4);
        fprintf(wyjscie, "%d\n", numer_serii);
        fprintf(wyjscie, "%.2lf\n", wynik);
        fprintf(wyjscie, "%d\n", kod_przetwarzania);
    }

    fclose(wejscie);
    fclose(wyjscie);
    return 0;
}

double avg(double* pomiary, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += pomiary[i];
    }
    return suma / n;
}

double max(double* pomiary, int n) {
    double maks = pomiary[0];
    for (int i = 1; i < n; i++) {
        if (pomiary[i] > maks) {
            maks = pomiary[i];
        }
    }
    return maks;
}

double mini(double* pomiary, int n) {
    double min = pomiary[0];
    for (int i = 1; i < n; i++) {
        if (pomiary[i] < min) {
            min = pomiary[i];
        }
    }
    return min;
}
