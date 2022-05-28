#include <iostream>
#include "Queue.h"
#include "Pow.h"

using namespace std;

int main() {
    Queue <3, int> q;
    q.pop();
    q.push(10);
    q.push(12);
    q.push(30);
    q.push(41);
    int a = pow<int , int>(3, 2);
    cout << a << '\n';
//    int b = pow(10, 0.53);
    return 0;
}
