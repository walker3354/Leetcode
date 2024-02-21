#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            multiset<int> s(nums.begin(), nums.end());
            int max_num, max_count = 0;
            for (auto i = s.begin(); i != s.end();) {
                int count = s.count(*i);
                if (max_count < count) {
                    max_count = count;
                    max_num = *i;
                }
                advance(i, count);
            }
            return max_num;
        }
};

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You
may assume that the majority element always exists in the array.



Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/