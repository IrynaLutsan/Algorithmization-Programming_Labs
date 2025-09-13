//Введіть номер місяця та виведіть одне з відповідних повідомлень: "Осінній семестр", "весняний семестр", "Канікули".
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>

int main()
{
    int a;
    puts("Enter a number of month:");
    scanf("%d", &a);

    switch(a) {  
        case 1:
        case 2:
        case 6:  
        case 7:
        case 8:
        case 12:
            printf("Holydays!\n");
            break;
        case 3:  
        case 4:
        case 5: 
            printf("Spring semester\n");
            break;
        case 9:  
        case 10:
        case 11:
            printf("Autumn semester\n");
            break;
        default: printf("Error! such a month does not exist\n");
    }
    return 0;
}