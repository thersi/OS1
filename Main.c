#include <stdio.h>
int main()
{
   // printf() displays the string inside quotation
   printf("Select one of the following operations:\n");
   printf("s (schedule), l (list), c (cancel), x (exit)\n");
   char chr;
   printf("Enter a character: \n");
   scanf("%c",&chr);   
   printf("you typed: %c \n", chr);
   //printf("%c", b);

   return 0;
}