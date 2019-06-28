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
* mylexer.h
* C++ header file generated from mylexer.l.
* 
* Date: 06/19/19
* Time: 20:13:56
* 
* ALex Version: 2.07
****************************************************************************/

#ifndef _MYLEXER_H
#define _MYLEXER_H

#include <yyclex.h>

/////////////////////////////////////////////////////////////////////////////
// mylexer

#ifndef YYEXPLEXER
#define YYEXPLEXER
#endif

class YYEXPLEXER YYFAR mylexer : public _YL yyflexer {
public:
	mylexer();
	virtual ~mylexer();

	// backards compatibility with lex
#ifdef input
	virtual int yyinput();
#endif
#ifdef output
	virtual void yyoutput(int ch);
#endif
#ifdef unput
	virtual void yyunput(int ch);
#endif

protected:
	void yytables();
	virtual int yyaction(int action);

public:
};

#ifndef YYLEXERNAME
#define YYLEXERNAME mylexer
#endif

#ifndef INITIAL
#define INITIAL 0
#endif

#endif
