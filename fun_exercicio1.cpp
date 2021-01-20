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
Vari�vel X e c da Firma, min e max par�metros da Firma
V: chamando o valor da vari�vel 
L: lag - defasagens - quantos per�odos pra tr�s 
S: specific object 
c: � um par�metro, valor fixo no tempo, n�o precisa descrever equa��o para par�metro 
*/
RESULT(VL("X",1)+V("c"))

EQUATION("c") 
v[0]=V("min");
v[1]=V("max");
v[2]=uniform(v[0], v[1]);
// na hora da simula��o, colocamos os par�metros que quisermos para min e max
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
Tem que manter a defini��o da equa��o "c" em seguida
*/


EQUATION("X_Sum")
/*
Vari�vel do Setor
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
Vari�vel do Setor
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
//v[1] pode ser v[1]=COUNT("FIRM") e tira o v[1]=0 de cima
//pode substituir o if else por: v[2] = v[1] != 0? v[0]/v[1] : 0; 

EQUATION("X_Max")
/*
Vari�vel do Setor
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
//pode substituir o if else por: v[0]=v[2]>v[0]?v[2]:v[0];


EQUATION("X_Marketshare")
/*
Vari�vel da Firma
*/
RESULT((V("X")/V("X_Sum")))
/*
Forma extensa alternativa:
v[0]=V("X")
v[1]=V("X_Sum")
if(v[1]!=0)
v[2]=v[0]/v[1]
else
v[2]=0
RESULT(v[2])
*/

EQUATION("Marketshare_Sum")
/*
Vari�vel da Setor
*/
v[0]=0;
CYCLE(cur, "FIRM")
{
	v[1]=VS(cur,"X_Marketshare");
	v[0]=v[0]+v[1];
}
RESULT(v[0])
//Mais simples: RESULT(SUM("X_Marketshare"))


EQUATION("Leader")
/*
Vari�vel do Setor 
*/
v[0]=0;
v[1]=0;
CYCLE(cur, "FIRM")
{
	v[1]++;
	//� a mesma coisa que v[1]=v[1]+1 
	v[2]=VS(cur, "X");
	if(v[2]>v[0])
		{
		v[0]=v[2];
		v[3]=v[1];
		}	
}
RESULT(v[3])
/*
Usando o SEARCH:
 
EQUATION("Leader") 
v[0]=V("X_Max"); 
cur1=SEARCH_CND("X", v[0]); 
v[1]=SEARCH_INST(cur1);
RESULT(v[1])

J� sabe o valor m�x, ent�o procura a firma condicionado ao valor que voc� estipulou 
v[1] � o resultado da pesquisa da inst�ncia (a posi��o) da firm de valor m�x encontrada
*/

EQUATION("Rank")
/*
Vari�vel do Setor
*/
		SORT("FIRM", "X", "DOWN");
		v[0]=0;
		CYCLE(cur,"FIRM")
				{
				v[0]++;
				WRITES(cur, "Firm_Rank", v[0]); // Firm_Rank � par�metro da Firma
				}
RESULT(0)

/* 
Se quiser que seja uma vari�vel ou inv�s de par�metro 
EQUATION_DUMMY("Firm_Rank", "Rank")
*/
		



MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
