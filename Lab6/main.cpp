#include <iostream>
#include "Iterator.h"
#include "CPoint.h"
#include <vector>
#include <algorithm>

using namespace std;

template <typename obj>
bool predicate (obj value) {
    return (value < 0);
}

template <typename obj>
bool equal (obj value) {
    return (value == 6);
}

int main() {
    int size;
    cin >> size;
    vector <int> vec (size);
    for (int i = 0; i < size; i++) {
        cin >> vec[i];
    }
    cout << "For first (int) container: \n";
    cout << "any of: ";
    cout << ((any_of(vec.begin(), vec.end(), predicate<int>))? "True" : "False");
    cout << '\n';
    cout << "one_of: ";
    cout << ((one_of(vec.begin(), vec.end(), predicate<int>))? "True" : "False");
    cout << '\n';
    cout << "find_not: ";
    if (find_not(vec.begin(), vec.end(), equal<int>) == vec.end()) {
        if (equal (*vec.end())) {
            cout << "Not found";
        }
        else {
            cout << *(find_not(vec.begin(), vec.end(), equal<int>));
        }
    }
    else {
        cout << *(find_not(vec.begin(), vec.end(), equal<int>));
    }
    cout << "\n\nFor second (CPoint2D) container: \n";
    vector <CPoint2D> vec_2 = {CPoint2D{6, 6}, CPoint2D{-1, -1}, CPoint2D{6, 6}};
    cout << "any of: ";
    cout << ((any_of(vec_2.begin(), vec_2.end(), predicate<CPoint2D>))? "True" : "False");
    cout << '\n';
    cout << "one_of: ";
    cout << ((one_of(vec_2.begin(), vec_2.end(), predicate<CPoint2D>))? "True" : "False");
    cout << '\n';
    cout << "find_not: ";
    if (find_not(vec_2.begin(), vec_2.end(), equal<CPoint2D>) == *(vec.end())) {
        if (equal (*vec_2.end())) {
            cout << "Not found";
        }
        else {
            cout << (find_not(vec_2.begin(), vec_2.end(), equal<CPoint2D>));
        }
    }
    else {
        cout << (find_not(vec_2.begin(), vec_2.end(), equal<CPoint2D>));
    }
    return 0;
}