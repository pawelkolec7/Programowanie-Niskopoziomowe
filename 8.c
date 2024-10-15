#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX 50

struct TablicaTowarów {
    char NazwaTowaru[50];
    int LiczbaSztuk;
    float Cena1Sztuki;
};
int main()
{
    char wybor;
    bool cont = true;
    int ile=0;
    float suma;
    struct TablicaTowarów Tab[MAX];
    while (cont) {
        printf("Wybierz opcje: [N|n – nowy towar, W|w - wyświetl wszystkie towary, R|r - oblicz sumę wartości wszystkich towarów, Q|q - koniec programu]\n");
        scanf(" %c", &wybor);
        switch (wybor & 0x5F) {
        case 'N':
            if (ile<MAX) {
                printf("Podaj nazwę towaru: ");
                scanf("%s", Tab[ile].NazwaTowaru);
                printf("Podaj liczbę sztuk towaru: ");
                scanf("%d", &Tab[ile].LiczbaSztuk);
                printf("Podaj cenę za 1 sztukę towaru: ");
                scanf("%f", &Tab[ile++].Cena1Sztuki);
            }
            else printf("Tablica jest pełna \n");
            break;
        case 'W':
        for (int i=0; i<ile; i++)
            printf("Towar %d to: %s\n", i + 1, Tab[i].NazwaTowaru);
        break;
        case 'Q': 
            cont = false;
            break;
        case 'R':
            suma=0;
            for (int i=0; i<ile; i++) {
                suma += Tab[i].Cena1Sztuki * Tab[i].LiczbaSztuk;
            }
            printf("Suma wartości wszystkich towarów %f\n", suma);
            break;
        default:
        printf("Wybrana została zła opcja\n");
        }
    }
    return 0;

}
