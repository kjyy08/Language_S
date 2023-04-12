#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Token.h"

using namespace std;

class Lexer
{
private:
	vector<Token*> tokens;    //  �Է°��� ��ū���� ���� ���� �����
    //int pos;     //  ���� ���� ���ڰ�
    string input;   //  �Է� ���� ���ڿ�

public:
	Lexer() { }
    ~Lexer() {
        for (auto it = tokens.begin(); it != tokens.end(); it++)
            delete *it;
        tokens.clear();
    }

public:
    //  ��ū�� �����
    void clearTokens();
    //  ���ڿ��� ��ū ������ �ɰ��� Ÿ���� �������� => ���ֺм�
    void scanToken(const string line);
    //  ��ū ��� �Լ�
    void printTokens();

    Token* getToken(int pos);
};

