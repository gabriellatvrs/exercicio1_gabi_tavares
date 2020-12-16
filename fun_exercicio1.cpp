//#define EIGENLIB			// uncomment to use Eigen linear algebra library
//#define NO_POINTER_INIT	// uncomment to disable pointer checking

#include "fun_head_fast.h"

// do not add Equations in this area

MODELBEGIN

// insert your equations here, between the MODELBEGIN and MODELEND words

/* 
ou assim para comentar em par�grafos
ctrl + i mostra os macros
c++ reconhece mai�sculo vs. min�sculo
n�o aceita acento, espa�o ou caractere especial, apenas _
*/


EQUATION("X")
/*
Vari�vel X
V: chamando o valor da vari�vel 
L: lag - defasagens - quantos per�odos pra tr�s 
S: specific object 
c: � um par�metro, valor fixo no tempo, n�o precisa descrever equa��o para par�metro 
*/

RESULT(VL("X",1)+V("c"))









MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
