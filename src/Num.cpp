#include "../include/Num.h"
#include "../include/Tag.h"

Num::Num(int v):Token(std::to_string(v), Tag::NUM)
{
    this->value= v;
    //ctor
}

Num::~Num()
{
    //dtor
}

string Num::toString() {
    return std::to_string(this->value);
}