#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <algorithm>

void f(int_buffer buf);
void fAuto(int_buffer buf);
void fSorted(int_sorted buf);
void fMerge(int_sorted buf1, int_sorted buf2);
void petc();

int main() {
    srand((unsigned) time(0));
    system("clear");
    //testing int_buffer
    f(int_buffer(10));
    petc();
    fAuto(int_buffer(10));
    petc();

    //testing int_sorted
    fSorted(int_sorted(nullptr, 0));
    petc();
    system("clear");
    fMerge(int_sorted(nullptr, 0), int_sorted(nullptr, 0));
    petc();
    system("clear");

    //timing sorts
    int_buffer buf(400000);
    for(auto& e: buf) {
        e = rand() % 399999 + 1;
    }
    int_sorted buffer(buf.begin(), buf.size());
    int_sorted buffer2 = buffer;
    std::cout << "Sorting a buffer with 400000 elements using merge sort..." << std::endl;
    petc();
    auto start = std::chrono::high_resolution_clock::now();
    int_sorted sortedBuffer = buffer.sort(buffer.begin(), buffer.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto mergeSortTime = std::chrono::duration<double>(stop - start);
    sortedBuffer.print();
    std::cout << std::endl << "Time to sort: " << mergeSortTime.count() << "s" << std::endl;
    petc();

    system("clear");
    std::cout << "Sorting a buffer with 400000 elements using std::sort()..." << std::endl;
    petc();
    start = std::chrono::high_resolution_clock::now();
    std::sort(buf.begin(), buf.end());
    stop = std::chrono::high_resolution_clock::now();
    auto sortTime = std::chrono::duration<double>(stop - start);
    for(auto e: buf) {
        std::cout << e << ", ";
    }
    std::cout << std::endl << std::endl << "Time to sort: " << sortTime.count() << "s" << std::endl;
    petc();

    system("clear");
    std::cout << "Sorting a buffer with 400000 elements using selection sort..." << std::endl;
    petc();
    std::cout << "Sorting..." << std::endl;
    start = std::chrono::high_resolution_clock::now();
    buffer.selectionSort();
    stop = std::chrono::high_resolution_clock::now();
    auto selectSortTime = std::chrono::duration<double>(stop - start);
    sortedBuffer.print();
    std::cout << std::endl << "Time to sort: " << selectSortTime.count() << "s" << std::endl;
    petc();

    return 0;
}

void f(int_buffer buf) {
    std::cout << "Creates a buffer and inserts numbers in a rising order:" << std::endl;
    int counter = 1;
    for(int* i = buf.begin(); i != buf.end(); i++) {
        *i = counter;
        counter++;
    }
    for(const int* i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl << std::endl;
}

void fAuto(int_buffer buf) {
    std::cout << "Creates a buffer and inserts numbers in a rising order:" << std::endl;
    int counter = 1;
    for(auto& e: buf) {
        e = counter;
        counter++;
    }
    for(auto e: buf) {
        std::cout << e << ", ";
    }
    std::cout << std::endl << std::endl;
}

void fSorted(int_sorted buf) {
    std::cout << "Inserts 100 random elements in the sorted buffer:" << std::endl;
    for(int i = 0; i < 100; i++) {
        buf.insert(rand() % 9999 + 1);
    }
    buf.print();
    std::cout << std::endl;
}

void fMerge(int_sorted buf1, int_sorted buf2) {
    std::cout << "Takes two sorted buffers and merges them..." << std::endl;
    for(int i = 0; i < 20; i++) {
        buf1.insert(rand() % 9999 +1);
        buf2.insert(rand() % 9999 +1);
    }
    std::cout << "Buffer1:" << std::endl;
    buf1.print();
    std::cout << std::endl << "Buffer2:" << std::endl;
    buf2.print();
    int_sorted mergedBuffer = buf1.merge(buf2);
    std::cout << std::endl << "Merged Buffer:" << std::endl;
    mergedBuffer.print();
    std::cout << std::endl << std::endl;
}

void petc() {
    std::cout << "Press [ENTER] to continue...";
    std::cin.get();
}