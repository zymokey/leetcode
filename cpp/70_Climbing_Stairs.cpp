/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
#include <iostream>

using namespace std;

class Solution {

    public:
        int climbStairs(int n) {
            int stepA = 1, stepB = 0;
            int res = 0;
            for(int i = 0; i < n; i++){
                res = stepA + stepB;
                stepB = stepA;
                stepA = res;
            }
            return res;
        }
        
};

int main() {
    Solution sol;
    cout << sol.climbStairs(22) << endl;
    return 0;
}