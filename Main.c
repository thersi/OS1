#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>



//NOTE: genreally, need to implement error catching for faulty user input

struct alarm {
   int alarm_id; 
   // should also have a ringtone or something here. 
   time_t time; 
   pid_t childPid;
   int pidNumber;
};

int idCount = 0;
int numOfElems = 0;
struct alarm alarms[100]; //maximum of 100 alarms. Maybe better to have infinite, dunno if possible 

void setAlarm(){ // could be boolean to return validation to main loop 

   int year, month, day, hrs, mins, seconds,i=0;
   printf("Enter Year: ");
   scanf("%d",&year);
   printf("Enter Month: ");
   scanf("%d",&month);
   printf("Enter Day: ");
   scanf("%d",&day);
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
   date->tm_mday = day;
   date->tm_mon = month - 1;
   date->tm_year = year - 1900;
   /* convert the structure to a time_t value */
   file = mktime(date);

   if (difftime(file, currenttime) < 0) {
      printf("Cannot set date in the past.");
      return;
   }

   //create a alarm structure and add it to array of structs
   pid_t pid = fork();
   int status;
   if (pid == 0) {
      sleep(difftime(file, currenttime));
      printf("RIIIIING\n");
      // remove the alarm from list as it has terminated 
      // DOES NOT WORK YET. ALARM SHOULD BE REMOVED FROM THE LIST
      printf("Parent is told to wait");
      int p = getpid();
      for (int i = 0; i < numOfElems; i++) {
         if (alarms[i].childPid == p) {
            for(int j=i; j<numOfElems; j++) {
               alarms[j] = alarms[j + 1];
            }
         numOfElems--;
         return;             
         }
      }
      //waitpid(pid, &status, 0);
      kill(p, 2);  
      if (wait(&status) == pid && WIFEXITED(status)){
         printf ("Exit status: %d\n", WEXITSTATUS(status));
      } 
    }
   /*else {
      waitpid(pid, &status, 0);
      printf("Waiting");
   }*/

   struct alarm a;
   a.time = file;
   a.alarm_id = idCount++;
   a.childPid = pid;
   a.pidNumber = getpid(); 
   alarms[numOfElems] = a; 
   numOfElems++;
   printf("new child has pid %d", pid);
   
    
   /* output results */
   printf("\nTimer set at %s",ctime(&file));
}


void deleteAlarm(){ // could be boolean to return validation to main loop 
   int number;
   printf("Type the number of the alarm you want to cancel: "); 
   scanf("%d", &number);
   
   for (int i = 0; i < numOfElems; i++) {
      if (alarms[i].alarm_id == number){
         kill(alarms[i].childPid, 2); 
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
   while (1)
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