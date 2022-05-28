#include "Exception.h"

Exception::Exception(string er) {
    error = er;
}

string Exception::print() {
    return error;
}