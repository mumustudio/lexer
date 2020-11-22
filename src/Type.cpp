#include "../include/Type.h"

Type *Type::Int = new Type("int", Tag::BASIC, 4);
Type *Type::Float = new Type("float", Tag::BASIC, 8);
Type *Type::Char = new Type("char", Tag::BASIC, 1);
Type *Type::Bool = new Type("bool", Tag::BASIC, 1);
Type *Type::NullType = NULL;

Type::Type(string s, int tag, int w) : Word(std::move(s), tag) {
    this->width = w;
    //ctor
}

Type::~Type() {
    //dtor
}

bool Type::numeric(Type p) {
    if (isEqual(p, *Type::Char) || isEqual(p, *Type::Int) || isEqual(p, *Type::Float)) {
        return true;
    } else {
        return false;
    }
}

Type Type::max(Type p1, Type p2) {
    if (!numeric(p1) || !numeric(p2)){
        return *NullType;
    }else if (isEqual(p1, *Type::Float) || isEqual(p2, *Type::Float)) {
        return *Type::Float;
    } else if (isEqual(p1, *Type::Int) || isEqual(p2, *Type::Int)) {
        return *Type::Int;
    } else {
        return *Type::Char;
    }
}

bool Type::isEqual(Type a, Type b) {
    if (a.lexeme == b.lexeme && a.tag == b.tag && a.width == b.width) {
        return true;
    } else {
        return false;
    }
}



