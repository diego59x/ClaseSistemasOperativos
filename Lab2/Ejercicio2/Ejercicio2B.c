#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    pid_t pid1;
    pid_t pid2;
    pid_t pid3;

    clock_t firstClock;
    clock_t secondClock;
    double result;

    firstClock = clock();

    pid1 = fork();
    if ( pid1 == 0 ){

        pid2 = fork();
        if (pid2 == 0) {
            pid3 = fork();
            
            if (pid3 == 0) {
                for(int i = 0; i < 1000000; i++){
                }
            }
        } else {
            for(int y = 0; y < 1000000; y++){
            } 
            wait(NULL);
        }
        
    } else {
        for(int z = 0; z < 1000000; z++){
        } 
        wait(NULL);

        secondClock = clock();

        result = (double)(secondClock - firstClock);

        printf("\n El resultado es: %f \n", result);

    }
    


    return(0);
}