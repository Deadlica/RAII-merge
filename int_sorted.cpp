// Labb 1, DT079G
// Samuel Greenberg
// int_sorted.cpp, 03/11/2021, 15/11/2021
// implementation av klassen int_sorted

#include "int_sorted.h"
#include <algorithm>
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size):
buffer(source, size) {
    if(size > 1) {
        buffer = sort(source, source + size).buffer;
    }
}
size_t int_sorted::size() const {
    return buffer.size();
}

size_t int_sorted::capacity() const {
    return buffer.size();
}

int* int_sorted::insert(int value) {
    int_sorted newElement(&value, 1);

    buffer = merge(newElement).buffer;
    return buffer.begin();
}
const int* int_sorted::begin() const {
    return buffer.begin();
}
const int* int_sorted::end() const {
    return buffer.end();
}

void int_sorted::print() const {
    for(auto e: *this) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    int_buffer c(size() + merge_with.size());
    const int* pointerA = begin(), *pointerB = merge_with.begin();
    int a, b, index = 0;
    while(pointerA != end() && pointerB != merge_with.end()) {
        a = *pointerA;
        b = *pointerB;
        if(a < b) {
            c[index++] = *pointerA;
            pointerA++;
        }
        else {
            c[index++] = *pointerB;
            pointerB++;
        }
    }
    while(pointerA != end()) {
        c[index++] = *pointerA;
        a = *++pointerA;
    }
    while(pointerB != merge_with.end()) {
        c[index++] = *pointerB;
        b = *++pointerB;
    }
    int_sorted merged(nullptr, 0);
    merged.buffer = c;//(c.begin(), c.size());
    return merged;
}
int_sorted int_sorted::sort(const int* begin, const int* end) {
    if(begin == end) {
        return int_sorted(nullptr, 0);
    }
    if(begin == end - 1) {
        return int_sorted(begin, 1);
    }

    ptrdiff_t half = (end - begin) / 2; // pointer diff type
    const int* mid = begin + half;
    return  sort(begin, mid).merge(sort(mid, end));
}

void selectionSort(int* begin, int* end) {
    int_buffer sorted(begin, end - begin);
    int* smallestPointer;
    int index = 0;
    for(int* i = begin; i != end; i++, index++) {
        smallestPointer = i;
        for(int* j = i + 1; j != end; j++) {
            if(*j < *smallestPointer) {
                smallestPointer = j;
            }
        }
        std::swap(*smallestPointer, *i);
    }
}