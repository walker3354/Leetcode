#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size();
            int left = 0;
            int sum = 0;
            int minLength = INT_MAX;

            for (int right = 0; right < n; right++) {
                sum += nums[right];
                while (sum >= target) {
                    minLength = min(minLength, right - left + 1);
                    sum -= nums[left];
                    left++;
                }
            }

            return (minLength != INT_MAX) ? minLength : 0;
        }
};

// note it subarry must continue ex： target = 7
// nums = {3,1,1,1,4}  ans = 4 => 1,1,1,4

/*
Given an array of positive integers nums and a positive integer target, return
the minimal length of a subarray whose sum is
greater than or equal to target.
If there is no such subarray, return 0 instead.



Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem
constraint. Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another
solution of which the time complexity is O(n log(n)).
*/