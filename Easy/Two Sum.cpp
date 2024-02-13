#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            vector<int> anwser;
            vector<int> original(nums);
            insertion_sort(nums);

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > target) break;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] > target) break;
                    if (nums[i] + nums[j] == target) {
                        anwser.push_back(nums[i]);
                        anwser.push_back(nums[j]);
                    }
                }
            }

            for (int i = 0; i < original.size(); i++) {
                if (original[i] == anwser[0]) {
                    anwser[0] = i;
                    continue;
                }
                if (original[i] == anwser[1]) anwser[1] = i;
            }

            return anwser;
        }

        void insertion_sort(vector<int> &nums) {
            for (int i = 1; i < nums.size(); i++) {
                int current = nums[i];
                int previous = i - 1;
                while (previous >= 0 && current < nums[previous]) {
                    nums[previous + 1] = nums[previous];
                    previous--;
                }
                nums[previous + 1] = current;
            }
        }
};

int main() {
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);
    Solution test;
    test.twoSum(vec, 6);
}

/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/