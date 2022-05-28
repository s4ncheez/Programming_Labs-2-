#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <vector>
#include "Exception.h"

using namespace std;

template <int N, class T>
class Queue {
private:
    vector <T> array;
    int size = 0;
public:
    Queue() {
        array = vector<T> (N);
    }

    void push (T ob) {
        try {
            if (size == N) {
                throw Exception("Error! The queue is full.");
            }
            array.push_back(ob);
            size++;
        }
        catch (Exception &ex) {
            cout << ex.print() << '\n';
        }
    }

    void pop () {
        try {
            if (size == 0) {
                throw Exception("Error! The queue is empty.");
            }
            array.erase(array.begin());
        }
        catch (Exception &ex) {
            cout << ex.print() << '\n';
        }
    }
};
#endif //QUEUE_H