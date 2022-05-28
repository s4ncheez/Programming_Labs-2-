#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

using namespace std;

class Exception: public exception {
private:
    string error;
public:
    explicit Exception (string er);
    string print();
};

#endif //EXCEPTION_H