#if !defined(TEMP)
#define TEMP

#include <stdint.h> 
#include "Arduino.h"
#include "pins_arduino.h"
#include <LiquidCrystal.h>

#define TEMP_SENSOR_PIN A0
#define TEMP_HEATER_PIN 13

#define _MIN_POWER 0x0 // LOW 
#define _MAX_POWER 0x1  // HIGH
#define MAX_TEMP_WATER 60.0 // *C 
#define MINUTO_MS 1000 // apenas pra testes


// ************** Modulo para as funções relacionadas a controle/leitura de temperatura ***************//


/** 
 * O transistor faz o chaveamento do sinal de 5V(arduino) para 12V(fonte)
 * O transistor protegerá o arduino da back EMF do relé
 * O diodo também protegerá o transistor da back EMF do relé. 
 */


/**
 *  Funcao usada para ler a temperatura 
 *  Convertera o valor de mV para *C 
 */
float read_temp();

/**
 * Funcao para pré-aquecer.
 */
void pre_heat();

/**
 * Funcao para controlar a resistência.
 * @param power _MIN_POWER = Desliga, _MAX_POWER = Liga. 
*/
void _set_heat(bool power);

/**
 * Funcao para controlar a temperatura 
 * Irá ligar ou desligar a resistência 
 * de acordo com a temperatura atual da água. 
 * @param temp: temperatura desejada 
 */
void set_temp(float temp, LiquidCrystal &lcd);

/**
* Aumentara 1*C por minuto 
*/
void _raise_temp();

/**
 * Mantem a temperatura por t_min minutos 
*/
void keep_temp(int t_min, LiquidCrystal &lcd); 

#endif // TEMP