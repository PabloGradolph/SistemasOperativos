#include <stdio.h>
#include <stdlib.h>

int main(){

    int *x;
    int *y;
    char *tira;

    int aux = 128;

    /* Si no inicializo los valores cambian con cada ejecución. */
    printf("La direccion de x es %p\n", x);
    printf("La direccion de y es %p\n", y);
    printf("La direccion de tira es %p\n", tira);

    x = &aux;

    /* Sale la misma dirección en x que en &aux */
    printf("La direccion de x es %p\n", x);
    printf("La direccion de aux es %p\n", &aux);

    /* Cambiamos el contenido desde el puntero o desde la variable. */
    *x = 28;
    printf("El contenido de aux es %d\n", aux);
    aux = 0;
    printf("El contenido de aux es %d\n", aux);

    /* Investigar el tema del malloc */
    /* y = int * malloc(sideof(int)); */

    printf("La direccion de y es %p\n", y);

    return 0;

}