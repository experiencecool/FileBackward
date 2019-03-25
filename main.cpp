#include <iostream>
#include <string>
#include "OFile.h"
#include "IFile.h"

int main(int argc, char * argv[]) {
    switch (argc){
        case 3:{
            OFile OutFile(argv[1]);
            IFile InFile(argv[2]);
            OutFile.Read();
            int size = OutFile.getsize();
            char **buffer = new char *[size];
            for (int i = 0; i < size; i++ ) {
                buffer[i] = new char[2];
            }
            for (int i = 0; i < size; i++) {
                buffer[i] = OutFile.getbuf(i);
            }
            InFile.Write(buffer, size);
        }
            cout << "FINISHED" << endl;
            break;
        case 2: cout << "missing an argument" << endl;
            break;
        case 1: cout << "not arguments" << endl;
            break;
        default: cout << "wrong input" << endl;
            break;
    }
    return 0;
}