#include "../include/Real.h"
#include "../include/Tag.h"

Real::Real(float v):Token(std::to_string(v), Tag::REAL)
{
    //ctor
    this->value = v;
}

Real::~Real()
{
    //dtor
}

string Real::toString() {
    return std::to_string(this->value);
}
