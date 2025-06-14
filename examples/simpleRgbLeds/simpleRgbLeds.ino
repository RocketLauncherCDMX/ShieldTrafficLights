// --------------------------- TRAFFICLIGHTS SHIELD ---------------------------------------
//
// FADE IN/OUT DE AMBOS LEDs RGB
// Este sketch barre el brillo de ambos LEDs RGB de 0 → 255 → 0 usando PWM,
// con pasos de 1 y un retardo de 10 ms entre cada nivel.
//
// Autor: Rocket Launcher
// Fecha: 13 de junio de 2025
//
// Funciones utilizadas:
//
// Shield.RGBn.set(Rv, Gv, Bv);   -> n = numero de LED RGB puede ser 1 o 2
//                                -> Rv = valor del canal rojo (0 - 255)
//                                -> Gv = valor del canal verde (0 - 255)
//                                -> Bv = valor del canal azul (0 - 255) 
//
// ----------------------------------------------------------------------------------------

#include <TrafficLights.h>

void setup() {
  // Inicializa el Shield (configura pines y arranca el PWM por software)
  Shield.begin();
}

void loop() {
  // --- Subida de brillo: de 0 a 255 ---
  for (int level = 0; level <= 255; level++) {
    // Ambos LEDs en aumento desde apagado hasta rojo al 100%
    Shield.RGB2.set(level, 0, 0);
    Shield.RGB1.set(level, 0, 0);
    delay(10);
  }

  for (int level = 0; level <= 255; level++) {
    // Ambos LEDs en aumento desde apagado hasta verde al 100%
    Shield.RGB2.set(0, level, 0);
    Shield.RGB1.set(0, level, 0);
    delay(10);
  }

  for (int level = 0; level <= 255; level++) {
    // Ambos LEDs en aumento desde apagado hasta azul al 100%
    Shield.RGB2.set(0, 0, level);
    Shield.RGB1.set(0, 0, level);
    delay(10);
  }
}