#if !defined(RECEITA)
#define RECEITA

#include <stdint.h>

#define ING_A 70
#define ING_B 75
#define ING_C 80


//****************** Modulo para organizar os dados da receita *************************//


/**
 *  Armazena os tempos (até três) da receita
 *  aumentara a temperatura por ingrediente 
*/
struct Receita{
    uint8_t a; 
    uint8_t b;
    uint8_t c; 
};

/**
 * Retorna uma receita com valores padrões 
 * Para o uso no modo automático 
*/
Receita receita_default();


#endif // RECEITA