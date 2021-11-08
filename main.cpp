#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>
#include <ctime>

void f(int_buffer buf);
void fAuto(int_buffer buf);

int main() {
    srand((unsigned) time(0));
    system("clear");
    //int_buffer testing
    f(int_buffer(10));
    fAuto(int_buffer(10));
    int_buffer buf(5);
    for(auto e: buf) {std::cout << e << ", ";}
    std::cout << std::endl;
    int_sorted bufS(buf.begin(), buf.size());
    for(int i = 0; i < 5; i++) {
        bufS.insert(rand() % 99 + 1);
    }
    for(auto e: bufS) {
        //if(e != 0){
            std::cout << e << ", ";
        //}
    }
    std::cout << std::endl << bufS.size() << " " << bufS.capacity() << std::endl;

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