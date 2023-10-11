// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=21913
 *
 * [199] 二叉树的右视图
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
    void dfs(TreeNode *p, int depth, vector<int> &res)
    {
        if (p == nullptr)
            return;
        if (depth == res.size())
            res.push_back(p->val);
        dfs(p->right, depth + 1, res);
        dfs(p->left, depth + 1, res);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        dfs(root, 0, res);
        return res;
        // vector<int> res;
        // // 层续遍历
        // queue<TreeNode *> q;
        // if (curr)
        //     q.push(curr);
        // while (!q.empty())
        // {
        //     int size = q.size();
        //     for (int i = 0; i < size; ++i)
        //     {
        //         curr = q.front();
        //         q.pop();
        //         if (i == size - 1)
        //             res.push_back(curr->val);
        //         if (curr->left)
        //             q.push(curr->left);
        //         if (curr->right)
        //             q.push(curr->right);
        //     }
        // }
        // return res;
        // vector<int> res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
