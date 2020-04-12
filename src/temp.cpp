#include "temp.h" 



float read_temp(){
	return (analogRead(TEMP_SENSOR_PIN)/1024.0)*500; // converte de mV para *C 
}


void pre_heat(){
	set_heat(_MAX_POWER);
}


void set_heat(int power){
	analogWrite(TEMP_HEATER_PIN, (power*1024)/500); // converte de *C para mV
}
