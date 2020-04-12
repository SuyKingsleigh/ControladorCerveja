#if !defined(USER_INTERFACE)
#define USER_INTERFACE


#include "receita.h"
#include "Arduino.h"

#define MANUAL false 
#define AUTOMATICO true

// ********************* Modulo para as operações do usuario (entrada de dados) *************************//

/**
 * @return  o modo de operacao (manual ou automatico) 
*/
bool get_mode();

/**
 * @return duracao receita 
*/
Receita * get_tempos();

void notify();

#endif // USER_INTERFACE