/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
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
        int maxDepth(TreeNode* root) {
            if(root == NULL) {
                return 0;
            } else {
                return 1 + max(maxDepth(root->left), maxDepth(root->right));
            }
        }
        
};

int main() {
    Solution sol;
    return 0;
}