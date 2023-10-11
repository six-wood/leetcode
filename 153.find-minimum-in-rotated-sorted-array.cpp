/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=21913
 *
 * [153] 寻找旋转排序数组中的最小值
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
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2; // 计算中点

            if (nums[mid] > nums[r])
            {
                l = mid + 1; // 最小值必定在右半部分，排除中点
            }
            else if (nums[mid] < nums[l])
            {
                r = mid; // 最小值必定在左半部分，包括中点
            }
            else
            {
                // 在这种情况下，数组没有旋转，或者最小值就是 nums[l]
                return nums[l];
            }
        }
        return nums[l];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */
