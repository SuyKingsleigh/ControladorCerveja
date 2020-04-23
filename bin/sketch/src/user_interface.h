#if !defined(USER_INTERFACE)
#define USER_INTERFACE

#include "receita.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

#define MANUAL false 
#define AUTOMATICO true

// botoes
#define ENTER 8
#define UP 10 
#define LOW 11

#define BUZZER A1 

// display 
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7


/**
 * Usará quatro botões, "mais", "menos" e "enter"
 * O fluxo será: 
 * > Escolher modo (manual ou automatico, + e - para escolher)
 * > Se manual: usará os botões + - e para controlar os tempos e 
*/


// ********************* Modulo para as operações do usuario (entrada de dados) *************************//


struct Config{
    bool mode; 
    Receita recipe;
};


/**
 * Define o modo de operação 
*/
bool set_mode(LiquidCrystal &lcd);

/**
 * Extrai as temperaturas de cada um dos três ingredientes  
*/
int _get_temp(LiquidCrystal &lcd, const char * str);

/**
 * Usuario definirá a receita
*/
Receita set_receita(LiquidCrystal &lcd);

/**
 * Usuario definirá modo 
 * se for automático, define também a receita 
*/
Config menu(LiquidCrystal &lcd);

/**
 * Notificará ao usuário algum evento
 * Ficara bipando até ele pressionar o ENTER
*/
void notify(LiquidCrystal &lcd, const char * str);


#endif // USER_INTERFACE