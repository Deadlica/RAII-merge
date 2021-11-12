#include "int_sorted.h"
#include <algorithm>
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size):
buffer(size), bufSize(size) {
    std::copy(source, source + size, buffer.begin());
    //std::sort(buffer.begin(), buffer.end());
}
size_t int_sorted::size() const {
    return bufSize;
}

size_t int_sorted::capacity() const {
    return buffer.size();
}

int* int_sorted::insert(int value) {
    if(bufSize == capacity()) {
        size_t newSize;
        if(capacity() == 0) {
            newSize = 16;
        }
        else {
            newSize = bufSize * 2;
        }
        int_buffer newBuffer(newSize);
        std::copy(buffer.begin(), buffer.end(), newBuffer.begin());
        buffer = newBuffer;
    }
    buffer[bufSize++] = value;
    std::sort(buffer.begin(), buffer.begin() + bufSize);
    return buffer.begin() + bufSize;
}
const int* int_sorted::begin() const {
    return buffer.begin();
}
const int* int_sorted::end() const {
    return begin() + bufSize;
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    int_sorted c(begin(), 0);
    const int* pointerA = begin(), *pointerB = merge_with.begin();
    int a, b;
    while(pointerA != end() && pointerB != merge_with.end()) {
        a = *pointerA;
        b = *pointerB;
        if(a < b) {
            c.insert(a);
            pointerA++;
        }
        else {
            c.insert(b);
            pointerB++;
        }
    }
    while(pointerA != end()) {
        c.insert(a);
        a = *++pointerA;
    }
    while(pointerB != merge_with.end()) {
        c.insert(b);
        b = *++pointerB;
    }
    return c;
}
int lolz = 0;
int_sorted int_sorted::sort(const int* begin, const int* end) {
    if(begin == end) {
        return int_sorted(nullptr, 0);
    }
    if(begin == end - 1) {
        return int_sorted(begin, 1);
    }

    ptrdiff_t half = (end - begin) / 2; // pointer diff type
    std::cout << lolz << std::endl;
    lolz++;
    const int* mid = begin + half;
    return  sort(begin, mid).merge(sort(mid, end));
}

int_sorted& int_sorted::selectionSort() {
    int* smallestPointer;
    for(int* i = buffer.begin(); i != buffer.end(); i++) {
        smallestPointer = i;
        for(int* j = i + 1; j != buffer.end(); j++) {
            if(*j < *smallestPointer) {
                smallestPointer = j;
            }
        }
        std::swap(*smallestPointer, *i);
    }
    return *this;
}