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
* Time: 20:41:35
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
#line 34 ".\\myparser.y"


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

#line 132 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 115 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE myYYTYPE
#endif



#line 147 "myparser.h"
#define _WHILE 257
#define _LP 258
#define _RP 259
#define _LC 260
#define _RC 261
#define _ID 262
#define _NUM 263
#define _BOOL 264
#define _EVAL 265
#define _UMINUS 266
#define _TIMES 267
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
#define _EOF 281
#endif
