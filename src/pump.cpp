#include "pump.h"

void pump_on(void (*f)(uint8_t, uint8_t)){
    f(PUMP_PIN, PUMP_HIGH);
}

void pump_off(void (*f)(uint8_t, uint8_t)){
    f(PUMP_PIN, PUMP_LOW);
}
