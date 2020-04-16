#include "receita.h"


Receita * receita_default(){
    Receita * r;
    r->a = ING_A;
    r->b = ING_B;
    r->c = ING_C;
    return r;
}