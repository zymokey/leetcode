/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,3,2]
Output: 3

Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        int singleNumber(vector<int>& nums) {
            int n = nums.size();
            int low = 0, high = 0;
            for(int i = 0; i < n; i++) {
                low = (low ^ nums[i]) & ~high;
                high = (high ^ nums[i]) & ~low;
            }
            return low;
        }
};

int main() {
    Solution sol;
    return 0;
}