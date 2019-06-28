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
* Time: 22:07:46
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
//#include "common.h"
#include "myparser.h"
#include <string>
#include <string.h>
using namespace std;

struct myYYTYPE {
	int ival;
	string sval;
	bool bval;
};


void print_token(int token, char* lex,string name);


#line 67 "mylexer.cpp"
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
#line 45 ".\\mylexer.l"

//this code will be added into yyaction function
    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
    //double yylval;

#line 165 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 51 ".\\mylexer.l"
/* do nothing */
#line 172 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 53 ".\\mylexer.l"
print_token(-1,yytext,"comment");
#line 179 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 56 ".\\mylexer.l"
print_token(_NUM, yytext, "int"); yylval.ival = atoi(yytext); return _NUM; 
#line 186 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 58 ".\\mylexer.l"
print_token(_BOOL, yytext, "bool"); yylval.bval = strcmp(yytext,"true")==0; return _BOOL; 
#line 193 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 60 ".\\mylexer.l"
print_token(_IF, yytext,"control");return _IF; 
#line 200 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 61 ".\\mylexer.l"
print_token(_ELSE, yytext,"control");return _ELSE; 
#line 207 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 62 ".\\mylexer.l"
print_token(_WHILE, yytext,"control");return _WHILE; 
#line 214 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 64 ".\\mylexer.l"
print_token(_ID, yytext, "id"); 
		yylval.sval = string(yytext);
		return _ID; 
#line 223 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 68 ".\\mylexer.l"
print_token(_PLUS, yytext,"operator"); return _PLUS;
#line 230 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 69 ".\\mylexer.l"
print_token(_MINUS, yytext,"operator"); return _MINUS;
#line 237 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 70 ".\\mylexer.l"
print_token(_TIMES, yytext,"operator"); return _TIMES;
#line 244 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 71 ".\\mylexer.l"
print_token(_EQ, yytext,"relation"); return _EQ;
#line 251 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 72 ".\\mylexer.l"
print_token(_LT, yytext,"relation"); return _LT;
#line 258 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 73 ".\\mylexer.l"
print_token(_GT, yytext,"relation"); return _GT;
#line 265 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 74 ".\\mylexer.l"
print_token(_ELT, yytext,"relation"); return _ELT;
#line 272 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 75 ".\\mylexer.l"
print_token(_EGT, yytext,"relation"); return _EGT;
#line 279 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 76 ".\\mylexer.l"
print_token(_NEQ, yytext,"relation"); return _NEQ;
#line 286 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 78 ".\\mylexer.l"
print_token(_EVAL, yytext,"eval operator "); return _EVAL;
#line 293 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 81 ".\\mylexer.l"
print_token(_NOT, yytext,"relop"); return _NOT;
#line 300 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 82 ".\\mylexer.l"
print_token(_AND, yytext,"relop"); return _AND;
#line 307 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 83 ".\\mylexer.l"
print_token(_OR, yytext,"relop"); return _OR;
#line 314 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 86 ".\\mylexer.l"
print_token(_SEM, yytext,"program");return _SEM;
#line 321 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 88 ".\\mylexer.l"
print_token(_LP, yytext,"prority");return _LP;
#line 328 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 89 ".\\mylexer.l"
print_token(_RP, yytext,"prority");return _RP;
#line 335 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 91 ".\\mylexer.l"
print_token(_LC, yytext,"block");return _LC;
#line 342 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 92 ".\\mylexer.l"
print_token(_RC, yytext,"block");return _RC;
#line 349 "mylexer.cpp"
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
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 27, 14 },
		{ 28, 14 },
		{ 29, 15 },
		{ 30, 16 },
		{ 31, 18 },
		{ 32, 19 },
		{ 33, 20 },
		{ 34, 21 },
		{ 35, 22 },
		{ 3, 1 },
		{ 4, 1 },
		{ 3, 3 },
		{ 36, 24 },
		{ 0, 26 },
		{ 37, 31 },
		{ 5, 1 },
		{ 38, 32 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 39, 34 },
		{ 10, 1 },
		{ 40, 35 },
		{ 11, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 41, 37 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 39, 38 },
		{ 42, 39 },
		{ 43, 40 },
		{ 44, 43 },
		{ 26, 11 },
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
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 18, 1 },
		{ 19, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 20, 1 },
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
		{ 21, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 17, 44 },
		{ 0, 0 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 },
		{ 17, 44 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 44, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 1 },
		{ 0, 0, 19 },
		{ 0, 0, 20 },
		{ 0, 0, 23 },
		{ 0, 0, 24 },
		{ 0, 0, 11 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 12, 0 },
		{ 0, -43, 3 },
		{ 0, 0, 22 },
		{ 0, -46, 13 },
		{ 0, -44, 18 },
		{ 0, -43, 14 },
		{ 44, 0, 8 },
		{ 44, -89, 8 },
		{ 44, -77, 8 },
		{ 44, -81, 8 },
		{ 44, -92, 8 },
		{ 44, -81, 8 },
		{ 0, 0, 25 },
		{ 0, -97, 0 },
		{ 0, 0, 26 },
		{ -26, 18, 2 },
		{ 0, 0, 15 },
		{ 0, 0, 17 },
		{ 0, 0, 12 },
		{ 0, 0, 16 },
		{ 44, -86, 8 },
		{ 44, -77, 8 },
		{ 44, 0, 5 },
		{ 44, -81, 8 },
		{ 44, -67, 8 },
		{ 0, 0, 21 },
		{ 44, -51, 8 },
		{ 44, -60, 8 },
		{ 44, -45, 8 },
		{ 44, -51, 8 },
		{ 44, 0, 6 },
		{ 44, 0, 4 },
		{ 44, -43, 8 },
		{ 0, 70, 7 }
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
		0
	};
	yybackup = backup;
}
#line 96 ".\\mylexer.l"




 void print_token(int token, char* lex,string name="no name")
{
	cout<<"\t dic "<<name<<" : "<<lex<<" token:"<<token<<endl;
}


