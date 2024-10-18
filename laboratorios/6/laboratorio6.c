// Royden Contreras Vallejos
// C12260
// Este programa lo que hace es sacar el maximo comun divisor de dos numeros,
// el ingreso de estos numeros se realiza mediante el uso de argumentos por linea
// de comando, estos numeros deben ser positivos, no puede recibir mas argumentos
// de la cuenta, tampoco puede recibir menos argumentos y si ambos numeros son 
// cero el programa tampoco se podra ejecutar 


// Ingreso de librerias 
#include <stdio.h>
#include <stdlib.h>


// Declaración de la función del maximo comun divisor 
int mcd(int x, int y);



// Implementacion de la funcion para obtener el maximo comun divisor
int mcd(int x, int y) {
    // sistema if que finaliza el progrma si alguno de los numeros ingresados
    // es negativo
    if (x < 0 || y < 0) { 
        printf("No se puede ejecutar, el programa solo acepta enteros positivos\n");
        exit(1);
    }
    // sistema if que finaliza el programa si ambas variables ingresadas son cero
    else if (x == 0 && y == 0) {
        printf("No se puede, ambos números no pueden ser cero en este programa.\n");
        exit(1);
    }
    // caso base, se da cuando y es igual a cero 
    if (y == 0) return x; 
    // llamada recursiva a la función mcd
    return mcd(y, x % y);  
}



// Funcion encargada de recibir los dos argumentos y convertir esos argumentos
// de string a entero
int main(int argc, char *argv[]) {
    // Sitema if encargado de terminarl el programa si solo se ingresa una varialbe
    if (argc==1)
    {
        printf("Error en la ejecución, el programa necesita dos entradas de numeros enteros positivos\n");
        // terminar el programa
        exit(1); 
    }
    else if (argc >3) {
        // sistema if encargado de terminar el programa si se ingresan mas de dos varilbes
        printf("Error en la ejecución, el programa solo acepta dos entradas\n");
        // terminar el programa
        exit(1); 
    }
    
    // Conversion de string a entero 
    int x = atoi(argv[1]); 
    int y = atoi(argv[2]); 

    // llamada a la función mcd
    int resultado = mcd(x, y); 
    
    printf("El máximo común divisor de %d y %d es: %d\n", x, y, resultado);
    return 0;
}