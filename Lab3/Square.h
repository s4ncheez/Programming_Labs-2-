#ifndef SQUARE_H
#define SQUARE_H

#include "iostream"

using namespace std;

namespace square {

    struct Vector {
        float x;
        float y;
    };

    class Square {

        friend bool operator==(const Square &square1, const Square &square2);

        friend bool operator!=(const Square &square1, const Square &square2);

        friend bool operator>(const Square &square1, const Square &square2);

        friend bool operator<(const Square &square1, const Square &square2);

        friend Square operator*(Square square, float k);

        friend Square operator+(Square square, Vector &V);

    private:
        float x_ver, y_ver;
        float side;
        float angle;
        float S;

    public:

        Square(float x, float y, float st, float ang) {
            x_ver = x;
            y_ver = y;
            side = st;
            angle = ang;
            S = side * side;
        }

        void cout_() const;
    };
}
#endif //SQUARE_H