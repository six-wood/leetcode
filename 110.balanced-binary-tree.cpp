/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=21913
 *
 * [110] 平衡二叉树
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    // int depth(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return 0;
    //     int leftHeight = depth(root->left);
    //     int rightHeight = depth(root->right);
    //     if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
    //         return -1;
    //     else
    //         return max(depth(root->left), depth(root->right)) + 1;
    // }

    // bool isBalanced(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return true;
    //     return depth(root) != -1;
    // }
    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(depth(root->left), depth(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if ((root->left != nullptr) & (root->right != nullptr))
            return (abs(depth(root->left) - depth(root->right)) <= 1) & isBalanced(root->left) & isBalanced(root->right);
        else if (root->left != nullptr)
            return depth(root->left) <= 1;
        else if (root->right != nullptr)
            return depth(root->right) <= 1;
        else
            return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
