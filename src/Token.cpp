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

// toString 實際Token字串
string Token::toString() {
    Tag tag = *(new Tag());
    string tagStr = tag.toString(this->tag);
    string inputStr = this->lex;

    //判斷tag 如果不屬於任何tag
    if (tagStr == "OTHER") {
        tagStr = (char) this->tag;
        inputStr = (char) this->tag;
    }

    char buf[30];
    std::snprintf(buf, 30, "Token: %-10s(%s)", inputStr.c_str(), tagStr.c_str());
    string tokenStr(buf);
    return tokenStr;
}
