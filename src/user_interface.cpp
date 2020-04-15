#include "user_interface.h"


bool set_mode(LiquidCrystal &lcd){
    return true;
}


Receita * set_receita(LiquidCrystal & lcd){
    return nullptr;
}


void notify(){
    // TODO
}


Config * menu(LiquidCrystal &lcd){
    Config * conf; 
    conf->mode = set_mode(lcd);
    conf->recipe = (conf->mode == AUTOMATICO) ? receita_default() : set_receita(lcd);
    return conf; 
}