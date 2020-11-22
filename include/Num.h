#ifndef NUM_H
#define NUM_H

#include "Token.h"

class Num : public Token {
public:
    using Token::Token;
    int value;

    Num(int v);

    virtual ~Num();

    string toString();

protected:

private:

};

#endif // NUM_H
