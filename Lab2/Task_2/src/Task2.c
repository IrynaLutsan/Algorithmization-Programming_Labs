/*  Розробіть програму, яка виконує задані обчислення та виводить 
на екран масив і результат обчислення.

Заповніть масив цілих чисел випадковими числами від -40 до 40
та обчисліть кількість відʼємних чисел. Розмір масиву 15. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define ARR_SIZE 15


int main() {
    srand(time(NULL));

    int arr[ARR_SIZE];
    int arr_len = ARR_SIZE;
    int min = -40, max = 40;
    fill_arr_rnd(arr, arr_len, min, max);
    print_arr(arr, arr_len);

    int result = count_negative(arr, arr_len);
    printf("Count of negative elements: %d\n", result);

    return 0;
}
