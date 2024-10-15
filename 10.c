#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* plik_in, * plik_out;
	int*sum = NULL, *avg = NULL, *counter = NULL;
	plik_in = fopen("plik1.txt", "r");
	plik_out = fopen("plik2.txt", "w");
	if (plik_in == NULL || plik_out == NULL) {
		printf("Błąd otwarcia pliku! \n");
		return -1;
	}
	int max = 0;
	while (!feof(plik_in)) {
		char c;
		int ile = 0, current = 0;
		while (!feof(plik_in)) {
			c = fgetc(plik_in);
			if (c == 10||c==-1) {
				sum[ile - 1] += current;
				avg[ile - 1] += current;
				counter[ile - 1] += 1;
				break;
			}
			if (c == ' ') {
				sum[ile - 1] += current;
				avg[ile - 1] += current;
				counter[ile - 1] += 1;
				current = 0;
				continue;
			}
			if (c >= '0' && c <= '9') {
				if (current == 0) {
					ile++;
					current = (int)(c - '0');
				}
				else {
					current *= 10;
					current += (int)(c - '0');
				}
				if (ile > max) {
					max = ile;
					sum = (int*)realloc(sum, max * sizeof(int));
					avg = (int*)realloc(avg, max * sizeof(int));
					counter = (int*)realloc(counter, max * sizeof(int));
					sum[ile - 1] = 0;
					avg[ile - 1] = 0;
					counter[ile - 1] = 0;
				}
			}
		}
	}
	fprintf(plik_out, "\nSuma: ");
	for (int i = 0; i < max; i++)
		fprintf(plik_out, "%d ", sum[i]);
	fprintf(plik_out, "\nŚrednia: ");
	for (int i = 0; i < max; i++)
		fprintf(plik_out, "%.1f ", (float)avg[i]/counter[i]);
	fclose(plik_in);
	fclose(plik_out);
	free(sum);
	free(avg);
    free(counter);
}