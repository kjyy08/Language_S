#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stmt
{

	//	while문을 위한 AST class
	typedef class WHILE
	{
		
	}While;

	//	if문을 위한 AST class
	typedef class IF
	{

	}If;
	
	//	Let문을 위한 AST class
	typedef class LET
	{

	}Let;

	//	중첩문을 위한 AST class
	typedef class STMTS
	{

	}Stmts;

};

