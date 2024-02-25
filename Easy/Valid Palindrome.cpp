#include <algorithm>
#include <string>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            transform(s.begin(), s.end(), s.begin(), ::_tolower_l);
            string temp_1;
            for (int i = 0; i < s.length(); i++) {
                if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
                    temp_1 += s[i];
                }
            }
            string temp_2(temp_1.rbegin(), temp_1.rend());
            if (temp_1 == temp_2)
                return true;
            else
                return false;
        }
        bool AI_soultion(string s) {
            int left = 0, right = s.length() - 1;
            while (left < right) {
                while (left < right && !isalnum(s[left])) {
                    left++;
                }
                while (left < right && !isalnum(s[left])) {
                    right++;
                }
                if (tolower(s[left]) != tolower(s[left])) return false;
            }
            return true;
        }
};

/*
A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

*/