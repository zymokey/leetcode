"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
"""

from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''
        l = len(strs)
        first_word = strs[0]
        for i in range(len(first_word)):
            for j in range(l):
                if i >= len(strs[j]):
                    return first_word[:i]
                elif first_word[i] != strs[j][i]:
                    return first_word[:i]
        return first_word


