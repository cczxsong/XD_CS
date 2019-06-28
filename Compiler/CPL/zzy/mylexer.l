%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019年5月31日
****************************************************************************/

#include "myparser.h"
#define ID 0
#define NUM 1
#define RESERVEDWORD 2
#define WORD 3
#define OPERATOR 4
#define DELIMITER 5
#define IF 6
#define ELSE 7
#define WHILE 8
#define TRUE 9
#define FALSE 10
int count = 0;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// place any declarations here
reservedWords [cC][oO][nN][sS][tT]|[vV][aA][rR]|[pP][rR][oO][cC][eE][dD][uU][rR][eE]|[bB][eE][gG][iI][nN]|[eE][nN][dD]|[iI][fF]|[tT][hH][eE][nN]|[wW][hH][iI][lL][eE]|[dD][oO]|[rR][eE][aA][dD]|[cC][aA][lL][lL]|[wW][rR][iI][tT][eE][wW][rR][iI][tT][eE][lL][nN]
char   	[a-zA-Z]
digit	[0-9]
digits	{digit}+
optional_fraction	(.{digits})?
optional_exponent	(E[+-]?{digits})?
delim [" "\n\t]
whitespace {delim}+
words {char}+
identfiers ([A-Za-z]|_)([A-Za-z]|[0-9]|_)*
operators \+|\-|\*|\/|\:=|\>=|\<=|\-=|\+=|#|=|\{|\}
delimiters [,\.;]
constant ([0-9])+
iff [iI][fF]
elsee [eE][lL][sS][eE]
whilee [wW][hH][iL][lL][eE]
truee [tT][rR][uU][eE]
falsee [fF][aA][lL][sS][eE]
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here
{truee} {printf("长度%d\t(识别true,‘%s’)\n",yyleng,yytext);return WHILE;}
{falsee} {printf("长度%d\t(识别false,‘%s’)\n",yyleng,yytext);return WHILE;}
{iff} {printf("长度%d\t(识别if,‘%s’)\n",yyleng,yytext);return IF;}
{elsee} {printf("长度%d\t(识别else,‘%s’)\n",yyleng,yytext);return ELSE;}
{whilee} {printf("长度%d\t(识别while,‘%s’)\n",yyleng,yytext);return WHILE;}
{reservedWords} {printf("长度%d\t(保留字,‘%s’)\n",yyleng,yytext);return RESERVEDWORD;}
{identfiers} {printf("长度%d\t(标识符,‘%s’)\n",yyleng,yytext);return ID;}
{constant} {printf("长度%d\t(数字,‘%s’)\n",yyleng,yytext);return NUM;}
//{digits}{optional_fraction}{optional_exponent}	{printf("%d\t(数字,‘%s’)\n",yyleng,yytext);}
//{words} {printf("%d\t(单词,‘%s’)\n",yyleng,yytext);}
{whitespace} {/* do nothing */;}
{operators} { printf("长度%d\t(操作符,‘%s’)\n",yyleng,yytext);return OPERATOR;}
{delimiters} {printf("长度%d\t(分隔符,‘%s’)\n",yyleng,yytext);return DELIMITER;}


%%

/////////////////////////////////////////////////////////////////////////////
// programs section
//int main(void)
//{
	//yyin=fopen("example.txt","r"); 
    //yylex(); 
	//fclose(yyin);
	//yylex();
	//printf("词法分析成功，返回记号类别为%d\n", yylex());
	//system("PAUSE");
//}
