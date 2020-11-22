#ifndef REAL_H
#define REAL_H

#include "Token.h"

class Real : public Token {
public:
    using Token::Token;
    float value;

    Real(float v);

    virtual ~Real();

    string toString();

protected:

private:
};

#endif // REAL_H
