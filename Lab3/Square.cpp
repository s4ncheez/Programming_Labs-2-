#include "Square.h"
#include <iostream>

using namespace std;

namespace square {

    bool operator==(const Square &square1, const Square &square2) {
        return (square1.S == square2.S);
    }

    bool operator!=(const Square &square1, const Square &square2) {
        return !(square1 == square2);
    }

    bool operator>(const Square &square1, const Square &square2) {
        return (square1.S > square2.S);
    }

    bool operator<(const Square &square1, const Square &square2) {
        return (square1.S < square2.S);
    }

    Square operator*(Square square, float k) {
        square.side *= k;
        square.S = square.side * square.side;
        return square;
    }

    Square operator*(float k, Square square) {
        return operator*(square, k);
    }

    Square operator+(Square square, Vector &V) {
        square.x_ver += V.x;
        square.y_ver += V.y;
        return square;
    }

    Square operator+(Vector &V, Square square) {
        return operator+(square, V);
    }

    void Square::cout_() const {
        cout << "Координаты вершины: " << x_ver << ' ' << y_ver << '\n';
        cout << "Сторона: " << side << '\n';
        cout << "Угол: " << angle << '\n';
        cout << "Площадь: " << S << '\n';
    }
}