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
 * Comportamento dos botões: 
 * Pressionado = False 
*/


// ********************* Modulo para as operações do usuario (entrada de dados) *************************//


struct Config{
    bool mode; 
    Receita * recipe;
};

/**
 * Define o modo de operação 
*/
bool set_mode(LiquidCrystal &lcd);

/**
 * Usuario define a receita
*/
Receita * set_receita(LiquidCrystal &lcd);

/**
 * Usuario define modo 
 * e se for automatico, define tambem a receita 
*/
Config * menu(LiquidCrystal &lcd);

/**
 * Notificara o usuario de algum evento
*/
void notify();

#endif // USER_INTERFACE