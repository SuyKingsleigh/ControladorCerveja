#include "src/temp.h"
#include "src/pump.h"


// Receita *recipe;
float t;

void print_temp(float &t){
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print("*C");
    Serial.println();
}


void setup(){
    pinMode(TEMP_SENSOR_PIN, INPUT);
    pinMode(TEMP_HEATER_PIN, OUTPUT);
    // recipe->leveduras = 30;
    // recipe->lupulo = 30;
    // recipe->malte = 30;
    Serial.begin(9600);
}

void loop(){
    t = read_temp();
    print_temp(t);
    set_heat(t);
    delay(500);
}
