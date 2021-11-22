// Labb 1, DT079G
// Samuel Greenberg
// int_sorted.h, 03/11/2021, 15/11/2021
// deklaration av klassen int_sorted

#ifndef INT_SORTED_H
#define INT_SORTED_H

#include "int_buffer.h"
#include <cstdlib>

class int_sorted {
public:
    int_sorted(const int* source, size_t size);
    size_t size() const;
    size_t capacity() const;
    int* insert(int value); // returns the insertion point.
    const int* begin() const;
    const int* end() const;
    void print() const;
    int_sorted merge(const int_sorted& merge_with) const;
    int_sorted sort(const int* begin, const int* end);

private:
    int_buffer buffer;
};

void selectionSort(int* begin, int* end);

#endif