#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//NOTE: genreally, need to implement error catching for faulty user input

struct alarm {
   int alarm_id; // !PLACEHOLDER! should maybe be PID of responsible child process. CHANGE LATER (use fork when initiating?)
   // should also have a ringtone or something here. 
   time_t time; 
};

int idCount = 0;
int numOfElems = 0;
struct alarm alarms[100]; //maximum of 100 alarms. Maybe better to have infinite, dunno if possible 
//#define NUM(alarms) (sizeof(alarms) / sizeof(alarms[0])) //trying to dynamically determine length of 



void setAlarm(){ // could be boolean to return validation to main loop 
   //TAKE DATE AS INPUT TOO? 

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

   //create a alarm structure and add it to array of structs
   struct alarm a;
   a.time = file;
   a.alarm_id = idCount++;
   alarms[numOfElems] = a; 
   numOfElems++;
   
   
    
   /* output results */
   printf("\nTimer set at %s",ctime(&file));
}

void deleteAlarm(){ // could be boolean to return validation to main loop 
   int number;
   printf("Type the number of the alarm you want to cancel: "); 
   scanf("%d", &number);
   
   for (int i = 0; i < numOfElems; i++) {
      if (alarms[i].alarm_id == number){
         for(int j=i; j<numOfElems; j++) {
            alarms[j] = alarms[j + 1];
         }
         printf("\nAlarm %d deleted \n", number);
         numOfElems--;
         return; 
      }
      
   }
   printf("\nNo alarm with the id %d exists\n", number);
}

void listAlarms(){ // could be boolean to return validation to main loop 
   time_t t = time(NULL);
   printf("\n%-20s %-10s\n", "UTC:",  asctime(localtime(&t)));
   printf("%-20s %-10s\n", "Alarm ID", "Time");
   printf("------------------------------------------------------\n");
   for (int i = 0; i < numOfElems; i++)
   {
      if (&alarms[i] != NULL){
         printf("%-20d %-10s \n", alarms[i].alarm_id, ctime(&alarms[i].time));
         
      }
   }

}


int main()
{
  //THIS FOR SOME REASON RUNS ONE EXTRA TIME WITHOUT TAKING INPUT. SUGGESTIONS? 
   while (1) //needs different logic than this maybe 
   {
      printf ("\n======================================================\n");
      printf("Select one of the following operations:\n");
      printf("s (schedule) | l (list) | c (cancel) | x (exit)\n");
      printf ("======================================================\n");
      char chr;
      printf("Enter a character: ");
      scanf("%s", &chr);
      
      
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
            printf("\nGood bye\n");
            exit(0);

         // operator doesn't match any option
         default:
            printf("Error! operator is not correct\n");
            break;
      }
   }

   return 0;
}