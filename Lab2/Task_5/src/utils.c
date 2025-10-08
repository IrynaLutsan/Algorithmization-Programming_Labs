#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int str_len(char *str){
    int len = 0;
    while (*str != 0){
        len++;
        str++;
    }
    return len;
}

int str_copy(char *dst, char *src){
    int count = 0;
    while (*src != 0){
        *dst = *src;
        dst++;
        src++;
        count++;
    }
    *dst = *src;
    return count + 1;
}

int str_cat(char *dst, char *src){
    char *end_of_dst = dst + str_len(dst);
    str_copy(end_of_dst, src);
    return str_len(dst);
}
