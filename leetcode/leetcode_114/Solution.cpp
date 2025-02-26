struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {

public:
    TreeNode* prev = nullptr;
    
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right); // Process right subtree first
        flatten(root->left); // Then process left subtree

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};