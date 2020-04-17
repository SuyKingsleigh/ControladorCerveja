#include "user_interface.h"


bool set_mode(LiquidCrystal &lcd){  
    lcd.clear();
    lcd.print("manual ou automatico");

    while(1){
        if(digitalRead(UP)){
            lcd.clear();
            lcd.print("automatico");
            delay(1000);
            return AUTOMATICO;
        }
        if(digitalRead(LOW)){
            lcd.clear();
            lcd.print("manual");
            delay(1000);
            return MANUAL;
        }
    }
}


int _get_temp(LiquidCrystal &lcd, const char * str){
    uint8_t a = 30;

    lcd.clear(); 
    lcd.println(str);
    delay(750);

    while(true){
        lcd.clear();

        if(digitalRead(UP)) a += 5; 
        if(digitalRead(LOW)) a -=5;

        if(a > 100) a = 100;
        if(a < 25) a = 25;

        lcd.print(a); 
        delay(250);
        if(digitalRead(ENTER)) break;
    }

    lcd.clear();
    return a;
}


Receita set_receita(LiquidCrystal &lcd){
    lcd.clear();
    Receita rct; 

    rct.a = _get_temp(lcd, "primeiro");
    rct.b = _get_temp(lcd, "segundo");
    rct.c = _get_temp(lcd, "terceiro");

    lcd.println("iniciando");
    return rct; 
}


void notify(){
    // TODO
}


Config menu(LiquidCrystal &lcd){
    Config conf; 
    conf.mode = set_mode(lcd);
    lcd.clear();
  
    conf.recipe = (conf.mode == AUTOMATICO) ? receita_default() : set_receita(lcd);

    return conf; 
}

