//Розробіть програму з використанням оператору switch () , яка згідно з введеною з клавіатури першої букви виводить на скран задану повну назви 
//або повідомлення про помилку, якщо введена буква не співпадає з заданими.
//Назви 5 країн Азії.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
   char c;
   
   puts("Enter the first letter of the country (A, C, I, J, T):");
   scanf("%c", &c);

   switch(toupper(c)) {
    case 'A': printf("Afghanistan\n"); break;
    case 'C': printf("China\n"); break;
    case 'I': printf("India\n"); break;
    case 'J': printf("Japan\n"); break;
    case 'T': printf("Thailand\n"); break;
    default: printf("Error! There is no such country in the list\n");
   }
   return 0;
}
