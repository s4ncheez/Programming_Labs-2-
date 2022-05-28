#include <iostream>
#include "Square.h"
#include "Stack.h"

using namespace std;
using namespace square;
using namespace stack;

int main() {
    ///Square squ_1(0, 0, 4, 45);
    ///Square squ_2 = squ_1 * 3;
    //squ_2.cout_();
    ///Vector v {5, 6};
    ///Square squ_3(squ_1);
    ///squ_3.cout_();
    ///squ_3 = squ_1 + v;
    ///squ_3.cout_();
    Stack st (3);
    st << 150;
    st.cout_();
    ///Stack stt(10);
    ///stt >> 0;
    ///stt << 1000;
    ///stt.cout_();
    ///stt >> 1000;
    ///stt.cout_();
    return 0;
}