"""
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
"""
from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        max = nums[0]
        for i in nums:
            sum += i
            if sum > max:
                max = sum
            if sum < 0:
                sum = 0
        return max
