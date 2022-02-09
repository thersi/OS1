#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setAlarm(){ // could be boolean to return validation to main loop 
   int hrs, mins, seconds,i=0;
   printf("Enter Hours: ");
   scanf("%d",&hrs);
   printf("Enter Minute: ");
   scanf("%d",&mins);
   printf("Enter Second: ");
   scanf("%d",&seconds);

   time_t now,file;
   struct tm *date;

   /* fill the tm structure with the current date/time */
   time_t currenttime = time(NULL);
   struct tm *tm_struct = localtime(&currenttime);
   int yearnow = tm_struct->tm_year;
   int monthnow = tm_struct->tm_mon;
   int daynow = tm_struct->tm_mday;
   int hournow = tm_struct->tm_hour;
   int minnow = tm_struct->tm_min;
   int secnow = tm_struct->tm_sec;

   time(&now);
   date = localtime(&now);
   /* backfill some specific items in the date structure */
   date->tm_sec = seconds;
   date->tm_min = mins;
   date->tm_hour = hrs;
   date->tm_mday = daynow;
   if (hrs < hournow) {
      date->tm_mday = daynow + 1;
   }
   if (hrs == hournow && mins < minnow) {
      date->tm_mday = daynow + 1;
   }
   if (hrs == hournow && mins == minnow && seconds < secnow) {
      date->tm_mday = daynow + 1;
   }
   date->tm_mon = monthnow;
   date->tm_year = yearnow;
   /* convert the structure to a time_t value */
   file = mktime(date);
    
   /* output results */
   printf("Timer set at %s\n",ctime(&file));

   //add alarm to data structure of alarms
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
   time_t t = time(NULL);
   printf("UTC:       %s", asctime(localtime(&t)));
   
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