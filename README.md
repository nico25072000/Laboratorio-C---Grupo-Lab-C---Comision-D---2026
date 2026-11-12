# Laboratorio-C---Grupo-Lab-C---Comision-D---2026

 - TRABAJO INTEGRADOR DEL LABORATORIO C
 - UTN - FACULTAD DE RESISTENCIA   

<img width="294" height="301" alt="UTN_logo" src="https://github.com/user-attachments/assets/4e455447-8b9a-46e1-ba5c-a43045e2e645" />



Integrantes:
 - Montanaro Valles, Estefania
 - Neira, Nicolas Matias
 - Strangaferro, Milagros

Comision: D


Descripcion del Problema 4: Reingreso Atmosférico, Frenado Aerodinámico y Amerizaje
(Trabajo, Energía e Impacto)

 - Tras completar el sobrevuelo lunar, el módulo de tripulación Orion (m = 10.400,0 kg) se separa
del módulo de servicio y reingresa a la atmósfera terrestre a una velocidad hiperveloz de vi =
11,0 km/s (11.000,0 m/s, equivalente a 39.600,0 km/h o Mach 32) a una altitud de h = 120,0 km
(120.000,0 m). El escudo térmico disipa la energía cinética mediante el trabajo de la fuerza de
resistencia aerodinámica del aire (Froz), reduciendo la rapidez hasta vf = 25,0 m/s al momento
de desplegar los paracaídas principales a una altitud de h = 2,50 km (2.500,0 m). Finalmente, la
nave impacta en la superficie del Océano Pacífico (amerizaje) a una rapidez final segura de
vimpacto = 8,0 m/s.

 - Ejemplos de preguntas de análisis y cálculo analítico que el programa debería responder, a
partir de distintos valores de entrada ingresados por el usuario

 a) Calcule el trabajo total Wroz realizado por la fuerza de rozamiento atmosférico sobre la
cápsula desde el reingreso (120.000,0 m) hasta la apertura de los paracaídas (2.500,0 m).
 b) Si la fase de mayor desaceleración dura Δt = 400,0 s, determine la desaceleración media
ejercida sobre la tripulación en m/s² y en múltiplos de la gravedad (g).
 c) Suponiendo que durante el amerizaje la cápsula se hunde d = 1,50 m en el agua hasta
detenerse momentáneamente antes de flotar, determine la fuerza promedio Fprom que el agua
ejerce sobre la estructura. Exprese el resultado en Newtons (N) y como múltiplo del peso de la
nave.
 d) Analice qué sucedería si el ángulo de reingreso γ estuviera fuera de la ventana de seguridad
(5,5° ≤ γ ≤ 7,0°): evalúe las consecuencias físicas si γ > 7,0° (desaceleración excesiva) o si γ <
5,5° (rebote atmosférico).


 - Funcionamiento:

Este programa es una aplicación modular desarrollada en lenguaje C que simula el reingreso atmosférico, la desaceleración aerodinámica, la apertura de paracaídas y el impacto/amerizaje de la cápsula espacial Orion (Escenario 4).
El sistema realiza cálculos físicos basados en:
 - El Teorema del Trabajo y la Energía Mecánica para obtener el trabajo realizado por la fuerza de rozamiento atmosférico.
 - Cinemática y Dinámica para calcular la desaceleración media expresada en múltiplos de la aceleración de la gravedad ($g$).
 - Fuerza de frenado en medios fluidos para determinar la fuerza promedio durante el impacto con el agua y su relación con el peso de la nave.
 - Evaluación de la ventana de reingreso según el ángulo de entrada ($\gamma$), advirtiendo sobre riesgos estructurales (ángulo muy empinado) o rebotes atmosféricos (ángulo muy plano).

La aplicación cuenta con una interfaz interactiva de consola basada en menús que permite configurar parámetros, simular eventos paso a paso y generar un reporte analítico detallado, todo ello respaldado por un módulo estricto de validación de entradas para evitar fallos por errores del usuario.


 - Instrucciones de compilacion y ejecucion

Pre-requisitos: Tener instalado un compilador de C compatible con el estándar C99 (como gcc) y las herramientas de construcción (make).

Pasos para compilar y ejecutar (Linux / macOS / Git Bash / PowerShell):

1. Clonar o descargar el repositorio y ubicarse en la carpeta raíz del proyecto:
   
     cd "Ruta/A/Tu/Carpeta/Simulador Artemis"

2. Compilar el proyecto (utilizando el Makefile provisto o mediante compilación directa):

   Opción con Makefile: make
   
   Opción directa con GCC (recomendada si estás en PowerShell/Git Bash):

   gcc main.c artemis.c validaciones.c -o simulador_artemis -lm

3. Ejecutar el programa

   En Linux / macOS / Git Bash: ./simulador_artemis

   En Windows (PowerShell / CMD): .\simulador_artemis.exe

Una vez hecho eso, solamente se ejecuta simulador_artemis.exe con doble clic.


 - Registro detallado del uso de Inteligencia Artificial:

   De manera transparente y cumpliendo con las normativas académicas de la cátedra, se detalla a continuación el uso de herramientas de Inteligencia Artificial en el desarrollo de este trabajo:
   
 - Herramientas de IA utilizadas: Modelos de lenguaje avanzados (Gemini) como asistentes de desarrollo y consulta técnica.
   
 - Tareas asistidas por la IA:

   1. Arquitectura y modularización: Asesoramiento en la estructuración limpia del código fuente en archivos separados (.h y .c) para cumplir con las pautasde programación estructurada.
   2. Verificación de fórmulas físicas: Revisión analítica de las ecuaciones de energía mecánica, trabajo de rozamiento y cálculo de la fuerza de frenado
hidrodinámico.
   3. Depuración de consola: Asistencia en la resolución de problemas de lectura de búfer (stdin) para el sistema de validación de entradas robustas.

 - Validación humana: Todo el código generado, junto con los cálculos físicos y la lógica de control, fue estrictamente revisado, probado, adaptado e integrado deforma manual por los integrantes del equipo para garantizar su correcto funcionamiento y cumplimiento de la rúbrica.
