#include "TrafficLights.h"
#include <avr/interrupt.h>

namespace TrafficLightsShield {

  // — Pines y estado interno de PWM por software: 6 canales RGB —
  static const uint8_t _swPins[6] = { A0, A1, A2, A3, A4, A5 };
  static       uint8_t _swDuty[6];          // duty en pasos 0…PWM_STEPS-1
  static       uint8_t _swPhase = 0;        // fase actual 0…PWM_STEPS-1

  // Resolución y frecuencia del PWM por software
  static const uint8_t  PWM_STEPS = 32;     // 32 niveles
  static const uint16_t PWM_FREQ  = 500;    // 500 Hz

  // Inicializa pines y duty=0
  static void _swpwm_init() {
    for (uint8_t i = 0; i < 6; i++) {
      pinMode(_swPins[i], OUTPUT);
      digitalWrite(_swPins[i], LOW);
      _swDuty[i] = 0;
    }
  }

  // Convierte un valor 0…255 a 0…PWM_STEPS-1
  static inline uint8_t _toStep(uint8_t v) {
    return (uint16_t)v * (PWM_STEPS - 1) / 255;
  }

  // Configura Timer1 para generar interrupciones a PWM_FREQ * PWM_STEPS
  static void _timer1_init() {
    noInterrupts();
    TCCR1A = 0;                                  // CTC
    TCCR1B = _BV(WGM12) | _BV(CS10);             // CTC, prescaler=1
    OCR1A  = (F_CPU / (uint32_t)PWM_FREQ / PWM_STEPS) - 1;
    TIMSK1 = _BV(OCIE1A);                        // habilita ISR
    interrupts();
  }

  // ISR ejecutada cada (1/PWM_FREQ/PWM_STEPS) s
  ISR(TIMER1_COMPA_vect) {
    for (uint8_t i = 0; i < 6; i++) {
      digitalWrite(_swPins[i],
        (_swPhase < _swDuty[i]) ? HIGH : LOW
      );
    }
    if (++_swPhase >= PWM_STEPS) _swPhase = 0;
  }

  // — Instancia global —
  ShieldClass Shield;

  // —— ShieldClass ——
  ShieldClass::ShieldClass()
    : semaforo1(2, 4, 5),
      semaforo2(6, 7, 9),
      RGB1(A0, A1, A2),
      RGB2(A3, A4, A5),
      blue1(10),
      blue2(11),
      buttonA(8),
      buttonB(12),
      buttonC(13),
      buzzer(3)
  {}

  void ShieldClass::begin() {
    _swpwm_init();
    _timer1_init();

    semaforo1.init();
    semaforo2.init();
    RGB1.init();
    RGB2.init();
    blue1.init();
    blue2.init();
    buttonA.init();
    buttonB.init();
    buttonC.init();
    buzzer.init();
  }

  // —— TrafficLight ——
  TrafficLight::TrafficLight(uint8_t r, uint8_t y, uint8_t g)
    : pinR(r), pinY(y), pinG(g) {}
  void TrafficLight::init() {
    pinMode(pinR, OUTPUT);
    pinMode(pinY, OUTPUT);
    pinMode(pinG, OUTPUT);
    color(RED);
  }
  void TrafficLight::color(TLColor c) {
    digitalWrite(pinR, (c==RED)    ? HIGH : LOW);
    digitalWrite(pinY, (c==YELLOW) ? HIGH : LOW);
    digitalWrite(pinG, (c==GREEN)  ? HIGH : LOW);
  }

  // —— RGBLed ——
  RGBLed::RGBLed(uint8_t r, uint8_t g, uint8_t b)
    : pinR(r), pinG(g), pinB(b) {}
  void RGBLed::init() {
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
    off();
  }
  void RGBLed::set(uint8_t r, uint8_t g, uint8_t b) {
    // Aquí intercambiamos rojo y verde:
    for (uint8_t i = 0; i < 6; i++) {
      if (_swPins[i] == pinR)           _swDuty[i] = _toStep(g);  // antes: r
      else if (_swPins[i] == pinG)      _swDuty[i] = _toStep(r);  // antes: g
      else if (_swPins[i] == pinB)      _swDuty[i] = _toStep(b);
    }
  }
  void RGBLed::red(uint8_t v)   { set(v, 0, 0); }  // ahora v irá al canal verde
  void RGBLed::green(uint8_t v) { set(0, v, 0); }  // ahora v irá al canal rojo
  void RGBLed::blue(uint8_t v)  { set(0, 0, v); }
  void RGBLed::off()            { set(0, 0, 0); }

  // —— BlueLed ——
  BlueLed::BlueLed(uint8_t p) : pin(p) {}
  void BlueLed::init() {
    pinMode(pin, OUTPUT);
    off();
  }
  void BlueLed::on()  { digitalWrite(pin, HIGH); }
  void BlueLed::off() { digitalWrite(pin, LOW);  }

  // —— Button ——
Button::Button(uint8_t p)
  : pin(p), oldState(HIGH), status(RELEASED) {}

void Button::init() {
  pinMode(pin, INPUT_PULLUP);   // Pull-up interno
}

ButtonState Button::read() {
  bool newState = digitalRead(pin);

  if (newState == LOW  && oldState == HIGH) {
    status = PRESSED;           // transición reposo → pulsado
  }
  else if (newState == HIGH && oldState == LOW) {
    status = RELEASED;          // transición pulsado → reposo
  }
  else if (newState == LOW  && oldState == LOW) {
    status = HOLD_PRESSED;      // se mantiene pulsado
  }
  else {
    status = HOLD_RELEASED;     // se mantiene suelto
  }

  oldState = newState;
  return status;
}

  // —— Buzzer ——
  Buzzer::Buzzer(uint8_t p) : pin(p) {}
  void Buzzer::init() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  void Buzzer::beep(uint16_t freq, uint16_t dur) {
    uint32_t end    = millis() + dur;
    uint32_t period = 1000000UL / freq;
    uint32_t half   = period / 2;
    while (millis() < end) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(half);
      digitalWrite(pin, LOW);
      delayMicroseconds(half);
    }
  }

} // namespace TrafficLightsShield
