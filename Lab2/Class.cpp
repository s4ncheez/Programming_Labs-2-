#include <iostream>
#include <fstream>
#include <string>
#include "Class.h"

using namespace std;

namespace Class {
    File_stream::File_stream() {
        filename = "default.txt";
    }

    File_stream::File_stream(string name) : filename(name) {}

    bool File_stream::set_file_name(string name) {
        filename = name;
        return !file.fail();
    }

    bool File_stream::open() {
        file.open(filename, ifstream::in);
        return !file.fail();
    }

    bool File_stream::close() {
        file.close();
        return !file;
    }

    string File_stream::getname() {
        return filename;
    }

    bool File_stream::check_is_open() {
        if (file.is_open()) {
            cout << "Yes, file is opened" << endl;
            return true;
        }
        else {
            cout << "No, file isn't opened" << endl;
            return false;
        }
    }

    bool File_stream::check_is_end() {
        if (file.eof()) {
            cout << "Yes, line is empty" << endl;
            return true;
        }
        else {
            cout << "No, line isn't empty" << endl;
            return false;
        }
    }

    string File_stream::get_next_line() {
        if (!file.eof()) {
            string line;
            getline(file, line);
            return line;
        }
        else {
            cout << "Error, can't get next line" << endl;
            return "";
        }
    }

    string File_stream::get_next_word() {
        if (!file.eof()) {
            string word;
            file >> word;
            return word;
        }
        else {
            cout << "Error, can't get next line" << endl;
            return "";
        }
    }

}