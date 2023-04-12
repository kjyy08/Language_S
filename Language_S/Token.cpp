#include "Token.h"

Token::Token(string s)
{
	value = s;

	//	Ű���尡 �ƴ� ���
	if (!isKeywords(s))
	{
		
	}
}

bool Token::operator==(Token& ref)
{
	if (value == ref.value && type == ref.type)
		return true;
	return false;
}

bool Token::isKeywords(string s)
{
	map<string, TOKTYPE>::const_iterator it = KEYWORDS.find(s);

	if (it != KEYWORDS.end())	//	Ű���忡 �ش��ϴ� ���� ������
	{
		value = s;
		type = it->second;
		return true;
	}
	
	else
	{
		value = s;
		return false;
	}
}