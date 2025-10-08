 /*Розробіть програму, що сортує заданим методом одновимірний масив цілих чисел та виводить масив до і після сортування.
 1. Заповніть масив цілих чисел випадковими числами від -40 до 40
 та відсортуйте цей масив за убуванням бульбашковим методом.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#define ARR_SIZE 20


int main() {
    srand(time(NULL));

    int arr[ARR_SIZE];
    int arr_len = ARR_SIZE;
    int min = -40, max = 40;
    fill_arr_rnd(arr, arr_len, min, max);
    printf("Array before sorting:\n");
    print_arr(arr, arr_len);

    bbl_sort(arr, arr_len);
    printf("Sorted array:\n");
    print_arr(arr, arr_len);
    return 0;
}

