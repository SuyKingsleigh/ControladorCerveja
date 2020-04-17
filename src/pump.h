#if !defined(PUMP)
#define PUMP

#include "Arduino.h"

#define PUMP_PIN 10
#define TANK_SENSOR_PIN 11


//****************** Modulo para organizar as funções da bomba ****************************//


/**
 * A bomba servirá para homogenizar.  
 * a cerveja, ela ira fazer com que a água circule. 
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
