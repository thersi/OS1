#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>


struct alarm { // alarm-structure to assign data and store in an array
   int alarm_id; 
   time_t time; 
   pid_t childPid;
   int pidNumber;
};

int zombies = 0; // integer to keep track of zombies to kill
int idCount = 0; // integer to keep track of what id an alarm should get
int numOfElems = 0; // integer to keep track of number of alarms added to the alarm-array
int spaceLeft = 100; // integer to keep track if all spaces in array is taken
struct alarm alarms[100]; // array to keep the alarms


void setAlarm(){ 
   // checks if array is full and refuses input if no space left
   if (spaceLeft == 0) {
      printf("No more space for alarms:(");
      return;
   }

   // scans input and validates it to set an alarm at chosen time & date
   int year, month, day, hrs, mins, seconds,i=0;
   printf("Enter Year: ");
   scanf("%d",&year);
   while (year < 2022) {
      printf("Cannot enter year in the past.\n");
      printf("Enter Year: ");
      scanf("%d",&year);
   }
   printf("Enter Month: ");
   scanf("%d",&month);
   while (month < 1 || month > 12) {
      printf("Enter month between 1 and 12.\n");
      printf("Enter Month: ");
      scanf("%d",&month);
   }
   printf("Enter Day: ");
   scanf("%d",&day);
   while (day < 1 || day > 31) {
      printf("Enter day between 1 and 31.\n");
      printf("Enter Day: ");
      scanf("%d",&day);
   }
   printf("Enter Hours: ");
   scanf("%d",&hrs);
   while (hrs < 0 || hrs > 23) {
      printf("Enter hours between 00 and 23.\n");
      printf("Enter Hours: ");
      scanf("%d",&hrs);
   }
   printf("Enter Minute: ");
   scanf("%d",&mins);
   while (mins < 0 || mins > 59) {
      printf("Enter minutes between 0 and 59.\n");
      printf("Enter Minute: ");
      scanf("%d",&mins);
   }
   printf("Enter Second: ");
   scanf("%d",&seconds);
   while (seconds < 0 || seconds > 59) {
      printf("Enter seconds between 0 and 59.\n");
      printf("Enter Second: ");
      scanf("%d",&seconds);
   }

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
   struct alarm a;
   a.time = file;
   a.alarm_id = idCount++;
   a.childPid = pid;
   a.pidNumber = getpid(); 
   alarms[numOfElems] = a; 
   numOfElems++;
   spaceLeft--;
   //printf("new child has pid %d", pid);

   if (pid == 0) {
      sleep(difftime(file, currenttime));
      printf("\nRIIIIING\n");
      int p = getpid();

      // sounding the alarm ringtone: 
      char *ringtonePath = "resources/ringtone.mp3";
      char *exPath;
      // playing the ringtones, based on the users OS 
      #if __linux__ 
      exPath = "/usr/bin/mpg123";
      execl(exPath, exPath, ringtonePath, (char *)NULL);
      #elif __APPLE__
      exPath = "/usr/bin/afplay";
      execl(exPath, exPath, ringtonePath, (char *)NULL);
      #elif __unix__
      exPath = "/usr/bin/mpg123";
      execl(exPath, exPath, ringtonePath, (char *)NULL);
      #elif _WIN32
      printf("No rintone available for windows users :'( "); 
      #endif

      //Killing the process after ringing
      kill(p, 2);
      exit(3);

    }
   /* output results */

   printf("\nTimer set at %s",ctime(&file));

   return;
}


void deleteAlarm(){ 
   int number;
   printf("Type the number of the alarm you want to cancel: "); 
   scanf("%d", &number);
   
   for (int i = 0; i < numOfElems; i++) {
      if (alarms[i].alarm_id == number){
         kill(alarms[i].childPid, 2); // kills child process
         zombies++; // one more zombie to kill
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

void listAlarms(){ 
   time_t t = time(NULL);
   printf("\n%-20s %-10s\n", "UTC:",  asctime(localtime(&t)));
   if (numOfElems == 0){
      
      printf("No active alarms to show\n");
      return;
   }
   printf("%-20s %-10s\n", "Alarm ID", "Time");
   printf("------------------------------------------------------\n");
   for (int i = 0; i < numOfElems; i++)
   {
      if (&alarms[i] != NULL){ // displayes all alarms in the array
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

      if (numOfElems >0){ // removes alarms that have rung from the displayed list
         time_t currenttime = time(NULL);
         struct tm *tm_struct = localtime(&currenttime);
         for (int i = 0; i < numOfElems; i++) {
            if (difftime(alarms[i].time, currenttime) <= 0){ // checks that the alarm in the list is in the past, and removes it if so
               for(int j=i; j < numOfElems; j++) {
                  alarms[j] = alarms[j + 1];
               }
               i--;
               numOfElems--;
               zombies++; // counts one zombie that needs to be killed
            }
         }
      }

      while (zombies > 0) {
         waitpid(-1, NULL, WNOHANG); // kills all registered zombies
         zombies--;
      }
      
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

         // input doesn't match any option
         default:
            printf("Error! operator is not correct\n");
            break;
      }
   }

   return 0;
}