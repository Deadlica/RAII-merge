#include "int_sorted.h"
#include <algorithm>

int_sorted::int_sorted(const int* source, size_t size):
buffer(size), bufSize(size) {
    std::copy(source, source + size, buffer.begin());
    std::sort(buffer.begin(), buffer.end());
}
size_t int_sorted::size() const {
    return bufSize;
}

size_t int_sorted::capacity() const {
    return buffer.size();
}

int* int_sorted::insert(int value) {
    if(bufSize == capacity()) {
        size_t newSize = bufSize * 2;
        int_buffer newBuffer(newSize);
        std::copy(buffer.begin(), buffer.end(), newBuffer.begin());
        buffer = newBuffer;
    }
    bufSize++;
    buffer[bufSize] = value;
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
    return *this;
}