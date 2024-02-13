#include <iostream>
#include <vector>

#include "basic_function.h"
#include "common_sort/basic_sort.h"

int main() {
    std::vector<int> array;
    random_element_generate(array, 10);

    show_array_element(array);
}