#ifndef POW_H
#define POW_H
#include <iostream>
#include "Exception.h"
#include <typeinfo>

using namespace std;

template <typename number, typename degree>
number pow (number num, typename std::enable_if<std::is_integral<degree>::value, degree >::type deg) {
    try {
        if (deg < 0) {
            return 1 / pow<number, degree>(num, abs(deg));
        }
        else if (deg == 0) {
            return 1;
        }
        else {
            int n = num;
            num = 1;
            for (int i = 0; i < deg; i++) {
                num *= n;
            }
        }
        return num;
    }
    catch (Exception &ex) {
        cout << ex.print() << '\n';
    }
    return -1;
}
#endif //POW_H