#include "src/temp.h"

void setup(){
	
}

void loop(){
	float t = read_temp(&analogRead);
    pre_heat(&analogWrite);
    set_heat(&analogWrite, 69); 
}
