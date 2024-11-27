#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

int main(){
    pid_t p1;
    pid_t p2;
    printf("%d about to create 2 child processes\n",getpid()); 
    p1 = fork();
    if (p1==0){
        int random1;
        random1 = rand()%5+1;
        printf("%d %d sec\n",getpid(),random1);
        sleep(random1);
        printf("%d finished after %d sec\n",getpid(),random1);
    }
    else {
        p2 = fork();
        if (p2==0){
            int random2;
            random2 = rand()%5+1;
            printf("%d %d sec\n",getpid(),random2);
            sleep(random2);
            printf("%d finished after %d sec\n",getpid(),random2);
        }
        else{
            
        }
    }
    
}
