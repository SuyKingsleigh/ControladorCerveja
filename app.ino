#include "src/temp.h"
#include "src/pump.h"

Receita *recipe;

void setup(){

    recipe->leveduras = 30;
    recipe->lupulo = 30;
    recipe->malte = 30;
}

void loop(){
	float t = read_temp(&analogRead);
    pre_heat(&analogWrite);
    set_heat(&analogWrite, 69); 
    pump_on(&digitalWrite);
    pump_off(&digitalWrite);
    
}
