/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {

    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()) return false;
            unordered_map<char, int> map;
            for(int i = 0; i < s.length(); i++) {
                map[s[i]]++;
                map[t[i]]--;
            }
            for(auto c : map) {
                if(c.second)
                    return false;
            }
            return true;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/