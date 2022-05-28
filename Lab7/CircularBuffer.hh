#ifndef CIRCULARBUFFER_HH
#define CIRCULARBUFFER_HH
#include <iterator>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>
typename CircularBuffer<T>:: Iterator:: difference_type CircularBuffer<T>:: Iterator:: operator- (const Iterator &Iter) const {
    return Elements - Iter.Elements;
}

template <class T>
CircularBuffer<T>:: Iterator:: Iterator (T* st) {
    Elements = st;
}

template <class T>
CircularBuffer<T>:: Iterator:: Iterator (const Iterator& Iter) {
    Elements = Iter.Elements;
}

template <class T>
CircularBuffer<T>:: Iterator:: ~Iterator() = default;

template <class T>
T& CircularBuffer<T>:: Iterator:: operator* () {
    return *(Elements);
}

template <class T>
T* CircularBuffer<T>:: Iterator:: operator& () {
    return Elements;
}

template <class T>
CircularBuffer<T>:: Iterator CircularBuffer<T>:: Iterator:: operator++ {
    Elements++;
    return *this;
};

template <class T>
CircularBuffer<T>:: Iterator CircularBuffer<T>:: Iterator:: operator-- {
    Elements--;
    return *this;
};

template <class T>
CircularBuffer<T>:: Iterator CircularBuffer<T>:: Iterator:: operator+ (int v) {
    Elements += v;
    return *this;
};

template <class T>
CircularBuffer<T>:: Iterator CircularBuffer<T>:: Iterator:: operator- (int v) {
    Elements -= v;
    return *this;
};

template <class T>
bool CircularBuffer<T>:: Iterator:: operator== (const Iterator &Iter) const {
    return Elements == Iter.Elements;
}

bool CircularBuffer<T>:: Iterator:: operator!= (const Iterator &Iter) const {
    return Elements != Iter.Elements;
}

bool CircularBuffer<T>:: Iterator:: operator< (const Iterator &Iter) const {
    return Elements < Iter.Elements;
}

bool CircularBuffer<T>:: Iterator:: operator<= (const Iterator &Iter) const {
    return Elements <= Iter.Elements;
}

bool CircularBuffer<T>:: Iterator:: operator> (const Iterator &Iter) const {
    return Elements > Iter.Elements;
}

bool CircularBuffer<T>:: Iterator:: operator>= (const Iterator &Iter) const {
    return Elements >= Iter.Elements;
}

template <class T>
CircularBuffer<T>:: Iterator CircularBuffer<T>:: begin() const {
    return Iterator(BufferElements);
}

template <class T>
CircularBuffer<T>:: Iterator CircularBuffer<T>:: end() const {
    return Iterator(BufferElements + size);
}

template <class T>
int CircularBuffer<T>:: show_capacity () const {
    return this->capacity;
}

template <class T>
int CircularBuffer<T>:: show_size () const {
    return this->size;
}

template <class T>
CircularBuffer<T>:: CircularBuffer(int c) {
    capacity = c;
    BufferElements = new T[capacity];
}

template <class T>
CircularBuffer<T>:: CircularBuffer(const CircularBuffer& buff) {
    size = buff.size;
    capacity = buff.capacity;
    BufferElements = buff.BufferElements;
}

template <class T>
CircularBuffer<T>:: ~CircularBuffer() {
    delete[] BufferElements;
}

template <class T>
void CircularBuffer<T>:: push_in_front (T val) {
    if (size < capacity) {
        for (int i = size; i >= 1; i--) {
            BufferElements[i] = BufferElements[i - 1];
        }
        BufferElements[0] = val;
        size++;
    }
    else {
        for (int j = capacity - 1; j >= 1; j++) {
            BufferElements[j] = BufferElements[j - 1];
        }
        BufferElements[0] = val;
    }
}

template <class T>
void CircularBuffer<T>:: pop_in_front () {
    for (int i = 0; i < size; i++) {
        BufferElements[i] = BufferElements[i + 1];
    }
    size--;
}

template <class T>
void CircularBuffer<T>:: push_in_back (T val) {
    if (size < capacity) {
        BufferElements[size] = val;
        size++;
    }
    else {
        for (int i = 1; i < capacity; i++) {
            BufferElements[i - 1] = BufferElements[i];
        }
        BufferElements[capacity - 1] = val;
    }
}

template <class T>
void CircularBuffer<T>:: pop_in_back () {
    if (size > 0) {
        size--;
    }
}

template <class T>
void CircularBuffer<T>:: push (Iterator It, T val) {
    *(begin() + (It - begin()) % size) = val;
}

template <class T>
void CircularBuffer<T>:: pop (int Iter) {
    for (int i = Iter + 1; i < size; i++) {
        BufferElements[(i - 1) % capacity] = BufferElements[i % capacity];
    }
    size--;
}

template <class T>
void CircularBuffer<T>:: resize (int new_c) {
    T* new_BufferElements = new T[new_c];
    size = min (size, new_c);
    for (int i = 0; i < size; i++) {
        new_BufferElements[i] = BufferElements[i];
    }
    delete BufferElements;
    BufferElements = new_BufferElements;
    capacity = new_c;
}

template <class T>
T CircularBuffer<T>:: operator[] (int ind) {
    return BufferElements[ind % capacity];
}

#endif //CIRCULARBUFFER_HH