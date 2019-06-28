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
* Time: 20:41:35
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

#line 68 "myparser.cpp"
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
#line 101 ".\\myparser.y"

	// place any extra initialisation code here
	cout << "hello Parser constructor!\n";
	nextstat = 0;
	

#line 95 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 109 ".\\myparser.y"

	// place any extra cleanup code here

#line 109 "myparser.cpp"
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
#line 143 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr).nP.desc = "P->ID=E\n\t#" ;
show(yyattribute(3 - 3).nE.code, "e");
						setValByAddr(entry(yyattribute(1 - 3).sval), yyattribute(3 - 3).nE.val);

						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nP.desc,yyattribute(1 - 3).sval,yyattribute(3 - 3).nE.desc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(3 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(emit("=",yyattribute(3 - 3).nE.place,___,entry(yyattribute(1 - 3).sval)));
						
						
						show((*(YYSTYPE YYFAR*)yyvalptr).nP.code,"id=e");
						
						
#line 232 "myparser.cpp"
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
#line 157 ".\\myparser.y"

show(yyattribute(1 - 3).nP.code, "p1"); show(yyattribute(3 - 3).nP.code, "p2");
						
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.clear();
						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(1 - 3).nP.code);

						mid4elem[yyattribute(3 - 3).nP.code.front()].label =yyattribute(3 - 3).nP.begin= newlabel();
						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(3 - 3).nP.code);
						backpatch(yyattribute(3 - 3).nP.begin, yyattribute(1 - 3).nP.nc);
						merge(yyattribute(3 - 3).nP.nc, (*(YYSTYPE YYFAR*)yyvalptr).nP.nc);
						show((*(YYSTYPE YYFAR*)yyvalptr).nP.code, "p;p");
						
#line 256 "myparser.cpp"
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
#line 169 ".\\myparser.y"

show(yyattribute(2 - 5).nB.code, "B"); show(yyattribute(4 - 5).nP.code, "P");
auto &t = (*(YYSTYPE YYFAR*)yyvalptr).nP;

	
						yyattribute(4 - 5).nP.begin=mid4elem[yyattribute(4 - 5).nP.code.front()].label = yyattribute(2 - 5).nB.True = newlabel();
						backpatch(yyattribute(2 - 5).nB.True, yyattribute(2 - 5).nB.tc);

						auto cadr1 = emit("j",yyattribute(2 - 5).nB.place, ___, yyattribute(4 - 5).nP.begin);
						auto cadr2 = emit("j", ___, ___, ___);

						
						mid4elem[yyattribute(2 - 5).nB.code.front()].label = (*(YYSTYPE YYFAR*)yyvalptr).nP.begin = newlabel();
						auto cadr3 = emit("j", ___, ___, (*(YYSTYPE YYFAR*)yyvalptr).nP.begin);

						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(2 - 5).nB.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(cadr1);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(cadr2);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(4 - 5).nP.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(cadr3);

						backpatch((*(YYSTYPE YYFAR*)yyvalptr).nP.begin, yyattribute(4 - 5).nP.nc);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.nc.push_back(cadr2);
						merge(yyattribute(2 - 5).nB.fc, (*(YYSTYPE YYFAR*)yyvalptr).nP.nc);
						show((*(YYSTYPE YYFAR*)yyvalptr).nP.code, "while b");
						
