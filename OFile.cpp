//
// Created by Exper on 25/03/2019.
//

#include "OFile.h"

void OFile::Read() {
    file.seekg(0, ios_base::beg);
    buffer = new char * [sizefile];
    for (int i = 0; i < sizefile; i++) {
        buffer[i] = new char[2];
    }
    for (int i = 0; i < sizefile; i++) {
        char *c = new char[2];
        file.seekg(i, ios_base:: beg);
        file.read(c, 1);
        c = convertChartoHex(c, i);
        buffer[i][0] = c[0];
        buffer[i][1] = c[1];
    }
    cout << name_of_file << ": data" << endl;
}

OFile::OFile(char *name) {
    CheckFile(name);
    OpenFile();
    setsize();
}

OFile::~OFile() {
    CloseFile();
    for (int i = 0; i < sizefile; i++) {
        delete[]buffer[i];
    }
    delete[]buffer;
}

void OFile::CloseFile() {
    file.close();
    cout << name_of_file << ": is closed" << endl;
}

int OFile::OpenFile() {
    file.open(name_of_file, ios::binary | ios::in);
    if(!file) {
        cout << name_of_file << ": Open file - Fail" << endl;
        exit(20);
    }
    else {
        cout << name_of_file << ": Open file - Success" << endl;
    }
    return 0;
}

void OFile::setsize() {
    file.seekg(0, ios_base::end);
    sizefile = file.tellg();
    file.seekg(0, ios_base::beg);
    if (sizefile == -1) {
        cout << name_of_file << ": Invalid size" << endl;
        exit(50);
    }
}

int OFile::getsize() {
    return sizefile;
}

char* OFile::getbuf(int i) {
    return buffer[i];
}


char* OFile::convertChartoHex(char * c, int i)
{
    int a = c[0];
    int k = 0;
    m[0] = 0;
    m[1] = 0;
    int l = 0;
    while (l != 2) {
        k = a % 16;
        a = a / 16;
        switch (k)
        {
            case 0:  m[l] = '0'; break;
            case 1:  m[l] = '1'; break;
            case 2:  m[l] = '2'; break;
            case 3:  m[l] = '3'; break;
            case 4:  m[l] = '4'; break;
            case 5:  m[l] = '5'; break;
            case 6:  m[l] = '6'; break;
            case 7:  m[l] = '7'; break;
            case 8:  m[l] = '8'; break;
            case 9:  m[l] = '9'; break;
            case 10:  m[l] = 'a'; break;
            case 11:  m[l] = 'b'; break;
            case 12:  m[l] = 'c'; break;
            case 13:  m[l] = 'd'; break;
            case 14:  m[l] = 'e'; break;
            case 15:  m[l] = 'f'; break;
        }
        l++;
    }
    char n = m[0];
    m[0] = m[1];
    m[1] = n;
    return m;
}

