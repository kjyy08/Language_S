#include "Lexer.h"

void Lexer::clearTokens()
{
    for (auto it = tokens.begin(); it != tokens.end(); it++)
        delete* it;

    tokens.clear();
}

void Lexer::printTokens()
{
    int i = 0;

    cout << "input => " << input << endl;

    for (auto it = tokens.begin(); it != tokens.end(); it++)
        cout << "[" << i++ << "] : " << "\"" << (*it)->getValue() << "\", ";//<< "          type = " << (*it)->getType() << endl;

    cout << endl;
}

void Lexer::scanToken(const string line)
{
    int ch = -1;
    int pos = 0;
    string s = "";

    input = line;

    ch = line[pos];

    while (pos < line.length())
    {
        s = "";
        ch = line[pos++];

        if (isalpha(ch))
        {
            // ident or keyword
            while (true)
            {
                s += ch;

                if (isalpha(line[pos]) || isdigit(line[pos]))
                    ch = line[pos++];
                else
                    break;
            }

            Token* tok = new Token();
            if (tok->isKeywords(s))
                tokens.push_back(tok);
            else
            {
                tok->SetType(Token::ID);
                tokens.push_back(tok);
            }
        }

        else if (isdigit(ch))
        {
            // number 
            while (true)
            {
                s += ch;

                if (isdigit(line[pos]))
                    ch = line[pos++];
                else
                    break;
            };

            tokens.push_back(new Token(s, Token::DIGIT));
        }

        else
        {
            s += ch;

            switch (ch)
            {
            case ' ': case '\t': case '\r':
                break;

            case '\"':  // string literal
                s = "";
                while (true)
                {
                    ch = line[pos++];
                    if (ch != '\"')
                        s += ch;
                    else
                        break;
                }
                tokens.push_back(new Token(s, Token::STR));
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
            case '&':
            case '|':
            case ':':
            case ';':
                tokens.push_back(new Token(s));
                break;
            case '=':
            case '<':
            case '>':
            case '!':
                if (line[pos] == '=' && line[pos] != ' ' && line[pos] != '\t' && line[pos] != '\r' && line[pos] != EOF)
                    s += line[pos++];
                tokens.push_back(new Token(s));
            }
        }
    }
}

Token* Lexer::getToken(int pos)
{
    if (pos >= tokens.size())
        return nullptr;
    else
        return tokens[pos];
}