#line 294 "myparser.cpp"
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
#line 195 ".\\myparser.y"
	
	show(yyattribute(2 - 9).nB.code, "B"); show(yyattribute(4 - 9).nP.code, "P4"); show(yyattribute(8 - 9).nP.code, "P8");
						
						mid4elem[yyattribute(4 - 9).nP.code.front()].label= yyattribute(2 - 9).nB.True = newlabel();
						mid4elem[yyattribute(8 - 9).nP.code.front()].label = yyattribute(2 - 9).nB.False = newlabel();
						auto cadr1 = emit("j", yyattribute(2 - 9).nB.place, ___, yyattribute(2 - 9).nB.True);
						backpatch(yyattribute(2 - 9).nB.True, yyattribute(2 - 9).nB.tc);
						auto cadr2 = emit("j", ___, ___, yyattribute(2 - 9).nB.False);						

						backpatch(yyattribute(2 - 9).nB.False, yyattribute(2 - 9).nB.fc);
						auto cadr3 = emit("j", ___, ___, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.nc.push_back(cadr3);

						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(2 - 9).nB.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(cadr1);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(cadr2);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(4 - 9).nP.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(cadr3);
						(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(8 - 9).nP.code);
						
						merge(yyattribute(4 - 9).nP.nc, yyattribute(8 - 9).nP.nc);
						merge(yyattribute(8 - 9).nP.nc, (*(YYSTYPE YYFAR*)yyvalptr).nP.nc);

						show((*(YYSTYPE YYFAR*)yyvalptr).nP.code, "if else");
						
#line 331 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 220 ".\\myparser.y"

							
			string e =  newlabel();
			auto cadr = emit("j", ___, ___, "END:");
			if (yyattribute(1 - 2).nP.nc.size()) {
				mid4elem[cadr].label = e;
				backpatch(e, yyattribute(1 - 2).nP.nc);
			}
			
			
			
			(*(YYSTYPE YYFAR*)yyvalptr).nP.code.clear();
			(*(YYSTYPE YYFAR*)yyvalptr).nP.append(yyattribute(1 - 2).nP.code);
			(*(YYSTYPE YYFAR*)yyvalptr).nP.code.push_back(cadr);
			freopen("in.cpl.out", "w", stdout);

			cout <<" $$$$$$$$$$$$$$$$$$$$$$$$$ "<< endl;
			cout << " $$$$$$$$$$$$$$$$$$$$$$$$$ " << endl;
			for (auto &el : (*(YYSTYPE YYFAR*)yyvalptr).nP.code) {
				cout<< mid4elem[el].str3c(symboltable.table);;
				cout <<"\t\t\t"<< mid4elem[el].str4e()<<endl;;
}cout << " $$$$$$$$$$$$$$$$$$$$$$$$$ " << endl; cout << " $$$$$$$$$$$$$$$$$$$$$$$$$ " << endl;
			freopen("CON", "w", stdout);
			show((*(YYSTYPE YYFAR*)yyvalptr).nP.code, "end");
						
#line 368 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 247 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->BOOL\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 1).bval;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc,"ID: " + (*(YYSTYPE YYFAR*)yyvalptr).nB.name + "@",to_string((*(YYSTYPE YYFAR*)yyvalptr).nB.place));
						

						codeADDR cadr = emit("j", yyattribute(1 - 1).bval, ___,___);
						//差不多是makechain的效果
						(*(YYSTYPE YYFAR*)yyvalptr).nB.tc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.fc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

				
						
#line 399 "myparser.cpp"
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
#line 266 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->E==E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nE.val==yyattribute(3 - 3).nE.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc,yyattribute(1 - 3).nE.desc,yyattribute(3 - 3).nE.desc);					
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nE.code);
						
						codeADDR cadr = emit("j==", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place,___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.tc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.fc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);
						
#line 429 "myparser.cpp"
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
#line 284 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->E<E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nE.val < yyattribute(3 - 3).nE.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc, yyattribute(1 - 3).nE.desc, yyattribute(3 - 3).nE.desc);

						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nE.code);

						codeADDR cadr = emit("j<", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.tc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.fc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);
						
#line 459 "myparser.cpp"
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
#line 302 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->E>E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nE.val > yyattribute(3 - 3).nE.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc, yyattribute(1 - 3).nE.desc, yyattribute(3 - 3).nE.desc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nE.code);
						
						
						codeADDR cadr = emit("j>", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.tc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.fc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);
						
#line 490 "myparser.cpp"
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
#line 321 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->E<=E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nE.val <= yyattribute(3 - 3).nE.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc, yyattribute(1 - 3).nE.desc, yyattribute(3 - 3).nE.desc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nE.code);

						codeADDR cadr = emit("j<=", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.tc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.fc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);
						
#line 520 "myparser.cpp"
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
#line 339 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->E>=E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nE.val >= yyattribute(3 - 3).nE.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc, yyattribute(1 - 3).nE.desc, yyattribute(3 - 3).nE.desc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nE.code);
				
						codeADDR cadr = emit("j>=", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.tc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.fc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);
						
#line 550 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 357 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->E><>E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nE.val != yyattribute(3 - 3).nE.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc, yyattribute(1 - 3).nE.desc, yyattribute(3 - 3).nE.desc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nE.code);

						codeADDR cadr = emit("j<>", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.tc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);

						cadr = emit("j", ___, ___, ___);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.fc.push_back(cadr);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.code.push_back(cadr);
						
