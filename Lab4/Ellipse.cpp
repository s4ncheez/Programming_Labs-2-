#include "Ellipse.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

Ellipse::Ellipse() {
    this->Ellipse::initFromDialog();
}

double Ellipse::square() {
    return (PI * half_axis_a * half_axis_b);
}

double Ellipse::perimeter() {
    return (4 * (PI * half_axis_a * half_axis_b + pow((half_axis_a - half_axis_b), 2)) / (half_axis_a + half_axis_b));
}

double Ellipse::mass() const {
    return weight;
}

CVector2D Ellipse::position() {
    return O;
}

bool Ellipse::operator==(const IPhysObject &ob) const {
    return (mass() == ob.mass());
}

bool Ellipse::operator<(const IPhysObject &ob) const {
    return (mass() < ob.mass());
}

void Ellipse::draw() {
    cout << "Name: " << name << '\n';
    cout << "Position: " << '(' << position().x << ',' << ' ' << position().y << ')' << '\n';
    cout << "Weight: " << weight << '\n';
    cout << "Perimeter: " << perimeter() << '\n';
    cout << "Square: " << square() << '\n';
    cout << "Size: " << size() << '\n';
}

void Ellipse::initFromDialog() {
    cout << "Enter the center: ";
    cin >> O.x >> O.y;
    cout << '\n' << "Enter the first half_axis: ";
    cin >> half_axis_a;
    cout << '\n' << "Enter the second half_axis: ";
    cin >> half_axis_b;
    cout << '\n' << "Enter the weight: ";
    cin >> weight;
    cout << '\n';
}

const char* Ellipse::classname() {
    return name;
}

unsigned int Ellipse::size() {
    return sizeof(*this);
}