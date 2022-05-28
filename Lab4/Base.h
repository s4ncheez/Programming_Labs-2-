#ifndef BASE_H
#define BASE_H
#include <iostream>

using namespace std;

class IGeoFig {
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x;
    double y;
    CVector2D(): x(0), y(0) {}
};

class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual CVector2D position() = 0;
    virtual bool operator== (const IPhysObject& ob) const = 0;
    virtual bool operator< (const IPhysObject& ob) const = 0;
};

class IPrintable {
public:
    virtual void draw() = 0;
};

class IDialogInitable {
public:
    virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
    virtual const char* classname() = 0;
    virtual unsigned int size() = 0;
};

class IFigure : public IGeoFig, public CVector2D, public IPhysObject, public IPrintable, public IDialogInitable, public BaseCObject {};

#endif //BASE_H