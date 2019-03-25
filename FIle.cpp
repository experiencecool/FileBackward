//
// Created by Exper on 25/03/2019.
//

#include "File.h"

File::File() {

}

File::~File() {

}

void File::SetFileName(char *name) {
    this->name_of_file = string(name);
}

int File::CheckFileExtension() {
    string sep = ".";
    string name = name_of_file;
    string ext;
    size_t pos = 0;
    while ((pos = name.find(sep)) != string::npos) {
        ext = name.substr(0, pos);
        name.erase(0, pos + sep.length());
    }
    if (name == "dat") {
        cout << name_of_file << ": correct" << endl;
        return 1;
    }
    else {
        cout << name_of_file << ": incorrect" << endl;
        exit(10);
    }
}

int File::CheckFile(char *name) {
    SetFileName(name);
    CheckFileExtension();
    return 0;
}

int File::OpenFile() {
    cout << name_of_file << ": Invalid open file" << endl;
    return 0;
}

void File::CloseFile(){
    cout << name_of_file << ": invalid close file" << endl;
}

