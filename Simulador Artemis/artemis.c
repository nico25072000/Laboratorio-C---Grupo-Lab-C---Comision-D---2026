#include <stdio.h>
#include <math.h>
#include "artemis.h"

void cargar_parametros_defecto(ParametrosMision *p) {
    p->masa = 10400.0;
    p->altitud_i = 120000.0;
    p->vel_i = 11000.0;
    p->altitud_f = 2500.0;
    p->vel_f = 25.0;
    p->vel_impacto = 8.0;
    p->tiempo_desacel = 400.0;
    p->hundimiento = 1.50;
    p->angulo_reingreso = 6.2; // Seguro dentro del rango 5.5 - 7.0
}

void calcular_simulacion(const ParametrosMision *p, ResultadosSimulacion *r) {
    // a) Trabajo de rozamiento (Teorema Energía Mecánica)
    double E_ki = 0.5 * p->masa * pow(p->vel_i, 2);
    double E_pi = p->masa * GRAVEDAD_G * p->altitud_i;
    double E_mi = E_ki + E_pi;

    double E_kf = 0.5 * p->masa * pow(p->vel_f, 2);
    double E_pf = p->masa * GRAVEDAD_G * p->altitud_f;
    double E_mf = E_kf + E_pf;

    r->trabajo_rozamiento = E_mf - E_mi;

    // b) Desaceleración media
    r->desaceleracion_m_s2 = (p->vel_f - p->vel_i) / p->tiempo_desacel;
    r->desaceleracion_g = fabs(r->desaceleracion_m_s2) / GRAVEDAD_G;

    // c) Impacto con el agua
    double F_neta = (p->masa * pow(p->vel_impacto, 2)) / (2.0 * p->hundimiento);
    double peso = p->masa * GRAVEDAD_G;
    r->fuerza_promedio_agua = F_neta + peso;
    r->fuerza_multiplo_peso = r->fuerza_promedio_agua / peso;

    // d) Evaluación de la ventana de entrada
    if (p->angulo_reingreso > 7.0) {
        r->estado_reingreso = 1; // Desaceleración y calor excesivos
    } else if (p->angulo_reingreso < 5.5) {
        r->estado_reingreso = 2; // Rebote atmosférico
    } else {
        r->estado_reingreso = 0; // Exitoso
    }
}

void mostrar_analisis_teorico_angulo(double angulo) {
    printf("\n--- EVALUACION DE VENTANA DE REINGRESO (Gamma = %.2f deg) ---\n", angulo);
    if (angulo > 7.0) {
        printf("\033[1;31m[CRITICO]: Angulo muy empinado (Gamma > 7.0 deg).\033[0m\n");
        printf("Consecuencia: La friccion atmosferica genera desaceleraciones extremas (>15g)\n");
        printf("y sobrepasa el limite termico del escudo, destruyendo la nave.\n");
    } else if (angulo < 5.5) {
        printf("\033[1;33m[ADVERTENCIA]: Angulo muy plano (Gamma < 5.5 deg).\033[0m\n");
        printf("Consecuencia: La atmosfera no ofrece suficiente frenado aerodinamico.\033[0m\n");
        printf("La nave 'rebota' (skip-out) hacia el espacio en una orbita incontrollable.\n");
    } else {
        printf("\033[1;32m[EXITO]: Angulo dentro de la ventana de seguridad (5.5 deg <= Gamma <= 7.0 deg).\033[0m\n");
        printf("La nave frena adecuadamente garantizando la supervivencia de la tripulacion.\n");
    }
}

void mostrar_reporte_completo(const ParametrosMision *p, const ResultadosSimulacion *r) {
    printf("\n===========================================================\n");
    printf("     REPORTE FINAL DE LA MISION ARTEMIS - ESCENARIO 4     \n");
    printf("===========================================================\n");
    printf("1. VALORES DE ENTRADA CONFIGURADOS:\n");
    printf("   - Masa de la capsula Orion:       %.2f kg\n", p->masa);
    printf("   - Altitud de reingreso:           %.2f m (%.2f km)\n", p->altitud_i, p->altitud_i / 1000.0);
    printf("   - Velocidad inicial:              %.2f m/s (Mach %.1f)\n", p->vel_i, p->vel_i / 340.0);
    printf("   - Altitud de apertura paracaidas: %.2f m\n", p->altitud_f);
    printf("   - Velocidad en paracaidas:        %.2f m/s\n", p->vel_f);
    printf("   - Velocidad de amerizaje:         %.2f m/s\n", p->vel_impacto);
    printf("   - Tiempo de desaceleracion fase:  %.2f s\n", p->tiempo_desacel);
    printf("   - Profundidad de hundimiento:     %.2f m\n", p->hundimiento);
    printf("   - Angulo de entrada (Gamma):      %.2f deg\n", p->angulo_reingreso);

    printf("\n2. RESULTADOS DEL ANALISIS FISICO Y ENERGETICO:\n");
    printf("   a) Trabajo del rozamiento (Wroz): %.4e Joules\n", r->trabajo_rozamiento);
    printf("   b) Desaceleracion media:          %.2f m/s^2 (%.2f g)\n", r->desaceleracion_m_s2, r->desaceleracion_g);
    printf("   c) Fuerza prom. del agua (Fprom): %.2f N (%.2f veces el Peso)\n", r->fuerza_promedio_agua, r->fuerza_multiplo_peso);

    mostrar_analisis_teorico_angulo(p->angulo_reingreso);
    printf("===========================================================\n\n");
}