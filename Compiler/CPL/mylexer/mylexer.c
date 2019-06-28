/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 55 of your 30 day trial period.
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
* mylexer.c
* C source file generated from mylexer.l.
* 
* Date: 06/12/19
* Time: 11:36:13
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.
1
Date: 2019年6月12日
****************************************************************************/
	#define ID 0
	#define NUMBER 1
	#define PLUS 2
	#define MINUS 3
	#define TIMES 4
	#define LP 5
	#define RP 6
	#define TR 7
	#define FA 8
	#define LT 9
	#define EQ 10
	#define MT 11
	#define LTOEQ 12
	#define MTOEQ 13
	#define NE 14
	#define NO 15
	#define AN 16
	#define LOR 17
	#define FUZ 18
	#define SEM 19
	#define LCB 20
	#define RCB 21
	#define TRUE 22
	#define FALSE 23
	
	

#line 40 ".\\mylexer.l"
	cha   	[a-zA-Z]
	digit	[0-9]
	digits	{digit}+
	optional_fraction	(.{digits})?
	optional_exponent	(E[+-]?{digits})?
	
	
#line 83 "mylexer.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mylexer.h"

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

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
#line 79 ".\\mylexer.l"
	{cha}({cha}|{digit})*	
		{ printf("标识符%s\n", yytext);return ID;}
	{digits}{optional_fraction}{optional_exponent}	
		{printf(“数字%s\n", yytext);return NUMBER;}
		  
		{tr}
			{printf ("Logical operations:true\n");return TR}
		{fa}
			{printf ("Logical operations:false\n");return FA}
		{plus} 
			{printf ("加法:+\n");return PLUS;} 
		{minus} 
			{printf ("负数:-\n");return MINUS;} 
		{times} 
			{printf ("乘法:*\n");return TIMES;} 
		{lp} 
			{printf ("小括号:(\n");return LP;} 
		{rp} 
			{printf ("小括号:)\n");return RP;} 
		{lt} 
			{printf ("小于号:<\n");return LT;}
		{mt} 
			{printf ("大于号:>\n");return MT;}
		{ltoeq} 
			{printf ("小于等于号:<=\n");return LTOEQ;}
		{mtoeq} 
			{printf ("大于等于号:>=\n");return MTOEQ;}
		{ne}
			 {printf ("不等于:<>\n");return NE;}
		{no}
			 {printf ("非:！\n");return NO;}
		{an}
			 {printf ("与:&\n");return AN;}
		{lor}
			 {printf ("或:||\n");return LOR;}
		{fuz}
			 {printf ("赋值::=\n");return FUZ;}
		{sem}
			 {printf ("分号:；\n");return SEM;}
		{lcb}
			 {printf ("左花括号:{\n");return LCB;}
		{rcb}
			 {printf ("右花括号:{\n");return RCB;}
			
		{ws} ; 
		. {printf("Error");exit(-1);} 
#line 245 "mylexer.c"
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 1;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0
};

#line 125 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	 printf("词法分析成功，返回记号类别为%d\n", yylex());

}


