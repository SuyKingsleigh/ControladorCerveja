#include "temp.h" 


float read_temp(){
	return (analogRead(TEMP_SENSOR_PIN)/1024.0)*500; // converte de mV para *C 
}


void pre_heat(){
	_set_heat(_MAX_POWER);
	while(read_temp() < MAX_TEMP_WATER) {;} 
	_set_heat(_MIN_POWER);
}


void _set_heat(bool power){
	digitalWrite(TEMP_HEATER_PIN, power);
}


void set_temp(float temp){
	while(read_temp() < temp) _raise_temp();
}


void _raise_temp(){
	auto start = millis()*1000;
	float desired_temp = read_temp() + 1; // temperatura desejada 

	// fica nesse loop por 1 minuto 
	while (((millis()*1000) - start) < 60){		
		// caso a temperatura medida seja maior que a desejada, desliga a resistencia
		// caso contrario a liga 
		(read_temp() >= desired_temp) ? _set_heat(_MIN_POWER) : _set_heat(_MAX_POWER); 
		delay(100);
	}
}

