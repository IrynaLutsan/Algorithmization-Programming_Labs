#include <stdio.h>

int count_chars(char *str, char chr){
    int count = 0;
    for (int i = 0; str[i] != 0; i++){
        if ( str[i] == chr){
            count++;
        }
    }
    return count;
}


int main(){
    char * arr[3] = {"Lutsano","Iryna", "Zinoviyvna"};
    printf("Прізвище: %s\nІмя: %s\nПо-батькові: %s\n", arr[0], arr[1], arr[2]);
    int cnt = count_chars(arr[0], 'o');
    printf("Кількість символів 'o' в першому рядку: %d\n", cnt);

    return 0;
}
