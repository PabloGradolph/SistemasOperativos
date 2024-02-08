#include <stdio.h>

void intercambiar(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main(){
    int a = 3, b = 5;
    printf("a = %d, b = %d\n", a, b);
    intercambiar(&a, &b);
    printf("Intercambiados -> a = %d, b = %d\n", a, b);

    return 0;
}