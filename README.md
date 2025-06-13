![Pinout](https://github.com/user-attachments/assets/e20d1178-ab96-4a7a-9706-dc1bb49483ec)

**TrafficLights Shield** es un shield para Arduino diseñado como tarjeta de aprendizaje que simula un cruce de semáforo.  
Ideal para principiantes en Arduino, permite controlar semáforos, LEDs de señalización, botones, sonido y comunicación Bluetooth.

### Características
- **2 semáforos** (rojo, amarillo, verde) con cruce peatonal  
- **2 LEDs azules** como señal de paso  
- **2 LEDs RGB** para efectos de color  
- **3 botones** de usuario  
- **Módulo Bluetooth HC-08** (RX/TX)  
- **Buzzer pasivo** para sonidos  
- Compatible con Arduino UNO y MEGA  
- Biblioteca de fácil uso con ejemplos incluidos

### Conexión de pines
![Pinout TrafficLights Shield](docs/pinout.png)

| Shield               | Arduino UNO   | Descripción                      |
|----------------------|---------------|----------------------------------|
| Red LED 1 (D2)       | D2            | Semáforo 1: luz roja             |
| Yellow LED 1 (D4)    | D4            | Semáforo 1: luz amarilla         |
| Green LED 1 (D5)     | D5            | Semáforo 1: luz verde            |
| Red LED 2 (D6)       | D6            | Semáforo 2: luz roja             |
| Yellow LED 2 (D7)    | D7            | Semáforo 2: luz amarilla         |
| Green LED 2 (D9)     | D9            | Semáforo 2: luz verde            |
| Blue LED 1 (D10)     | D10           | LED azul 1                       |
| Blue LED 2 (D11)     | D11           | LED azul 2                       |
| RGB LED 1 (A0,A1,A2) | A0,A1,A2      | LED RGB 1 (R,G,B)                |
| RGB LED 2 (A3,A4,A5) | A3,A4,A5      | LED RGB 2 (R,G,B)                |
| Button 1 (D8)        | D8            | Botón usuario A                  |
| Button 2 (D12)       | D12           | Botón usuario B                  |
| Button 3 (D13)       | D13           | Botón usuario C                  |
| HC-08 RX/TX          | RX/TX (D0/D1) | Comunicación Bluetooth           |
| Buzzer (D3)          | D3            | Buzzer pasivo                    |

### Instalación de la biblioteca

1. Copia la carpeta `library` dentro de tu carpeta `Arduino/libraries/`.
2. Reinicia el IDE de Arduino.
3. Verás la biblioteca **TrafficLights** disponible en **Sketch → Include Library**.

### Ejemplos incluidos

- **01_TrafficCrossWithSound**: Cruce de semáforos con sonido
- **02_PedestrianCrossing**: Semáforo para peatones usando LEDs azules y Serial
- **03_RGBWithButtons**: Control de LEDs RGB con botones
- **04_SemaforosRGB**: Semáforos usando LEDs RGB
- **05_MemoryGame**: Juego de memoria con todos los LEDs y botones

---

## Pinout

![Diagrama de Pinout](docs/pinout.png)

*(Imagen arriba: diagrama claro de conexiones shield → Arduino UNO.)*

---

## Infografía

![Infografía TrafficLights Shield](docs/infographic.png)

*(Infografía estilo ilustración resaltando semáforos, LEDs, botones, Bluetooth y buzzer.)*

---

## Tutorial de uso (docs/tutorial.md)

```markdown
# Tutorial de uso con Arduino UNO y MEGA

## 1. Montaje físico
1. Inserta el TrafficLights Shield sobre tu Arduino UNO o MEGA.
2. Conecta Arduino a tu PC vía USB.

## 2. Primer ejemplo: Cruce de semáforos con sonido
1. Abre el IDE de Arduino.
2. Ve a **File → Examples → TrafficLights → 01_TrafficCrossWithSound**.
3. Sube el sketch.  
4. Observa cómo alternan las luces de los semáforos y suena el buzzer.

## 3. Peatones y Serial
1. Abre **02_PedestrianCrossing**.
2. Conecta consola Serial a 115200 baudios.
3. Pulsa **Botón A** para iniciar fase peatonal (LED azul encendido + mensaje Serial).
4. Pulsa de nuevo para volver al flujo vehicular.

## 4. Control de color con botones
- **03_RGBWithButtons**: cada botón cambia el color del LED RGB correspondiente.

## 5. Semáforos RGB
- **04_SemaforosRGB**: reemplaza luces fijas por efectos RGB.

## 6. Juego de memoria
- **05_MemoryGame**: el shield muestra una secuencia de colores y debes repetirla usando botones.

¡Explora los ejemplos, ajusta tiempos y diviértete aprendiendo Arduino!

