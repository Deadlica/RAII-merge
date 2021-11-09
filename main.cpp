#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>
#include <ctime>

void f(int_buffer buf);
void fAuto(int_buffer buf);

int main() {
    srand((unsigned) time(0));
    system("clear");
    //testing int_buffer
    //f(int_buffer(10));
    //fAuto(int_buffer(10));

    //testing int_sorted
    int_buffer buf(10);
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