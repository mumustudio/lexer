#include <iostream>
#include "../include/Lexer.h"
#include "../include/Type.h"
#include "../include/Num.h"
#include "../include/Real.h"
#include "../EndException.h"

int Lexer::line = 1;

Lexer::Lexer() {
    this->peek = ' ';
    reserve(new Word("if", Tag::IF));
    reserve(new Word("else", Tag::ELSE));
    reserve(new Word("while", Tag::WHILE));
    reserve(new Word("do", Tag::DO));
    reserve(new Word("break", Tag::BREAK));
    reserve(Word::w_True);
    reserve(Word::w_False);
    reserve(Type::Int);
    reserve(Type::Char);
    reserve(Type::Bool);
    reserve(Type::Float);
}

Lexer::~Lexer() {
    //dtor
}

void Lexer::reserve(Word *w) {
    this->words[w->lexeme] = w;
}

void Lexer::readch() {
    int ch;
    ch = std::cin.get();
    if (ch != EOF) {
        this->peek = ch;
    } else {
        throw *(new EndException);
    }
}

bool Lexer::readch(char c) {
    readch();
    if (this->peek != c) {
        return false;
    }
    this->peek = ' ';
    return true;
}

Token Lexer::scan() {
    for (;; readch()) {
        if (this->peek == ' ' || this->peek == '\t') {
            continue;
        } else if (this->peek == '\n') {
            Lexer::line = Lexer::line + 1;
        } else {
            break;
        }
    }
    switch (this->peek) {
        case '&':
            if (readch('&'))
                return *Word::w_and;
            else
                return Token('&');
        case '|':
            if (readch('|'))
                return *Word::w_or;
            else
                return Token('|');
        case '=':
            if (readch('='))
                return *Word::w_eq;
            else
                return Token('=');
        case '!':
            if (readch('='))
                return *Word::w_ne;
            else
                return Token('!');
        case '<':
            if (readch('='))
                return *Word::w_le;
            else
                return Token('<');
        case '>':
            if (readch('='))
                return *Word::w_ge;
            else
                return Token('>');
    }

    if (isdigit(this->peek)) {
        int v = 0;
        do {
            v = 10 * v + std::stoi(&this->peek, nullptr, 10);
            readch();
        } while (isdigit(this->peek));

        if (this->peek != '.') {
            return Num(v);
        }
        float x = v;
        float d = 10;
        for (;;) {
            readch();
            if (!isdigit(this->peek)) {
                break;
            }
            x = x + std::stoi(&this->peek, nullptr, 10) / d;
            d = d * 10;
        }
        return Real(x);
    }

    if (isalpha(this->peek)) {
        string b = "";
        do {
            b = b + this->peek;
            readch();
        } while (isalnum(this->peek));
        string s = b;
        Word *w = words[s];
        if (w != nullptr) {
            return *w;
        }
        w = new Word(s, Tag::ID);
        words[s] = w;
        return *w;
    }

    Token *tok = new Token(this->peek);
    this->peek = ' ';
    return *tok;
}
