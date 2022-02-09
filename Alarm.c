#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define _XOPEN_SOURCE
#include <time.h>


static int PID= 0;

typedef struct Alarm
{    int PID;
    time_t time;


}alarms[10];
void getTime(time_t time)
{
    FILE* fp = fopen("test.txt","w+");
    struct Alarm alarm;
    alarm.PID= PID;
    alarm.time=time;
}

void setAlarm(time_t time)
{
    Alarm alarm;
    alarm.PID= PID; //Bør finne bedre løsning på dette
    printf("Enter alarm time:");
    scanf("%zu", &(alarms[PID].time));

    if ( *PID > 10 )
    {

    }
}


int main(int argc,char* argv[])
{
    addAlarm(Alarm a, )
    struct timeval timeValue;
    time_t now = time(0);
    getTime(now);
}
