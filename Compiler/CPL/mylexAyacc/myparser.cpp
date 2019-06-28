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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 06/19/19
* Time: 22:20:03
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年6月10日
****************************************************************************/

#include <string>
//#include "common.h"
#include "mylexer.h"

using namespace std;

struct myYYTYPE {
	int ival;
	string sval;
	bool bval;
};

void msg(string str, string extr = " ") {
	cout << "grammar " << str << " " << extr << endl << endl;;
}


#line 64 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 56 ".\\myparser.y"
 msg("gramar: ="); 
#line 202 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 57 ".\\myparser.y"
 msg("gramar:P;P"); 
#line 215 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 58 ".\\myparser.y"
 msg("gramar:WHILE");
#line 228 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 59 ".\\myparser.y"
 msg("gramar:IF ELSE"); 
#line 241 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 63 ".\\myparser.y"
 cout << yyattribute(1 - 1).bval; 
#line 254 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 64 ".\\myparser.y"
 msg("logic calc:=="); 
#line 267 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 65 ".\\myparser.y"
 msg("logic calc:<"); 
#line 280 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 66 ".\\myparser.y"
 msg("logic calc:>"); 
#line 293 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 67 ".\\myparser.y"
 msg("logic calc:<="); 
#line 306 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 68 ".\\myparser.y"
 msg("logic calc:>=");
#line 319 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 69 ".\\myparser.y"
 msg("logic calc:<>"); 
#line 332 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 70 ".\\myparser.y"
 msg("logic calc:!"); 
#line 345 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 71 ".\\myparser.y"
 msg("logic calc:&"); 
#line 358 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 72 ".\\myparser.y"
 msg("logic calc:||"); 
#line 371 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 76 ".\\myparser.y"
 msg("calc:minus");
#line 384 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 77 ".\\myparser.y"
 msg("calc:-E");
#line 397 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 78 ".\\myparser.y"
 msg("calc:plus");
#line 410 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 79 ".\\myparser.y"
 msg("calc:times"); 
#line 423 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 81 ".\\myparser.y"
 cout << yyattribute(1 - 1).sval; 
