#ifndef STACK_H
#define STACK_H

#include "iostream"

using namespace std;

namespace stack {

    class Stack {

        friend Stack operator>>(Stack &st, int j);
        friend Stack operator<<(Stack &st, int j);


    private:
        int *stack;
        int k;
        int maxk;

    public:

        Stack(){
            stack = new int[100];
            maxk = 100;
            k = -1;
        };

        Stack (int i) {
            stack = new int[i];
            maxk = i;
            k = -1;
        }

        ~Stack() {
            delete[] stack;
        }

        void cout_() const;

    };
}
#endif //STACK_H