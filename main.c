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
    p2 = fork();
    if (p1==0){
        printf("child 1");
    }
    else if (p2==0){
        printf("child 2");
    }
    else{
        printf("parent");
    }
}