#line 436 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "_WHILE", 257 },
		{ "_LP", 258 },
		{ "_RP", 259 },
		{ "_LC", 260 },
		{ "_RC", 261 },
		{ "_ID", 262 },
		{ "_NUM", 263 },
		{ "_BOOL", 264 },
		{ "_EVAL", 265 },
		{ "_TIMES", 266 },
		{ "_MINUS", 267 },
		{ "_PLUS", 268 },
		{ "_LT", 269 },
		{ "_EQ", 270 },
		{ "_GT", 271 },
		{ "_ELT", 272 },
		{ "_EGT", 273 },
		{ "_NEQ", 274 },
		{ "_NOT", 275 },
		{ "_AND", 276 },
		{ "_OR", 277 },
		{ "_IF", 278 },
		{ "_ELSE", 279 },
		{ "_SEM", 280 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: P",
		"P: _ID _EVAL E",
		"P: P _SEM P",
		"P: _WHILE B _LC P _RC",
		"P: _IF B _LC P _RC _ELSE _LC P _RC",
		"B: _BOOL",
		"B: E _EQ E",
		"B: E _LT E",
		"B: E _GT E",
		"B: E _ELT E",
		"B: E _EGT E",
		"B: E _NEQ E",
		"B: _NOT B",
		"B: B _AND B",
		"B: B _OR B",
		"E: E _MINUS E",
		"E: _MINUS E",
		"E: E _PLUS E",
		"E: E _TIMES E",
		"E: _LP E _RP",
		"E: _ID",
		"E: _NUM"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 3, 0 },
		{ 1, 3, 1 },
		{ 1, 5, 2 },
		{ 1, 9, 3 },
		{ 2, 1, 4 },
		{ 2, 3, 5 },
		{ 2, 3, 6 },
		{ 2, 3, 7 },
		{ 2, 3, 8 },
		{ 2, 3, 9 },
		{ 2, 3, 10 },
		{ 2, 2, 11 },
		{ 2, 3, 12 },
		{ 2, 3, 13 },
		{ 3, 3, 14 },
		{ 3, 2, 15 },
		{ 3, 3, 16 },
		{ 3, 3, 17 },
		{ 3, 3, -1 },
		{ 3, 1, 18 },
		{ 3, 1, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 281;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 4, YYAT_ACCEPT, 0 },
		{ 11, YYAT_ERROR, 0 },
		{ 14, YYAT_SHIFT, 32 },
		{ 51, YYAT_SHIFT, 1 },
		{ 50, YYAT_SHIFT, 51 },
		{ 49, YYAT_SHIFT, 50 },
		{ 52, YYAT_SHIFT, 53 },
		{ 47, YYAT_SHIFT, 49 },
		{ 51, YYAT_SHIFT, 2 },
		{ 44, YYAT_SHIFT, 48 },
		{ 12, YYAT_SHIFT, 28 },
		{ 11, YYAT_SHIFT, 22 },
		{ 11, YYAT_SHIFT, 23 },
		{ 11, YYAT_SHIFT, 24 },
		{ 11, YYAT_SHIFT, 25 },
		{ 11, YYAT_SHIFT, 26 },
		{ 11, YYAT_SHIFT, 27 },
		{ 30, YYAT_SHIFT, 5 },
		{ 14, YYAT_SHIFT, 29 },
		{ 14, YYAT_SHIFT, 30 },
		{ 16, YYAT_SHIFT, 34 },
		{ 30, YYAT_SHIFT, 6 },
		{ 30, YYAT_SHIFT, 7 },
		{ 30, YYAT_SHIFT, 8 },
		{ 51, YYAT_SHIFT, 3 },
		{ 52, YYAT_SHIFT, 15 },
		{ 30, YYAT_SHIFT, 9 },
		{ 16, YYAT_SHIFT, 19 },
		{ 16, YYAT_SHIFT, 20 },
		{ 16, YYAT_SHIFT, 21 },
		{ 27, YYAT_ERROR, 0 },
		{ 43, YYAT_SHIFT, 19 },
		{ 43, YYAT_SHIFT, 20 },
		{ 43, YYAT_SHIFT, 21 },
		{ 30, YYAT_SHIFT, 10 },
		{ 42, YYAT_SHIFT, 19 },
		{ 42, YYAT_SHIFT, 20 },
		{ 42, YYAT_SHIFT, 21 },
		{ 41, YYAT_SHIFT, 19 },
		{ 41, YYAT_SHIFT, 20 },
		{ 41, YYAT_SHIFT, 21 },
		{ 27, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 19 },
		{ 40, YYAT_SHIFT, 20 },
		{ 40, YYAT_SHIFT, 21 },
		{ 39, YYAT_SHIFT, 19 },
		{ 39, YYAT_SHIFT, 20 },
		{ 39, YYAT_SHIFT, 21 },
		{ 38, YYAT_SHIFT, 19 },
		{ 38, YYAT_SHIFT, 20 },
		{ 38, YYAT_SHIFT, 21 },
		{ 31, YYAT_SHIFT, 19 },
		{ 31, YYAT_SHIFT, 20 },
		{ 31, YYAT_SHIFT, 21 },
		{ 2, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 4, YYAT_SHIFT, 15 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 0, 0, YYAT_DEFAULT, 51 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ -211, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ 0, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ -258, 1, YYAT_DEFAULT, 16 },
		{ -250, 1, YYAT_DEFAULT, 14 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ -258, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 51 },
		{ -239, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ -234, 1, YYAT_DEFAULT, 30 },
		{ 0, 0, YYAT_DEFAULT, 51 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ -241, 1, YYAT_ERROR, 0 },
		{ -215, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 51 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -218, 1, YYAT_REDUCE, 7 },
		{ -221, 1, YYAT_REDUCE, 6 },
		{ -224, 1, YYAT_REDUCE, 8 },
		{ -228, 1, YYAT_REDUCE, 9 },
		{ -231, 1, YYAT_REDUCE, 10 },
		{ -235, 1, YYAT_REDUCE, 11 },
		{ -252, 1, YYAT_DEFAULT, 52 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ -254, 1, YYAT_DEFAULT, 52 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -274, 1, YYAT_ERROR, 0 },
		{ -256, 1, YYAT_ERROR, 0 },
		{ -254, 1, YYAT_ERROR, 0 },
		{ -255, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 4 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 23;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 30, 46 },
		{ 30, 11 },
		{ 51, 52 },
		{ 32, 47 },
		{ 29, 45 },
		{ 28, 44 },
		{ 27, 43 },
		{ 26, 42 },
		{ 25, 41 },
		{ 24, 40 },
		{ 23, 39 },
		{ 22, 38 },
		{ 21, 37 },
		{ 20, 36 },
		{ 19, 35 },
		{ 15, 33 },
		{ 13, 31 },
		{ 10, 18 },
		{ 9, 17 },
		{ 5, 16 },
		{ 3, 14 },
		{ 1, 12 },
		{ 0, 4 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 21, -1 },
		{ 19, 30 },
		{ 0, -1 },
		{ 18, 30 },
		{ 0, -1 },
		{ 16, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 15, -1 },
		{ 15, 30 },
		{ 0, -1 },
		{ 0, -1 },
		{ 13, -1 },
		{ 0, -1 },
		{ 14, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 11, -1 },
		{ 10, -1 },
		{ 9, -1 },
		{ 8, -1 },
		{ 7, -1 },
		{ 6, -1 },
		{ 5, -1 },
		{ 4, -1 },
		{ 3, -1 },
		{ 4, -1 },
		{ 2, 30 },
		{ -2, -1 },
		{ 0, -1 },
		{ 2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 1, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 86 ".\\myparser.y"




int main(int argc, char *argv[])
{
	cin.sync();
	freopen("example.txt","r",stdin);
	int n = 1;
	mylexer lexer;
	myparser parser;
	
		if (parser.yycreate(&lexer)) {
			if (lexer.yycreate(&parser)) {
				n = parser.yyparse();
				cout << "\nparser return:" << n << endl;
			}
		}
//	freopen("CON","r",stdin);
	cout<<"\n#######语法分析成功#######"<<endl;
	system("pause");
	return n;
}
