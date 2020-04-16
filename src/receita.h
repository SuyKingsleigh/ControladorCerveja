#if !defined(RECEITA)
#define RECEITA

#include <stdint.h>

#define ING_A 30
#define ING_B 40 
#define ING_C 50


//****************** Modulo para organizar os dados da receita *************************//


/**
 *  Armazena os tempos (até três) da receita
 *  aumentara a temperatura por ingrediente 
 *  entao um nao pode ser menor que o anterior
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
Receita * receita_default();


#endif // RECEITA