// Royden Contreras Valejos
// C12260
// Laboratorio 4 de Programacion Bajo Plataformas Abiertas
// Durante este laboratorio se va elaborar una calculadora que sea capaz
// De realizar operaciones bit a bit
// Para esto se ingresaran dos variables las cuales contendran numeros
// Cabe mensonar que las operaciones bit a bit se realizan en numeros binarios 
// Por lo que uno de los apartados sera especificamente para ver el resultado
// en numero binario


// Apartado de definicion de funciones 

// Ingreso de librerias
#include <stdio.h>
#include "calculadora.h"



// como el resultado de todas las operacion se deben mostrar en binario
// se iniciara por la funcion que realice este procedimiento 
// Funcion para imprimir el resultado en binario
void print_binary(unsigned int num) {
    printf("En binario: ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}



// Funcion encargada de realizar la operacion and
int bitwise_and(unsigned int a, unsigned int b) {
    // operacion and
    unsigned int z = a & b; 

    return z;

}



// Funcion encargada de realizar la operacion or
int bitwise_or(unsigned int a, unsigned int b) {
    // operacion or
    unsigned int w = a | b; 

    return w;

}



// Funcion encargada de realizar la operacion xor
int bitwise_xor(unsigned int a, unsigned int b) {
    // operacion xor
    unsigned int e = a ^ b; 

    return e;

}



// Funcion encargada de realizar la operacion not
int bitwise_not(unsigned int a) {
    // operacion not
    unsigned int r = ~a;

    return r;

}
