#if !defined(TEMP)
#define TEMP

// necessario para usar o uint8_t
#include <stdint.h> 
#include "Arduino.h"
#include "pins_arduino.h"

#define TEMP_SENSOR_PIN A0
#define TEMP_HEATER_PIN A1

#define _MAX_POWER 100

// Modulo para as funções relacionadas a controle/leitura de temperatura 

/**
 *  Funcao usada para ler a temperatura 
 *  Convertera o valor de mV para *C 
 * @param pin = Pino onde estara conectado o sensor de temperatura
 */
float read_temp();

/**
 * Funcao para pre aquecer, setara a potencia em 100% 
 */
void pre_heat();

/**
 * Funcao para controlar a temperatura. 
 * @param power -> Potencia (0 a 100); 
*/
void set_heat(int power);

#endif // TEMP
