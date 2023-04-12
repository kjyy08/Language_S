#include "Parser.h"
#include <iostream>
#include <regex>

Token* Parser::getToken()
{
	Token* tok = lexer.getToken(pos++);

	if (tok == nullptr)
		tok = new Token("EOF", Token::_EOF);
	return tok;
}

Token* Parser::getNextToken()
{
	return lexer.getToken(pos + 1);
}


bool Parser::match(Token::TOKTYPE type)
{
	if (currentToken->getType() == type)
	{
		currentToken = getToken();

		if (currentToken->getType() == Token::_EOF)
			return false;
		else
			return true;
	}
	
	return false;
}

int Parser::expr()	//	<expr> => <bexp> { & <bexp> | '|' <bexp> } | !<expr> | true | false
{
	int result = 0;

	if (currentToken->getType() == Token::NOT)
	{
		match(Token::NOT);
		result = !(expr());
	}
	
	else if (currentToken->getType() == Token::TRUE)
	{
		currentToken = getToken();
		result = 1;	
	}

	else if (currentToken->getType() == Token::FALSE)
	{
		currentToken = getToken();
		result = 0;

	}

	else
	{
		result = bexp();

		while (currentToken->getType() == Token::AND || currentToken->getType() == Token::OR)
		{
			if (currentToken->getType() == Token::AND)
			{
				currentToken = getToken();
				result = result & bexp();
			}

			else if (currentToken->getType() == Token::OR)
			{
				currentToken = getToken();
				result = result | bexp();
			}
		}
	}

	return result;
}


int Parser::bexp()	//	<bexp> => <aexp> [ <relop> <aexp> ]
{
	int result = aexp();

	if (currentToken->getType() == Token::EQUAL)	//	==
	{
		match(Token::EQUAL);
		result = (result == aexp());
	}

	else if (currentToken->getType() == Token::NOTEQUAL)	//	!=
	{
		match(Token::NOTEQUAL);
		result = (result != aexp());
	}

	else if (currentToken->getType() == Token::LESSTHAN)	//	<
	{
		match(Token::LESSTHAN);
		result = (result < aexp());
	}

	else if (currentToken->getType() == Token::MORETHAN)	//	>
	{
		match(Token::MORETHAN);
		result = (result > aexp());
	}

	else if (currentToken->getType() == Token::ATMOST)	//	<=
	{
		match(Token::ATMOST);
		result = (result <= aexp());
	}

	else if (currentToken->getType() == Token::ATLEAST)	//	>=
	{
		match(Token::ATLEAST);
		result = (result >= aexp());
	}
	
	return result;
}

//	int Parser::relop()	//	<relop> => == | != | <|> | <= | >=
//	{
//		OPERATOR result = currentToken->getType();
//		int nextToken = getNextToken();
//	
//		if (isdigit(nextToken))	//	다음 토큰 값이 숫자 또는 문자라면 부호가 하나인 경우임. ex) >, <, !
//			return result;
//		else
//		{
//			string s = "";
//			s = s + (char)token + (char)nextToken;
//	
//			if (s == "==")
//				result = EQUAL;
//			
//			else if (s == "!=")
//				result = NOTEQUAL;
//			
//			else if (s == ">=")
//				result = ATLEAST;
//			
//			else if (s == "<=")
//				result = ATMOST;
//		}
//	
//		return result;
//	}

int Parser::aexp()	//	<aexp> => <term> { + <term> | - <term> }
{
	int result = term();

	while (currentToken->getType()== Token::PLUS || currentToken->getType() == Token::MIN)
	{
		if (currentToken->getType() == Token::PLUS)
		{
			match(Token::PLUS);
			result += term();
		}
		else if (currentToken->getType() == Token::MIN)
		{
			match(Token::MIN);
			result -= term();
		}
	}

	return result;
}


int Parser::term()	//	<term> => <factor> { * <factor> | / <factor> }
{
	// TODO: 여기에 구현 코드 추가.
	int result = factor();

	while (currentToken->getType() == Token::MUL || currentToken->getType() == Token::DIV)
	{
		if (currentToken->getType() == Token::MUL)
		{
			match(Token::MUL);
			result *= term();
		}
		else if (currentToken->getType() == Token::DIV)
		{
			match(Token::DIV);
			result /= term();
		}
	}

	return result;
}


int Parser::factor()	//	<factor> => [-] ( <number> | ( <aexp> ) )
{
	// TODO: 여기에 구현 코드 추가.
	int result = 0;

	if (currentToken->getType() == Token::MIN)
	{
		match(Token::MIN);
		if (currentToken->getType() == Token::LPAREN)
		{
			match(Token::LPAREN);
			result = -(aexp());
			match(Token::RPAREN);
		}

		else if (currentToken->getType() == Token::DIGIT)
			result = -(number());
	}
	else
	{
		if (currentToken->getType() == Token::LPAREN)
		{
			match(Token::LPAREN);
			result = aexp();
			match(Token::RPAREN);
		}

		else if (currentToken->getType() == Token::DIGIT)
			result = number();
	}

	return result;
}

int Parser::number()	//	<number> => <digit> { <digit> }
{
	int result = 0;

	if (currentToken->getType() == Token::DIGIT)
	{
		result = stoi(currentToken->getValue());
		match(Token::DIGIT);
	}

	return result;
}

void Parser::print(int result)
{
	cout << endl;
	cout <<"\n\t= " << result << endl;
	cout << "-------------------------------------" << endl;
}

void Parser::parse()
{
	pos = 0;
	lexer.scanToken(input);
	currentToken = getToken();

	int result = expr();
	print(result);
}

void Parser::parse(string s)
{
	input = s;
	pos = 0;
	lexer.scanToken(s);
	currentToken = getToken();

	int result = expr();
	print(result);
	
	lexer.clearTokens();
	currentToken = nullptr;
}

