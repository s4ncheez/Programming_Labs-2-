#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <iterator>
#include <algorithm>

using namespace std;

template <class T>
class CircularBuffer {
private:
    int size = 0;
    int capacity = 0;
    T* BufferElements = nullptr;
public:
    class Iterator: public iterator<random_access_iterator_tag, T> {
    private:
        T* Element = nullptr;
    public:
        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        explicit Iterator(T* start) {
            Element = start;
        }
        Iterator (const Iterator &It) {
            Element = It.Element;
        }
        reference operator* () {
            return *(Element);
        }
        pointer operator-> () {
            return Element;
        }
        Iterator operator+ (difference_type val) {
            Iterator temp = *this;
            temp += val;
            return temp;
        }
        Iterator operator+= (difference_type val) {
            Element += val;
            return *this;
        }
        Iterator operator++ () {
            ++Element;
            return *this;
        }
        Iterator operator++ (int) {
            Iterator temp = *this;
            Element++;
            return temp;
        }
        Iterator operator- (difference_type val) {
            Iterator temp = *this;
            temp -= val;
            return temp;
        }
        Iterator operator-= (difference_type val) {
            Element -= val;
            return *this;
        }
        Iterator operator-- () {
            --Element;
            return *this;
        }
        Iterator operator-- (int) {
            Iterator temp = *this;
            Element++;
            return temp;
        }
        difference_type operator- (const Iterator &It) const {
            return Element - It.Element;
        }
        bool operator== (const Iterator &It) const {
            return Element == It.Element;
        }
        bool operator!= (const Iterator &It) const {
            return Element != It.Element;
        }
        bool operator< (const Iterator &It) const {
            return Element < It.Element;
        }
        bool operator<= (const Iterator &It) const {
            return Element <= It.Element;
        }
        bool operator> (const Iterator &It) const {
            return Element > It.Element;
        }
        bool operator>= (const Iterator &It) const {
            return Element >= It.Element;
        }
    };

    Iterator begin() const {
        return Iterator(BufferElements);
    }
    Iterator end() const {
        return Iterator(BufferElements + size);
    }
    T& operator[] (int index) {
        return BufferElements[index];
    }
    explicit CircularBuffer(int cap) {
        capacity = cap;
        BufferElements = new T[capacity];
    }
    CircularBuffer(const CircularBuffer& Buffer) {
        size = Buffer.size;
        capacity = Buffer.capacity;
        transfer(Buffer.BufferElements);
    }
    ~CircularBuffer() {
        delete[] BufferElements;
    }
    void push_in_front (T value) {
        if (size < capacity) {
            for (int i = size; i >= 1; i--) {
                BufferElements[i] = BufferElements[i - 1];
            }
            BufferElements[0] = value;
            size++;
        }
        else {
            for (int j = capacity - 1; j >= 1; j--) {
                BufferElements[j] = BufferElements[j - 1];
            }
            BufferElements[0] = value;
        }
    }
    void pop_in_front () {
        for (int i = 0; i < size; i++) {
            BufferElements[i] = BufferElements[i + 1];
        }
        size--;
    }
    void push_in_back (T value) {
        if (size < capacity) {
            BufferElements[size] = value;
            size++;
        }
        else {
            for (int i = 1; i < capacity; i++) {
                BufferElements[i - 1] = BufferElements[i];
            }
            BufferElements[capacity - 1] = value;
        }
    }
    void pop_in_back () {
        if (size > 0) {
            size--;
        }
    }
    void push (int ind, T value) {
        *(begin() + ind) = value;
    }
    void pop (int ind) {
        for (int i = ind + 1; i < size; i++) {
            BufferElements[(i - 1)] = BufferElements[i];
        }
        size--;
    }
    void transfer (T* buff) {
        BufferElements = new T[capacity];
        for (int i = 0; i < size; i++) {
            BufferElements[i] = buff[i];
        }
        delete buff;
    }
    void resize (int new_cap) {
        size = min (size, new_cap);
        capacity = new_cap;
        transfer(BufferElements);
    }
    int show_capacity () const {
        return this->capacity;
    }
    int show_size() const {
        return this->size;
    }
};
#endif //CIRCULARBUFFER_H