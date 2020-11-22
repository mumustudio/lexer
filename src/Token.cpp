#include <string>
#include "../include/Token.h"
#include "../include/Tag.h"

using namespace std;

Token::Token(int t) {
    this->tag = t;//ctor
}

Token::Token(string s, int t) {
    this->lex = std::move(s);
    this->tag = t;//ctor
}

Token::~Token() {
    //dtor
}

string Token::toString() {
    Tag tag = *(new Tag());
    string tagStr = tag.toString(this->tag);
    string inputStr = this->lex;
    if (tagStr == "OTHER") {
        tagStr = (char) this->tag;
        inputStr = (char) this->tag;
    }

    char buf[30];
    std::snprintf(buf, 30, "Token: %-10s(%s)", inputStr.c_str(), tagStr.c_str());
    string tokenStr(buf);
//    string tokenStr = std::sprintf("Token:" + inputStr+ "\t\t(" + tagStr+")");
    return tokenStr;
}
