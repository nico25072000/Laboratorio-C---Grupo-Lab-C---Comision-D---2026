#ifndef VALIDACIONES_H
#define VALIDACIONES_H

// Lee un número entero de la consola dentro de un rango [min, max]
int leer_entero(const char *mensaje, int min, int max);

// Lee un número flotante (double) de la consola dentro de un rango [min, max]
double leer_double(const char *mensaje, double min, double max);

// Limpia el búfer de entrada estándar (stdin)
void limpiar_buffer(void);

#endif