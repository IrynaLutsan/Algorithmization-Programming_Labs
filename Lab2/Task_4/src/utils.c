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

void bbl_sort(int *arr, int arr_len){
    
    for (int i = 0; i < arr_len - 1; i++){
        for (int j = arr_len - 1; j > i; j--){
            if (arr[j] > arr[j - 1]){
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
