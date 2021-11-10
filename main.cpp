#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <algorithm>

void f(int_buffer buf);
void fAuto(int_buffer buf);

int main() {
    srand((unsigned) time(0));
    system("clear");
    //testing int_buffer
    //f(int_buffer(10));
    //fAuto(int_buffer(10));

    //testing int_sorted
    int_buffer buf(0);
    int_sorted bufSorted(buf.begin(), buf.size());
    for(int i = 0; i < 10; i++) {
        bufSorted.insert((rand() % 99 + 1));
    }
    for(auto e: bufSorted) {
            std::cout << e << ", ";
    }
    std::cout << std::endl;

    int_sorted bufSorted2(buf.begin(), buf.size());
       for(int i = 0; i < 10; i++) {
        bufSorted2.insert((rand() % 99 + 1));
    }
    for(auto e: bufSorted2) {
            std::cout << e << ", ";
    }
    std::cout << std::endl << std::endl;

    //testing int_sorted.merge()
    int_sorted mergeBuf = bufSorted.merge(bufSorted2);
    for(auto e: mergeBuf) {
        std::cout << e << ", "; 
    }
    std::cout << std::endl;

    //testing sort
    int_buffer buf2(40000);
    for(auto& e: buf2) {
        e = rand() % 99 + 1;
    }
    int_sorted unsortedBuffer(buf2.begin(), buf2.size());
    auto start = std::chrono::high_resolution_clock::now();
    int_sorted sortedBuffer = unsortedBuffer.sort(unsortedBuffer.begin(), unsortedBuffer.end());
    //unsortedBuffer.selectionSort();
    //std::sort(buf2.begin(), buf2.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration<double>(stop - start);
    for(auto e: sortedBuffer) {
        std::cout << e << ", ";
    }
    std::cout << std::endl << "Time to sort: " << time.count() << "s" << std::endl;

    return 0;
}

void f(int_buffer buf) {
    int counter = 1;
    for(int* i = buf.begin(); i != buf.end(); i++) {
        *i = counter;
        counter++;
    }
    for(const int* i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
}

void fAuto(int_buffer buf) {
    int counter = 1;
    for(auto& e: buf) {
        e = counter;
        counter++;
    }
    for(auto e: buf) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}
