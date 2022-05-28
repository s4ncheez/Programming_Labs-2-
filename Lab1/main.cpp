#include <iostream>
#include "fun.h"

using namespace std;

int main() {
    int per1, per2;
    cin >> per1 >> per2;
    fun::change_max1(&per1, &per2);
    cout << per1 << ' ' << per2 << '\n';

    float per_1, per_2;
    cin >> per_1 >> per_2;
    fun::change_fl1(&per_1);
    fun::change_fl2(per_2);
    cout << per_1 << ' ' << per_2 << '\n';

    fun::Circle circle;
    cin >> circle.x >> circle.y >> circle.R;
    float ch;
    cin >> ch;
    fun::Circle *p;
    p = &circle;
    fun::change_R1(p, ch);
    fun::change_R2(circle, ch);
    cout << circle.R << '\n';

    float arr[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    float mult;
    cin >> mult;
    fun::mult_matrix1(*arr, mult);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    fun::mult_matrix2(arr[3][3], mult);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
