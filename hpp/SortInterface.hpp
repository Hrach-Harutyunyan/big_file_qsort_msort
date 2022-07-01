#ifndef __SORT__INTERFACE__HPP__
#define __SORT__INTERFACE__HPP__

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

class SortingBigFile
{
public:
    SortingBigFile();
    virtual ~SortingBigFile() { };
    virtual void sort() = 0;
    virtual void writeInFile();

protected:
    virtual void readFromFile();

protected:
    virtual void display();

protected:
    std::ifstream fin;
    std::ofstream fout;
    std::string strArray = "";
    std::vector <int> array {};

};

SortingBigFile::SortingBigFile() : strArray{} {}

void SortingBigFile::writeInFile() {
    for(auto a : array) {
        fout << a << '\n';
    }
}

void SortingBigFile::readFromFile() {
    this->strArray = "";
    std::getline(fin, this->strArray);
}

void SortingBigFile::display() {  
    for(auto it = array.begin(); it != array.end(); it++) {
        std::cout << *it << std::endl;
    }
}

namespace order 
{
    void Sort(SortingBigFile* obj) {
        obj->sort();
    }
    
    void Sort(SortingBigFile* obj, char ch) {
        if(ch == 'm' || ch == 'q') {
            obj->sort();
            obj->writeInFile();
        }
    }
}

#include "QuickHeader.hpp"
#include "MergeHeader.hpp"

#endif
