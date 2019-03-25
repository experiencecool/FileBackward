//
// Created by Exper on 25/03/2019.
//
/*
 * class File
 * parent class for IFile and OFile
 */
#ifndef VISUALSVNPRJ_FILE_H
#define VISUALSVNPRJ_FILE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File{
public:
    ~File();
    File();
protected:
    string name_of_file;
    int CheckFile(char *name); //set name of file and check extension ".dat"
    virtual int OpenFile();
    virtual void CloseFile();
private:
    int CheckFileExtension(); // check extension of file
    void SetFileName(char *name);
};

#endif //VISUALSVNPRJ_FILE_H
