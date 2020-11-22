#ifndef WORD_H
#define WORD_H

#include <string>
#include "Tag.h"
#include "Token.h"

using namespace std;

class Word : public Token {
public:
    using Token::Token;
    string lexeme;

    Word(string, int);

    virtual ~Word();

    static Word *w_and;
    static Word *w_or;
    static Word *w_eq;
    static Word *w_ne;
    static Word *w_le;
    static Word *w_ge;
    static Word *w_minus;;
    static Word *w_True;
    static Word *w_False;
    static Word *w_temp;

    string toString();

protected:

private:
};


#endif // WORD_H
