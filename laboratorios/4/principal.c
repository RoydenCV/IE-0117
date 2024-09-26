// Apartado de depliegue de informacion de la calculadora 


// Ingreso de librerias
#include <stdio.h>
#include "calculadora.h"



// Despliegue de informacion
int main() {

    unsigned int z;
    unsigned int w;
    unsigned int e;
    unsigned int r;
  
    //Definicion de variables
    printf("Para las siguientes operaciones: \n");
    printf("a = 6 \n");
    printf("b = 0 \n");
    // reglon vacio
    printf("\n");


    // Llama a la funcion and
    z = bitwise_and(6, 0);
    // impresion de resultado
    printf("El resultado de a & b es: %u\n", z);
    // Impresion de resultado en binario
    print_binary(z);
    // reglon vacio
    printf("\n");

    
    // Llamado a la funcion or
    w = bitwise_or(6, 0);
    // impresion de resultado
    printf("El resultado de a | b es: %u\n", w);
    // Impresion de resultado en binario
    print_binary(w);
    // reglon vacio
    printf("\n");


    // Llamado a la funcion xor
    e = bitwise_xor(6, 0);
    // impresion de resultado
    printf("El resultado de a ^ b es: %u\n", e);
    // Impresion de resultado en binario
    print_binary(e);
    // reglon vacio
    printf("\n");


    // Llamado a la funcion not
    r = bitwise_not(6);
    // impresion de resultado
    printf("El resultado de ~a es: %u\n", r);
    // Impresion de resultado en binario
    print_binary(r);
   

    return 0;

}
