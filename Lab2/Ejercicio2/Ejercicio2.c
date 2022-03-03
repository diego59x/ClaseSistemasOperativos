#include <stdio.h>
#include <unistd.h>
#include <time.h>


int main() {

    clock_t firstClock;
    clock_t secondClock;
    double result;

    firstClock = clock();
    for(int i = 0; i < 1000000; i++){

    }
    for(int y = 0; y < 1000000; y++){
        
    }
    for(int z = 0; z < 1000000; z++){
        
    }
    secondClock = clock();

    result = (double)(secondClock - firstClock);

    printf("\n El resultado es %f \n", result);

    return(0);
}