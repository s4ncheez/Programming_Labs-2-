#include "Stack.h"
#include <iostream>

using namespace std;

namespace stack {

    Stack operator<<(Stack &st, int j) {
        if (st.k + 1 == st.maxk) return 0;
        st.stack[++st.k] = j;
        return st;
    }

    Stack operator>>(Stack &st, int j) {
        if (st.k == -1) return 0;
        st.stack[st.k--] = -1;
        return st;
    }

    void Stack::cout_() const {
        if (k == -1) cout << "Stack is empty" << '\n';
        else {
            cout << "Elements of stack:" << '\n';
            for (int i = k; i >= 0; i--) cout << stack[k] << ' ';
            cout << '\n';
        }
    }
}