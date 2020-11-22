#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

class Token {
public:
    int tag;
    string lex;

    Token(int t);
    Token(string s, int t);

    virtual ~Token();

    string toString();

protected:

private:
};

#endif // TOKEN_H
