/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 63 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 06/19/19
* Time: 20:13:56
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019Äê6ÔÂ10ÈÕ
****************************************************************************/



//this code will be added into the header of generated .cpp file
#include <iostream>
#include "help.h"
#include "myparser.h"
#include <string>
#include <string.h>
using namespace std;



void print_token(int token, char* lex,string name);
/*
enum _TOKEN_ {	_ID=0, _NUM,_BOOL,
				_LT,  _EQ, _GT,_ELT,_EGT,_NEQ,
				_NOT,_AND,_OR,
				_IF, _ELSE, _WHILE, 
				_PLUS, _MINUS, _TIMES, _OVER, _EVAL,
				_LP,_RP,_LC,_RC,
				_COMMENT,_EOF
};
*/

#line 71 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 50 ".\\mylexer.l"

//this code will be added into yyaction function
    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
    //double yylval;

#line 169 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 56 ".\\mylexer.l"
/* do nothing */
#line 176 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 58 ".\\mylexer.l"
print_token(-1,yytext,"comment");
#line 183 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 61 ".\\mylexer.l"
print_token(_NUM, yytext, "int"); yylval.ival = atoi(yytext); return _NUM; 
#line 190 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 63 ".\\mylexer.l"
print_token(_BOOL, yytext, "bool"); yylval.bval = strcmp(yytext,"true")==0; return _BOOL; 
#line 197 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 65 ".\\mylexer.l"
print_token(_IF, yytext,"control");return _IF; 
#line 204 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 66 ".\\mylexer.l"
print_token(_ELSE, yytext,"control");return _ELSE; 
#line 211 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 67 ".\\mylexer.l"
print_token(_WHILE, yytext,"control");return _WHILE; 
#line 218 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 69 ".\\mylexer.l"
print_token(_ID, yytext, "id"); 
		yylval.sval = string(yytext);
		return _ID; 
#line 227 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 73 ".\\mylexer.l"
print_token(_PLUS, yytext,"operator"); return _PLUS;
#line 234 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 74 ".\\mylexer.l"
print_token(_UMINUS, yytext,"operator"); return _UMINUS;
#line 241 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 75 ".\\mylexer.l"
print_token(_TIMES, yytext,"operator"); return _TIMES;
#line 248 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 80 ".\\mylexer.l"
print_token(_EQ, yytext,"relation"); return _EQ;
#line 255 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 81 ".\\mylexer.l"
print_token(_ELT, yytext,"relation"); return _ELT;
#line 262 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 82 ".\\mylexer.l"
print_token(_EGT, yytext,"relation"); return _EGT;
#line 269 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 83 ".\\mylexer.l"
print_token(_EVAL, yytext,"eval operator "); return _EVAL;
#line 276 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 84 ".\\mylexer.l"
print_token(_NEQ, yytext,"relation"); return _NEQ;
#line 283 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 85 ".\\mylexer.l"
print_token(_LT, yytext,"relation"); return _LT;
#line 290 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 86 ".\\mylexer.l"
print_token(_GT, yytext,"relation"); return _GT;
#line 297 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 88 ".\\mylexer.l"
print_token(_NOT, yytext,"relop"); return _NOT;
#line 304 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 89 ".\\mylexer.l"
print_token(_AND, yytext,"relop"); return _AND;
#line 311 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 90 ".\\mylexer.l"
print_token(_OR, yytext,"relop"); return _OR;
#line 318 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 93 ".\\mylexer.l"
print_token(_SEM, yytext,"program");return _SEM;
#line 325 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 95 ".\\mylexer.l"
print_token(_LP, yytext,"prority");return _LP;
#line 332 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 96 ".\\mylexer.l"
print_token(_RP, yytext,"prority");return _RP;
#line 339 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 98 ".\\mylexer.l"
print_token(_LC, yytext,"block");return _LC;
#line 346 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 99 ".\\mylexer.l"
print_token(_RC, yytext,"block");return _RC;
#line 353 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 101 ".\\mylexer.l"
 return _EOF; 
#line 360 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 193;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 3, 3 },
		{ 3, 3 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 29, 15 },
		{ 30, 15 },
		{ 28, 12 },
		{ 31, 16 },
		{ 32, 17 },
		{ 33, 19 },
		{ 34, 20 },
		{ 35, 21 },
		{ 36, 22 },
		{ 3, 1 },
		{ 4, 1 },
		{ 3, 3 },
		{ 5, 1 },
		{ 37, 23 },
		{ 38, 25 },
		{ 6, 1 },
		{ 39, 27 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 0, 28 },
		{ 11, 1 },
		{ 40, 33 },
		{ 12, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 41, 34 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 42, 36 },
		{ 43, 37 },
		{ 44, 39 },
		{ 45, 40 },
		{ 42, 41 },
		{ 46, 42 },
		{ 47, 43 },
		{ 48, 44 },
		{ 49, 47 },
		{ 50, 48 },
		{ 27, 5 },
		{ 51, 50 },
		{ 52, 51 },
		{ 53, 52 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 19, 1 },
		{ 20, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 21, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 23, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 18, 49 },
		{ 0, 0 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 },
		{ 18, 49 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 49, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 1 },
		{ 0, 0, 19 },
		{ 0, 30, 0 },
		{ 0, 0, 20 },
		{ 0, 0, 23 },
		{ 0, 0, 24 },
		{ 0, 0, 11 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, -30, 0 },
		{ 0, -43, 3 },
		{ 0, 0, 22 },
		{ 0, -46, 17 },
		{ 0, -43, 15 },
		{ 0, -42, 18 },
		{ 49, 0, 8 },
		{ 49, -88, 8 },
		{ 49, -76, 8 },
		{ 49, -80, 8 },
		{ 49, -91, 8 },
		{ 49, -76, 8 },
		{ 0, 0, 25 },
		{ 0, -95, 0 },
		{ 0, 0, 26 },
		{ 0, -4, 0 },
		{ -28, 26, 2 },
		{ 0, 0, 13 },
		{ 0, 0, 16 },
		{ 0, 0, 12 },
		{ 0, 0, 14 },
		{ 49, -77, 8 },
		{ 49, -58, 8 },
		{ 49, 0, 5 },
		{ 49, -62, 8 },
		{ 49, -49, 8 },
		{ 0, 0, 21 },
		{ 0, -12, 0 },
		{ 49, -43, 8 },
		{ 49, -56, 8 },
		{ 49, -41, 8 },
		{ 49, -47, 8 },
		{ 0, -17, 0 },
		{ 49, 0, 6 },
		{ 49, 0, 4 },
		{ 49, -38, 8 },
		{ 0, -6, 0 },
		{ 0, 70, 7 },
		{ 0, 31, 0 },
		{ 0, 32, 0 },
		{ 0, 33, 0 },
		{ 0, 0, 27 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 103 ".\\mylexer.l"




 void print_token(int token, char* lex,string name="no name")
{
	if(_mCOUNTprinttoken)cout<<"\trecogzed "<<name<<" : "<<lex<<" token:"<<token<<endl;
}


