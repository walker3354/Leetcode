#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if (nums.size() == 0) return;
            k %= nums.size();
            vector<int> temp(nums.begin() + (nums.size() - k), nums.end());
            for (int i = 0; i < k; i++) {
                nums.pop_back();
            }
            for (auto i = nums.begin(); i != nums.end(); ++i) {
                temp.push_back(*i);
            }
            nums = temp;
        }
};