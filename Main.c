#include <stdio.h>
#include <stdlib.h>

void setAlarm(){

}

void deleteAlarm(int number){
   //DO SOMETHING HERE
   printf("Alarm %d deleted \n", number);
}

void listAlarms(){

}


int main()
{
  
   while (1) //needs different logic than this maybe 
   {
      printf ("\n======================================================\n");
      printf("Select one of the following operations:\n");
      printf("s (schedule) | l (list) | c (cancel) | x (exit)\n");
      printf ("======================================================\n");
      char chr;
      int number;
      printf("Enter a character: ");
      scanf("%c", &chr);
      
      
      switch (chr){
         case 's':
            printf("You typed s\n"); //function call here
            break;

         case 'l':
            printf("You typed l\n"); //function call here
            break;

         case 'c':
            
            printf("Type the number of the alarm you want to cancel: "); 
            scanf("%d", &number);
            deleteAlarm(number);
            break;

         case 'x':
            printf("good bye\n"); //function call here
            exit(0);

         // operator doesn't match any option
         default:
            printf("Error! operator is not correct\n");
            break;
      }
   }

   return 0;
}