#include <stdio.h>
#include <unistd.h>
#include <time.h>


int main() {

    clock_t firstClock;
    clock_t secondClock;
    double result;

    firstClock = clock();
    for(int i = 0; i < 1000000; i++){
        printf("\n Ciclo 1 %d \n", i);
    }
    for(int y = 0; y < 1000000; y++){
        printf("\n Ciclo 2 %d \n", y);
        
    }
    for(int z = 0; z < 1000000; z++){
        printf("\n Ciclo 3 %d \n", z);
        
    }
    secondClock = clock();

    result = (double)(secondClock - firstClock) / CLOCKS_PER_SEC;

    printf("\n El resultado es %f \n", result);

    return(0);
}