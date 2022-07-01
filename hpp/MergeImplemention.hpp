#ifndef __MERGE__IMPLEMENTATION__HPP__
#define __MERGE__IMPLEMENTATION__HPP__

#include "MergeHeader.hpp"

MergeSort::MergeSort(const std::string& path) { 
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

MergeSort::MergeSort(const std::string& inputPath, const std::string& outputPath) {
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

MergeSort::~MergeSort() {
    if(fin.is_open()) fin.close();
    if(fout.is_open()) fout.close();
}

void MergeSort::merge_sort (std::vector <int>& arr, int start, int end) {
    if(arr.size() < 2) return;
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort (arr, start, mid);
        merge_sort (arr, mid + 1, end);
        merge (arr, start, mid, end);
    }
}

void MergeSort::merge (std::vector<int>& arr, int start, int mid, int end) {
	int temp[end - start + 1];
	int left_index = start;
	int right_index = mid + 1;
	int temp_index = 0;
	while(left_index <= mid && right_index <= end) {
		if(arr[left_index] <= arr[right_index]) {
			temp[temp_index] = arr[left_index];
			left_index++;
			temp_index++;
		} else {
			temp[temp_index] = arr[right_index];
			right_index++;
			temp_index++;
		}
	}
	
	while(left_index <= mid) {
		temp[temp_index] = arr[left_index];
		left_index++;
		temp_index++;
	}

	while(right_index <= end) {
		temp[temp_index] = arr[right_index];
		right_index++;
		temp_index++;
	}

	for(int i = start; i <= end; i++) {
		arr[i] = temp[i - start];
	}
}

void MergeSort::sort() {
    while(fin.peek() != std::ifstream::traits_type::eof()) {
        std::string num = "";
        fin >> num;
        this->array.push_back(std::stoi(num));
    }
    merge_sort(array, 0, array.size() - 1);
    display();
}

#endif
