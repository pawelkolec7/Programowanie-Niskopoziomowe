#include <stdio.h>

int main() {
    int height;
    printf("Wysokość trójkąta: "); 
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height-i; j++) {
            printf(" ");
        }
        for (int l = 1; l <= 2*i-1; l++) {
            printf("X");
        }
        printf("\n");
    }

    return 0;
}
