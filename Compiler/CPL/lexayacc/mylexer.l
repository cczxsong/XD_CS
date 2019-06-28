%{
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
%}

%name mylexer
delim [ \t\n]
ws    {delim}+

char [a-zA-Z_]
digit [0-9]
id    {char}({char}|{digit})*
int	{digit}+
//nint -{digit}+
bool false|true




%%

%{
//this code will be added into yyaction function
    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
    //double yylval;
%}

{ws}		{/* do nothing */}

"//".*	{print_token(-1,yytext,"comment");}


{int} {print_token(_NUM, yytext, "int"); yylval.ival = atoi(yytext); return _NUM; }

{bool} {print_token(_BOOL, yytext, "bool"); yylval.bval = strcmp(yytext,"true")==0; return _BOOL; }

"if"		{print_token(_IF, yytext,"control");return _IF; }
"else"		{print_token(_ELSE, yytext,"control");return _ELSE; }
"while"		{print_token(_WHILE, yytext,"control");return _WHILE; }

{id} {print_token(_ID, yytext, "id"); 
		yylval.sval = string(yytext);
		return _ID; }

"+"         {print_token(_PLUS, yytext,"operator"); return _PLUS;}
"-"         {print_token(_UMINUS, yytext,"operator"); return _UMINUS;}
"*"         {print_token(_TIMES, yytext,"operator"); return _TIMES;}
/*
"/"         {print_token(_OVER, yytext,"operator"); return _OVER;}
*/

"=="			{print_token(_EQ, yytext,"relation"); return _EQ;}
"<="		{print_token(_ELT, yytext,"relation"); return _ELT;}
">="		{print_token(_EGT, yytext,"relation"); return _EGT;}
"="		{print_token(_EVAL, yytext,"eval operator "); return _EVAL;}
"<>"		{print_token(_NEQ, yytext,"relation"); return _NEQ;}
"<"			{print_token(_LT, yytext,"relation"); return _LT;}
">"			{print_token(_GT, yytext,"relation"); return _GT;}

"!"		{print_token(_NOT, yytext,"relop"); return _NOT;}
"&"		{print_token(_AND, yytext,"relop"); return _AND;}
"||"		{print_token(_OR, yytext,"relop"); return _OR;}


";"		{print_token(_SEM, yytext,"program");return _SEM;}

"("         {print_token(_LP, yytext,"prority");return _LP;}
")"         {print_token(_RP, yytext,"prority");return _RP;}

"{"         {print_token(_LC, yytext,"block");return _LC;}
"}"         {print_token(_RC, yytext,"block");return _RC;}

"###EOF###" { return _EOF; }

%%



 void print_token(int token, char* lex,string name="no name")
{
	if(_mCOUNTprinttoken)cout<<"\trecogzed "<<name<<" : "<<lex<<" token:"<<token<<endl;
}

