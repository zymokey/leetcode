/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> m;
            vector<int> res;
            for(int i = 0; i < nums1.size(); i++) {
                m[nums1[i]] += 1;
            }
            for(int i = 0; i < nums2.size(); i++) {
                if(m[nums2[i]]-- > 0) {
                    res.push_back(nums2[i]);
                }
            }
            return res;
        }

};

int main() {
    Solution sol;
    return 0;
}

/*


*/