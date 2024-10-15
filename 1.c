#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	FILE *plik;
	plik = fopen("nazwa_pliku.txt", "rt");
	int *count = malloc(sizeof(int));
	*count = 0;
	char znak;
	printf("Podaj znak, który ma zostać zliczony: ");
	scanf("%c", &znak);
	if (plik == NULL) 
	{
		printf("Błąd otwarcia pliku");
		return -1;
	}
	while (!feof(plik)) 
	{
		char a = fgetc(plik);
		if (a == znak)
			(*count)++;
	}
	printf("Liczba wystąpień znaku \"%c\" w pliku to: %d", znak, *count);
	free(count);
	fclose(plik);
	return 0;
}