#line 580 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 375 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->!B\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = !yyattribute(2 - 2).nB.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc,yyattribute(2 - 2).nB.desc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(2 - 2).nB.code);
						merge( yyattribute(2 - 2).nB.tc,(*(YYSTYPE YYFAR*)yyvalptr).nB.fc) ;
						
						//书中没有生成
						
						
						merge(yyattribute(2 - 2).nB.fc, (*(YYSTYPE YYFAR*)yyvalptr).nB.tc);
						merge(yyattribute(2 - 2).nB.tc, (*(YYSTYPE YYFAR*)yyvalptr).nB.fc);
						
#line 608 "myparser.cpp"
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
#line 391 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->B & B\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nB.val && yyattribute(3 - 3).nB.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);

						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc, yyattribute(1 - 3).nB.desc, yyattribute(3 - 3).nB.desc);
						
						

						merge(yyattribute(1 - 3).nB.fc, (*(YYSTYPE YYFAR*)yyvalptr).nB.fc);
						merge(yyattribute(3 - 3).nB.tc, (*(YYSTYPE YYFAR*)yyvalptr).nB.fc);
						yyattribute(1 - 3).nB.True = newlabel();
						
						mid4elem[yyattribute(3 - 3).nB.code.front()].label=yyattribute(1 - 3).nB.True;
						backpatch(yyattribute(1 - 3).nB.True,yyattribute(1 - 3).nB.tc);
						merge(yyattribute(3 - 3).nB.tc, (*(YYSTYPE YYFAR*)yyvalptr).nB.tc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nB.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nB.code);
						
#line 641 "myparser.cpp"
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
#line 412 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr).nB.desc = "B->B || B\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nB.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nB.val = yyattribute(1 - 3).nB.val || yyattribute(3 - 3).nB.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nB.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nB.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nB.desc, yyattribute(1 - 3).nB.desc, yyattribute(3 - 3).nB.desc);

						merge(yyattribute(1 - 3).nB.tc, (*(YYSTYPE YYFAR*)yyvalptr).nB.tc);
						merge(yyattribute(3 - 3).nB.tc, (*(YYSTYPE YYFAR*)yyvalptr).nB.tc);	
						merge(yyattribute(3 - 3).nB.fc, (*(YYSTYPE YYFAR*)yyvalptr).nB.fc);

						mid4elem[yyattribute(3 - 3).nB.code.front()].label=yyattribute(1 - 3).nB.False = newlabel();
						backpatch(yyattribute(1 - 3).nB.False, yyattribute(1 - 3).nB.fc);
						
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(1 - 3).nB.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nB.append(yyattribute(3 - 3).nB.code);					
					
						
#line 671 "myparser.cpp"
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
#line 433 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr).nE.desc = "E->-E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nE.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nE.val = -yyattribute(2 - 2).nE.val;
						(*(YYSTYPE YYFAR*)yyvalptr).nE.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place);
						setValByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place, (*(YYSTYPE YYFAR*)yyvalptr).nE.val);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nE.desc,yyattribute(2 - 2).nE.desc);

						(*(YYSTYPE YYFAR*)yyvalptr).nE.append(yyattribute(2 - 2).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nE.code.push_back(
						emit("-", yyattribute(2 - 2).nE.place, ___, (*(YYSTYPE YYFAR*)yyvalptr).nE.place)
						);
							
#line 696 "myparser.cpp"
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
#line 447 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr).nE.code.clear();
show(yyattribute(1 - 3).nE.code, "E"); show(yyattribute(3 - 3).nE.code, "E");
						(*(YYSTYPE YYFAR*)yyvalptr).nE.desc = "E->E+E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nE.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nE.val = yyattribute(1 - 3).nE.val+yyattribute(3 - 3).nE.val;
		
						(*(YYSTYPE YYFAR*)yyvalptr).nE.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place);
						setValByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place, (*(YYSTYPE YYFAR*)yyvalptr).nE.val);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nE.desc, yyattribute(1 - 3).nE.desc, yyattribute(3 - 3).nE.desc);
					
						(*(YYSTYPE YYFAR*)yyvalptr).nE.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nE.append(yyattribute(3 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nE.code.push_back(
							emit("+", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place, (*(YYSTYPE YYFAR*)yyvalptr).nE.place)
						);
show((*(YYSTYPE YYFAR*)yyvalptr).nE.code, "e->e+e"); 
						
#line 725 "myparser.cpp"
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
#line 464 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr).nE.desc = "E->E*E\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nE.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nE.val = yyattribute(1 - 3).nE.val * yyattribute(3 - 3).nE.val;

						(*(YYSTYPE YYFAR*)yyvalptr).nE.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place);
						setValByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place, (*(YYSTYPE YYFAR*)yyvalptr).nE.val);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nE.desc, yyattribute(1 - 3).nE.desc, yyattribute(3 - 3).nE.desc);

						(*(YYSTYPE YYFAR*)yyvalptr).nE.append(yyattribute(1 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nE.append(yyattribute(3 - 3).nE.code);
						(*(YYSTYPE YYFAR*)yyvalptr).nE.code.push_back(
							emit("*", yyattribute(1 - 3).nE.place, yyattribute(3 - 3).nE.place, (*(YYSTYPE YYFAR*)yyvalptr).nE.place)
						);
						
					
#line 753 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 480 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr).nE= yyattribute(2 - 3).nE;
						(*(YYSTYPE YYFAR*)yyvalptr).nE.desc = "E->(E)\n\t#";
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nE.desc,yyattribute(2 - 3).nE.desc);

						//$$.append($2.code);//避免多余的存在
						
#line 772 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 487 ".\\myparser.y"
//变量有地址
						(*(YYSTYPE YYFAR*)yyvalptr).nE.desc = "E->ID\n\t#";
						(*(YYSTYPE YYFAR*)yyvalptr).nE.place = newtemp(yyattribute(1 - 1).sval);						
						(*(YYSTYPE YYFAR*)yyvalptr).nE.val = getValByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place);
						(*(YYSTYPE YYFAR*)yyvalptr).nE.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nE.desc,"ID: "+yyattribute(1 - 1).sval+"@",to_string((*(YYSTYPE YYFAR*)yyvalptr).nE.place));
					
