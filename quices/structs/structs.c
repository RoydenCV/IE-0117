// Royden Contreras Vallejos
// C12260
// Este sera un programa de structs el cual contendra los datos de 3 animales
// dicho programa se desarrollara a continuacion 

// Ingreseo de la libreria
#include <stdio.h>

// Nos dicen que deben ser tres animales, por lo que vamos a definir el tamaño
#define MAXANIMALS 3

// Definimos la estructura 
struct animal {
    char nombre[50];
    int edad;
    char especie[50];
};


// Vamos a usar un sistema for que sea el encargado de ingresar las variables al
// inventario, lo que deja lo siguiente:

int main() {
    struct animal inventory[MAXANIMALS];

    // Ingreso de datos de los animales
    for (int i = 0; i < MAXANIMALS; i++) {
        printf("Ingrese el nombre del animal %d: ", i + 1);
        scanf("%49s", inventory[i].nombre); 
        
        printf("Ingrese la edad de %s: ", inventory[i].nombre);
        scanf("%d", &inventory[i].edad);
        
        printf("Ingrese la especie de %s: ", inventory[i].nombre);
        scanf("%49s", inventory[i].especie); 
    }



    // Una vez hecho esto ahora imprimimos la informacion al usuario 
    for (int i = 0; i < MAXANIMALS; i++) {
        printf("Animal %d:\n", i + 1);
        printf("  Nombre: %s\n", inventory[i].nombre);
        printf("  Edad: %d\n", inventory[i].edad);
        printf("  Especie: %s\n", inventory[i].especie);
    }

}