
#include <stdio.h>

// Definiendo las constantes simbolicas
// Carne: C12260
#define K_G 122 /* peso en kilogramos del objeto */
#define V 60 /* velocidad en m/s a la que se desplaza*/


int main () {

    // Declacion de varialbes
    double Ecinetica;

    // Calculando la energia usando la formula 
    Ecinetica = 0.5 * K_G * V * V;

    // Impresion de resultado
    printf("El peso del objeto es de: %d Kilogramos\n", K_G);
    printf("La velocidad del objeto es de: %d m/s\n", V);
    printf("La energia cinetica del objeto es de: %.2f julios\n", Ecinetica);

    return 0;  
}

