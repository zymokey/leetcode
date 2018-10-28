/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:
Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
    public:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

        int sumNumbers(TreeNode* root) {
            return DFS(root, 0);
        }

        int DFS(TreeNode *root, int curSum) {
            if(!root) return 0;
            curSum = curSum * 10 + root->val;
            if(root->left == NULL && root->right == NULL) return curSum;
            return DFS(root->left, curSum) + DFS(root->right, curSum);
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/