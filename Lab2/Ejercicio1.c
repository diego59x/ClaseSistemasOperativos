#include <stdio.h>
#include <unistd.h>

int main(){

    fork();
    fork();
    fork();
    fork();
    // Para validar las creaciones de los fork 
    // Hice un print de este texto
    // Asi sabre cuantos hijos se crearon
    printf("Holas \n");
    return (0);
}
