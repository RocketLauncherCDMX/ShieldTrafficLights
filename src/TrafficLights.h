#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H

#include <Arduino.h>

namespace TrafficLightsShield {

  // Colores de semáforo
  enum TLColor { RED, YELLOW, GREEN };

  // Estados de botón
  enum ButtonState { RELEASED, PRESSED, HOLD_PRESSED, HOLD_RELEASED };

  // Un semáforo de tres luces
  class TrafficLight {
    uint8_t pinR, pinY, pinG;
  public:
    TrafficLight(uint8_t redPin, uint8_t yellowPin, uint8_t greenPin);
    void init();
    void color(TLColor c);
  };

  // Un LED RGB con PWM por software integrado
  class RGBLed {
    uint8_t pinR, pinG, pinB;
  public:
    RGBLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);
    void init();
    void set(uint8_t r, uint8_t g, uint8_t b);
    void red(uint8_t v);
    void green(uint8_t v);
    void blue(uint8_t v);
    void off();
  };

  // Un LED simple (azul)
  class BlueLed {
    uint8_t pin;
  public:
    BlueLed(uint8_t p);
    void init();
    void on();
    void off();
  };

  // Un botón de usuario (con debounce básico)
  class Button {
    uint8_t pin;
    bool    oldState;
  public:
    ButtonState status;
    Button(uint8_t p);
    void init();
    ButtonState read();
  };

  // Un buzzer pasivo (square-wave bloqueante)
  class Buzzer {
    uint8_t pin;
  public:
    Buzzer(uint8_t p);
    void init();
    void beep(uint16_t freq, uint16_t duration);
  };

  // “Singleton” que agrupa todo el shield
  class ShieldClass {
  public:
    TrafficLight semaforo1, semaforo2;
    RGBLed       RGB1, RGB2;
    BlueLed      blue1, blue2;
    Button       buttonA, buttonB, buttonC;
    Buzzer       buzzer;

    ShieldClass();
    void begin();
  };

  // Instancia global
  extern ShieldClass Shield;

}
using namespace TrafficLightsShield;

#endif // TRAFFICLIGHTS_H
