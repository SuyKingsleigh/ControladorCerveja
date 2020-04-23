#include <LiquidCrystal.h>

#include "src/temp.h"
#include "src/pump.h"
#include "src/receita.h"
#include "src/user_interface.h"

Config conf; 
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup(){
    // pinos da temperatura 
    pinMode(TEMP_SENSOR_PIN, INPUT);
    pinMode(TEMP_HEATER_PIN, OUTPUT);

    // pinos da bomba
    pinMode(PUMP_PIN, OUTPUT);
    pinMode(TANK_SENSOR_PIN, INPUT);
    
    // pinos do botoes
    pinMode(UP, INPUT);
    pinMode(LOW, INPUT);
    pinMode(ENTER, INPUT);

    pinMode(BUZZER, OUTPUT);
    lcd.begin(16,2);

    // pega a receita
    conf = menu(lcd);

    // fica bloqueado ate encher o tanque de agua 
    // quando estiver cheio, ferve a agua e liga a bomba
    if(!check_water_min_lvl()) lcd.println("sem agua");
    while(!check_water_min_lvl()){;}
    
    lcd.clear();
    lcd.println("Esquentando");
    pre_heat();

    pump_on();
    lcd.clear();
    lcd.println("Iniciando");
}

void loop(){
    // Notifica para adicionar os igredientes
    // controla a temperatura aumentando 1*C por min 
    // quando termina os três ingredientes sinaliza o fim da receita 

    notify(lcd, "ing 1");
    set_temp(conf.recipe.a, lcd);
    keep_temp(2, lcd);

    notify(lcd, "ing 2");
    set_temp(conf.recipe.b, lcd);
    keep_temp(2, lcd);

    notify(lcd, "ing 3");
    set_temp(conf.recipe.c, lcd);
    keep_temp(2, lcd);

    // notifica fim
    notify(lcd, "FIM");
    pump_off();
}