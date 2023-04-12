#include <iostream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

//	편의를 위해 입력값에 대해서 정수로만 결과를 나타냄.
//	교수님 과제 너무 어려워요........

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