//#define EIGENLIB			// uncomment to use Eigen linear algebra library
//#define NO_POINTER_INIT	// uncomment to disable pointer checking

#include "fun_head_fast.h"

// do not add Equations in this area

MODELBEGIN

// insert your equations here, between the MODELBEGIN and MODELEND words

/* 
ou assim para comentar em parágrafos
ctrl + i mostra os macros
c++ reconhece maiúsculo vs. minúsculo
não aceita acento, espaço ou caractere especial, apenas _
*/


EQUATION("X")
/*
Variável X
V: chamando o valor da variável 
L: lag - defasagens - quantos períodos pra trás 
S: specific object 
c: é um parâmetro, valor fixo no tempo, não precisa descrever equação para parâmetro 
*/

RESULT(VL("X",1)+V("c"))









MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
