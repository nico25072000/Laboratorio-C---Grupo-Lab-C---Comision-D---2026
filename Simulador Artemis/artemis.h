#ifndef ARTEMIS_H
#define ARTEMIS_H

#define GRAVEDAD_G 9.80
#define MASARREF 10400.0

// Estructura que almacena los parámetros de entrada y estado de la nave
typedef struct {
    double masa;            // kg
    double altitud_i;       // m
    double vel_i;           // m/s
    double altitud_f;       // m
    double vel_f;           // m/s
    double vel_impacto;     // m/s
    double tiempo_desacel;  // s
    double hundimiento;     // m
    double angulo_reingreso;// grados
} ParametrosMision;

// Estructura que almacena los resultados calculados de la simulación
typedef struct {
    double trabajo_rozamiento;
    double desaceleracion_m_s2;
    double desaceleracion_g;
    double fuerza_promedio_agua;
    double fuerza_multiplo_peso;
    int estado_reingreso; // 0: Seguro, 1: Destrucción por g, 2: Rebote atmosférico
} ResultadosSimulacion;

// Funciones principales
void cargar_parametros_defecto(ParametrosMision *p);
void calcular_simulacion(const ParametrosMision *p, ResultadosSimulacion *r);
void mostrar_analisis_teorico_angulo(double angulo);
void mostrar_reporte_completo(const ParametrosMision *p, const ResultadosSimulacion *r);

#endif