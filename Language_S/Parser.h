#pragma once
#include "Lexer.h"

using namespace std;

class Parser
{
private:
	Lexer lexer;
	string input;	//	입력 값
	int pos = 0;	//	현재 위치
	Token *currentToken;	//	현재 토큰

public:
	Parser() { }
	Parser(string s) { input = s; }

private:
	//	현재 위치의 토큰을 가져오고 다음 토큰으로 위치를 옮겨줌.
	Token* getToken();
	//	현재 위치의 토큰과 값이 같은지 확인.
	bool match(Token::TOKTYPE type);
	//	다음 위치의 토큰을 가져옴, 공백 탭 리턴 제외
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

