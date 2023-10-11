/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=21913
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int> &height)
    {
        int slow = 0, fast = height.size() - 1;
        int area = 0, maxArea = 0;
        while (slow < fast)
        {
            area =
                (height[slow] > height[fast] ? height[fast] : height[slow]) * (fast - slow);
            maxArea = area > maxArea ? area : maxArea;
            if (height[slow] > height[fast])
                --fast;
            else
                ++slow;
        }
        return maxArea;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
