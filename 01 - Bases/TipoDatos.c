#include <stdio.h>

int main() {
	int num1 = 0;
	long int num2 = 0;
	float num3 = 0.0;
	
	/* 
        %d para ints
        %ld para longs
        %f para imprimir floats
        %s para cadena de caracteres
        4.2 en int -> Ocupa 4 con precisión de 2
        .2 en float -> Imprime solo 2 decimales (suele truncar)
        Estas precisiones numero1.numero2 (numero1 -> ocupa, numero2 -> precisión)
        también sirven para cadena de caracteres.
        Signo - para empezar a escribir desde el principio y no por la izquierda.
    */
	printf("num1 es: |%4.2d|, num2 es: %ld y num3 es %.2f ... |%-5.3s|\n", num1, num2, num3, "holahola");
	
    num1 = 25;
    int num4, num5;

    printf("Dos numeros: ");
    scanf("%d, %d", &num4, &num5); /* & Para punteros.*/
    printf("num4 %d, num5 %d\n", num4, num5);
    
	return 0;
}