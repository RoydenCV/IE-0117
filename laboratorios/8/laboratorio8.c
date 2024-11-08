// Royden Contreras Vallejos 
// C12260
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Primeramente agregamos todas las librerias. 
// Definimos la variable para el numero de personas
int npersonas;

// Vamos a definir cuantas personas van a estar en el arreglo, para ello se le
// debera preguntar al usuario 
// Definimos la estructura para almacenar los datos
typedef struct {
    char nombre[20];
    char apellidos[50];
    int telefono;
    char carnet[10];
    char enfasis[30];
} datos_persona;

// Función para ingresar los datos de una persona
void setDatos(datos_persona *persona) {
    // Limpiar el buffer de entrada para evitar problemas con fgets después de scanf
    getchar(); 

    // Ingresar nombre
    printf("Ingrese el nombre: ");
    fgets(persona->nombre, sizeof(persona->nombre), stdin);
    persona->nombre[strcspn(persona->nombre, "\n")] = '\0';  // Eliminar salto de línea
    if (strlen(persona->nombre) > 20) { 
        printf("El nombre no puede tener más de 20 caracteres\n");
        exit(1);
    }

    // Ingresar apellidos
    printf("Ingrese los apellidos: ");
    fgets(persona->apellidos, sizeof(persona->apellidos), stdin);
    persona->apellidos[strcspn(persona->apellidos, "\n")] = '\0';  // Eliminar salto de línea
    if (strlen(persona->apellidos) > 50) {
        printf("Los apellidos no pueden tener más de 50 caracteres\n");
        exit(1);
    }

    // Ingresar teléfono
    printf("Ingrese el telefono (8 dígitos): ");
    char telefono_str[10];
    fgets(telefono_str, sizeof(telefono_str), stdin);
    if (sscanf(telefono_str, "%d", &persona->telefono) != 1 || persona->telefono < 10000000 || persona->telefono > 99999999) {
        printf("El telefono debe tener 8 dígitos\n");
        exit(1);
    }

    // Ingresar carnet
    printf("Ingrese el carnet: ");
    fgets(persona->carnet, sizeof(persona->carnet), stdin);
    persona->carnet[strcspn(persona->carnet, "\n")] = '\0';  // Eliminar salto de línea
    if (strlen(persona->carnet) > 10) {
        printf("El carnet no puede tener más de 10 caracteres\n");
        exit(1);
    }

    // Ingresar énfasis
    printf("Ingrese el enfasis: ");
    fgets(persona->enfasis, sizeof(persona->enfasis), stdin);
    persona->enfasis[strcspn(persona->enfasis, "\n")] = '\0';  // Eliminar salto de línea
}

// Función para imprimir los datos de una persona
void print_struct(datos_persona *persona) {
    printf("\n");
    printf("Nombre: %s\n", persona->nombre);
    printf("Apellidos: %s\n", persona->apellidos);
    printf("Telefono: %d\n", persona->telefono);
    printf("Carnet: %s\n", persona->carnet);
    printf("Enfasis: %s\n", persona->enfasis);
}

int main(int argc, char const *argv[]) {
    // Pedir el número de personas a registrar
    printf("Ingrese el numero de personas que desea registrar: \n");
    scanf("%d", &npersonas);

    // Asignar dinámicamente el arreglo de personas
    datos_persona *personas = malloc(npersonas * sizeof(datos_persona));

    if (personas == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Ingresar los datos de cada persona
    for (int i = 0; i < npersonas; i++) {
        printf("Ingrese los datos de la persona %d\n", i + 1);
        setDatos(&personas[i]);
    }

    // Imprimir los datos de cada persona
    for (int i = 0; i < npersonas; i++) {
        printf("Datos de la persona %d\n", i + 1);
        print_struct(&personas[i]);
    }

    // Liberar la memoria asignada
    free(personas);

    return 0;
}