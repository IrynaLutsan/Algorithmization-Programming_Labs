#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int main() {
    char msg1[256], msg2[256], msg3[512];
    printf("Введіть назву предмету, та ім'я викладача:\n");
    //scanf("%255s", msg1);
    gets(msg1);
    
    printf("Введіть дату консультації:\n");
    //scanf("%255s", msg2);
    gets(msg2);

    str_copy(msg3, msg1);
    int len = str_cat(msg3, msg2);
    printf("%s(%d)\n", msg3, len);

    return 0;
}
