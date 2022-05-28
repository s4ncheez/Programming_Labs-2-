#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Base.h"

class Rectangle: public IFigure {
private:
    double weight = 0;
    const char* name = "Rectangle";
    CVector2D A;
    CVector2D B;
    CVector2D C;
    CVector2D D;
public:
    Rectangle();
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator== (const IPhysObject& ob) const override;
    bool operator< (const IPhysObject& ob) const override;
    void draw() override;
    void initFromDialog() override;
    const char* classname() override;
    unsigned int size() override;
};
#endif //RECTANGLE_H