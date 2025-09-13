//Введіть з клавіатури ціле число, якщо воно парне, перевірте чи є додатним, якщо - непарне, чи більше 25.

#include <stdio.h>
#include <stdlib.h>

 
int main()
{
    int x;
    puts("Input value:");
    scanf("%d", &x);

    if (x % 2 == 0) {
        if (x > 0) {
            printf("number %d is even and positive\n", x);
        }
    } else {
        if (x > 25) {
            printf("number %d is odd and greater than 25\n", x);
        } else {
        printf("number %d is odd and less than 25\n", x);
    }
    return 0;
}
}