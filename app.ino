#include "src/temp.h"
#include "src/pump.h"
#include "src/user_interface.h"
#include "src/receita.h"


Receita * recipe; 
float t;


void print_temp(float &t){
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print("*C");
    Serial.println();
}


void setup(){
    // pinos da temperatura 
    pinMode(TEMP_SENSOR_PIN, INPUT);
    pinMode(TEMP_HEATER_PIN, OUTPUT);

    // pinos da bomba
    pinMode(PUMP_PIN, OUTPUT);
    pinMode(TANK_SENSOR_PIN, INPUT);
    
    // define modo de operação e receita
    if(get_mode() == AUTOMATICO){
        recipe = auto_mode();
    }

    Serial.begin(9600);
}

void loop(){
    t = read_temp();
    print_temp(t);
}
