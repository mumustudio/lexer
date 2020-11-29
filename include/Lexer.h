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
    char peek;
    map<string, Word *> words;
    fstream *file;  //讀取的檔案
    Lexer(fstream *file);

    virtual ~Lexer();

    void reserve(Word *w);

    void readch();

    bool readch(char c);

    Token scan();

protected:

private:
};

#endif // LEXER_H
