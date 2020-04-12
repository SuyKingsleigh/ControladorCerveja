#if !defined(TEMP)
#define TEMP

// necessario para usar o uint8_t
#include <stdint.h> 
#define TEMP_SENSOR_PIN 1
#define TEMP_HEATER_PIN 2

#define _MAX_POWER 100

// Modulo para as funções relacionadas a controle/leitura de temperatura 

/**
 *  Funcao usada para ler a temperatura 
 *  Convertera o valor de mV para *C 
 *  implementando desta forma permite que o codigo fique mais generico, eficiente e organizado
 * @param (*f)(uint8_t) analogRead
 * @param pin = Pino onde estara conectado o sensor de temperatura
 */
float read_temp(int (*f)(uint8_t));

/**
 * Funcao para  pre aquecer, setara a potencia em 100% 
 * @param (*f) -> analogWrite
 */
void pre_heat(void (*f)(uint8_t, int));

/**
 * Funcao para controlar a temperatura. 
 * @param (*f) -> analogWrite; 
 * @param power -> Potencia (0 a 100); 
*/
void set_heat(void (*f)(uint8_t, int), int power);

#endif // TEMP
