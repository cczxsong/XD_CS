%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年6月10日
****************************************************************************/

#include <string>
#include "help.h"
#include "mylexer.h"

using namespace std;

void msg(string str, string extr = " ") {
	if(__mCOUTmsg)cout << "gramar " << str << " " << extr << endl << endl;;
}

void yymsg(string str, string e1 = "", string e2 = "") {
	if (__mCOUTyymsg)cout << "$$$ " << str << " " << e1 << " " << e2 << endl;
}
void show(list<codeADDR> &c,string s="") {
	cout <<"%%%"<< s << endl;
	
	for (auto i : c)cout << i << ",";
	cout << "\n\n";

}
%}


%name myparser
//class definition
{

	Symboltable symboltable;
	codeADDR nextstat;
	vector<f4Elem> mid4elem;	//adr next 指向同一标号的链
	
	void threeAddrCode() {
		cout << "there are addr code for this time of analyse\n";
		
	}
	//返回code地址
	codeADDR emit(string op,ADDR arg1,ADDR arg2,ADDR ret) {
		auto f4 = f4Elem(symboltable.getNextId(),op, arg1, arg2, ret);
		mid4elem.push_back(f4);
		
		if(__mCOUT4E) cout<< nextstat<<":"<<f4.str4e()<<endl;
		if (__mCOUT3C)cout<< nextstat<< ":" << f4.str3c(symboltable.table) << endl;
		return nextstat++;//用于转移
	}
	codeADDR emit(string op, ADDR arg1, ADDR arg2, string label) {
		auto cadr = emit(op, arg1, arg2, ___);
		mid4elem[cadr].tolabel = label;
		return cadr;
	}
	ADDR entry(string name="") {
		return symboltable.entry(name);
	}
	ADDR newtemp(string name = "") {//用于控制语句的短路计算
		return entry(name);
	}

	string getNameByAddr(ADDR addr) {
		return symboltable.getElemByAddr(addr).name;
	}
	void setValByAddr(ADDR addr, vTYPE v) {
		symboltable.table[addr].val = v;
	}
	vTYPE getValByAddr(ADDR addr) {
		return symboltable.table[addr].val;
	}

	//label 是3地址码的一部分,用于跳转语句 返回label在符号表这的地址
	string newlabel() {
		return symboltable.newLabel();
	}
	//将跳转到一个地方的三地址码接一起
	//为序号为i的三地址码高招新链
	//list<codeADDR>* makechain() //没必要了 都有tc,fc

	//合并跳转代码序列
	void  merge(list<codeADDR>&l1, list<codeADDR>&l2) {
		cout << "chain merge" << endl;
		l2.splice(l2.end(), l1);
		l1.clear();//不确定是不是移动;
	}

	//backpatch label to some goto code			jump chain
	void backpatch(string label, list<codeADDR>&jc) {
		cout << "chain backpatch label:" <<label<< endl;
		
		for (auto &it : jc) {
			mid4elem[it].tolabel =label;
		}
		jc.clear();
	}
}
// constructor
{
	// place any extra initialisation code here
	cout << "hello Parser constructor!\n";
	nextstat = 0;
	
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here

%include{
#ifndef YYSTYPE
#define YYSTYPE myYYTYPE
#endif


}



%token   _WHILE    _LP _RP _LC _RC 
%token <sval> _ID 
%token <ival>_NUM
%token <bval> _BOOL
%type <nE> E
%type <nB> B
%type <nP> P
//eval 优先级低s
%right _EVAL
//not 优先级最高
%left  _UMINUS _TIMES _PLUS  _LT _EQ _GT _ELT _EGT _NEQ _NOT _AND _OR _IF _ELSE _SEM _EOF




%%
		

P	: _ID _EVAL E	{
						$$.desc = "P->ID=E\n\t#" ;
show($3.code, "e");
						setValByAddr(entry($1), $3.val);

						yymsg($$.desc,$1,$3.desc);
						
						$$.append($3.code);
						$$.code.push_back(emit("=",$3.place,___,entry($1)));
						
						
						show($$.code,"id=e");
						
						}
	| P _SEM P			{
show($1.code, "p1"); show($3.code, "p2");
						
						$$.code.clear();
						$$.append($1.code);

						mid4elem[$3.code.front()].label =$3.begin= newlabel();
						$$.append($3.code);
						backpatch($3.begin, $1.nc);
						merge($3.nc, $$.nc);
						show($$.code, "p;p");
						}
	| _WHILE B _LC P _RC		{
show($2.code, "B"); show($4.code, "P");
auto &t = $$;

	
						$4.begin=mid4elem[$4.code.front()].label = $2.True = newlabel();
						backpatch($2.True, $2.tc);

						auto cadr1 = emit("j",$2.place, ___, $4.begin);
						auto cadr2 = emit("j", ___, ___, ___);

						
						mid4elem[$2.code.front()].label = $$.begin = newlabel();
						auto cadr3 = emit("j", ___, ___, $$.begin);

						$$.append($2.code);
						$$.code.push_back(cadr1);
						$$.code.push_back(cadr2);
						$$.append($4.code);
						$$.code.push_back(cadr3);

						backpatch($$.begin, $4.nc);
						$$.nc.push_back(cadr2);
						merge($2.fc, $$.nc);
						show($$.code, "while b");
						}
	| _IF B _LC P _RC _ELSE _LC P _RC	{	
	show($2.code, "B"); show($4.code, "P4"); show($8.code, "P8");
						
						mid4elem[$4.code.front()].label= $2.True = newlabel();
						mid4elem[$8.code.front()].label = $2.False = newlabel();
						auto cadr1 = emit("j", $2.place, ___, $2.True);
						backpatch($2.True, $2.tc);
						auto cadr2 = emit("j", ___, ___, $2.False);						

						backpatch($2.False, $2.fc);
						auto cadr3 = emit("j", ___, ___, ___);
						$$.nc.push_back(cadr3);

						$$.append($2.code);
						$$.code.push_back(cadr1);
						$$.code.push_back(cadr2);
						$$.append($4.code);
						$$.code.push_back(cadr3);
						$$.append($8.code);
						
						merge($4.nc, $8.nc);
						merge($8.nc, $$.nc);

						show($$.code, "if else");
						}
	| P _EOF{
							
			string e =  newlabel();
			auto cadr = emit("j", ___, ___, "END:");
			if ($1.nc.size()) {
				mid4elem[cadr].label = e;
				backpatch(e, $1.nc);
			}
			
			
			
			$$.code.clear();
			$$.append($1.code);
			$$.code.push_back(cadr);
			freopen("in.cpl.out", "w", stdout);

			cout <<" $$$$$$$$$$$$$$$$$$$$$$$$$ "<< endl;
			cout << " $$$$$$$$$$$$$$$$$$$$$$$$$ " << endl;
			for (auto &el : $$.code) {
				cout<< mid4elem[el].str3c(symboltable.table);;
				cout <<"\t\t\t"<< mid4elem[el].str4e()<<endl;;
}cout << " $$$$$$$$$$$$$$$$$$$$$$$$$ " << endl; cout << " $$$$$$$$$$$$$$$$$$$$$$$$$ " << endl;
			freopen("CON", "w", stdout);
			show($$.code, "end");
						}
	;

B	: _BOOL			{
						$$.desc = "B->BOOL\n\t#";
						$$.place = newtemp();
						$$.val = $1;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc,"ID: " + $$.name + "@",to_string($$.place));
						

						codeADDR cadr = emit("j", $1, ___,___);
						//差不多是makechain的效果
						$$.tc.push_back(cadr);
						$$.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);						
						$$.fc.push_back(cadr);
						$$.code.push_back(cadr);

				
						}
	| E _EQ E		{
						$$.desc = "B->E==E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val==$3.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc,$1.desc,$3.desc);					
						
						$$.append($1.code);
						$$.append($3.code);
						
						codeADDR cadr = emit("j==", $1.place, $3.place,___);
						$$.tc.push_back(cadr);
						$$.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						$$.fc.push_back(cadr);
						$$.code.push_back(cadr);
						}
	| E _LT E		{ 
						$$.desc = "B->E<E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val < $3.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc, $1.desc, $3.desc);

						$$.append($1.code);
						$$.append($3.code);

						codeADDR cadr = emit("j<", $1.place, $3.place, ___);
						$$.tc.push_back(cadr);
						$$.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						$$.fc.push_back(cadr);
						$$.code.push_back(cadr);
						}
	| E _GT E		{ 
						$$.desc = "B->E>E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val > $3.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc, $1.desc, $3.desc);
						
						$$.append($1.code);
						$$.append($3.code);
						
						
						codeADDR cadr = emit("j>", $1.place, $3.place, ___);
						$$.tc.push_back(cadr);
						$$.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						$$.fc.push_back(cadr);
						$$.code.push_back(cadr);
						}
	| E _ELT E		{ 
						$$.desc = "B->E<=E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val <= $3.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc, $1.desc, $3.desc);
						
						$$.append($1.code);
						$$.append($3.code);

						codeADDR cadr = emit("j<=", $1.place, $3.place, ___);
						$$.tc.push_back(cadr);
						$$.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						$$.fc.push_back(cadr);
						$$.code.push_back(cadr);
						}
	| E _EGT E		{ 
						$$.desc = "B->E>=E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val >= $3.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc, $1.desc, $3.desc);
						
						$$.append($1.code);
						$$.append($3.code);
				
						codeADDR cadr = emit("j>=", $1.place, $3.place, ___);
						$$.tc.push_back(cadr);
						$$.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						$$.fc.push_back(cadr);
						$$.code.push_back(cadr);
						}
	| E _NEQ E		{ 
						$$.desc = "B->E><>E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val != $3.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc, $1.desc, $3.desc);
						
						$$.append($1.code);
						$$.append($3.code);

						codeADDR cadr = emit("j<>", $1.place, $3.place, ___);
						$$.tc.push_back(cadr);
						$$.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						$$.fc.push_back(cadr);
						$$.code.push_back(cadr);
						}
	| _NOT B		{
						$$.desc = "B->!B\n\t#";
						$$.place = newtemp();
						$$.val = !$2.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc,$2.desc);
						
						$$.append($2.code);
						merge( $2.tc,$$.fc) ;
						
						//书中没有生成
						
						
						merge($2.fc, $$.tc);
						merge($2.tc, $$.fc);
						}
	| B _AND B		{
						$$.desc = "B->B & B\n\t#";
						$$.place = newtemp();
						$$.val = $1.val && $3.val;
						$$.name = getNameByAddr($$.place);

						yymsg($$.desc, $1.desc, $3.desc);
						
						

						merge($1.fc, $$.fc);
						merge($3.tc, $$.fc);
						$1.True = newlabel();
						
						mid4elem[$3.code.front()].label=$1.True;
						backpatch($1.True,$1.tc);
						merge($3.tc, $$.tc);
						
						$$.append($1.code);
						$$.append($3.code);
						}
	| B _OR B		{ 
						$$.desc = "B->B || B\n\t#";
						$$.place = newtemp();
						$$.val = $1.val || $3.val;
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc, $1.desc, $3.desc);

						merge($1.tc, $$.tc);
						merge($3.tc, $$.tc);	
						merge($3.fc, $$.fc);

						mid4elem[$3.code.front()].label=$1.False = newlabel();
						backpatch($1.False, $1.fc);
						
						$$.append($1.code);
						$$.append($3.code);					
					
						}
		;
		

