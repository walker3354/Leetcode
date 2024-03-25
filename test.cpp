#include <iostream>

using namespace std;

int test_func(int a, int b) { return a + b; }

int test_func_2(int a) { return a; }

int main() { cout << test_func_2(test_func(10, 20)); }