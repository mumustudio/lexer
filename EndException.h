//
// Created by blue1 on 2020/11/22.
//

#ifndef UNTITLED_ENDEXCEPTION_H
#define UNTITLED_ENDEXCEPTION_H
#include <exception>

class EndException: public std::exception {
public:
    virtual const char* what() const throw()
  {
    return "End of file reached";
  }
};


#endif //UNTITLED_ENDEXCEPTION_H
