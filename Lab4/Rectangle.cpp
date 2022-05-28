#include "Rectangle.h"
#include "iostream"

using namespace std;

Rectangle::Rectangle() {
    this-> Rectangle::initFromDialog();
}

double Rectangle::square() {
    return ((D.x - A.x) * (B.y - A.y));
}

double Rectangle::perimeter() {
    return ((C.x - A.x) + (B.y - A.y) + (C.x - B.x) + (C.y - D.y));
}

double Rectangle::mass() const {
    return weight;
}

CVector2D Rectangle::position() {
    CVector2D center_of_mass;
    center_of_mass.x = (C.x - A.x) / 2;
    center_of_mass.y = (B.y - A.y) / 2;
    return center_of_mass;
}

bool Rectangle::operator==(const IPhysObject &ob) const {
    return (mass() == ob.mass());
}

bool Rectangle::operator<(const IPhysObject &ob) const {
    return (mass() < ob.mass());
}

void Rectangle::draw() {
    cout << "Name: " << name << '\n';
    cout << "Position: " << '(' << position().x << ',' << ' ' << position().y << ')' << '\n';
    cout << "Weight: " << weight << '\n';
    cout << "Perimeter: " << perimeter() << '\n';
    cout << "Square: " << square() << '\n';
    cout << "Size: " << size() << '\n';
}

void Rectangle::initFromDialog() {
    cout << "Enter the first vertex: ";
    cin >> A.x >> A.y;
    cout << '\n' << "Enter the second vertex: ";
    cin >> B.x >> B.y;
    cout << '\n' << "Enter the third vertex: ";
    cin >> C.x >> C.y;
    cout << '\n' << "Enter the fourth vertex: ";
    cin >> D.x >> D.y;
    cout << '\n' << "Enter the weight: ";
    cin >> weight;
    cout << '\n';
}

const char* Rectangle::classname() {
    return name;
}

unsigned int Rectangle::size() {
    return sizeof(*this);
}