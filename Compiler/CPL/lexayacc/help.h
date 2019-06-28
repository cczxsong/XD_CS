#pragma once
#include <map>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <assert.h>

using namespace std;
typedef int ADDR,codeADDR;
//type value the type
typedef int vTYPE;
enum VALUE_TYPE { CONSTANT,UNDEFINED,LABEL, VARIABLE, TEMP_VARIABLE };

#ifndef _mCONTROLLOG__
#define __mCOUT4E 0
#define __mCOUT3C 1
#define __mCOUTmsg 1
//add find symbol 
#define __mCOUTsmsg 1
//�������
#define __mCOUTyymsg 1
//�ʷ� �ս��ʶ��
#define _mCOUNTprinttoken 0
#endif // !_m3CCONTROL__


struct myYYTYPE
{
	int ival;
	string sval;
	bool bval;
	struct yyBOOL{
		ADDR  place; //��ŷ��ű��еĵ�ַ ����Ǵ�������
		string name; //�����ս�� û������ �а���ʱ����Ҳ������
		bool val;
		string desc;
		////BOOl v�� û��M������ ���ʵ��
		//codeADDR begin, next;
		//�������Ϊ��·�����������

		string True; //����ɨ��ʹ�õ�
		string False;
		list<codeADDR> code,tc,fc;//���뼯 ������
		void append(list<codeADDR> &l) {
			code.splice(code.end(), l);
			l.clear();//��ȷ���ǲ����ƶ�;
		}
		yyBOOL() {
			code.clear();
			tc.clear();
			fc.clear();
		}
	} nB; //���ս��B

	struct yyEXPRESS{
		ADDR  place; //��ŷ��ű��е�#����#��ַ ����Ǵ�������
		string name; //�����ս�� û������ �а���ʱ����Ҳ������
		vTYPE val;
		string desc;
		////BOOl v�� û��M������ ���ʵ��
		list<codeADDR> code;//���뼯
		void append(list<codeADDR> &l) {
		code.splice(code.end(), l);
		l.clear();//��ȷ���ǲ����ƶ�;
		}
		yyEXPRESS() {
			code.clear();
		}
	} nE;//���ս��E
	struct yyPROGRAM {
		string desc;
		//ADDR  place; �ṹû���������
		////BOOl v�� û��M������ ���ʵ��
		string begin;//P��ʼ�ͽ��������� #��������#

		
		list<codeADDR>  code,nc;//���뼯
		void append(list<codeADDR> &l) {
			code.splice(code.end(), l);
			l.clear();//��ȷ���ǲ����ƶ�;
		}
		yyPROGRAM() {
			code.clear();
			nc.clear();
		}
	} nP;//���ս��P
	
}; 
#ifndef __my_SYMBOL_NULL
#define ___ -1
#endif
struct Elem {
	ADDR	id;
	string	name;
	vTYPE val;//	���� codeADDR code;
	VALUE_TYPE type;

	Elem(int _i, string _n, vTYPE _v, VALUE_TYPE _t) :
		id(_i), name(_n), val(_v), type(_t) {
		if(_v==LABEL)val = -1;
	}
	string getName() {
		return name;
	}

};

//todo �ֱ������ת����ͨ����4Ԫʽ
struct f4Elem {//Ҳ��code
	string	 op;
	ADDR	arg1;
	ADDR	arg2;
	ADDR	ret; //op Ϊj ʱ �������Ϊ stat ��ת��ַ
	string toString3c;
	string toString4e;
	string label,tolabel;
	f4Elem(int nid,
		string _op,
		ADDR _arg1,
		ADDR _arg2,
		ADDR _ret) :op(_op), arg1(_arg1), arg2(_arg2), ret(_ret) {
			assert(arg1 >= -1 && arg1 <  nid);
			assert(arg2 >= -1 && arg2 <  nid);
			if(op[0]!='j')assert(ret >= -1 && ret <  nid);
			toString3c = "";
			toString4e = "";
			tolabel = "undefined";
			label = "";
	}

	string str4e() {

		string a1 = arg1 == -1 ? "___" : to_string(arg1);
		string a2 = arg2 == -1 ? "___" : to_string(arg2);
		if (op[0] == 'j') {
			return toString4e = label+"(" + op + "," + a1 + " ," + a2 + "," + tolabel + ")";
		}
		else return toString4e = label+"(" + op + "," + a1 + " ," + a2 + "," + to_string(ret) + ")";
		
	}
	string str3c(vector<Elem> &t) {
	

		string a1 = arg1 == -1 ? " " : t[arg1].getName();
		string a2 = arg2 == -1 ? " " : t[arg2].getName();
		if (op[0] == 'j') {
			if (arg1 != -1 && arg2 != -1)//jrop a,b,x
				toString3c ="if " + a1 + " " + op.substr(1) + " " + a2+" goto "+tolabel;
			else if (arg1 == -1 && arg2 == -1) // j,,x
				toString3c ="goto " + tolabel;
			else if (arg1 != -1 && arg2 == -1) // ��Ԫ
				toString3c = "if " + op.substr(1) + a1+ " goto " + tolabel;
			else {
				assert(false);
			}
		}
		else {
			if (arg1 != -1 && arg2 != -1)// op, a , b,ret
				toString3c = t[ret].getName() + " = " + a1 + " " + op + " " + a2;
			else if (arg1 != -1 && arg2 == -1) {//
				if (op == "=") //ret=E
					toString3c = t[ret].getName() + op + a1;
				else////ret = -E
					toString3c = t[ret].getName() + " = " + op + a1;
			}
			else if (arg1 != -1 && arg2 == -1)// ret = -E
				toString3c = t[ret].getName() + " = " + op + a1;
			else assert(false);
		}
		return label + toString3c;
	}
};			 


class Symboltable {
	
	void smsg(string str) {
		if(__mCOUTsmsg)cout << "### " << str << endl;
	}
	
	map<string, ADDR> indextable;
	int nextId;
	int nextLabelId;
public:
	
	vector<Elem> table;
	Symboltable() {
		
		table.clear();
		indextable.clear();
		nextId = 0;
		nextLabelId = 1;
		smsg("Symboltable init ok.");

	}
	//����ԭ���� ���entry�Ĺ��� Ĭ��Ϊδ����
	ADDR entry(string _n = "",VALUE_TYPE _t = UNDEFINED, vTYPE _v = -1) {
		
		if (_n.length() == 0) {
			_n = "T" + to_string(nextId);
			
		}
		//����Ѿ����������
		auto it = indextable.find(_n);

		if (it == indextable.end()) {
			Elem  te(nextId, _n, _v, _t);
			indextable.insert(make_pair(_n, nextId));
			table.push_back(te);
			nextId++;
			smsg("add new symbol id:" + to_string(te.id)+"->"+_n);
			return te.id;
		}
		else {
			smsg("find symbol id:" + to_string(it->second) + "->" + _n);
			return it->second;
		}
		return -1;
	}
	
	int getNextId() {
		return nextId;
	}
	
	Elem & getElemByAddr(ADDR ad) {
		return table[ad];
	}

	static void hello() {
		cout << "hello in symbol table";
	}
	// �����±�ǩ�ڷ��ű��е�����
	string newLabel() {
		ADDR ad =  entry("L" + to_string(nextLabelId++) + ":",LABEL);
		return table[ad].name;
	}
};


