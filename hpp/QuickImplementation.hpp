#ifndef __QUICK__IMPLEMENTATION__HPP__
#define __QUICK__IMPLEMENTATION__HPP__

#include "QuickHeader.hpp"


QuickSort::QuickSort(const std::string& path)  {

    try {
        fin.open(path, std::ifstream::in);
        if (!fin.is_open() ) throw std::exception();
        if (fin.peek() == std::ifstream::traits_type::eof()) throw "Empty file";

    }
    catch(const std::exception& e) {

        std::cerr  << "Invalid path to file:" << '\n';

    } 
    catch (const char* ) {

        std::cerr << "The file is empty:" << '\n';

    }
    
}

QuickSort::QuickSort(const std::string& inputPath, const std::string& outputPath) {

    try {

        fin.open(inputPath, std::ifstream::in);
        fout.open(outputPath, std::ofstream::app);
        if (!fin.is_open() || !fout.is_open()) throw std::exception(); 
        if (fin.peek() == std::ifstream::traits_type::eof()) throw "Empty file";

    }
    catch(const std::exception& e) {

        std::cerr <<  "Invalid path to file:" << '\n';

    }
    catch (const char* ) {

        std::cerr << "The file is empty:" << '\n';

    }

}

QuickSort::~QuickSort() {

    if(fin.is_open()) fin.close();
    if(fout.is_open()) fout.close();

}


void QuickSort::quick_sort(std::vector<int>& arr, int low, int high)
{
    if(arr.size() < 2) return;
    
    int i = low;
    int j = high;
    int pivot = arr[(i + j) / 2];

    int temp;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quick_sort(arr, low, j);
    if (i < high)
        quick_sort(array, i, high);

}

void QuickSort::sort() {

    while(fin.peek() != std::ifstream::traits_type::eof()) {
        
        std::string num = "";
        fin >> num;
        this->array.push_back(std::stoi(num));

    }
    quick_sort(array, 0, array.size() - 1);
    display();
}


#endif