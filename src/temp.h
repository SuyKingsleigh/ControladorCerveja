#if !defined(TEMP)
#define TEMP


#include <stdint.h> 
#include "Arduino.h"
#include "pins_arduino.h"

#define TEMP_SENSOR_PIN A0
#define TEMP_HEATER_PIN A1

#define _MIN_POWER 0
#define _MAX_POWER 100
#define MAX_TEMP_WATER 95

// ************** Modulo para as funções relacionadas a controle/leitura de temperatura ***************//

/**
 *  Funcao usada para ler a temperatura 
 *  Convertera o valor de mV para *C 
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
void _set_heat(int power);

/**
 * Funcao para controlar a temperatura 
 * @param temp: temperatura desejada 
 */
void set_temp(float temp);


#endif // TEMP