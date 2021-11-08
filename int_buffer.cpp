#include "int_buffer.h"

#include <algorithm>
#include <iostream>

int_buffer::int_buffer(size_t size):
buffer_start(new int[size]),
buffer_end(buffer_start + size) {
}

int_buffer::int_buffer(const int* source, size_t size):
int_buffer(size) {
    std::copy(source, source + size, buffer_start);
}

int_buffer::int_buffer(const int_buffer& rhs):
int_buffer(rhs.buffer_start, rhs.size()) {
    
}

int_buffer::int_buffer(int_buffer&& rhs):buffer_start(nullptr), buffer_end(nullptr) {
    swap(rhs);
}

int_buffer& int_buffer::operator=(const int_buffer& rhs) {
    int_buffer copy = rhs;
    swap(copy);
    return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs) {
    swap(rhs);
    return *this;
}

int& int_buffer::operator[](size_t index) {
    return buffer_start[index];
}

const int& int_buffer::operator[](size_t index) const {
    return buffer_start[index];
}

size_t int_buffer::size() const {
    return buffer_end - buffer_start;
}

int* int_buffer::begin() {
    return buffer_start;
}

int* int_buffer::end() {
    return buffer_end;
}

const int* int_buffer::begin() const {
    return buffer_start;
}

const int* int_buffer::end() const {
    return buffer_end;
}

int_buffer::~int_buffer() {
    delete [] buffer_start;
}

void int_buffer::swap(int_buffer& rhs) {
    std::swap(this->buffer_start, rhs.buffer_start);
    std::swap(this->buffer_end, rhs.buffer_end);
}