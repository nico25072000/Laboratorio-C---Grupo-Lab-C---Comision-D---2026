#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descarta los caracteres remanentes hasta el salto de línea
    }
}

int leer_entero(const char *mensaje, int min, int max) {
    int valor;
    int num_leidos;
    do {
        printf("%s [%d - %d]: ", mensaje, min, max);
        num_leidos = scanf("%d", &valor);
        if (num_leidos != 1) {
            printf("\033[1;31mError: Entrada invalida. Por favor ingrese un numero entero.\033[0m\n");
            limpiar_buffer();
        } else if (valor < min || valor > max) {
            printf("\033[1;31mError: El valor debe estar entre %d y %d.\033[0m\n", min, max);
        } else {
            limpiar_buffer();
            return valor;
        }
    } while (1);
}

double leer_double(const char *mensaje, double min, double max) {
    double valor;
    int num_leidos;
    do {
        printf("%s [%.2f - %.2f]: ", mensaje, min, max);
        num_leidos = scanf("%lf", &valor);
        if (num_leidos != 1) {
            printf("\033[1;31mError: Entrada invalida. Por favor ingrese un numero decimal valido.\033[0m\n");
            limpiar_buffer();
        } else if (valor < min || valor > max) {
            printf("\033[1;31mError: El valor debe estar entre %.2f y %.2f.\033[0m\n", min, max);
        } else {
            limpiar_buffer();
            return valor;
        }
    } while (1);
}