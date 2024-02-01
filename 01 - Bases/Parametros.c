#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    
    /* 
        argc es el contador de parámetros:
        El nombre del ejecutable es el primer parámetros siempre. 
        argv es el vector con todos los parámetros.
        Ej: En la ejecución ./program p1 p2 p3 p4
            argc = 5
            argv = {program, p1, p2, p3, p4}
    */

    float num1, num2;
    for (int i=0; i < argc; i++){
        printf("%s\n", argv[i]);
    }  
    
    /*
    atof para retornar float
    atoi para retornar entero
    */
    num1 = atof(argv[1]);
    num2 = atof(argv[2]);
    printf("Resultado: %f\n", num1 + num2);
    return 0; 
}