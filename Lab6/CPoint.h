#ifndef CPOINT_H
#define CPOINT_H
#include <iostream>

using namespace std;

class CPoint2D {
private:
    double x;
    double y;
public:
    CPoint2D() {
        x = 0;
        y = 0;
    }
    CPoint2D(double x_, double y_) {
        x = x_;
        y = y_;
    }
    explicit CPoint2D(double x_) {
        x = x_;
        y = x_;
    }
    bool operator== (const CPoint2D& second) const {
        return (this->x == second.x && this->y == second.y);
    }
    bool operator== (double number) const {
        return (this->x == number && this->y == number);
    }
    bool operator< (double number) const {
        return (this->x < number && this->y < number);
    }
    bool operator< (const CPoint2D& second) const {
        return (this->x < second.x && this->y < second.y);
    }
    friend ostream& operator<< (ostream& out, const CPoint2D& point) {
        out << point.x << ',' << ' ' << point.y;
        return out;
    }
};
#endif //CPOINT_H