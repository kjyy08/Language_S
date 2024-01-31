#pragma once
#include "Lexer.h"

using namespace std;

class Parser
{
private:
	Lexer lexer;
	string input;	//	�Է� ��
	int pos = 0;	//	���� ��ġ
	Token *currentToken;	//	���� ��ū

public:
	Parser() { }
	Parser(string s) { input = s; }

private:
	//	���� ��ġ�� ��ū�� �������� ���� ��ū���� ��ġ�� �Ű���.
	Token* getToken();
	//	���� ��ġ�� ��ū�� ���� ������ Ȯ��.
	bool match(Token::TOKTYPE type);
	//	���� ��ġ�� ��ū�� ������, ���� �� ���� ����
	Token* getNextToken();

public:


public:
	int expr();
	int term();
	int factor();
	int number();
	int aexp();
	int bexp();
	//int relop();

public:
	void SetString(string s) { input = s; }
	void parse(string s);
	void parse();
	void print(int result);
};

