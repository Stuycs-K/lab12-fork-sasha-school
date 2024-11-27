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
        srand( time(NULL) ); //seed
        int random1;
        random1 = rand()%5+1;
        printf("%d %d sec\n",getpid(),random1);
        sleep(random1);
        printf("%d finished after %d sec\n",getpid(),random1);
        return random1; // return secs
    }
    else {
        p2 = fork();
        if (p2==0){
            srand( time(NULL) +1); //re-seed
            int random1;
            random1 = rand()%5+1;
            printf("%d %d sec\n",getpid(),random1);
            sleep(random1);
            printf("%d finished after %d sec\n",getpid(),random1);
            return random1;  //return secs
        }
        else{
            int status1;
            pid_t child;
            child = wait(&status1);
            printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), child, WEXITSTATUS( status1 )); //use return status

        }
    }
    
}
