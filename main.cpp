#include <iostream>
#include "include/Lexer.h"
#include "EndException.h"

using namespace std;

int main() {
    Lexer *lexer = new Lexer();

    try {
        while (true) {
            Token t = lexer->scan();
            cout << t.toString() << endl;
        }
    } catch (EndException &s) {
        cout << s.what() << endl;
    }
    return 0;
}
