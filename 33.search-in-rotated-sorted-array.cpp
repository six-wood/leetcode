// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=21913
 *
 * [33] 搜索旋转排序数组
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
    int binary_search(vector<int> &nums, int traget, int left, int right)
    {
        int mid = 0;
        while (left <= right)
        {
            mid = (right + left) >> 1;
            if (nums[mid] < traget)
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return left;
    }

    int search(vector<int> &nums, int target)
    {
        int left = -1, right = nums.size() - 1;
        int mid = 0;
        while (left + 1 < right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] > nums[right])
            {
                left = mid;
            }
            else
                right = mid;
        }
        int min_loc = right, location = 0;
        left = 0, right = nums.size() - 1;

        if (target > nums.back())
        {
            location = binary_search(nums, target, 0, min_loc - 1);
        }
        else
            location = binary_search(nums, target, min_loc, nums.size() - 1);

        if (nums[location] != target)
            return -1;

        return location;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
