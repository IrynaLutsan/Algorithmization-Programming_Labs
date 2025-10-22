#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN -5000
#define MAX 5000

void fill_arr_rnd(long *arr, int arr_len, long min, long max){

    for (int i = 0; i < arr_len; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void print_arr(long *arr, int arr_len){
    for(int i = 0; i < arr_len; i++){
        printf("%ld ", arr[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int arr_size;
    printf("Введіть розмір масиву: ");
    scanf("%d", &arr_size);
    long* arr = (long*)malloc(arr_size * sizeof(long));

    fill_arr_rnd(arr, arr_size, MIN, MAX);
    print_arr(arr, arr_size);
    free(arr);

    return 0;
}
