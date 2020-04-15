#include "receita.h"


Receita * receita_default(){
    Receita * r;
    r->leveduras = DEF_LEVEDURAS;
    r->malte = DEF_MALTE;
    r->lupulo = DEF_LUPULO;
}