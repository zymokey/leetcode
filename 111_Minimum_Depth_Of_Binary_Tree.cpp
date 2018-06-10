/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/
#include <iostream>

using namespace std;

class Solution {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    public:
        int minDepth(TreeNode* root) {
            if(root == NULL) return 0;
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if(left == 0 || right == 0) {
                return left + right + 1;
            } else {
                return min(left, right) + 1;
            }
        }
};

int main() {
    Solution sol;
    return 0;
}