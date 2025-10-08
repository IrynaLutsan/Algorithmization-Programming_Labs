#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void fill_arr_rnd(int *arr, int arr_len, int min, int max){

    for (int i = 0; i < arr_len; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return;
}

void print_arr(int *arr, int arr_len) {
    for (int i = 0; i < arr_len; i++){
    printf("%d ", arr[i]);
    }
    printf("\n");
}

int count_negative(int *arr, int arr_len){
    int count = 0;
    for (int i = 0; i < arr_len; i++){
        if (arr[i] < 0){
            count++;
        }
    }
    return count;
}
