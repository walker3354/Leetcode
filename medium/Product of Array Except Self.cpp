#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> answer(n, 1);
            int prefix = 1;
            for (int i = 0; i < n; i++) {
                answer[i] *= prefix;
                prefix *= nums[i];
            }
            prefix = 1;
            for (int j = n - 1; j >= 0; j--) {
                answer[j] *= prefix;
                prefix *= nums[j];
            }
            return answer;
        }
        vector<int> my_soultion(vector<int>& nums) {
            int len = nums.size();
            int zero_counter = 0;
            for (int i = 0; i < len; i++) {
            }
        }
};

/*
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.



Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 */