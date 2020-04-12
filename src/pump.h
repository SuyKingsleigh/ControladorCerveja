#if !defined(PUMP)
#define PUMP


#include <stdint.h>

//pins 
#define PUMP_PIN 3
#define TANK_SENSOR_PIN 4

// defaults
#define PUMP_HIGH 0x1
#define PUMP_LOW 0x0
// Modulo para organizaar as funcoes da bomba


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
 * @param f: &digitalWrite
*/
void pump_on(void (*f)(uint8_t, uint8_t));

/**
 * Desliga a bomba 
 * @param f: &digitalWrite
*/
void pump_off(void (*f)(uint8_t, uint8_t));

/**
 * Sensor de nivel minimo. 
 * Retorna TRUE se esta ACIMA do nivel minimo (ou seja, podera ligar a resistenca)
 * @param f: &digitalRead
 */
bool check_water_min_lvl(int (*f)(uint8_t));

#endif // PUMP
