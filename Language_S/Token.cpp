#include "Token.h"

Token::Token(string s)
{
	value = s;

	//	키워드가 아닌 경우
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

	if (it != KEYWORDS.end())	//	키워드에 해당하는 값이 존재함
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