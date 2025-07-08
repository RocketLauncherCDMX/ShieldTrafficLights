![Artboard 1](https://github.com/user-attachments/assets/f28bd189-3841-40d5-8fb8-9d2f6d0636e3)

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

Procedimiento 1

1. Descarga en el siguiente enlace la biblioteca en formato .zip
(https://github.com/RocketLauncherCDMX/ShieldTrafficLights/releases/download/v1.0.0/RocketLauncher_trafficShield.zip)
1. En Arduino, da click en el menú Programa/Incluir Libreria/Añadir Biblioteca .zip
2. Selecciona la carpeta comprimida RocketLauncher_trafficShield.zip

Procedimiento 2

1. Copia la carpeta `RocketLauncher_trafficShield` dentro de tu carpeta `Arduino/libraries/`.
2. Reinicia el IDE de Arduino.
3. Verás la biblioteca **TrafficLights** disponible en **Sketch → Include Library**.



### Ejemplos incluidos

Una vez instalada o copiada la libreria, elige tu Arduino UNO o MEGA, ve a la pestaña Archivo/Ejemplos/RocketLauncher_trafficShield/examples

- **rgbLedsButtons**: Muestra como controlar los LEDs RGB a traves de los botones
- **simpleCurceDeSemaforo**: Semáforos de la intersección de calles
- **simpleRgbLeds**: Control de LEDs RGB simple
