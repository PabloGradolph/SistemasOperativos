#include <stdio.h>
#include <string.h>


/* Hola nombre */
int main () {

    char nombre[32];

    printf ("Escribe tu nombre: ");
    scanf("%s",nombre);

    printf ("Hola %s \n", nombre);

    return 0;

}
