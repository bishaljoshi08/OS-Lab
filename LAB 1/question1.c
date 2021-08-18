// C program to implement process system call
#include<stdio.h>
#include<time.h>
#include<sys/wait.h>
#include<unistd.h>

void delay(int number_of_milliseconds)
{
    // Converting time into micro_seconds
    int micro_seconds = 1000 * number_of_milliseconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + micro_seconds);
}

void main(){
    int id = fork();
    // fork returns 0 in child process
    if (id == 0){       
        printf("I am inside child. Where is my parent?\n");
        // total delay of 5 seconds
        for (int i = 0; i < 5; i++) {  
            // delay of one second
            delay(1000);   
            printf("%d seconds have passed\n", i + 1);
        }                       
    }
    // fork return the process id of its child in parent which is > 0 
    else if (id > 0){   
        printf("I am inside parent. Is child terminated?\n");
        wait(NULL);
        printf("I am inside parent. I have waited for child to terminate.\n");
    }
}