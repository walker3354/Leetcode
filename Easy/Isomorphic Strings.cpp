#include <string>
using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            int s_len = s.size();
            int t_len = t.size();
            if (s_len != t_len) return false;

            for (int i = 0; i < s_len - 1; i++) {
                char s_temp = s[i];
                char t_temp = t[i];
                if (s.find(s_temp, i + 1) == t.find(t_temp, i + 1)) continue;
                return false;
            }
            return true;
        }
};

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get
t.

All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same
character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true


Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/