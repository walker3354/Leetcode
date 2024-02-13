#include <iostream>
#include <random>
#include <vector>

void random_element_generate(std::vector<int> &array, int max_elem,
                             int base = 0, int limit = 10) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(base, limit);
    int dice_roll = distribution(generator);
    for (int i = 0; i < max_elem; i++) {
        array.push_back((rand() % limit) - base);
    }
}

void show_array_element(std::vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << std::endl;
    }
}