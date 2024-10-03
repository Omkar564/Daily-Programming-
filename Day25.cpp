#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

private:
    bool isValidBSTHelper(TreeNode* node, int min, int max) {
        if (node == NULL) {
            return true; // An empty node is a valid BST
        }
        
        // Check if the current node's value is within the valid range
        if (node->val <= min || node->val >= max) {
            return false; // Not a valid BST
        }
        
        // Recursively check the left and right subtree
        return isValidBSTHelper(node->left, min, node->val) && 
               isValidBSTHelper(node->right, node->val, max);
    }
};

// Example usage:
int main() {
    // Create a sample binary tree:
    //     2
    //    / \
    //   1   3
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution solution;
    if (solution.isValidBST(root)) {
        std::cout << "The tree is a valid BST." << std::endl;
    } else {
        std::cout << "The tree is NOT a valid BST." << std::endl;
    }

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

