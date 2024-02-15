#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "common_function/basic_function.h"
using namespace std;

int main() {
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(10);
    vec.push_back(5);
    show_vector_element(vec);

    set<int> s;
    copy(vec.begin(), vec.end(), inserter(s, s.begin()));
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }
}