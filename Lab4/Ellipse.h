#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Base.h"

class Ellipse: public IFigure {
private:
    double weight = 0;
    double half_axis_a = 0;
    double half_axis_b = 0;
    CVector2D O;
    const char* name = "Ellipse";
public:
    Ellipse();
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
#endif //ELLIPSE_H