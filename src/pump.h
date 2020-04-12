#if !defined(PUMP)
#define PUMP

#include <stdint.h>
#include "Arduino.h"

#define PUMP_PIN 10
#define TANK_SENSOR_PIN 11


/**
 *  Armazena os tempos (até três) da receita
*/
struct Receita{
    uint8_t lupulo; 
    uint8_t malte;
    uint8_t leveduras; 
};

/**
 * Liga a bomba 
*/
void pump_on();

/**
 * Desliga a bomba 
*/
void pump_off();

/**
 * Sensor de nivel minimo. 
 * @return Retorna TRUE se esta ACIMA do nivel minimo (ou seja, podera ligar a resistenca)
 */
bool check_water_min_lvl();

#endif // PUMP
