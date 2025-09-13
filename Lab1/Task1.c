//Перевірте, чи більше 100 введене з клавіатури ціле число.
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    puts("Input number:");
    scanf("%d", &n);

    if (n > 100) {
        printf("number %d is bigger than 100\n", n);
    } else {
        printf("number %d is less than 100\n", n);
    }
    return 0;
}

