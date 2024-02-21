#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int index = 1;
            int c = 1;
            int val = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == val && c < 2) {
                    nums[index] = nums[i];
                    index++;
                    c++;
                } else if (nums[i] != val) {
                    val = nums[i];
                    c = 1;
                    nums[index] = nums[i];
                    index++;
                }
            }
            return index;
        }

        int my_soultion(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            multiset<int> m_s(nums.begin(), nums.end());
            // set<int> s(nums.begin(), nums.end());
            nums.clear();
            for (auto i = m_s.begin(); i != m_s.end();) {
                int s_count = m_s.count(*i);
                if (s_count == 1) {
                    nums.push_back(*i);
                    ++i;
                } else if (s_count >= 2) {
                    nums.push_back(*i);
                    nums.push_back(*i);
                    advance(i, s_count);
                }
            }
            return nums.size();
        }
};

/*
Given an integer array nums sorted in non-decreasing order, remove some
duplicates in-place such that each unique element appears at most twice. The
relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you
must instead have the result be placed in the first part of the array nums. More
formally, if there are k elements after removing the duplicates, then the first
k elements of nums should hold the final result. It does not matter what you
leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the
input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of
nums being 1, 1, 2, 2 and 3 respectively. It does not matter what you leave
beyond the returned k (hence they are underscores). Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of
nums being 0, 0, 1, 1, 2, 3 and 3 respectively. It does not matter what you
leave beyond the returned k (hence they are underscores).
 */