// Royden Contreras Vallejos
// C1226
// Este es un codigo el cual pondra a pruebas nuestros conocimientos sobre memoria
// dinamica, para la realizacion de dicho codigo deberemos seguir una serie
// de parametros que aplicaremos a continuacion. 

// Ingreso de librerias 
#include <stdio.h>
#include <stdlib.h>


// Primeramente se debe crear una funcion que reciba una cantidad N de elementos
// y un puntero de tipo double, sin embargo esta funcion debe reservar N elementos
// del tipo double y asignarlos al puntero de entrada 

int elementosN(int N, double **puntero) {
    // Reserva de N elementos de tipo double.
    *puntero = (double *)malloc(N * sizeof(double));

    // Debemos retornar un -1 si hay algun error y un 0 si no los hay, para eso:
    if (*puntero == NULL) {
        // Caso de fallo.
        return -1;
    }

    // Caso de exito.
    return 0;

} 



// Hacemos un main que primeramente asigne la cantidad N y despues depliegue la
// informacion.

int main() {
    // Ingreso de variables y cantidad N (puede ser cualquier valor).
    double *miPuntero;
    int N = 0;
    int resultado = elementosN(N, &miPuntero);

    // Imprimimos mensaje de error o exito segun la salida de nuestra variable
    // resultado
    if (resultado == 0) {
        printf("Memoria reservada exitosamente.\n");
        
        // Liberamos la memoria 
        free(miPuntero);
    } else {
        printf("Error al reservar la memoria.\n");

    }

    return 0;
}
