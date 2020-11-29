#include <iostream>
#include "include/Lexer.h"
#include "EndException.h"

using namespace std;

int main(int argc,char *argv[]) {
    if(argc<2){
        cout<<"please type at least one argument..."<<endl;
        return 1;
    }
    string filename=argv[1];

    fstream file;
    file.open(filename, ios::in);

    if (!file.is_open()) {
        cout << "file is not open" << endl;
        return 1;
    }

    Lexer *lexer = new Lexer(&file);

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
