// Royden Contreras Vallejos
// C12260
// Este es un programa que genera tanto piramides normales, como piramides invertidas, para ello se le solicita 
// al usuario que ingrese el simbolo que tenga la piramide y a parte, se le solicitara cual sera el tamaño de la
// base de la piramide, esto permitira la elavoracion de un codigo interactivo con el usuario, todo esto se 
// realizara dentro de un sistema while que que solo finalizara si el usuario ingresa la palabra "SALIR"



// Ingreso de librerias 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


// Funcion que genera la piramide normal (La base de la piramide hacia abajo).
// Esta funcion como funciona es cuadriculando el area ingresada por el usuario. unas vez que esta cuadriculado
// procede a llenar los espacios segun se necesiten, ya sea con el simbolo seleccionado por el usuario o por 
// espacios en blanco 
void piramide_normal(int numero, char simbolo) {
    int altura = (numero + 1) / 2;
    // Este primer ciclo for se encarga de contabilizar la altura que tengra la priramide 
    for (int i = 0; i < altura; i++) {
        printf("\n");
        // Este for se encarga de ir contando lo espacios en blanco, ya que son necesarios para la forma de la 
        //piramide 
        for (int x = 0; x < altura - i - 1; x++) {
            printf(" ");
        }
        // Este sistema for se encargar de ir creado el tamaño de la base, segun a que altura se encuentre.
        for (int j = 0; j < (i * 2) + 1 && (i * 2) + 1 <= numero; j++) {
            printf("%c", simbolo);
        }
    
    }
    // Espacio en blanco 
    printf("\n");
}


// Funcion que genera una piramide invertida (La base de la piramide hacia arriba).
// El funcionamiendo de esta funcion es la misma que la anterior, la diferencai en esta es que para invertir la 
// la piramide lo que se hace es invertir los simbolos (los que eran positivos, pasan a ser negativos). a aparte
// de otras correcciones mas. 
void piramide_invertida(int numero, char simbolo) {
    printf("\n");
    // Este primer ciclo for se encarga de contabilizar la altura que tengra la priramide 
    for (int i = numero; i > 0; i--) { 
        // Este for se encarga de ir contando lo espacios en blanco, ya que son necesarios para la forma de la 
        //piramide 
        for (int x = 0; x < numero - i; x++) {
            printf(" ");
        }
        // Este sistema for se encargar de ir creado el tamaño de la base, segun a que altura se encuentre.
        for (int j = 0; j < (2 * i - 1); j++) { 
            printf("%c", simbolo);
        }
        // Espacio en blanco 
        printf("\n"); 
    }
}


int main(int argc, char const *argv[]) {
    int numero;
    char simbolo;
    char continuar[10]; 
    int opcion;
    int contador = 0;

    // Ya que ocupamos que el programa sea interactivo con los usuarios necesitaremos un sistema while que sea capaz
    // de reconocer si el usuario desea continuar en el programa o salirse, es por eso que aqui se inicia con este 
    // apartado 
    while (true) {
        // Mensaje de bienvenida y seleccion del tipo de piramide que desea el usuario. 
        printf("Bienvenido, este es un programa el cual genera tanto piramides normales como invertidas.\n");
        printf("Seleccione el tipo de piramide que desea usando las siguiente opciones: \n");
        printf("1. Pirámide normal\n");
        printf("2. Pirámide invertida\n");
        printf("Ingrese la opción que desea: \n");
        scanf("%d", &opcion);
        // Limpiar el buffer después de leer la opción
        getchar(); 

        switch (opcion) {
            // El caso 1 se utiliza cuando el usuario selecciona el tipo de piramide normal 
            case 1:
                // Mensaje de solicitud del simbolo de la piramide.
                printf("Ingrese el símbolo que quiere que tenga la pirámide: \n");
                // Lector de simbolo
                scanf("%c", &simbolo);
                // Mensaje de solicitud de tamaño de base.
                printf("Ingrese el tamaño de la base de la pirámide: \n");
                // Lector de tamaño de la pirámide. 
                scanf("%d", &numero);
                // Llamado a la funcion que se encarga de imprimir las pirámides normales.
                piramide_normal(numero, simbolo);
                break;

            // El caso 2 se utiliza cuando el usuario selecciona el tipo de piramide invertida
            case 2:
                // Mensaje de solicitud del simbolo de la pirámide.
                printf("Ingrese el símbolo que quiere que tenga la pirámide: \n");
                // Lector de simbolo 
                scanf("%c", &simbolo);
                // Mensaje de solicitud de tamaño de base.
                printf("Ingrese el tamaño de la base de la pirámide: \n");
                // Lector del tamaño de la pirámide 
                scanf("%d", &numero);
                // Llamado a la funcion encargada de imprimir la pirámide invertida 
                piramide_invertida(numero, simbolo);
                break;
            default:
                printf("Opción no válida\n");
                break;
        }

        contador++;

        // Condicional que permitira al usuario repetir el ejercicio
        printf("\nSi desea continuar escriba 'continuar' o si desea finalizar escriba 'SALIR': ");
        scanf("%s", continuar);
        
        if (strcmp(continuar, "SALIR") == 0) {
            // Salir del bucle
            break; 
        }
    }

    return 0;
}