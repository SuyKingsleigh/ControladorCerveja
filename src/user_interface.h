#if !defined(USER_INTERFACE)
#define USER_INTERFACE


#include "receita.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

#define MANUAL false 
#define AUTOMATICO true

// botoes
#define ENTER 8
#define EXIT 9
#define UP 10 
#define LOW 11

// display 
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7


/**
 * Usará quatro botões, "mais", "menos", "ok" e "exit"
 * O fluxo será: 
 * > Escolher modo (manual ou automatico, + e - para escolher)
 * > Se manual: tempos dos ingredientes
*/


// ********************* Modulo para as operações do usuario (entrada de dados) *************************//


struct Config{
    bool mode; 
    Receita recipe;
};

/**
 * Verifica se o botao esta pressionado 
 * @return true se pressionado
*/
bool is_pressed(uint8_t btn);

/**
 * Define o modo de operação 
*/
bool set_mode(LiquidCrystal &lcd);

/**
 * Extrai as temperaturas de cada um dos três ingredientes  
*/
int _get_temp(LiquidCrystal &lcd, const char * str);

/**
 * Usuario define a receita
*/
Receita set_receita(LiquidCrystal &lcd);

/**
 * Usuario define modo 
 * e se for automatico, define tambem a receita 
*/
Config menu(LiquidCrystal &lcd);

/**
 * Notificara o usuario de algum evento
*/
void notify(LiquidCrystal &lcd);

#endif // USER_INTERFACE