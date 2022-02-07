#include <stdio.h>
#include <stdlib.h>

int main()
{
   // printf() displays the string inside quotation
   while (1)
   {
      printf ("\n======================================================\n");
      printf("Select one of the following operations:\n");
      printf("s (schedule) | l (list) | c (cancel) | x (exit)\n");
      printf ("======================================================\n");
      char chr;
      printf("Enter a character: ");
      scanf("%c", &chr);
      //printf("\nyou typed: %c ", chr);
      //printf("%c", b);
      
      switch (chr){
         case 's':
            printf("You typed s\n");
            break;

         case 'l':
            printf("You typed l\n");
            break;

         case 'c':
            printf("You typed c\n");
            break;

         case 'x':
            printf("good bye\n");
            exit(0);

         // operator doesn't match any option
         default:
            printf("Error! operator is not correct\n");
            break;
      }
   }

   return 0;
}