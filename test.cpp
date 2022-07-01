#include "SortInterface.hpp"


int main(int argc, char* argv[]) {
    
    try {
        if(argc == 2) {
            SortingBigFile* file = new QuickSort(argv[1]);
            order::Sort(file);
            delete file;
        }
        else if(argc == 3 && strlen(argv[2]) == 1)  {
            SortingBigFile* file{};
            if(argv[2][0] == 'm') {
                file = new MergeSort(argv[1]);
            } else if(argv[2][0] == 'q') {
                file = new QuickSort(argv[1]);
            }
            order::Sort(file);
            delete file;
        }
        else if (argc == 3 && strlen(argv[2]) != 1) {
            SortingBigFile* file = new QuickSort(argv[1], argv[2]);
            order::Sort(file, 'q');
            delete file;
        }
        else if (argc == 4 && strlen(argv[3]) == 1) {
            SortingBigFile* file {};
            if(argv[3][0] == 'm') {
                file = new MergeSort(argv[1], argv[2]);
            } else if(argv[3][0] == 'q') {
                file = new QuickSort(argv[1], argv[2]);
            }
            order::Sort(file, argv[3][0]);
            delete file;
        }
        else throw std::exception();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << ": Specify the file path: There must be one or two file paths and the last argument 'q' or 'm' for sorting.";
    }

    return 0;
}
