#include <iostream>
#include "CircularBuffer.h"

using namespace std;

void show_param(CircularBuffer<int> &buffer) {
    cout << "Capacity: " << buffer.show_capacity() << '\n';
    cout << "Size: " << buffer.show_size() << '\n';
    cout << "Elements: ";
    for (auto elem: buffer) {
        cout << elem << ' ';
    }
    cout << '\n';
    cout << "Begin: " << *buffer.begin() << '\n';
    cout << "End: " << *(buffer.end() - 1) << '\n';
    cout << "Second element: " << buffer[1] << '\n';
}

int main() {
    CircularBuffer<int> buf (4);
    buf.push_in_front(15);
    buf.push_in_back(3);
    buf.push_in_back(21);
    buf.push_in_front(11);
    show_param(buf);
    //buf.push_in_back(120);
    cout << "=========" << '\n';
    show_param(buf);

    std::sort(buf.begin(), buf.end());

    cout << "=========" << '\n';
    show_param(buf);

    return 0;
}
