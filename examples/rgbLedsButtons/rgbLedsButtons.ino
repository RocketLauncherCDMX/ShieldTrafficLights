// --------------------------------------- TRAFFICLIGHTS SHIELD -------------------------------------
//
// EJEMPLO 04: CICLO DE INTENSIDAD POR COLOR
//
// Cada botón controla UN solo canal de color (R - G - B) de los dos LEDs RGB.
//
// 1) Mantén presionado el botón   → la intensidad sube poco a poco (0 → 255).
// 2) Cuando llega a 255           → se queda fija en 255 aunque sigas presionando.
// 3) Suelta y vuelve a presionar  → el canal se apaga (0) y se queda ahí.
// 4) Suelta y presiona otra vez   → comienza de nuevo el ciclo de subida.
//
// Autor: Rocket Launcher
// Fecha: 13 de junio de 2025
// --------------------------------------------------------------------------------------------------
//
// ASIGNACIÓN DE BOTONES
// - ButtonA  → Rojo   (canal R)
// - ButtonB  → Verde  (canal G)
// - ButtonC  → Azul   (canal B)
//
// PARÁMETROS DEL CICLO
// - Paso de incremento: 1 unidad
// - Velocidad: 10 ms por paso
//

#include <TrafficLights.h>

const uint8_t STEP       = 1;      // Suma por paso
const uint16_t STEP_TIME = 10;     // Tiempo entre pasos (ms)

// Estados del ciclo para cada color
// 0 = SUBE (0→255)   1 = ALTO (255)   2 = APAGADO (0)
uint8_t redStage   = 0;
uint8_t greenStage = 0;
uint8_t blueStage  = 0;

// Valores actuales de brillo (0…255)
uint8_t redValue   = 0;
uint8_t greenValue = 0;
uint8_t blueValue  = 0;

void setup() {
  // Inicializa el TrafficLights Shield
  Shield.begin();

  // Asegura todos los canales apagados al iniciar
  Shield.RGB1.off();
  Shield.RGB2.off();

  // Mensaje opcional
  Serial.begin(115200);
  Serial.println("Ejemplo 04: Ciclo de intensidad (R-G-B)");
}

void loop() {

  // ===================== BOTÓN A : ROJO =====================
  ButtonState aState = Shield.buttonA.read();

  // Transiciones al PRESIONAR
  if (aState == PRESSED) {
    if (redStage == 1) {           // Estaba en ALTO → pasa a APAGADO
      redStage = 2;
      redValue = 0;
    }
    else if (redStage == 2) {      // Estaba en APAGADO → comienza a SUBIR
      redStage = 0;
      redValue = 0;
    }
    // Si estaba en SUBE (0) y se presiona otra vez, no cambia nada especial
  }

  // Mientras se mantiene pulsado (SUBE)
  if (aState == HOLD_PRESSED && redStage == 0) {
    if (redValue < 255) {
      redValue = redValue + STEP;
    }
    else {                         // Llegó a 255 ⇒ bloquea en ALTO
      redValue = 255;
      redStage = 1;
    }
  }

  // ===================== BOTÓN B : VERDE ====================
  ButtonState bState = Shield.buttonB.read();

  if (bState == PRESSED) {
    if (greenStage == 1) {
      greenStage = 2;
      greenValue = 0;
    }
    else if (greenStage == 2) {
      greenStage = 0;
      greenValue = 0;
    }
  }

  if (bState == HOLD_PRESSED && greenStage == 0) {
    if (greenValue < 255) {
      greenValue = greenValue + STEP;
    }
    else {
      greenValue = 255;
      greenStage = 1;
    }
  }

  // ===================== BOTÓN C : AZUL =====================
  ButtonState cState = Shield.buttonC.read();

  if (cState == PRESSED) {
    if (blueStage == 1) {
      blueStage = 2;
      blueValue = 0;
    }
    else if (blueStage == 2) {
      blueStage = 0;
      blueValue = 0;
    }
  }

  if (cState == HOLD_PRESSED && blueStage == 0) {
    if (blueValue < 255) {
      blueValue = blueValue + STEP;
    }
    else {
      blueValue = 255;
      blueStage = 1;
    }
  }

  // ---------- ACTUALIZA LOS DOS LEDs RGB ----------
  Shield.RGB1.set(redValue, greenValue, blueValue);
  Shield.RGB2.set(redValue, greenValue, blueValue);

  // Pausa fija para controlar la velocidad de incremento
  delay(STEP_TIME);
}
