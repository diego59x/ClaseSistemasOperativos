#include <stdio.h>
#include <unistd.h>
#include <time.h>


int main() {

    pid_t pid1;
    pid1 = fork();
    if (pid1 == 0 ) {
        for (int i = 0; i < 4000000; i++) {
            printf(" a a %d \n ", i);
        }
    } else {
        while(1){}
    }


    return (0);
}