E	: _UMINUS E		{
						$$.desc = "E->-E\n\t#";
						$$.place = newtemp();
						$$.val = -$2.val;
						$$.name = getNameByAddr($$.place);
						setValByAddr($$.place, $$.val);
						yymsg($$.desc,$2.desc);

						$$.append($2.code);
						$$.code.push_back(
						emit("-", $2.place, ___, $$.place)
						);
							}

	  | E _PLUS E{ $$.code.clear();
show($1.code, "E"); show($3.code, "E");
						$$.desc = "E->E+E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val+$3.val;
		
						$$.name = getNameByAddr($$.place);
						setValByAddr($$.place, $$.val);
						yymsg($$.desc, $1.desc, $3.desc);
					
						$$.append($1.code);
						$$.append($3.code);
						$$.code.push_back(
							emit("+", $1.place, $3.place, $$.place)
						);
show($$.code, "e->e+e"); 
						}
	| E _TIMES E	{ 
						$$.desc = "E->E*E\n\t#";
						$$.place = newtemp();
						$$.val = $1.val * $3.val;

						$$.name = getNameByAddr($$.place);
						setValByAddr($$.place, $$.val);
						yymsg($$.desc, $1.desc, $3.desc);

						$$.append($1.code);
						$$.append($3.code);
						$$.code.push_back(
							emit("*", $1.place, $3.place, $$.place)
						);
						
					}
	| _LP E _RP		{
						$$= $2;
						$$.desc = "E->(E)\n\t#";
						yymsg($$.desc,$2.desc);

						//$$.append($2.code);//避免多余的存在
						}
	| _ID			{//变量有地址
						$$.desc = "E->ID\n\t#";
						$$.place = newtemp($1);						
						$$.val = getValByAddr($$.place);
						$$.name = getNameByAddr($$.place);
						yymsg($$.desc,"ID: "+$1+"@",to_string($$.place));
					}
	| _NUM			{//常量不需要存储  直接放到符号表中去
						$$.desc = "E->NUM\n\t#";							
						$$.place = newtemp();
						$$.val = $1;
						$$.name = getNameByAddr($$.place);
						setValByAddr($$.place, $1);
						yymsg($$.desc,"constant NUM:",to_string($1));
					}
	;
		


%%



int main(int argc, char *argv[])
{
	cin.sync();
	cin.clear();
	freopen("example.txt","r",stdin);
	//freopen("in.cpl.out", "w", stdout);
	int n = 1;
	mylexer lexer;
	myparser parser;
	
		if (parser.yycreate(&lexer)) {
			if (lexer.yycreate(&parser)) {
				n = parser.yyparse();
				cout << "\n\tparser return:" << n << endl;
				parser.threeAddrCode();
			}
		}
	
	
	freopen("CON","r",stdin);
	if (n==0) cout<<"\n#######语法分析成功#######"<<endl;
	else {
		cout << "\n#######语法分析失败#######" << endl;
	}
	system("pause");
	return n;
}

