#include "temp.h" 



float read_temp(int (*f)(uint8_t)){
	return 500*(f)(TEMP_SENSOR_PIN)/1024;
}

void set_heat(void (*f)(uint8_t, int), int power){
	f(TEMP_HEATER_PIN, power);
}

void pre_heat(void (*f)(uint8_t, int)){
	set_heat(f,_MAX_POWER);
}