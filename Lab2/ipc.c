#include <stdio.h>
#include <unistd.h>

int main() { 
    int n;
    char x;
    printf("holis, ingresa un numero: \n");
    scanf("%d", &n);
    printf("holis, ingresa una letra: \n" );
    scanf(" %c", &x);


    printf("ingresaste %d , %c \n", n , x);
    return (0);
}