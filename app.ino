#include <LiquidCrystal.h>

#include "src/temp.h"
#include "src/pump.h"
#include "src/user_interface.h"
#include "src/receita.h"

Receita * recipe; 
Config * conf; 

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
float t;

bool status = HIGH;

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
    
    // pinos do botoes
    pinMode(ENTER, INPUT);
    pinMode(EXIT, INPUT);
    pinMode(UP, INPUT);
    pinMode(LOW, INPUT);

    // obtem as configuracoes 
    lcd.begin(16,2);
    conf = menu(lcd);

    // apenas para debug 
    Serial.begin(9600);
}

void loop(){
    // t = read_temp();
    // print_temp(t);
    // Serial.println(status);
    // digitalWrite(TEMP_HEATER_PIN, status);
    // delay(1000);
    // status = !status;
}
