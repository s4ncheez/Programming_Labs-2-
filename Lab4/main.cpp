#include <iostream>
#include "Base.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include <vector>
#include <algorithm>

using namespace std;

bool compare (IFigure *first, IFigure *second) {
    return *first < *second;
}

int main() {
    vector<IFigure*> figures;
    int com;
    double x, y, sum_sq, sum_per, weight_center;
    unsigned int sum_mem;
    CVector2D center;
    bool work = true;
    while (work) {
        cout << "To add a figure - enter 1" << '\n';
        cout << "To show all figures - enter 2" << '\n';
        cout << "To count common square - enter 3" << '\n';
        cout << "To count common perimeter - enter 4" << '\n';
        cout << "To find a common center of weight - enter 5" << '\n';
        cout << "To count common memory - enter 6" << '\n';
        cout << "To sort figures by their mass - enter 7" << '\n';
        cout << "To exit - enter 8" << '\n' << '\n';
        cout << "Print command: ";
        cin >> com;
        cout << '\n';
        if (com == 1) {
            cout << "To add a Rectangle - enter 1" << '\n';
            cout << "To add an Ellipse - enter 2" << '\n';
            cout << "To exit - enter 3" << '\n';
            int fig;
            cout << "Print command: ";
            cin >> fig;
            cout << '\n';
            if (fig == 1) figures.push_back(new Rectangle());
            else if (fig == 2) figures.push_back(new Ellipse());
            else if (fig == 3) cout << "Exit..." << '\n';
            else cout << "Unknown command, try again!" << '\n';
        }
        else if (com == 2) {
            for (auto &figure: figures) {
                figure->draw();
                cout << '\n';
            }
        }
        else if (com == 3) {
            sum_sq = 0;
            cout << "Square of each figure:" << '\n';
            for (auto &figure: figures) {
                cout << figure->classname() << ':' << ' ' << figure->square() << '\n';
                sum_sq += figure->square();
            }
            cout << "Common square = " << sum_sq << '\n';
        }
        else if (com == 4) {
            sum_per = 0;
            cout << "Perimeter of each figure:" << '\n';
            for (auto &figure: figures) {
                cout << figure->classname() << ':' << ' ' << figure->perimeter() << '\n';
                sum_per += figure->perimeter();
            }
            cout << "Common perimeter = " << sum_per << '\n';
        }
        else if (com == 5) {
            weight_center = 0;
            x = 0;
            y = 0;
            for (auto &figure: figures) {
                x += figure->position().x * figure->mass();
                y += figure->position().y * figure->mass();
                weight_center += figure->mass();
            }
            center.x = x / weight_center;
            center.y = y / weight_center;
            cout << "Position of center of weight: " << '(' << center.x << ',' << ' ' << center.y << ')' << '\n';
        }
        else if (com == 6) {
            sum_mem = 0;
            cout << "Memory of each figure:" << '\n';
            for (auto &figure: figures) {
                cout << figure->classname() << ':' << ' ' << figure->size() << '\n';
                sum_mem += figure->size();
            }
            cout << "Common memory = " << sum_mem << '\n';
        }
        else if (com == 7) {
            sort(figures.begin(), figures.end(), compare);
            cout << "Figures are sorted" << '\n';
            cout << "Weight of each figure:" << '\n';
            for (auto &figure: figures) cout << figure->classname() << ':' << ' ' << figure->mass() << '\n';
        }
        else if (com == 8) {
            work = false;
            cout << "Exit...";
        }
        else {
            cout << "Unknown command, try again!" << '\n';
        }
        cout << '\n';
    }
    return 0;
}