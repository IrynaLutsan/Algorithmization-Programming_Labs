//Введіть з клавіатури чотири дійсних числа. Визначте мінімальне з них і виведіть на екран 
//це число та інформацію про те, чи є воно додатнім, від’ємним або нулем.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, d;
    puts("Enter 4 real numbers:");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    printf("You entered: %f %f %f %f\n", a, b, c, d);

    float min = min_f(min_f(a, b), min_f(c, d));
    printf("Minimal Number: %f\n", min);
    if (min > 0) {
        printf("This number is Positive");
    } else if (min < 0) {
       printf("This number is Negative"); 
    } else {
        printf("This number is Zero!");
    }
    return 0;
}

          