#ifndef __QUICK__HEADER__HPP__
#define __QUICK__HEADER__HPP__

#include "SortInterface.hpp"

class QuickSort : public SortingBigFile
{
public:
    QuickSort(const std::string&, const std::string&);
    QuickSort(const std::string&);
    ~QuickSort();

public:
    void sort() override;

private:
    void quick_sort(std::vector <int>&, int low, int high);
};

#include "QuickImplementation.hpp"

#endif
