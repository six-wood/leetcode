// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=21913
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
class Solution
{
public:
    int low_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = low_bound(nums, target);
        int right = low_bound(nums, target + 1) - 1;
        if (left == nums.size() || nums[left] != target)
        {
            return {-1, -1};
        }
        return {left, right};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
