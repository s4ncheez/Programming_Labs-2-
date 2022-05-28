#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>

using namespace std;

template <typename iterator, typename object, typename T>
bool any_of (iterator begin, iterator end, T function) {
    for (auto it = begin; it != end; it++) {
        if (function(*it)) {
            return true;
        }
    }
    return false;
}

template <typename object, typename iterator, typename T>
bool one_of (iterator begin, iterator end, T function) {
    int is_good = 0;
    for (auto it = begin; it != end; it++) {
        if (function(*it)) {
            is_good++;
        }
    }
    return (is_good == 1);
}

template <typename object, typename iterator, typename T>
iterator find_not (iterator begin, iterator end, T function) {
    for (auto it = begin; it != end; it = next(it)) {
        if (!function(*it)) {
            return it;
        }
    }
    return end;
}
#endif //ITERATOR_H