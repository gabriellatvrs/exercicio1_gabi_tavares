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

EQUATION("c") 
v[0]=V("min");
v[1]=V("max");
v[2]=uniform(v[0], v[1]);
// na hora da simulação, colocamos os parâmetros que quisermos para min e max
RESULT(v[2])

/*
OUTRAS FORMAS DE FAZER 

EQUATION("X")
RESULT(VL("X",1)+RND)

EQUATION("X")
v[0]=VL("X",1);
v[1]=V("c");
v[2]=v[0]+v[1];
RESULT(v[2])
Tem que manter a definição da equação "c" em seguida
*/


EQUATION("X_Sum")
/*
Variável do Setor
*/
v[0]=0;
CYCLE(cur, "FIRM")
{
	v[1]=VS(cur,"X");
	v[0]=v[0]+v[1];
}

RESULT(v[0])

EQUATION("X_Ave")
/*
Variável do Setor
*/
v[0]=0;
v[1]=0;
v[2]=0;
CYCLE(cur, "FIRM")
{
	v[3]=VS(cur,"X");
	v[0]=v[0]+v[3];
	v[1]=v[1]+1;
}
if(v[1]==0)	
v[2]=0; 
else 
v[2]=v[0]/v[1]
RESULT(v[2])

EQUATION("X_Max")
/*
Variável do Setor
*/
v[0]=0;
CYCLE(cur, "FIRM")
{
	v[1]=VS(cur,"X");
	
	if(v[1]>=v[0]) 	
	v[0]=v[1]; 
	else 
	v[0]=v[0];
}
RESULT(v[0])

EQUATION("X_Marketshare")
/*
Variável da Firma
*/
RESULT((V("X")/V("X_Sum")))

EQUATION("Marketshare_Sum")
/*
Variável da Firma
*/
v[0]=0;
CYCLE(cur, "FIRM")
{
	v[1]=VS(cur,"X_Marketshare");
	v[0]=v[0]+v[1];
}
RESULT(v[0])



MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
