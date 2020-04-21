#if !defined(PUMP)
#define PUMP

#include "Arduino.h"

#define PUMP_PIN 12
#define TANK_SENSOR_PIN 9


//****************** Modulo para organizar as funções da bomba ****************************//


/**
 * A bomba servirá para homogenizar a  cerveja. 
 * Ela fara com que a água circule. 
 * O circuito da bomba é praticamente igual ao da resistencia.
 * O que mudaria seria a bomba de fato, o que não tem no proteus
*/


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