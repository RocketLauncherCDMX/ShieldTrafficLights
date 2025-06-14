// ------------------------------------------------ TRAFFICLIGHTS SHIELD ----------------------------------------------
//
// EJEMPLO 01: CRUCE DE SEMÁFORO CONVENCIONAL
// Este ejemplo muestra un cruce de dos vías con semáforos alternantes,
// sin cruce peatonal ni botones de usuario. Aprende a controlar dos
// semáforos básicos usando el TrafficLights Shield.
//
// Autor: Rocket Launcher
// Fecha: 13 de junio de 2025
// Visita https://github.com/RocketLauncherCDMX/ShieldTrafficLights para más información
// ------------------------------------------------------------------------------------------------------------

#include <TrafficLights.h>

// Tiempos de cada fase (en milisegundos)
const uint16_t GREEN_TIME  = 5000;  // Verde dura 5 s
const uint16_t YELLOW_TIME = 2000;  // Amarillo dura 2 s

void setup() {
  // Inicializa comunicación serial para depuración
  Serial.begin(115200);
  while (!Serial) { /* espera a que Serial esté lista */ }

  // Inicializa todos los componentes del Shield
  Shield.begin();
  Serial.println("=== TrafficLights Shield: Cruce convencional iniciado ===");
}

void loop() {
  // — FASE 1: Semáforo 1 en VERDE, Semáforo 2 en ROJO —
  Serial.println("Fase 1: Semaforo1 VERDE, Semaforo2 ROJO");
  Shield.semaforo1.color(GREEN);  // Semáforo 1: luz verde
  Shield.semaforo2.color(RED);    // Semáforo 2: luz roja
  delay(GREEN_TIME);

  // — FASE 1A: Cambio a AMARILLO en Semáforo 1 —
  Serial.println("Fase 1A: Semaforo1 AMARILLO, Semaforo2 ROJO");
  Shield.semaforo1.color(YELLOW); // Semáforo 1: luz amarilla
  Shield.semaforo2.color(RED);    // Semáforo 2 sigue en rojo
  delay(YELLOW_TIME);

  // — FASE 2: Semáforo 1 en ROJO, Semáforo 2 en VERDE —
  Serial.println("Fase 2: Semaforo1 ROJO, Semaforo2 VERDE");
  Shield.semaforo1.color(RED);    // Semáforo 1: luz roja
  Shield.semaforo2.color(GREEN);  // Semáforo 2: luz verde
  delay(GREEN_TIME);

  // — FASE 2A: Cambio a AMARILLO en Semáforo 2 —
  Serial.println("Fase 2A: Semaforo1 ROJO, Semaforo2 AMARILLO");
  Shield.semaforo1.color(RED);    // Semáforo 1 sigue en rojo
  Shield.semaforo2.color(YELLOW); // Semáforo 2: luz amarilla
  delay(YELLOW_TIME);

  // Al finalizar, el bucle se repite y vuelve a Fase 1
}
