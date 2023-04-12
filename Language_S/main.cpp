#include <iostream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

//	���Ǹ� ���� �Է°��� ���ؼ� �����θ� ����� ��Ÿ��.
//	������ ���� �ʹ� �������........

int main()
{	
	Parser* p = new Parser();
	
	while (true)
	{
		string s;
		
		cout << "input : ";
		getline(cin, s);
		p->parse(s);
	}
	
	delete p;
	
	Lexer *l = new Lexer();

	l->scanToken("let int x123; in;\
				x = 0;\
				x = x + 1;\
	end; \
	print(\"hello world\") true false");
	l->printTokens();
	
	cout << endl;
	
	l->clearTokens();
	l->scanToken("elif: a= 10");
	l->printTokens();

	delete l;
	return 0;
}