#line 791 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 494 ".\\myparser.y"
//常量不需要存储  直接放到符号表中去
						(*(YYSTYPE YYFAR*)yyvalptr).nE.desc = "E->NUM\n\t#";							
						(*(YYSTYPE YYFAR*)yyvalptr).nE.place = newtemp();
						(*(YYSTYPE YYFAR*)yyvalptr).nE.val = yyattribute(1 - 1).ival;
						(*(YYSTYPE YYFAR*)yyvalptr).nE.name = getNameByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place);
						setValByAddr((*(YYSTYPE YYFAR*)yyvalptr).nE.place, yyattribute(1 - 1).ival);
						yymsg((*(YYSTYPE YYFAR*)yyvalptr).nE.desc,"constant NUM:",to_string(yyattribute(1 - 1).ival));
					
#line 811 "myparser.cpp"
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
		{ "_UMINUS", 266 },
		{ "_TIMES", 267 },
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
		{ "_EOF", 281 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: P",
		"P: _ID _EVAL E",
		"P: P _SEM P",
		"P: _WHILE B _LC P _RC",
		"P: _IF B _LC P _RC _ELSE _LC P _RC",
		"P: P _EOF",
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
		"E: _UMINUS E",
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
		{ 1, 2, 4 },
		{ 2, 1, 5 },
		{ 2, 3, 6 },
		{ 2, 3, 7 },
		{ 2, 3, 8 },
		{ 2, 3, 9 },
		{ 2, 3, 10 },
		{ 2, 3, 11 },
		{ 2, 2, 12 },
		{ 2, 3, 13 },
		{ 2, 3, 14 },
		{ 3, 2, 15 },
		{ 3, 3, 16 },
		{ 3, 3, 17 },
		{ 3, 3, 18 },
		{ 3, 1, 19 },
		{ 3, 1, 20 }
	};
	yyreduction = reduction;

	yytokenaction_size = 262;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 4, YYAT_ACCEPT, 0 },
		{ 11, YYAT_ERROR, 0 },
		{ 30, YYAT_SHIFT, 5 },
		{ 51, YYAT_SHIFT, 52 },
		{ 50, YYAT_SHIFT, 1 },
		{ 49, YYAT_SHIFT, 50 },
		{ 30, YYAT_SHIFT, 6 },
		{ 30, YYAT_SHIFT, 7 },
		{ 30, YYAT_SHIFT, 8 },
		{ 50, YYAT_SHIFT, 2 },
		{ 30, YYAT_SHIFT, 9 },
		{ 11, YYAT_SHIFT, 22 },
		{ 11, YYAT_SHIFT, 23 },
		{ 11, YYAT_SHIFT, 24 },
		{ 11, YYAT_SHIFT, 25 },
		{ 11, YYAT_SHIFT, 26 },
		{ 11, YYAT_SHIFT, 27 },
		{ 14, YYAT_SHIFT, 32 },
		{ 17, YYAT_SHIFT, 34 },
		{ 30, YYAT_SHIFT, 10 },
		{ 27, YYAT_ERROR, 0 },
		{ 48, YYAT_SHIFT, 49 },
		{ 51, YYAT_SHIFT, 15 },
		{ 51, YYAT_SHIFT, 16 },
		{ 46, YYAT_SHIFT, 48 },
		{ 50, YYAT_SHIFT, 3 },
		{ 17, YYAT_SHIFT, 20 },
		{ 17, YYAT_SHIFT, 21 },
		{ 42, YYAT_SHIFT, 20 },
		{ 42, YYAT_SHIFT, 21 },
		{ 43, YYAT_SHIFT, 47 },
		{ 27, YYAT_ERROR, 0 },
		{ 12, YYAT_SHIFT, 28 },
		{ 14, YYAT_SHIFT, 29 },
		{ 14, YYAT_SHIFT, 30 },
		{ 41, YYAT_SHIFT, 20 },
		{ 41, YYAT_SHIFT, 21 },
		{ 40, YYAT_SHIFT, 20 },
		{ 40, YYAT_SHIFT, 21 },
		{ 39, YYAT_SHIFT, 20 },
		{ 39, YYAT_SHIFT, 21 },
		{ 38, YYAT_SHIFT, 20 },
		{ 38, YYAT_SHIFT, 21 },
		{ 37, YYAT_SHIFT, 20 },
		{ 37, YYAT_SHIFT, 21 },
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
		{ 4, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 0, 0, YYAT_DEFAULT, 50 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ -218, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ 0, 1, YYAT_DEFAULT, 51 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ -258, 1, YYAT_DEFAULT, 17 },
		{ -228, 1, YYAT_DEFAULT, 14 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ -243, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 50 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -241, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ 0, 0, YYAT_DEFAULT, 27 },
		{ -244, 1, YYAT_DEFAULT, 30 },
		{ 0, 0, YYAT_DEFAULT, 50 },
		{ 0, 0, YYAT_DEFAULT, 30 },
		{ -256, 1, YYAT_ERROR, 0 },
		{ -222, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 50 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -224, 1, YYAT_REDUCE, 8 },
		{ -226, 1, YYAT_REDUCE, 7 },
		{ -228, 1, YYAT_REDUCE, 9 },
		{ -230, 1, YYAT_REDUCE, 10 },
		{ -232, 1, YYAT_REDUCE, 11 },
		{ -239, 1, YYAT_REDUCE, 12 },
		{ -231, 1, YYAT_DEFAULT, 51 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -237, 1, YYAT_DEFAULT, 51 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -258, 1, YYAT_ERROR, 0 },
		{ -255, 1, YYAT_ERROR, 0 },
		{ -253, 1, YYAT_ERROR, 0 },
		{ -258, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 4 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 22;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 30, 45 },
		{ 30, 11 },
		{ 50, 51 },
		{ 32, 46 },
		{ 29, 44 },
		{ 28, 43 },
		{ 27, 42 },
		{ 26, 41 },
		{ 25, 40 },
		{ 24, 39 },
		{ 23, 38 },
		{ 22, 37 },
		{ 21, 36 },
		{ 20, 35 },
		{ 15, 33 },
		{ 13, 31 },
		{ 10, 19 },
		{ 9, 18 },
		{ 5, 17 },
		{ 3, 14 },
		{ 1, 12 },
		{ 0, 4 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 20, -1 },
		{ 18, 30 },
		{ 0, -1 },
		{ 17, 30 },
		{ 0, -1 },
		{ 15, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 14, -1 },
		{ 14, 30 },
		{ 0, -1 },
		{ 0, -1 },
		{ 12, -1 },
		{ 0, -1 },
		{ 13, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
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
#line 506 ".\\myparser.y"




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


