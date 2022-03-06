#include <stdio.h>
#include <unistd.h>
#include <time.h>


int main() {

    pid_t pid1;
    pid1 = fork();
    if (pid1 == 0 ) {
        printf("Hilo hijo creado \n ");
    } else {
        while(1){}
    }


    return (0);
}