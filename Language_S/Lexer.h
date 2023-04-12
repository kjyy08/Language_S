#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Token.h"

using namespace std;

class Lexer
{
private:
	vector<Token*> tokens;    //  입력값을 토큰으로 나눈 값이 저장됨
    //int pos;     //  현재 읽은 문자값
    string input;   //  입력 받은 문자열

public:
	Lexer() { }
    ~Lexer() {
        for (auto it = tokens.begin(); it != tokens.end(); it++)
            delete *it;
        tokens.clear();
    }

public:
    //  토큰을 비워줌
    void clearTokens();
    //  문자열을 토큰 단위로 쪼개고 타입을 지정해줌 => 어휘분석
    void scanToken(const string line);
    //  토큰 출력 함수
    void printTokens();

    Token* getToken(int pos);
};

