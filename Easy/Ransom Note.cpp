#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int ran_len = ransomNote.size();
            int mag_len = magazine.size();
            if (mag_len < ran_len) return false;

            unordered_map<char, int> mag_map;
            for (int i = 0; i < magazine.size(); i++) {
                char temp = magazine[i];
                if (mag_map.find(temp) != mag_map.end())
                    mag_map[temp]++;
                else
                    mag_map[temp] = 1;
            }

            for (int i = 0; i < ransomNote.size(); i++) {
                char temp = ransomNote[i];
                if (mag_map.find(temp) == mag_map.end()) return false;
                if (mag_map[temp] == 0) return false;
                mag_map[temp]--;
            }
            return true;
        }
};

/*
Given two strings ransomNote and magazine, return true if ransomNote can be
constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true


Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/