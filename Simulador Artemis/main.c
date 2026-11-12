#include <stdio.h>
#include <stdlib.h>
#include "artemis.h"
#include "validaciones.h"

void mostrar_menu(void) {
    printf("\n===================================================\n");
    printf("   SIMULADOR ARTEMIS - REINGRESO Y AMERIZAJE (C)   \n");
    printf("===================================================\n");
    printf("1. Ejecutar simulacion con parametros por defecto\n");
    printf("2. Personalizar parametros de vuelo y reingreso\n");
    printf("3. Simular secuencia/evento por turnos\n");
    printf("4. Generar reporte completo del escenario\n");
    printf("5. Salir del programa\n");
    printf("===================================================\n");
}

void simular_por_turnos(const ParametrosMision *p) {
    printf("\n--- INICIANDO SIMULACION PASO A PASO POR EVENTOS ---\n");
    printf("[Evento 1]: Reingreso Atmosferico a %.2f km con V = %.2f m/s...\n", p->altitud_i / 1000.0, p->vel_i);
    printf("Presione Enter para continuar...");
    getchar();

    printf("[Evento 2]: Frenado aerodinamico extremo durante %.2f s...\n", p->tiempo_desacel);
    printf("Presione Enter para desplegar paracaidas...");
    getchar();

    printf("[Evento 3]: Apertura de paracaidas principales a %.2f m. Velocidad reducida a %.2f m/s.\n", p->altitud_f, p->vel_f);
    printf("Presione Enter para presenciar el amerizaje...");
    getchar();

    printf("[Evento 4]: Amerizaje en Océano Pacifico a V = %.2f m/s. Penetración en agua: %.2f m.\n", p->vel_impacto, p->hundimiento);
    printf("\033[1;32m[OK]: Amerizaje completado con exito. Tripulacion a salvo.\033[0m\n");
}

int main(void) {
    ParametrosMision parametros;
    ResultadosSimulacion resultados;
    int opcion;

    cargar_parametros_defecto(&parametros);

    do {
        mostrar_menu();
        opcion = leer_entero("Seleccione una opcion del menu", 1, 5);

        switch (opcion) {
            case 1:
                cargar_parametros_defecto(&parametros);
                calcular_simulacion(&parametros, &resultados);
                printf("\n\033[1;32mParametros cargados y simulación ejecutada correctamente.\033[0m\n");
                break;

            case 2:
                printf("\n--- CONFIGURACION DE PARAMETROS PERSONALIZADOS ---\n");
                parametros.masa = leer_double("Masa de la capsula (kg)", 1000.0, 50000.0);
                parametros.altitud_i = leer_double("Altitud inicial (m)", 10000.0, 500000.0);
                parametros.vel_i = leer_double("Velocidad inicial (m/s)", 1000.0, 20000.0);
                parametros.altitud_f = leer_double("Altitud paracaidas (m)", 500.0, 10000.0);
                parametros.vel_f = leer_double("Velocidad paracaidas (m/s)", 5.0, 100.0);
                parametros.vel_impacto = leer_double("Velocidad amerizaje (m/s)", 1.0, 30.0);
                parametros.tiempo_desacel = leer_double("Tiempo desaceleracion (s)", 10.0, 2000.0);
                parametros.hundimiento = leer_double("Hundimiento en agua (m)", 0.1, 10.0);
                parametros.angulo_reingreso = leer_double("Angulo de reingreso (grados)", 0.0, 15.0);

                calcular_simulacion(&parametros, &resultados);
                printf("\n\033[1;32mParametros actualizados con exito.\033[0m\n");
                break;

            case 3:
                simular_por_turnos(&parametros);
                break;

            case 4:
                calcular_simulacion(&parametros, &resultados);
                mostrar_reporte_completo(&parametros, &resultados);
                break;

            case 5:
                printf("\nGracias por utilizar el Simulador Artemis. ¡Hasta pronto!\n");
                break;
        }

    } while (opcion != 5);

    return 0;
}