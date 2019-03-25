//
// Created by Exper on 25/03/2019.
//
/*
 *  class OFile
 *  child of file
 *  open input file and read it
 */

#ifndef VISUALSVNPRJ_OFILE_H
#define VISUALSVNPRJ_OFILE_H

#include "File.h"

class OFile : public File {
public:
    void Read();
    int getsize(); // size in bytes
    char* getbuf(int i); // get i-th symbol. does not work before Read() method
    OFile(char *name);
    ~OFile();
private:
    char m[2] = {0,0}; //needed in convertChartoHex method
    char **buffer; // array of arrays (char[2] i.e. 2bytes of size). Contain data from file
    ifstream file;
    int sizefile;
    void CloseFile();
    int OpenFile();
    void setsize(); //goes to the end of the file and gets the size of it. then returns to the beginning
    char* convertChartoHex(char* c, int i);
};

#endif //VISUALSVNPRJ_OFILE_H
