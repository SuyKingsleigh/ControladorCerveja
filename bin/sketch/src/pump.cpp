#include "pump.h"


void pump_on(){
    digitalWrite(PUMP_PIN, HIGH);
}


void pump_off(){
    digitalWrite(PUMP_PIN, LOW);
}


bool check_water_min_lvl(){
    return digitalRead(TANK_SENSOR_PIN) == HIGH;
}