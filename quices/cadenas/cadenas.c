// Royden Contreras Vallejos
// C12260
// Arrays y cadenas

#include <stdio.h>
#include <string.h>

int main() {
    // Variable que nos ayudará a contar las palabras
    int i, j;
    // Cadena limitada a 20 caracteres (asumiendo que cada palabra tiene en promedio 10 caracteres)
    char cadena[20];

    // Mensaje solicitando la oración al usuario
    printf("Ingrese una oración de máximo 20 caracteres: ");
    scanf("%[^\n]", cadena);

    // Imprimir el tamaño de la cadena
    printf("Tamaño de cadena: %lu\n", strlen(cadena));

    // Imprimir los caracteres de la cadena
    printf("La oración ingresada es: %s\n", cadena);

    // Longitud de la cadena
    int len = strlen(cadena);
    // Definir la cadena invertida
    char invertida[len + 1]; // +1 para el carácter nulo

    // Bucle para invertir la cadena
    for (i = 0, j = len - 1; j >= 0; i++, j--) {
        invertida[i] = cadena[j];
    }

    // Agregar carácter nulo al final de la cadena invertida
    invertida[i] = '\0';

    // Impresión de la cadena invertida
    printf("La oracion invertida es: %s\n", invertida);

    return 0;
}