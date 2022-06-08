#ifndef __MERGE__HEADER__HPP__
#define __MERGE__HEADER__HPP__

#include "SortInterface.hpp"


class MergeSort : public SortingBigFile 
{
public:
    MergeSort(const std::string&, const std::string&);
    MergeSort(const std::string&);
    ~MergeSort();

public:
    void sort() override;

private:
    void merge_sort (std::vector <int>&, int, int);
    void merge (std::vector <int>&, int, int, int);
};


#include "MergeImplemention.hpp"

#endif