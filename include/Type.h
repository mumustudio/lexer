#ifndef TYPE_H
#define TYPE_H

#include <string>
#include "Tag.h"
#include "Word.h"

using namespace std;

class Type : public Word {
public:
    int width;

    Type(string s, int tag, int w);

    virtual ~Type();

    static Type *Int;
    static Type *Float;
    static Type *Char;
    static Type *Bool;
    static Type *NullType;

    string toString();

    bool numeric(Type p);
    bool isEqual(Type a,Type b);
    Type max(Type p1,Type p2);
protected:

private:

};


#endif // TYPE_H
