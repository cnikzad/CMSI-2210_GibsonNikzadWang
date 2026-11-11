#include <stdio.h>
#include <time.h>

static void waitForEnter(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}
 
int main(void)
{
    time_t startTime, endTime;
    double elapsed;
    int minutes, seconds;
 
    printf("This program will time how long you can hold your breath!\n");
    printf("Take a deep breath, then press the 'Enter' key.\n");
    printf("When you have to exhale, press the 'Enter' key again.\n");
    printf("The duration you were able to hold your breath will be displayed in minutes and seconds.\n\n");
 
    printf("Press Enter when you are ready to start...");
    fflush(stdout);
    waitForEnter();
 
    startTime = time(NULL);         
    printf("Timer started! Hold your breath... press Enter to stop.");
    fflush(stdout);
    waitForEnter();
 
    endTime = time(NULL);          
 
    elapsed = difftime(endTime, startTime);   
    minutes = (int)elapsed / 60;
    seconds = (int)elapsed % 60;
 
    printf("\nYou held your breath for %d minute%s and %d second%s.\n",
           minutes, minutes == 1 ? "" : "s",
           seconds, seconds == 1 ? "" : "s");
 
    return 0;
}
 