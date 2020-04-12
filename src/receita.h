#if !defined(RECEITA)
#define RECEITA


#include <stdint.h>

#define DEF_LUPULO 30
#define DEF_MALTE 30 
#define DEF_LEVEDURAS 30

//****************** Modulo para organizar os dados da receita *************************//

/**
 *  Armazena os tempos (até três) da receita
*/
struct Receita{
    uint8_t lupulo; 
    uint8_t malte;
    uint8_t leveduras; 
};

Receita * auto_mode();

#endif // RECEITA