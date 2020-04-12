#include "temp.h" 


float read_temp(){
	return (analogRead(TEMP_SENSOR_PIN)/1024.0)*500; // converte de mV para *C 
}


void pre_heat(){
	_set_heat(_MAX_POWER);
	while(read_temp() < MAX_TEMP_WATER) {;}
}


void _set_heat(int power){
	analogWrite(TEMP_HEATER_PIN, (power*1024)/500); // converte de *C para mV
}


void set_temp(float temp){
	float t = read_temp();
	if(t == temp) return;
	if(t > temp){
		_set_heat(_MIN_POWER);
		while(read_temp() >= temp){;}
	}else{
		_set_heat(_MAX_POWER);
		while(read_temp() <= temp){;}
	}
}

