//
// Created by Exper on 25/03/2019.
//

#include "IFile.h"

void IFile::Write(char **buffer, int size) {
    char *c = new char [size];
    for (int i = size - 1; i >= 0; i--) {
        c[size - 1 - i] = convertHextoChar(buffer[i]);
    }
    file.write(c, size);
    cout << name_of_file << ": data is written" << endl;
}

IFile::IFile(char *name) {
    CheckFile(name);
    OpenFile();
}

IFile::~IFile() {
    CloseFile();
}

void IFile::CloseFile() {
    file.close();
    cout << name_of_file << ": file is closed" << endl;
}

int IFile::OpenFile() {
    file.open(name_of_file, ios::binary | ios::out);
    if(!file){
        cout << name_of_file << ": open file - fail" << endl;
        exit(20);
    }
    else {
        cout << name_of_file << ": open file - success" << endl;
    }
    return 0;
}

char IFile::convertHextoChar(char *c) {
    int number[2];
    switch (c[0]) {
        case '0': number[0] = 0; break;
        case '1': number[0] = 1; break;
        case '2': number[0] = 2; break;
        case '3': number[0] = 3; break;
        case '4': number[0] = 4; break;
        case '5': number[0] = 5; break;
        case '6': number[0] = 6; break;
        case '7': number[0] = 7; break;
        case '8': number[0] = 8; break;
        case '9': number[0] = 9; break;
        case 'a': number[0] = 10; break;
        case 'b': number[0] = 11; break;
        case 'c': number[0] = 12; break;
        case 'd': number[0] = 13; break;
        case 'e': number[0] = 14; break;
        case 'f': number[0] = 15; break;
    }
    switch (c[1]) {
        case '0': number[1] = 0; break;
        case '1': number[1] = 1; break;
        case '2': number[1] = 2; break;
        case '3': number[1] = 3; break;
        case '4': number[1] = 4; break;
        case '5': number[1] = 5; break;
        case '6': number[1] = 6; break;
        case '7': number[1] = 7; break;
        case '8': number[1] = 8; break;
        case '9': number[1] = 9; break;
        case 'a': number[1] = 10; break;
        case 'b': number[1] = 11; break;
        case 'c': number[1] = 12; break;
        case 'd': number[1] = 13; break;
        case 'e': number[1] = 14; break;
        case 'f': number[1] = 15; break;
    }
    int res = number[0] * 16 + number[1];
    char sim = (char) res;
    return sim;
}