#ifndef LEXER_H
#define LEXER_H

#include <map>
#include <string>
#include <fstream>
#include "Word.h"
#include "Token.h"

using namespace std;

class Lexer {
public:
    static int line;
    char peek;
    map<string, Word *> words;

    Lexer();

    virtual ~Lexer();

    void reserve(Word *w);

    void readch();

    bool readch(char c);

    Token scan();

protected:

private:
};

#endif // LEXER_H
