#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            const int vec_len = nums.size();
            vector<vector<int>> answer;
            //<- to make sure the answer will be increase ex:(i,j,k) i <j <k
            for (int i = 0; i < vec_len - 2; ++i) {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue; // condition 3. will have same result
                int left = i + 1, right = vec_len - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum < 0) {
                        ++left;
                    } else if (sum > 0) {
                        --right;
                    } else {
                        answer.push_back({nums[i], nums[left], nums[right]});
                        // same condition prevent have same result
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        //
                        ++left;
                        --right;
                    }
                }
            }
            return answer;
        }
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that
1. i != j, i != k, and j != k
2.nums[i] + nums[j] + nums[k] == 0.
3.Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter. Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/