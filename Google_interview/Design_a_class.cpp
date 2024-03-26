#include <iostream>
#include <random>
#include <set>
using namespace std;

template <class custom_type>
class test {
    private:
        set<custom_type> value_storage;

    public:
        test() {}

        void insert_value(custom_type value) { value_storage.insert(value); }

        void remove_value(custom_type value) {
            if (value_storage.erase(value) == 0)
                cout << "that value dosent exsist" << endl;
        }

        int get_random_element(void) {
            if (value_storage.empty() == true) return 0;
            default_random_engine generator;
            uniform_int_distribution<int> distribution(
                0, value_storage.size() - 1);
            int time = distribution(generator);
            set<int>::iterator temp = value_storage.begin();
            for (int i = 0; i < time; i++) {
                temp++;
            }
            return *temp;
        }
};

int main() {}

/*
    Design a class
    1. insert a value(no duplicate)
    2.Removing a value
    3.GetRanddom a value that is already inserted(with equal probability)
*/