%{
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
	
	
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// place any declarations here
	cha   	[a-zA-Z]
	digit	[0-9]
	digits	{digit}+
	optional_fraction	(.{digits})?
	optional_exponent	(E[+-]?{digits})?
	
	
/************************************
	plus "+"
	minus "-"
	times "*"
	lp "("
	rp ")"
	tr "true"
	fa "false"
	lt "<"
	eq "="
	mt ">"
	ltoeq "<="
	mtoeq ">="
	ne "<>"
	no "!"
	an "&"
	lor "||"
	fuz ":="
	sem ";"
	lcb "{"
	rcb "}"
	delim [ /n/t] 
	ws {delim}* 
	
***********************/

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here
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
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	 printf("词法分析成功，返回记号类别为%d\n", yylex());

}

