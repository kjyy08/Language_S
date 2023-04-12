#pragma once
#include <string>
#include <map>

using namespace std;

class Token
{
public:
	typedef enum TOKENNAME
	{
		NONE = -1,
		ID,			//	var
		FALSE,		//	false
		TRUE,		//	true
		DIGIT,		//	0, 1, 2, 3, 4....9
		CHAR,		//	a, b, c, d...A, B, C, D...~ Z
		STR,		//	string
		INT,
		FLOAT,
		BOOL,
		PLUS,		//	+
		MIN,		//	-
		MUL,		//	*
		DIV,		//	/
		NOT,		//	!
		AND,		//	&
		OR,			//	|
		ASSIGN,		//	=
		EQUAL,		//	==
		NOTEQUAL,	//	!=
		LESSTHAN,	//	<
		MORETHAN,	//	>
		ATMOST,		//	<=
		ATLEAST,	//	>=
		LPAREN,		//	(
		RPAREN,		//	)
		IF,
		THEN,
		ELSEIF,
		ELSE,
		WHILE,
		LET,
		IN,
		END,
		COLON,
		SEMICOLON,
		_EOF,		//	EOF
	}OPERATOR, TOKTYPE;

private:
	const map<string, TOKTYPE> KEYWORDS =
	{
		{ "false", FALSE },
		{ "true", TRUE },
		{ "+", PLUS },
		{ "-", MIN },
		{ "*", MUL },
		{ "/", DIV },
		{ "!", NOT },
		{ "&", AND },
		{ "|", OR },
		{ "=", ASSIGN },
		{ "==", EQUAL },
		{ "!=", NOTEQUAL },
		{ "<", LESSTHAN },
		{ ">", MORETHAN },
		{ "<=", ATMOST },
		{ ">=", ATLEAST },
		{ "(", LPAREN },
		{ ")", RPAREN },
		{ "if", IF },
		{ "then", THEN },
		{ "else", ELSE },
		{ "elif", ELSEIF },
		{ "while", WHILE },
		{ "let", LET },
		{ "in", IN},
		{ "end", END },
		{ "int", INT},
		{ "float", FLOAT},
		{ "bool", BOOL},
		{ ":", COLON},
		{ ";", SEMICOLON },
		{ "^Z", _EOF },

	};


private:
	string value;	//	���� �� ����	EX) if ( a == 3) -> "if", "(", "a", "==", "3", ")"
	TOKTYPE type;	//	��ū�� Ÿ��

public:
	Token() : type(NONE) {}
	Token(string s);
	Token(string s, TOKTYPE t) : value(s), type(t) { }
	bool operator==(Token& ref);


public:
	//	��ū�� ���� ����
	void SetValue(string s) { value = s; }
	void SetType(TOKTYPE t) { type = t; }
	//	�Է¹��� s�� ���� id or keywords ���� Ȯ�� �� ��ȯ.
	bool isKeywords(string s);
	string getValue() const { return value; }
	TOKTYPE getType() const { return type; }
};

