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


void _print_temp(LiquidCrystal &lcd){
	lcd.clear();
	lcd.print(read_temp());
	lcd.print("*C");
	delay(300);
}


void set_temp(float temp, LiquidCrystal &lcd){
	// se for igual faz nada
	// se for menor, esquenta 1C/min 
	// se for maior desliga a resistencia e espera resfriar
	lcd.clear();
	if(temp == read_temp()) return;
	else if(temp > read_temp())
		while (temp > read_temp()){
			_print_temp(lcd);
			_raise_temp(); // fica preso nesse loop por pelo menos 1 minuto 
		}
	else{
		_set_heat(_MIN_POWER);
		while(temp < read_temp()) _print_temp(lcd);
	}
}


void _raise_temp(){
	auto start = millis();
	float desired_temp = read_temp() + 1; // temperatura desejada 

	// fica nesse loop por 1 minuto 
	while (((millis()) - start) < MINUTO_MS){		
		// caso a temperatura medida seja maior que a desejada, desliga a resistencia
		// caso contrario a liga 
		(read_temp() >= desired_temp) ? _set_heat(_MIN_POWER) : _set_heat(_MAX_POWER); 
		delay(100);
	}
}


void keep_temp(int t_min, LiquidCrystal &lcd){
	auto start = millis();
	float pr_temp = read_temp(); // manter nessa temp 

	lcd.clear();
	lcd.println("Descanso");

	while((millis()-start) < t_min * MINUTO_MS)
		(read_temp() > pr_temp) ? _set_heat(_MIN_POWER) : _set_heat(_MAX_POWER);
}