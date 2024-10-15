#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void conv_A(FILE*);
void conv_B(FILE*);

int main()
{
    FILE* plik;
    plik = fopen("plik1.txt", "r+");
    char opcja;
    printf("Wybierz opcje konwersji: [A,B]\n");
    scanf("%c", &opcja);
    if (plik == NULL)
    {
        printf("Błąd otwarcia pliku\n");
        return -1;
    }
    switch (opcja & 0x5F) {
    case 'A':
        conv_A(plik);
        break;
    case 'B':
        conv_B(plik);
        break;
    default:
        printf("Wybrano złą opcje! \n");
        break;
    }
    fclose(plik);
    return 0;
}
void conv_A(FILE* plik_in)
{
	FILE* plik_out;
	plik_out = fopen("plik2.txt", "wt");
	if (plik_out == NULL)
	{
		printf("Błąd otwarcia pliku");
		return;
	}
	char c;
	int max = 0;
	int* tab = NULL;
	while (!feof(plik_in)) {
		int counter = 0;
		while (!feof(plik_in)) {
			c = fgetc(plik_in);
			if (c != '*')
				break;
			counter++;
		}
		if (counter > max) {
			max = counter;
			tab = (int*)realloc(tab, max * sizeof(int));
			tab[max - 1] = 0;
		}
		else if (counter == max) {
			tab[counter - 1] += 1;
		}
		else {
			max = counter;
			tab = (int*)realloc(tab, max * sizeof(int));
			tab[counter - 1] += 1;
		}
		for (int i = 0; i < counter-1; i++) {
			fprintf(plik_out, "%c", ' ');
		}
		for (int i = 0; i < counter; i++) {
			fprintf(plik_out, "%d.", 1 + tab[i]);
		}
		while (c!=-1)
		{
			fprintf(plik_out, "%c", c);
			if (c == '\n')
				break;
			c = fgetc(plik_in);
		}
	}
	fclose(plik_out);

}
void conv_B(FILE* plik_in)
{
	FILE* plik_out;
	plik_out = fopen("plik2.txt", "wt");
	if (plik_out == NULL)
	{
		printf("Błąd otwarcia pliku");
		return;
	}
	char c;
	int max = 0;
	int* tab = NULL;
	while (!feof(plik_in)) {
		int counter = 0;
		while (!feof(plik_in)) {
			c = fgetc(plik_in);
			if (c != '*')
				break;
			counter++;
		}
		if (counter > max) {
			max = counter;
			tab = (int*)realloc(tab, max * sizeof(int));
			tab[max - 1] = 0;
		}
		else if (counter == max) {
			tab[counter - 1] += 1;
		}
		else {
			max = counter;
			tab = (int*)realloc(tab, max * sizeof(int));
			tab[counter - 1] += 1;
		}
		for (int i = 0; i < counter-1; i++) {
			fprintf(plik_out, "%c",' ');
		}
		switch (counter-1) {
		case 0:
			fprintf(plik_out, "%c.", 'A' + tab[counter-1]);
			break;
		case 1:
			fprintf(plik_out, "%d.", 1 + tab[counter-1]);
			break;
		case 2:
			fprintf(plik_out, "%c.", 'a' + tab[counter-1]);
			break;
		case 3:
			fprintf(plik_out, "(%d)", 1 + tab[counter-1]);
			break;
		case 4:
			fprintf(plik_out, "(%c)", 'a' + tab[counter-1]);
			break;
		default:
			break;
		}
		while (c != -1)
		{
			fprintf(plik_out, "%c", c);
			if (c == '\n')
				break;
			c = fgetc(plik_in);
		}
	}
	fclose(plik_out);
}


// * Line 1
// ** Line 2
// *** Line 3
// **** Line 4
// ** Line 5
// * Line 9

