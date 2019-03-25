//
// Created by Exper on 25/03/2019.
//
/*
 *  class IFile
 *  child of File
 *  open output file and write it
 */

#ifndef VISUALSVNPRJ_IFILE_H
#define VISUALSVNPRJ_IFILE_H

#include "File.h"

class IFile : public File {
public:
    void Write(char** buffer, int size);
    IFile(char* name);
    ~IFile();
private:
    ofstream file;
    void CloseFile();
    int OpenFile();
    char convertHextoChar(char *c);
};

#endif //VISUALSVNPRJ_IFILE_H
