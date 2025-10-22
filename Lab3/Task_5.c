#include <stdio.h>
#include <stdlib.h>
#define MIN (-50)
#define MAX (50)

void matrix_user_input(int *m, int d){
    int i, j;
    for (i = 0; i < d; i++) {  
        printf("Введіть %d елементів для Рядка %d: ", d, i + 1);
        for (j = 0; j < d; j++) {
            scanf("%d", (m + i *d) + j);
        }
    }
}

void fill_matrix_rnd(int *m, int d, int min, int max){

    for (int i = 0; i < d * d; i++) {
        m[i] = rand() % (max - min + 1) + min;
    }
}

void print_matrix(int *m, int d){
    int i, j;
    for (i = 0; i < d; i++) {  
        for (j = 0; j < d; j++) {
            printf("%d ", *((m + i *d) + j));
        }
        printf("\n");
    }
}

void sum_matrix(int *m1, int *m2, int d){
    int i, j;
    for (i = 0; i < d; i++) {  
        for (j = 0; j < d; j++) {
            *((m2 + i *d) + j) += *((m1 + i *d) + j);
        }
    }
}

void matrix_max(int *m1, int *m2, int *m3, int d){
    int i, j;
    for (i = 0; i < d; i++) {  
        for (j = 0; j < d; j++) {
            *((m3 + i *d) + j) = *((m1 + i *d) + j) > *((m2 + i *d) + j)? 
                                 *((m1 + i *d) + j): *((m2 + i *d) + j);

        }
    }
}


int main(){
    int matrix_demention;
    printf("Введіть розмірність квадратного масиву: ");
    scanf("%d", &matrix_demention);
    int* matrix_1 = (int*)malloc(matrix_demention * matrix_demention * sizeof(int));
    int* matrix_2 = (int*)malloc(matrix_demention * matrix_demention * sizeof(int));
    int* matrix_3 = (int*)malloc(matrix_demention * matrix_demention * sizeof(int));

    matrix_user_input(matrix_1, matrix_demention);
    //fill_matrix_rnd(matrix_1, matrix_demention, MIN, MAX);
    fill_matrix_rnd(matrix_2, matrix_demention, MIN, MAX);
    printf("Перша матриця: \n");
    print_matrix(matrix_1, matrix_demention);
    printf("Друга матриця: \n");
    print_matrix(matrix_2, matrix_demention);
    sum_matrix(matrix_1, matrix_2, matrix_demention);
    printf("Друга матриця після сумування з першою: \n");
    print_matrix(matrix_2, matrix_demention);
    matrix_max(matrix_1, matrix_2, matrix_3, matrix_demention);
    printf("Третя матриця: \n");
    print_matrix(matrix_3, matrix_demention);


    free(matrix_1);
    free(matrix_2);
    free(matrix_3);

    return 0;
}
