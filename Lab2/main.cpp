#include <iostream>
#include "Class.h"

using namespace std;
using namespace Class;

int main() {
    //File_stream fin{"testlab.txt"};
    File_stream fin;
    fin.set_file_name("default2.txt");
    string namefile = fin.getname();
    cout << namefile << endl;
    return 0;
}