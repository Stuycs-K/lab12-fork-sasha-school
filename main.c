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
    p1 = fork();
    if (p1==0){
        printf("child 1 pid: %d\n",getpid());
    }
    else {
        p2 = fork();
        if (p2==0){
            printf("child 2 pid: %d\n",getpid());    
        }
        else{
            printf("parent pid: %d\n",getpid()); 
        }
    }
    
}
