#include <vector>

void swap(std::vector<int> &array, int r, int l) {
    int temp = array[r];
    array[r] = array[l];
    array[l] = temp;
}

void insertion_sort(std::vector<int> &array) {
    if (array.size() <= 1) return;
    for (int i = 1; i < array.size(); i++) {
        int current = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

void bubble_sort(std::vector<int> &array) {
    if (array.size() <= 1) return;
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[i]) swap(array, j, i);
        }
    }
}

void selection_sort(std::vector<int> &array) {
    if (array.size() <= 1) return;
    for (int i = 0; i < array.size() - 1; i++) {
        int mini_pos = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[mini_pos]) mini_pos = j;
        }
        swap(array, i, mini_pos);
    }
}
