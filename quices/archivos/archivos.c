// Royden Contreras Vallejos
// C12260
// Este sera un programa el cual pregunte por el Nombre, apellido y carnet aun 
// usuarios, este lo escribira en un archivo txt donde se encontraran nombres
// ingresados anteriormente. 

// Ingreso de librería 
#include <stdio.h>

int main() {
    // Variables que contendrán la información
    FILE *archivo;
    // Para nombres y apellidos es muy dificil asginar una limitante por lo que 
    // vamos a obtar por poner una limitante alta
    char nombre[100];
    char apellido[100];
    // Los carnés están compuestos por 6 dígitos pero vamos a poner 10 para que
    // haya margen
    char carne[10];

    // Abrimos el archivo en modo anexar
    archivo = fopen("estudiantes.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Mensaje solicitando el nombre del usuario:
    printf("Ingrese el nombre: ");
    scanf(" %[^\n]", nombre); // Agregar un espacio antes de % para limpiar el buffer

    // Mensaje solicitando el apellido del usuario:
    printf("Ingrese el apellido: ");
    scanf(" %[^\n]", apellido); // Agregar un espacio antes de % para limpiar el buffer

    // Mensaje solicitando el carné del usuario:
    printf("Ingrese el carné: ");
    scanf(" %[^\n]", carne); // Agregar un espacio antes de % para limpiar el buffer

    // Escribir la información en el archivo
    fprintf(archivo, "%s %s %s\n", nombre, apellido, carne);

    fclose(archivo); // Cerrar el archivo

    return 0;
}