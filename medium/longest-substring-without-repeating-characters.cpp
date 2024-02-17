#include <algorithm>
#include <set>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            set<char> answer_pool;
            int i = 0, j = 0, answer = 0;
            int lenght = s.length();
            while (i < lenght && j < lenght) {
                if (answer_pool.find(s[j]) == answer_pool.end()) {
                    answer_pool.insert(s[j++]);
                    answer = max(answer, j - i);
                } else {
                    answer_pool.erase(s[i++]);
                }
            };
            return answer;
        };
};
/*
Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and
not a substring.
*/