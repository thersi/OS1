#include <stdio.h>
#include <stdlib.h>

void setAlarm(){ // could be boolean to return validation to main loop 
   int hrs, mins, seconds,i=0;
   printf("Enter Hours: ");
   scanf("%d",&hrs);
   printf("Enter Minute: ");
   scanf("%d",&mins);
   printf("Enter Second: ");
   scanf("%d",&seconds);

   //Validation of input here
   //create time object/variable 
   //add alarm to data structure of alarms
   printf("TIMER SET AT: %d : %d : %d ",hrs,mins,--seconds);
}

void deleteAlarm(){ // could be boolean to return validation to main loop 
   int number;
   printf("Type the number of the alarm you want to cancel: "); 
   scanf("%d", &number);
   //DO SOMETHING HERE
   // validation that number corresponds to an alarm. error if not 
   // remove alarm from data structure
   printf("Alarm %d deleted \n", number);
}

void listAlarms(){
   //List all alarms in the data structure 
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
      //int number;
      printf("Enter a character: ");
      scanf("%c", &chr);
      
      
      switch (chr){
         case 's':
            setAlarm();
            break;

         case 'l':
            listAlarms();
            break;

         case 'c':
            deleteAlarm();
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