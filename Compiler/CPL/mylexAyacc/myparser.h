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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 06/19/19
* Time: 22:20:03
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 30 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE myYYTYPE
#endif



#line 79 "myparser.h"
#define _WHILE 257
#define _LP 258
#define _RP 259
#define _LC 260
#define _RC 261
#define _ID 262
#define _NUM 263
#define _BOOL 264
#define _EVAL 265
#define _TIMES 266
#define _MINUS 267
#define _PLUS 268
#define _LT 269
#define _EQ 270
#define _GT 271
#define _ELT 272
#define _EGT 273
#define _NEQ 274
#define _NOT 275
#define _AND 276
#define _OR 277
#define _IF 278
#define _ELSE 279
#define _SEM 280
#endif
