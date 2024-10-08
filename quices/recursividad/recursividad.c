// Royden Contreras Vallejos
// C12260
// Este programa usara la recursividad para calcular la potencia de un numero 
// Este numero esta compuesto por los ultimos numeros del carnet, siendo a = 6
// y b = 0, debido a que este ultimo es cero vamos a obtar por seleccionar otros
// numeros de carne, por lo que a = 2 y b = 6


// Introduccion de libreria. 
#include <stdio.h>

// Función recursiva para calcular la potencia
int potencia(int a, int b) {
    // Caso base: Este caso se da si b = 0, esta condicion se pone debido a que
    // cualquier numero elebado a la cero es 1. 
    if (b == 0) {
        return 1;
    }
    // Caso recursivo: este caso se da cuando b > 0, si esto se cumple debemos
    //cumplir lo siguiente: a^b = a * a^(b-1)
    return a * potencia(a, b - 1);
}

int main() {
    // Introduccion de variables
    int a = 2; 
    int b = 6;

    // Llamamos a la función potencia y mostramos el resultado
    printf("%d elevado a %d es %d\n", a, b, potencia(a, b));

    return 0;
}