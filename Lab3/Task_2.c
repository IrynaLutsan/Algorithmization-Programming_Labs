#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 4

void fill_arr_rnd(float *arr, int rows, int cols, float min, float max){

    for (int i = 0; i < rows * cols; i++) {
        arr[i] = min + (float)rand() / RAND_MAX * (max - min);
    }
}

void print_arr(float *arr, int rows, int cols){
    int i, j;
    for (i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%5.2f ", (arr + i * cols)[j]);
        } 
        printf("\n");
    }
}

int count_bigger_than(float arr[ROWS][COLS], float val){
    int i, j;
    int count = 0;
    for (i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if (arr[i][j] > val){
               count++; 
            }
        }
    }
    return count;
}


int main() {
    srand(time(NULL));
    float arr[ROWS][COLS];
    fill_arr_rnd(&arr[0][0], ROWS, COLS, 10.5, 30.5);
    printf("Масив заповнений рандомними числами: \n");
    print_arr(&arr[0][0], ROWS, COLS);
    int count = count_bigger_than(arr, 15.5);
    printf("Кількість чисел в масиві що більші за 15.5: %d\n", count);

    return 0;
}
