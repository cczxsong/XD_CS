%{
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

%}

%name myparser


%include{
#ifndef YYSTYPE
#define YYSTYPE myYYTYPE
#endif


}



%token   _WHILE    _LP _RP _LC _RC
%token <sval> _ID 
%token <ival>_NUM
%token <bval> _BOOL
%type <ival> E
%type <bval> B
%type <sval> P

%right _EVAL
%left  _TIMES _MINUS _PLUS  _LT _EQ _GT _ELT _EGT _NEQ _NOT _AND _OR _IF _ELSE _SEM




%%
		
P		: _ID _EVAL E{ msg("gramar: ="); }
		| P _SEM P		{ msg("gramar:P;P"); }
		| _WHILE B _LC P _RC		{ msg("gramar:WHILE");}
		| _IF B _LC P _RC _ELSE _LC P _RC	{ msg("gramar:IF ELSE"); }

		;

	B: _BOOL { cout << $1; }
		| E _EQ E		{ msg("logic calc:=="); }
		| E _LT E		{ msg("logic calc:<"); }
		| E _GT E		{ msg("logic calc:>"); }
		| E _ELT E		{ msg("logic calc:<="); }
		| E _EGT E		{ msg("logic calc:>=");}
		| E _NEQ E		{ msg("logic calc:<>"); }
		| _NOT B		{ msg("logic calc:!"); }
		| B _AND B		{ msg("logic calc:&"); }
		| B _OR B		{ msg("logic calc:||"); }
		;
		

E		: E _MINUS E	{ msg("calc:minus");}
		| _MINUS E		{ msg("calc:-E");}
		| E _PLUS E		{ msg("calc:plus");}
		| E _TIMES E	{ msg("calc:times"); }
		| _LP E _RP
		| _ID	{ cout << $1; }
		| _NUM	 
		;
		

%%



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