// Royden Contreras Vallejos 
// C12260
// Este sera un programa el cual le ingresemos una fecha, este debera verificar
// que la informacion sea correcta y una vez haya hecho eso, deplegara 
// la informacion ingresada 

#include <stdio.h>

int main() {
    // Declaracion de variables
    int dia;
    int mes;
    int año;

    // Solicitud al usuario que ingrese la fecha
    printf("Ingrese el dia, el mes (numero) y el año: ");

    // Lectura de la fecha usando scanf
    int fecha = scanf("%d-%d-%d", &dia, &mes, &año);

    printf("Numero de elementos leidos: %d\n", fecha);

    // Verificador de elementos
    if (fecha == 3) {
        // Verificación de las restricciones
        if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
            printf("Error: El dia debe estar entre 1 y 31 y el mes entre 1 y 12.\n");
        } else {
            // Conversión de número a mes
            if (mes == 9) {
                printf("La fecha es: %d de septiembre de %d\n", dia, año);
            } else if (mes == 10) {
                printf("La fecha es: %d de octubre de %d\n", dia, año);
            } else if (mes == 11) {
                printf("La fecha es: %d de noviembre de %d\n", dia, año);
            } else if (mes == 12) {
                printf("La fecha es: %d de diciembre de %d\n", dia, año);
            } else {
                printf("El mes ingresado no es válido para mostrar.\n");
            }
        }
    } else {
        printf("Error: No se pudieron leer todos los elementos correctamente.\n");
    }

    return 0;
}