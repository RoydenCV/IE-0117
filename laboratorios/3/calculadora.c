// Apartado de definicion de funciones 

#include <stdio.h>
#include "calculadora.h"


// funcion1(): Se encarga de realizar la suma de la calculadora
int funcion1(int x, int y) {
    printf("Suma:  x=%d    y=%d\n", x, y);
    int z = x + y;
    // impresion del resultado
    printf("z = %d\n", z);
    // par o impar
    if (z % 2 == 0) {
        printf("El numero es par\n");
    } else {
        printf("El numero es impar\n");
    }
    // reglon vacio
    printf("\n");

    return z;
}


// funcion2(): Se encarga de realizar la resta de la calculadora
int funcion2(int x, int y) {
    printf("Resta:  x=%d    y=%d\n", x, y);
    int q = x - y;
    // impresion del resultado
    printf("q = %d\n", q);
    // par o impar
    if (q % 2 == 0) {
        printf("El numero es par\n");
    } else {
        printf("El numero es impar\n");
    }
    // reglon vacio
    printf("\n");

    return q;
}



// funcion3(): Se encarga de realizar la multiplicacion de la calculadora
int funcion3(int x, int y) {
    printf("Multiplicacion:  x=%d    y=%d\n", x, y);
    int w = x * y;
    // impresion del resultado
    printf("w = %d\n", w);
    // par o impar
    if (w % 2 == 0) {
        printf("El numero es par\n");
    } else {
        printf("El numero es impar\n");
    }
    // reglon vacio
    printf("\n");

    return w;
}


// funcion4(): Se encarga de realizar la division de la calculadora
int funcion4(double x, double y) {
    printf("Division:  x=%.2f    y=%.2f\n", x, y);
    double e = x / y;
    // impresion del resultado
    printf("e = %.2f\n", e); // Cambiado a %d para enteros
    // convirttiendo la variable e en un numero entero 
    int ent = (int)e;
    // par o impar
    if (ent % 2 == 0) {
        printf("El numero es par\n");
    } else {
        printf("El numero es impar\n");
    }
    // reglon vacio
    printf("\n");

    return e;
}




// funcion5(): Se encarga de determinar el modulo de un numero en la calculadora
int funcion5(int x, int y) {
    printf("Modulo de los numeros: x=%d    y=%d\n", x, y);
    int r = x * y;
    // impresion del resultado
    printf("r = %d\n", r);
    // par o impar
    if (r % 2 == 0) {
        printf("El numero es par\n");
    } else {
        printf("El numero es impar\n");
    }
    // reglon vacio
    printf("\n");

    return r;
}



// funcion6(): Se encarga de determinar la potencia de un numero en la calculadora
int funcion6(int x) {
    printf("Potencia: x=%d\n", x);
    int t = x * x;
    // impresion del resultado
    printf("t = %d\n", t);
    // par o impar
    if (t % 2 == 0) {
        printf("El numero es par\n");
    } else {
        printf("El numero es impar\n");
    }

    return t;
}

