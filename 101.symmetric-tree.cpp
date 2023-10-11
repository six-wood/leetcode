/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=21913
 *
 * [101] 对称二叉树
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p != nullptr & q != nullptr)
            return (p->val == q->val) & (isSameTree(p->left, q->right)) & (isSameTree(p->right, q->left));
        else
            return (p == q);
    }

    bool isSymmetric(TreeNode *root)
    {
        return isSameTree(root->left, root->right);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
