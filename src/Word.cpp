#include "../include/Word.h"
#include "string"

using namespace std;

Word::Word(string s, int tag):Token(s, tag)
{
    this->lexeme=std::move(s);
    //ctor
}

Word::~Word()
{
    //dtor
}

Word *Word::w_and = new Word("&&",Tag::AND);
Word *Word::w_or = new Word("||", Tag::OR);
Word *Word::w_eq = new Word("==", Tag::EQ);
Word *Word::w_ne = new Word("!=", Tag::NE);
Word *Word::w_le = new Word("<=", Tag::LE);
Word *Word::w_ge = new Word(">=", Tag::GE);
Word *Word::w_minus = new Word("minus", Tag::MINUS);
Word *Word::w_True = new Word("true", Tag::TRUE);
Word *Word::w_False = new Word("false", Tag::FALSE);
Word *Word::w_temp = new Word("t", Tag::TEMP);

string Word::toString(){
    return this->lexeme;
}
