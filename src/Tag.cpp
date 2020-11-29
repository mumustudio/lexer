#include "../include/Tag.h"
#include <string>

using namespace std;

Tag::Tag()
{
    //ctor
}

Tag::~Tag()
{
    //dtor
}

// toString 回傳tag  !!若無對應tag回傳OTHER(之後要判斷)!!
string Tag::toString(int tag) {
    switch (tag) {
        case Tag::AND:
            return "AND";
        case Tag::BASIC:
            return "BASIC";
        case Tag::BREAK:
            return "BREAK";
        case Tag::DO:
            return "DO";
        case Tag::ELSE:
            return "ELSE";
        case Tag::EQ:
            return "EQ";
        case Tag::FALSE:
            return "FALSE";
        case Tag::GE:
            return "GE";
        case Tag::ID:
            return "ID";
        case Tag::IF:
            return "IF";
        case Tag::INDEX:
            return "INDEX";
        case Tag::LE:
            return "LE";
        case Tag::MINUS:
            return "MINUS";
        case Tag::NE:
            return "NE";
        case Tag::NUM:
            return "NUM";
        case Tag::OR:
            return "OR";
        case Tag::REAL:
            return "REAL";
        case Tag::TEMP:
            return "TEMP";
        case Tag::TRUE:
            return "TRUE";
        case Tag::WHILE:
            return "WHILE";
        default:
            return "OTHER";
    }
}

