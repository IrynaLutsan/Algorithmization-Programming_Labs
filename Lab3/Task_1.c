#include <stdio.h>

int main() {
    int a[5][4];
    int i, j;

    for (i = 0; i < 5; i++) {  
        printf("Введіть 4 елементи для Рядка %d: ", i + 1);
        for (j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nВведений масив:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    printf("\nСума додатних непарних елементів у стовпцях:\n");
    for (j = 0; j < 4; j++) {
        int sum = 0;
        for (i = 0; i < 5; i++) {
            if (a[i][j] > 0 && a[i][j] % 2 != 0)
                sum += a[i][j];
        }
        printf("Стовпець %d: %d\n", j + 1, sum);
    }

    return 0;
}
